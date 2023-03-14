//GUILHERME MARTINS SPECHT

//Finalidade de simular o comportamento de produtos em relação ao estoque.

//ULTIMA ATUALIZACAO: 23/09/2021

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

#define MAX_PRODUTOS 10

// --- SOLUÇÃO (início) ---
class Produto {

    private:

        int Codigo;
        string Descricao;
        int Quantidade;
        double Valor_Unitario;

    public:

        Produto(int cod=0, string desc="", int q=0, double vu=0.0){
            Codigo = cod;
            Descricao = desc;
            Quantidade = q;
            Valor_Unitario = vu;
        }

        int obtemCodigo(){
            return Codigo;
        }

        string obtemDescricao(){
            return Descricao;
        }

        int obtemQuantidade(){
            return Quantidade;
        }

        double obtemValorUnitario(){
            return Valor_Unitario;
        }

        void defineCodigo(int codigo){
            Codigo = codigo;
        }

        void defineDescricao(string descricao){
            Descricao = descricao;
        }

        void defineQuantidade(int quantidade){
            Quantidade = quantidade;
        }

        void defineValorUnitario(double valor_unitario){
            Valor_Unitario = valor_unitario;
        }

        string str(){
            stringstream ss;
            ss << "[";
            ss << Codigo;
            ss << "] ";
            ss << Descricao;
            ss << ": ";
            ss << Quantidade;
            ss << fixed << setprecision(2);
            ss << "x" << Valor_Unitario << endl;

            return ss.str();
        }
};

class Estoque {

    private:

        string Deposito;
        Produto *vetor[MAX_PRODUTOS];
        int numProdutos;

    public:

        Estoque(string dep="", int numprod=0){
            Deposito = dep;
            numProdutos = numprod;
        }

        string obtemDeposito(){
            return Deposito;
        }

        int obtemNumProdutos(){
            return numProdutos;
        }

        Produto* obtemProduto(int i){
            if (i<0 || i >= numProdutos){
                return nullptr;
            }
            return vetor[i];
        }

        void defineDeposito(string deposito){
            Deposito = deposito;
        }

        bool adicionaProduto(Produto *p){
            if (numProdutos < MAX_PRODUTOS){
                vetor[numProdutos] = p;
                numProdutos++;
                return true;
            }
            return false;
        }

        double calculaTotalEstoque(){
             double TotalEstoque = 0.0;
            for (int i = 0; i < numProdutos; i++)
                TotalEstoque += (vetor[i]->obtemQuantidade())*(vetor[i]->obtemValorUnitario());
            return TotalEstoque;
        }

        string str(){
            stringstream ss;
            ss << "Deposito: " << Deposito << endl;
            for(int i=0; i<numProdutos; i++){
            ss << vetor[i]->str() << endl;
            }
            ss << fixed << setprecision(2);
            if(!calculaTotalEstoque()<=0)
            ss << "TOTAL DO ESTOQUE = " << calculaTotalEstoque() << endl;

            return ss.str();
            }
};

// --- SOLUÇÃO (fim) ---

int main() {
    Produto *produto[] = {
        new Produto(1,"Cimento CP IV 32 25kg Votoran", 500, 17.29),
        new Produto(2,"Cimento CPB-40 Branco Estrutural 15kg Axton", 100, 72.90),
        new Produto(3,"Rejunte Ceramica Ceramfix Marfim 1kg", 50, 7.00),
        new Produto(4,"Luva PVC Branco Rosca 1/2\" 20mm Plastilit", 60, 1.47),
        new Produto(5,"Luva PVC Marrom Solda 1\" 32mm Tigre", 30, 2.79),
        new Produto(6,"Meio Bloco Ceramico 6 Furos 9x14x12cm Olaria Estancia", 10000, 0.76),
        new Produto(7,"Bloco de Concreto Celular Autoclavado 60x30x10cm Sical", 1000, 13.99),
        new Produto(8,"Telha Ceramica 40x22,5cm Francesa Esmaltada Chumbo Vogel", 300, 2.79),
        new Produto(9,"Telha Cerâmica 41x24cm Portuguesa Natural Cláudio Vogel", 1000, 0.94),
        new Produto(10,"Janela de Correr Alumínio Pintado Preto Fosco 1,00x1,50m Linha Confort Brimak", 10, 574.90),
        new Produto(11,"Folha de Porta de Giro Branco 2,10x0,70m Artens", 5, 219.90)
    };
    int numProdutos = sizeof(produto)/sizeof(Produto *);

    Estoque *estoque = new Estoque("Provisorio");
    cout << estoque->str() << endl;

    estoque->defineDeposito("Deposito Geral");
    int p;
    // Insere 5 produtos
    for (p=0; p<5; ++p)
        if (!estoque->adicionaProduto(produto[p])) { cerr << "ERRO1"; exit(1); }
    // Testa se os 5 produtos foram inseridos
    for (p=0; p<5; ++p)
        if (estoque->obtemProduto(p) != produto[p]) { cerr << "ERRO2"; exit(1); }
    // Testa se há outros itens no estoque
    for (; p<numProdutos; ++p)
        if (estoque->obtemProduto(p) != nullptr) { cerr << "ERRO3"; exit(1); }
    cout << estoque->str() << endl;

    // Adiciona mais 5 produtos
    for (p=5; p<MAX_PRODUTOS; ++p)
        if (!estoque->adicionaProduto(produto[p])) { cerr << "ERRO4"; exit(1); }
    // Tenta adicionar produtos além do limite
    for (; p<numProdutos; ++p)
        if (estoque->adicionaProduto(produto[p])) { cerr << "ERRO5"; exit(1); }
    // Testa se os 10 produtos estao inseridos
    for (p=0; p<MAX_PRODUTOS; ++p)
        if (estoque->obtemProduto(p) != produto[p]) { cerr << "ERRO6"; exit(1); }
    cout << estoque->str() << endl;

    delete estoque;
    for (int p=0; p<numProdutos; ++p)
        delete produto[p];

    return 0;
}
