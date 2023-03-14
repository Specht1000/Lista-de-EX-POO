//Exercicio009.cpp

//GUILHERME MARTINS SPECHT

//Finalidade de ler uma matriz 6x4, recalcula a matriz digitada, onde cada linha devera se multiplicada pelo maior elemento
//da linha em questao

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
    int mat[6][4], i, j, maiornumero, linhamaiornumero;

    cout << "Informe os numeros da matriz por linha: " << endl;
    for(i=0;i<6;i++){
        for(j=0;j<4;j++){
           cin >> mat[i][j];
           if(j==0)
                maiornumero = mat[i][j];
           else if(mat[i][j]>maiornumero)
                maiornumero = mat[i][j];
        }
        for(j=0;j<4;j++){
            mat[i][j]*= maiornumero;
        }
    }


    cout << "A matriz resultante da multiplicacao do maior elemento da linha e: \n" << endl;

    for (i=0;i<6;i++){
        for(j=0;j<4;j++){
            cout << mat[i][j];
            cout << " ";
        }
        cout << "\n" << endl;
    }
    return 0;
}
