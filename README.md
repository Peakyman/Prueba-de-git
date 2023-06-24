# Prueba-de-git
El nombre del repositorio se debe a que estuve haciendo pruebas por cambios en el git y github.
En este proyecto se presenta una version con OpenMP del algoritmo de la Criba de Eratostenes.
Este algoritmo fue creado en lenguaje C++, usando la libreria <omp.h> para la "paralelizacion" con memoria distribuida.
Es importante tener instaladas todas las directivas a usar (g++ y OpenMP) para que funcione nuestro algoritmo.

En el algoritmo tenemos una estructura básica, pero muy efectiva, que es un vector, el cual su indice nos dice
cual es el número, y su valor es un booleano para saber si es primo o no (true para primo y false para no primo).

Con OpenMP, paralelizamos la región en donde se imprimen los numeros, que es la más compleja y que toma más tiempo,
por eso la decision de hacerlo ahí. Se usa las directivas "#pragma omp parallel{}", donde dentro de las comillas va la
region del codigo a paralelizar, y luego se usa "#pragma omp for" arriba del bucle "for" que se encarga de imprimir y sumar
la cantidad de digitos primos. También se incluye un "#pragma omp atomic" encima de la suma, ya que es una instrucción simple
pero eficiente, más que con una región critica (pragma omp critical) debido a que al ser ejecutada es vista por el resto del 
sistema como una sola instrucción indivisible.

Una aclaración importante, es que se usa las lineas de codigo "ios_base::sync_with_stdio(false);" y
"cin.tie(NULL);" para obtener una impresión de los numeros incluso más rapida (paralelizado se aprecian menos segundos, 
pero depende del hardware). La primera desactiva el vaciado automático del búfer de salida, mientras que la segunda 
desactiva la sincronización con los flujos de entrada/salida de C en C++.

Finalmente, para compilar el codigo en linux, debemos usar el comando "g++ -fopenmp nprimosomp.cpp -o programa", el nombre "programa"
podemos cambiarlo al que queramos, solo es para que genere un ejecutable, el cual es el que vamos a abrir para ver el correcto 
funcionamiento del programa, con el comando "./programa".
