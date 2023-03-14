#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Equipe {
private:
    string clube;
    int pontos;
public:
    Equipe(string c="", int p=0) {
        clube = c;
        pontos = p;
    }
    string obtemClube() { return clube; }
    void defineClube(string c) { clube = c; }
    int obtemPontos() { return pontos; }
    void definePontos(int p) { pontos = p; }
    string toString() {
        stringstream ss;
        ss << clube << ": " << pontos << " pontos";
        return ss.str();
    }
    string toCSV() {
        stringstream ss;
        ss << clube << ";" << pontos;
        return ss.str();
    }
};

class Campeonato {
  private:
    class Nodo {
       public:
         Equipe *equipe;
         Nodo *prox, *ant;
         Nodo(Equipe *e);
    };
    Nodo *primeiro;
    int numEquipes;
  public:
    Campeonato();
    ~Campeonato();
    int obtemNumEquipes();
    Equipe *obtemEquipe(int indice);
    void insere(string c, int p);
    void insere(Equipe *e);
    void limpa();
};

// --- SOLUÇÃO (início) ---

     Campeonato::Nodo::Nodo(Equipe *e){
    	prox = nullptr;
    	ant = nullptr;
    	equipe = e;
    }

    Campeonato::Campeonato(){
    	primeiro = nullptr;
    	numEquipes = 0;
    }
    Campeonato::~Campeonato(){
    	limpa();
    }
    int Campeonato::obtemNumEquipes(){
     	return numEquipes;
     }
    Equipe* Campeonato::obtemEquipe(int indice){
    	Nodo *aux = primeiro;
        for(int i = 0; i < indice; i++){
    		aux = aux->prox;
    	}
    	return aux->equipe;
    }

    void Campeonato::insere(Equipe *e){
        if(numEquipes == 0){
    		primeiro = new Nodo(e);
    		numEquipes++;
    	}
    	else{
    		Nodo *aux = new Nodo(e);
    		if(aux->equipe->obtemPontos() > primeiro->equipe->obtemPontos()){
    			Nodo *aux2 = primeiro;
    			primeiro = new Nodo(e);
    			primeiro->prox = aux2;
	    		numEquipes++;
    		 }
    		 else{
    		 	Nodo *aux3 = primeiro;
	    		while(aux3 != NULL){
	    			if(aux3->prox->equipe->obtemPontos() == aux->equipe->obtemPontos()){
	    				if(aux3->prox->equipe->obtemClube() > aux->equipe->obtemClube()){
	    				aux->prox = aux3->prox;
	    				aux3->prox = aux;
	    				numEquipes++;
	    				break;
	    				}
	    			}
	    			if(aux3->prox->equipe->obtemPontos() < aux->equipe->obtemPontos()){
	    				aux->prox = aux3->prox;
	    				aux3->prox = aux;
	    				numEquipes++;
	    				break;
	    			}
	    			aux3 = aux3->prox;
	    		}
	    	}
	    }
}
    void Campeonato::insere(string c, int p){
    	insere(new Equipe(c,p));
    }
    void Campeonato::limpa(){
        Nodo *aux
        while(primeiro != nullptr){
            aux = primeiro;
            primeiro = primeiro->prox;
            delete aux;
        }
    }
// --- SOLUÇÃO (fim) ---

void mostraCampeonato(Campeonato *c) {
  int tam = c->obtemNumEquipes();
  for (int i=0; i<tam; ++i) {
      Equipe *e = c->obtemEquipe(i);
      cout << e->toString() << endl;
  }
  cout << "------------------" << endl;
}

int main() {
    Campeonato *brasileirao2021 = new Campeonato();
    mostraCampeonato(brasileirao2021);
    Equipe *e = new Equipe("Chapecoense",12);
    brasileirao2021->insere(e);
    mostraCampeonato(brasileirao2021);
    brasileirao2021->insere("Santos",28);
    brasileirao2021->insere("Bragantino",41);
    brasileirao2021->insere("Atletico Goianiense",31);
    mostraCampeonato(brasileirao2021);
    brasileirao2021->insere("Flamengo",42);
    brasileirao2021->insere("Atletico-MG",53);
    brasileirao2021->insere("Internacional",36);
    brasileirao2021->insere("Fluminense",33);
    brasileirao2021->insere("Juventude",28);
    brasileirao2021->insere("Sport",26);
    brasileirao2021->insere("Cuiaba",31);
    brasileirao2021->insere("Gremio",23);
    mostraCampeonato(brasileirao2021);
    brasileirao2021->insere("Corinthians",37);
    brasileirao2021->insere("Athletico-PR",33);
    brasileirao2021->insere("Palmeiras",40);
    brasileirao2021->insere("Sao Paulo",30);
    brasileirao2021->insere("Ceara",29);
    brasileirao2021->insere("Fortaleza EC",39);
    brasileirao2021->insere("Bahia",27);
    brasileirao2021->insere("America-MG",31);
    mostraCampeonato(brasileirao2021);
    delete brasileirao2021;
    return 0;
}
