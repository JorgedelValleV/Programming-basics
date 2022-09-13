// Nombre del alumno .....Jorge del Valle Vazquez
// Usuario del Juez ......DG206

#include "cartas.h"
#include "checkML.h"
std::ostream & operator<<(std::ostream & entrada, tCarta const & dato) {
	switch (dato) {
	case AVANZAR:std::cout << "A"; break;
	case GIRODERECHA:std::cout << "GD"; break;
	case GIROIZQUIERDA:std::cout << "GI"; break;
	case LASER:std::cout << "L"; break;
	}
	return entrada;
}
std::ostream & operator<<(std::ostream & entrada, tMazo const & dato) {
	for (int i = 0; i < dato.numElem; ++i) {
		std::cout << dato.lista[(dato.inicio + i) % NUM_CARTAS] << ' ';
	}
	std::cout << '\n';
	return entrada;
}
//funcion que crea un mazo aleatorio con 18 cartas de avanzar, 8 de girar a la izquierda, 8 derecha y 4 laser
void crearMazoAleatorio(tMazo & m) {
	for (int i = 0; i < numAV; ++i) { m.lista[i] = new tCarta; *m.lista[i] = AVANZAR; }
	for (int i = numAV; i < (numAV + numGI); ++i) { m.lista[i] = new tCarta; *m.lista[i] = GIROIZQUIERDA; }
	for (int i = (numAV + numGI); i < (numAV + numGI + numGD); ++i) { m.lista[i] = new tCarta; *m.lista[i] = GIRODERECHA; }
	for (int i = (numAV + numGI + numGD); i < (numAV + numGI + numGD + numPL); ++i) { m.lista[i] = new tCarta; *m.lista[i] = LASER; }
	m.inicio = 0;
	m.final = 0;
	m.numElem = NUM_CARTAS;
	size_t aux = (rand() % 30) + 1;
	for (size_t i = 0; i < aux; ++i) {
		std::random_shuffle(m.lista, m.lista+m.numElem);
	}
}
//funcion que extrae una carta del mazo y devuelve cierto solo si se ha ejecutado, es decir, habia cartas en el mazo
bool cogerCarta(tMazo & mazo, tCarta & carta) {
	if (mazo.numElem > 0) {
		carta = *mazo.lista[mazo.inicio];
		mazo.inicio = (mazo.inicio + 1) % NUM_CARTAS;
		--mazo.numElem;
		return true;
	}
	return false;
}
//funcion que devuelve las cartas empleadas en la ejecucion de una jugada de forma aleatoria
void devolverCarta(tMazo & mazo, tVCartas &  v) {
	std::random_shuffle(v.begin(), v.end());
	for (int i = 0; i < v.size(); ++i) {
		*mazo.lista[mazo.final] = v[i];
		mazo.final = (mazo.final + 1) % NUM_CARTAS;
	}
	mazo.numElem += v.size();
	v.clear();
}
//funcion que incluye en la mano una carta robada del mazo(o una carta introducida en una secuencia no valida)
void incluirCarta(tMano &mano, tCarta carta) {
	++mano[carta];//equivale a ++mano[int(carta)] ya que el enum toma el valor del entero
}
void liberarmazo(tMazo & m) {
	for (int i = 0; i < NUM_CARTAS; ++i)
		delete m.lista[i];
	m.numElem = 0;
}