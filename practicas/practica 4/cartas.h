// Nombre del alumno .....Jorge del Valle Vazquez
// Usuario del Juez ......DG206

#ifndef CARTA_H
#define CARTA_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
#include <algorithm>
#include <utility>
#include <ctime>
#include <cstdlib>
const int numAV = 18;
const int numGI = 8;
const int numGD = 8;
const int numPL = 4;
const int NUM_CARTAS = 38;
enum tCarta { AVANZAR, GIROIZQUIERDA, GIRODERECHA, LASER };
using tVCartas = std::vector <tCarta>;
using tMano = std::vector<int>;
using tArrayPtrCartas = tCarta *[NUM_CARTAS]; 
struct tMazo { 
	int inicio, final, numElem;  
	tArrayPtrCartas lista; 
};
/*struct tMazo {
	tVCartas v;
	int inicio;
	int finall;
	int numCartas;
};*/
std::ostream & operator<<(std::ostream & entrada, tCarta const & dato);
std::ostream & operator<<(std::ostream & entrada, tMazo const & dato);
//funcion que crea un mazo aleatorio con 18 cartas de avanzar, 8 de girar a la izquierda, 8 derecha y 4 laser
void crearMazoAleatorio(tMazo & m);
//funcion que extrae una carta del mazo y devuelve cierto solo si se ha ejecutado, es decir, habia cartas en el mazo
bool cogerCarta(tMazo & mazo, tCarta & carta);
//funcion que devuelve las cartas empleadas en la ejecucion de una jugada de forma aleatoria
void devolverCarta(tMazo & mazo, tVCartas & v);
//funcion que incluye en la mano una carta robada del mazo
void incluirCarta(tMano &mano, tCarta carta);
void liberarmazo(tMazo & m);
#endif