#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

class Hora {
private:
    int hora, minuto, segundo;
public:
    Hora();
    Hora(int h, int m, int s);
    ~Hora();
    int obtemHora() const;
    int obtemMinuto() const;
    int obtemSegundo() const;
    void defineHora(int h);
    void defineMinuto(int m);
    void defineSegundo(int s);
    string str() const;
    Hora operator+(const Hora &hr);
    friend ostream &operator<<(ostream &out, const Hora &h);
    friend istream &operator>>(istream &in, Hora &h);
};

ostream &operator<< (ostream &out, const Hora &h);
istream &operator>> (istream &in, Hora &h);

Hora::Hora(){
}

Hora::Hora(int hora, int minuto, int segundo){
    this->hora = hora;
    this->minuto = minuto;
    this->segundo = segundo;
}

Hora::~Hora(){
}


int Hora::obtemHora()const {
    return hora;
}

int Hora::obtemMinuto()const {
    return minuto;
}

int Hora::obtemSegundo()const {
    return segundo;
}

void Hora::defineHora(int hora){
    this->hora = hora;
}

void Hora::defineMinuto(int m){
    this->minuto = minuto;
}

void Hora::defineSegundo(int s){
    this->segundo = segundo;
}

Hora Hora::operator+(const Hora &hr){

     Hora horario;

     horario.defineSegundo(segundo + hr.obtemSegundo());
     horario.defineMinuto(minuto + hr.obtemMinuto());
     horario.defineHora(hora + hr.obtemHora());

    if(horario.obtemSegundo() >= 60){
       horario.defineSegundo(horario.obtemSegundo() - 60);
       horario.defineMinuto(horario.obtemMinuto() + 1);
    }
    if(horario.obtemMinuto() >= 60){
        horario.defineMinuto(horario.obtemMinuto() - 60);
        horario.defineHora(horario.obtemHora() + 1);
    }
    if(horario.obtemHora() >= 24){
        horario.defineHora(horario.obtemHora() - 24);
    }
    return horario;
    }

string Hora::str()const{

    stringstream ss;
    ss << setfill('0') << setw(2);
    ss << hora;
    ss << ":";
    ss << setfill('0') << setw(2);
    ss << minuto;
    ss << ":";
    ss << setfill('0') << setw(2);
    ss << segundo;

    return ss.str();

}

ostream& operator<< (ostream &out, const Hora &h){
    out << h.str();
    return out;
}

istream& operator>> (istream &in , Hora &h){
    in >> h.hora;
    in >> h.minuto;
    in >> h.segundo;
    return in;
}


int main() {
    Hora h1, h2;
    cin >> h1;
    cin >> h2;
    Hora h3 = h1 + h2;
    cout << h3 << endl;
    return 0;
}
