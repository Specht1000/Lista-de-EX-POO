//Exercicio007.cpp

//GUILHERME MARTINS SPECHT

//Finalidade de captar a informçao de 10 pessoas, calcular a media de suas idades, pessoas com peso maior que 90kg e altura
//menor que 1.50m e calcular a porcentagem de pessoas entre 10 e 30 anos com mais de 1.90m.

//ULTIMA ATUALIZAÇÃO: 12/08/2021

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int i, idade, auxidade=0, a=0, b=0, c=0;
    float peso, altura, mediaidade, porcem;

    for(i=1;i<11;i++){
        cout << "PESSOA "<< i << endl;
        cout << "IDADE "<< i <<":"<< endl;
        cin >> idade;
        cout << "PESO(kg) "<< i <<":"<< endl;
        cin >> peso;
        cout << "ALTURA(m) "<< i <<":"<< endl;
        cin >> altura;
        cout << "\n";

        if(altura>1.90){
            c++;
        }

        if(idade>10 && idade<30 && altura>1.90){
            b++;
        }

        if(peso>90 && altura<1.50){
            a++;
        }

        auxidade = auxidade + idade;
}
    mediaidade = (auxidade*1.0)/10.0;
    porcem = ((b*1.0)/(c*1.0))*100.0;

    cout << "\n";
    cout << fixed << setprecision (4) ;
    cout << "MEDIA IDADE: " << mediaidade << endl;
    cout << "PESSOAS +90kg/-1,50m: " << a << endl;
    cout << "PESSOAS ENTRE 10 E 30 MAIORES QUE 1.90m: " << porcem << endl;

    return 0;
}
