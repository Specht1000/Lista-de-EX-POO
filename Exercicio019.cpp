//Exercicio019.cpp

//GUILHERME MARTINS SPECHT

//Finalidade de modelar o funcionamento de um inseto sobre uma linha horizontal.

//ULTIMA ATUALIZACAO: 30/08/2021

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Inseto {

private:

    int valor;
    int distancia;
    int sentido;

public:

    Inseto(int v){
        valor = v;
        sentido = 1;
        distancia = 0;
    }

    void vira(){
       if(sentido == 1){
            sentido = 0;
        }
        else {
            sentido = 1;
        }
    }

    void anda(){
        if(sentido == 1){
            valor = valor + 1;
        }
        if(sentido == 0){
            valor = valor - 1;
        }

    distancia = distancia + 1;
    }

    int obtemPosicao(){ //getter
        return valor;
    }

    int obtemDistancia(){ //getter
        return distancia;
    }
};

int main() {

    string s;
    int pos;

    cin >> pos;
    cin >> s;

    Inseto inseto(pos);
    for (int i=0; i<s.size(); ++i) {
        char c = s.at(i);
        if (c=='.')
            inseto.anda();
        else if (c=='@')
            inseto.vira();
    }
    cout << inseto.obtemPosicao() << " " << inseto.obtemDistancia() << endl;
    return 0;
}
