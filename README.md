# posix-threads
2 ejercicios con hilos de posix en c

1) Realice un código en C usando la biblioteca pthread en el que dada una matriz Anxn se
obtengan dos vectores: a y b, ambos de tamaño n. El vector a contendrá los resultados de
las sumas de los elementos de las filas de A y el vector b de la multiplicación de los
elementos de las columnas. Utilice un hilo para cada par de filas y columnas. 

2) Realice un programa en C que cree tantos hilos como argumentos reciba el programa al
ser ejecutado, estos argumentos serán letras del alfabeto. Cada hilo leerá una cadena de
caracteres de entrada estándar y contará las ocurrencias de su respectiva letra en esa cadena.
Ejm:
./cuenta a c d (Este programa creará tres hilos y cada uno leerá una cadena de entrada estándar)
Si el hilo 0 leyó “Hola”, el hilo 1 leyó “Mundo” y el hilo 2 leyó “!”, una posible salida a lo anterior
es:
Thread 0: La letra “a” aparece 1 veces en “Hola”
Thread 2: La letra “d” aparece 0 veces en “!”
Thread 1: La letra “c” aparece 0 veces en “Mundo”
