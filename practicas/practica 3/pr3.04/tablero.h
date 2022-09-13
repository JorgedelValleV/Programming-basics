#ifndef TABLERO_H
#define TABLERO_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

const int MIN_JUG = 1;
const int MAX_JUG = 4;
const int DIMENSION = 8;
const int NUM_CASILLAS = 6;
const int NUM_DIRECCIONES = 4;
const std::vector<int> incF{ -1,0,1,0 };
const std::vector<int> incC{ 0,1,0,-1 };

enum tEstadoCasilla { VACIA, HIELO, MURO, CAJA, JOYA, TORTUGA };
enum tDir { UP, RIGHT, DOWN, LEFT };
enum tCarta { AVANZAR, GIRODERECHA, GIROIZQUIERDA, LASER };

struct tTortuga {
	int identificacion;
	tDir direccion;
};
struct tCasilla {
	tEstadoCasilla contenido;
	tTortuga tortuga;
};
struct tCoordenada {
	int fila;
	int columna;
};
using tTablero = std::vector <std::vector<tCasilla>>;
using tVCartas = std::vector <tCarta>;

//operadores incremento prefijo 
tDir operator++(tDir & dir);
// incremento posfijo 
tDir operator++(tDir & dir, int);
//(a) Transformar un caracter en una casilla. La funcion recibira tambien un parametro con el identificador de la tortuga. Este parametro solo llevara valor cuando el caracter corresponda a una tortuga.
tCasilla charTOcasilla(char c);
//(b) Transformar una casilla en una cadena de caracteres.
std::string casillaTOstr(tCasilla c);
//(c) Mostrar por pantalla o ?chero una casilla. 
void mostrarCasilla(tCasilla cas);
//(d) Mostrar por pantalla o fichero un tablero.
void mostrarTablero(tTablero const t);
//(e) Cargar un tablero a partir de unos datos dados por teclado o fichero.
void cargar(tTablero & t, int n);
//(f)funcion que comprueba que las coordenadas estan dentro del tablero
bool dentroTablero(tTablero const & t, tCoordenada c, tDir d);
//(g) Fucion que reciba un tablero, las coordenadas en que se encuentra la tortuga con la pistola laser y la direccion a la que apunta la tortuga y modiﬁque el tablero de acuerdo con el resultado del disparo
void laser(tTablero & t, tCoordenada pos, tDir disparo);
//(h)Funcion que comprueba si un movimiento es posible
bool movPosible(tTablero const & t, tCoordenada c, tDir dir);
// funcion que lleva a cabo la accion de la tortuga 
bool realizarMovimiento(tTablero  & t, tCoordenada c, tVCartas const &v);
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso();
#endif