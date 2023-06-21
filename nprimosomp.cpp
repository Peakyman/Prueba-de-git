#include <iostream>
#include <vector>
#include <omp.h>
using namespace std;

int main() {
	int cantPrimos=0;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    const int limite = 500000000;
    vector<bool> esPrimo(limite + 1, true);
    esPrimo[0] = esPrimo[1] = false;
    for (int i = 2; i * i <= limite; i++) {
        if (esPrimo[i]) {
            for (int j = i * i; j <= limite; j += i) {
                esPrimo[j] = false;
            }
        }
    }
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
    return 0;
}
