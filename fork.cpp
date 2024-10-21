#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
#include <fstream>
#include <cstdlib> // Per a rand() i srand()
#include <ctime> // Per a time()

using namespace std;

const int MAX_NOMS = 10;

int main() {
    int n;
    cout << "Introdueix el nombre de processus: ";
    cin >> n;

    // Fitxer temporal on es guardaran els noms
    ofstream fitxer("noms.txt");

    if (!fitxer.is_open()) {
        cerr << "Error en obrir el fitxer!" << endl;
        return 1;
    }

    // Crear processos fills i esperar un a un
    for (int i = 0; i < n; i++) {
        pid_t pid = fork();
        if (pid == 0) {  // Codi del proces fill
            string nom;
            cout << "Proces fill amb PID " << getpid() << ". Introdueix un nom: ";
            cin >> nom;

            // Obrir fitxer en mode append per afegir el nom
            ofstream fitxer_fills("noms.txt", ios::app);
            if (!fitxer_fills.is_open()) {
                cerr << "Error en obrir el fitxer des del proces fill!" << endl;
                return 1;
            }

            fitxer_fills << nom << endl;
            fitxer_fills.close();

            return 0;  // Sortir del procds fill
        } else if (pid > 0) {
            // El proces pare espera que el proces fill acabi abans de crear el seguent
            wait(NULL);
        } else {
            cerr << "Error en crear el proces fill!" << endl;
            return 1;
        }
    }

    // Llegir tots els noms del fitxer al proces pare
    ifstream fitxer_pare("noms.txt");
    string noms[MAX_NOMS];
    int nomsCount = 0;

    if (fitxer_pare.is_open()) {
        while (getline(fitxer_pare, noms[nomsCount]) && nomsCount < n) {
            nomsCount++;
        }
        fitxer_pare.close();
    } else {
        cerr << "Error en obrir el fitxer al proces pare!" << endl;
        return 1;
    }

    // Triar una persona aleatoria
    srand(time(0));
    if (nomsCount > 0) {
        int index = rand() % nomsCount;
        cout << "La persona escollida es: " << noms[index] << endl;
    } else {
        cout << "No hi ha noms disponibles." << endl;
    }

    // Esborrem el fitxer temporal
    remove("noms.txt");

    return 0;
}
