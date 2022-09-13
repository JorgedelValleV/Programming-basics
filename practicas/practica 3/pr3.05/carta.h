#ifndef CARTA_H
#define CARTA_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
#include <algorithm>
#include <utility>


enum tCarta { AVANZAR, GIRODERECHA, GIROIZQUIERDA, LASER };
using tVCartas = std::vector <tCarta>;
struct tMazo {
	tVCartas v;
	int inicio;
	int finall;
	int numCartas;
};
std::ostream & operator<<(std::ostream & entrada,tCarta & dato);
std::ostream & operator<<(std::ostream & entrada, tMazo & dato);
tMazo crearMazoAleatorio(int numAV,int numGI,int numGD, int numPL);
bool cogerCarta(tMazo & mazo, tCarta & carta);
void devolverCarta(tMazo & mazo,tVCartas & v);
bool resuelveCaso();
#endif