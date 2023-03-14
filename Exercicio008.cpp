//Exercicio008.cpp

//GUILHERME MARTINS SPECHT

//Finalidade de mostrar os numeros primos e suas respectivas posicoes

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int num[9], i, j, cont;


    for (i=0; i<9; i++)
    {
        cout << "Vetor " << i << ":" << endl;
        cin >> num[i];
    }

    for (i=0; i<9; i++)
    {
        cont = 0;

        for(j=1; j<=num[i]; j++){
            if((num[i]%j)==0){
                cont++;
            }
        }
            if (cont == 2){
                cout << num[i] << " " << i << "\n" << endl;;
        }
    }

        return 0;
    }
