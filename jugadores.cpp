#include <iostream>
#include <string>
#include <cstdlib> // Función rand().
#include <ctime>   // Función time() para generar una nueva seed aleatoria.
using namespace std;

#define log(x) cout << x << endl;

class Jugador
{
public:
    int vida;
    int ataque;
    string nombre;
    Jugador *atacadoPor;
    Jugador();
    Jugador(int v, int atk, string n);

    void atacar(Jugador* jugador);
};

int main()
{
    srand(time(0)); // Seed para generar valores aleatorios
    Jugador j1(100, 10, "Juan"), j2(200, 20, "PedroHD");
    while(j1.vida>0 && j2.vida>0){
        j1.atacar(&j2);
        if(j1.vida>0 && j2.vida>0){
            j2.atacar(&j1);
        }else{
            break;
        }
    }
    if(j1.vida>0 && j2.vida<=0){
        cout << j1.nombre << " es el ganador" << endl;
    }else{
        cout << j2.nombre << " es el ganador" << endl;
    }
    /*
        Crear al menos 2 jugadores con diferentes nombres, vida y ataque.
        Los jugadores deben atacarse entre sí, tomando turnos, hasta que uno pierda toda su vida.
        En cuanto la vida del jugador se reduzca a 0 el programa muestra al ganador y se termina.
        No importa quien ataca primero.
    */

    return 0;
}

Jugador::Jugador()
{
    vida = 100;
    ataque = 5;
    nombre = "No definido";
}

Jugador::Jugador(int v, int atk, string n)
{
    if(v>0 && atk>0 && v<201 && atk<21){
        vida = v;
        ataque = atk;
    }else if(v<1 && atk<1){
        vida = 1;
        ataque = 1;
    }else if(v>200 && atk>20){
        vida = 200;
        ataque = 20;
    }
    nombre = n;
}

void Jugador::atacar(Jugador* jugador)
{
    int x = rand() % 10;
    if(x>1){
        jugador->vida -= this->ataque;
        cout << this->nombre << " ataco a " << jugador->nombre << "e hizo " << ataque << " de daño, vida restante de " << jugador->nombre << " = " << jugador->vida << endl;
    }else{
        cout << this->nombre << " ataco a " << jugador->nombre << " pero fallo, vida restante de " << jugador->nombre << " = " << jugador->vida << endl;
    }
    jugador->atacadoPor = this;
}