#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int CantPrimos=0;
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
    for (int i = 2; i <= limite; i++) {
        if (esPrimo[i]) {
            cout << i << "\n ";
            CantPrimos++;
        }
    }
    cout<<"Hay "<<CantPrimos<<" numeros primos."<<endl;
    return 0;
}
