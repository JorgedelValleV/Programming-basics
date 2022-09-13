// Nombre del alumno .....Jorge del Valle Vazquez
// Usuario del Juez ......DG206

#include "carta.h"
std::ostream & operator<<(std::ostream & entrada, tCarta & dato) {
	switch (dato) {
	case AVANZAR:std::cout << "A"; break;
	case GIRODERECHA:std::cout << "GD"; break;
	case GIROIZQUIERDA:std::cout << "GI"; break;
	case LASER:std::cout << "L"; break;
	}
	return entrada;
}
std::ostream & operator<<(std::ostream & entrada, tMazo & dato) {
	for (int i = 0; i < dato.numCartas; ++i) {
		std::cout << dato.v[(dato.inicio+i)% dato.v.size()] << ' ';
	}
	std::cout << '\n';
	return entrada;
}
tMazo crearMazoAleatorio(int numAV, int numGI, int numGD, int numPL) {
	tMazo m;
	for (int i = 0; i < numAV; ++i)m.v.push_back(AVANZAR);
	for (int i = numAV; i < (numAV+ numGI); ++i)m.v.push_back(GIROIZQUIERDA);
	for (int i = (numAV + numGI); i < (numAV + numGI + numGD); ++i)m.v.push_back(GIRODERECHA);
	for (int i = (numAV + numGI + numGD); i < (numAV + numGI + numGD + numPL); ++i)m.v.push_back(LASER);
	m.inicio = 0;
	m.finall = 0;
	m.numCartas = m.v.size();
	return m;
}
bool cogerCarta(tMazo & mazo, tCarta & carta) {
	if (mazo.numCartas > 0) {
		carta = mazo.v[mazo.inicio];
		mazo.inicio = (mazo.inicio + 1) % mazo.v.size();
		--mazo.numCartas;
		return true;
	}
	return false;
}
void devolverCarta(tMazo & mazo, tVCartas &  v){
	for (int i = 0; i < v.size(); ++i) {
		mazo.v[mazo.finall]=v[i];
		mazo.finall = (mazo.finall + 1) % mazo.v.size();
		++mazo.numCartas;
	}
	v.clear();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int cartasAvanza; int cartasGI; int cartasGD; int cartasPL;
	std::cin >> cartasAvanza >> cartasGI >> cartasGD >> cartasPL;
	if (!std::cin) return false;
	tMazo mazo = crearMazoAleatorio(cartasAvanza, cartasGI, cartasGD, cartasPL);
	int numMovimientos;
	std::cin >> numMovimientos;
	tVCartas v;
	for (int i = 0; i < numMovimientos; ++i) {
		int tipoMov;
		std::cin >> tipoMov;
		if (tipoMov == 1) {
			tCarta carta;
			bool ok = cogerCarta(mazo, carta);
			if (ok) v.push_back(carta);
		}
		else devolverCarta(mazo, v);
	}

	std::cout << mazo;

	return true;

}