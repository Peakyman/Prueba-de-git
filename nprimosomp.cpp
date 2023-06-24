#include <iostream>
#include <vector>
#include <omp.h>
#include <ctime>
using namespace std;

int main() {
	clock_t inicio = clock(); //temporizador
	int cantPrimos=0; //contador de numeros primos
	ios_base::sync_with_stdio(false); //desactiva el vaciado automático del búfer de salida
	cin.tie(NULL); //desactiva la sincronización con los flujos de entrada/salida de C en C++
    
    const int limite = 500000000; //numero limite de numeros a evaluar
    vector<bool> esPrimo(limite + 1, true); //vector numeros, true quiere decir que es primo
    esPrimo[0] = esPrimo[1] = false; //inicializa 0 y 1 como no primos (false)
    //Inicializa recorrido for para descartar numeros no primos (Criba de Eratostenes)
    for (int i = 2; i * i <= limite; i++) {
        if (esPrimo[i]) {
            for (int j = i * i; j <= limite; j += i) {
                esPrimo[j] = false;
            }
        }
    }
    //Imprimir de forma paralelizada los numeros primos, contarlos e imprimir la cantidad
    #pragma omp parallel
    {
    	#pragma omp for
    	for (int i = 2; i <= limite; i++) {
        	if (esPrimo[i]) {
            	cout << i << " ";
            	#pragma omp atomic
            	cantPrimos++;
        	}
    	}		
	}
    
    cout<<"\nLa cantidad de numeros primos es de "<<cantPrimos<<endl;
    
    clock_t fin = clock();
    double tiempo_transcurrido = double(fin - inicio) / CLOCKS_PER_SEC;
    printf("Tiempo transcurrido: %.2f minutos\n", tiempo_transcurrido / 60.0);
    return 0;
}
