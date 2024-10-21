# Proyecto Fork en C++

Este proyecto en C++ utiliza el sistema de creación de procesos mediante `fork()`. Permite a los usuarios crear múltiples procesos que introducen nombres y seleccionan aleatoriamente uno de ellos.

## Requisitos

- Un sistema operativo compatible con POSIX (Linux, macOS, etc.)
- `g++` instalado para compilar el código.

## Compilación

Para compilar el programa, utiliza el siguiente comando en la terminal:
`g++ -o fork fork.cpp`<br>
Este comando genera un ejecutable llamado fork a partir del archivo fork.cpp.

## Ejecución
Para ejecutar el programa, utiliza el siguiente comando en la terminal:

`./fork`<br><br>
Al ejecutar el programa, se te pedirá que introduzcas el número de procesos que deseas crear. Luego, cada proceso solicitará un nombre. Aquí tienes un ejemplo de cómo sería la ejecución:
<br><br>
`Introdueix el nombre de processos: 3`<br>
`Procés fill amb PID 2656. Introdueix un nom: Marc`<br>
`Procés fill amb PID 2657. Introdueix un nom: Tome`<br>
`Procés fill amb PID 2658. Introdueix un nom: Jimenez`<br>
`La persona escollida és: Tome`<br>
