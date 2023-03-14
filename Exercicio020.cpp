//Exercicio020.cpp

//GUILHERME MARTINS SPECHT

//Finalidade de calcular as ações de uma conta corrente.

//ULTIMA ATUALIZAÇÃO: 09/09/2021

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class ContaCorrente {

    private:

        string numero;
        string titular;
        double limite;
        double saldo;

    public:

        ContaCorrente(string n="", string t="", double l=0.0){
            numero = n;
            titular = t;
            limite = l;
            saldo = 0;
        }

        void deposita(double v){
            saldo = saldo + v;
        }

        bool debita(double v){
            if(((limite)*(-1)) <= saldo - v){
                saldo -= v;
                return true;
            }
            else{
                return false;
            }
        }

        string obtemNumero(){
            return numero;
        }

        string obtemTitular(){
            return titular;
        }

        double obtemLimite(){
            return limite;
        }

        double obtemSaldo(){
            return saldo;
        }

        void aplicaJuros(){
            saldo = ((saldo * 0.1)/100) + saldo;
        }
};

int main()
{
    string NumeroDaConta;
    string NomeDoTitular;
    double Limite;
    char Op;
    double Valor;
    double Saldo=0;
    int DebitoNegado = 0;
    int SaldoNegativo = 0;

    getline(cin, NumeroDaConta);
    getline(cin, NomeDoTitular);
    cin >> Limite;
    ContaCorrente conta(NumeroDaConta, NomeDoTitular, Limite);

    while(1){
        cin >> Op;

        if(Op == '.'){
            Saldo = conta.obtemSaldo();
            if(Saldo < 0){
                SaldoNegativo++;
                conta.aplicaJuros();
            }
            break;
        }

        else if(Op == ','){
            Saldo = conta.obtemSaldo();
            if(Saldo < 0){
                SaldoNegativo++;
                conta.aplicaJuros();
            }
        }

        else if(Op == '+'){
        cin >> Valor;
            conta.deposita(Valor);
        }

        else if(Op == '-'){
            cin >> Valor;
            if(!conta.debita(Valor)){
                DebitoNegado++;
            }
            else{
                cout << "";
            }
        }

        else{
            cerr << "ERRO" << endl;
            break;
        }
    }

    cout << "" << endl;
    cout << conta.obtemNumero() << endl;
    cout << conta.obtemTitular() << endl;
    cout << conta.obtemLimite() << endl;
    cout << fixed << setprecision (4);
    cout << conta.obtemSaldo() << endl;
    cout << SaldoNegativo << endl;
    cout << DebitoNegado << endl;


    return 0;
}
