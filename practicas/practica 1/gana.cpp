#include <iostream>
#include <string>

// Escribir aqui la funcion leeOpcion.

int leeOpcion(std::string pregunta, std::string mensajeError, int valMin, int valMax)
{
	int opt = 0;
	std::cout << pregunta;
	std::cin >> opt;
	while (opt<valMin || opt>valMax)
	{
		std::cout << mensajeError << pregunta;
		std::cin >> opt;
	}
	return opt;
}

// Escribe aqui el tipo enumerado

enum tElemento { PIEDRA, PAPEL, TIJERAS, LAGARTO, SPOCK };

// Escribir aqui las funciones leeJugada y toString.

bool verificar(std::string cad)
{
	return
		cad == "piedra" ||
		cad == "papel" ||
		cad == "tijeras" ||
		cad == "lagarto" ||
		cad == "Spock";
}
tElemento fromString(std::string str)
{
	tElemento elemento;
	if (str == "piedra")elemento = PIEDRA;
	else if (str == "papel")elemento = PAPEL;
	else if (str == "tijeras")elemento = TIJERAS;
	else if (str == "lagarto")elemento = LAGARTO;
	else elemento = SPOCK;
	return elemento;
}
tElemento leeJugada(std::string pregunta)
{
	std::string str = "";
	std::cout << pregunta;
	std::cin >> str;
	while (!verificar(str))
	{
		std::cout << pregunta;
		std::cin >> str;
	}
	tElemento elem = fromString(str);
	return elem;

}
std::string toString(tElemento jug)
{
	std::string cadena = "";
	if (jug == PIEDRA)cadena = "piedra";
	else if (jug == PAPEL)cadena = "papel";
	else if (jug == TIJERAS)cadena = "tijeras";
	else if (jug == LAGARTO)cadena = "lagarto";
	else cadena = "Spock";
	return cadena;
}

// Escribe aqui el tipo enumerado

// Escribir aqui la funcion toString, leeJuegada y gana.

bool gana(tElemento jugador1, tElemento jugador2)
{
	switch (jugador1) {
	case PIEDRA:	return jugador2 == LAGARTO || jugador2 == TIJERAS;
	case PAPEL:		return jugador2 == PIEDRA || jugador2 == SPOCK;
	case TIJERAS:	return jugador2 == PAPEL || jugador2 == LAGARTO;
	case LAGARTO:	return jugador2 == SPOCK || jugador2 == PAPEL;
	case SPOCK:		return jugador2 == TIJERAS || jugador2 == PIEDRA;
	}
}

void resuelveCaso()
{
	tElemento jugada1, jugada2;
	jugada1 = leeJugada("");
	jugada2 = leeJugada("");

	if (gana(jugada1, jugada2)) {
		std::cout << "Gana " << toString(jugada1) << '\n';
	}
	else if (gana(jugada2, jugada1)) {
		std::cout << "Gana " << toString(jugada2) << '\n';
	}
	else {
		std::cout << "Empate\n";
	}
}

int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	system("Pause");
	return 0;
}