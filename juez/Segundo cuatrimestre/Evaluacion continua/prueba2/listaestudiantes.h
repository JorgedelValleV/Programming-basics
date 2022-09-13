//DG206
//Jorge del valle

//*********************
//
// Declaracion de una lista de estudiantes
//
//****************************

#ifndef LISTAESTUDIANTE
#define LISTAESTUDIANTE

#include "estudiante.h"

const int TM = 30;
struct tListaEstudiante {
	tEstudiante * lista;
	int cont;
	int capacidad;
};
struct compNIF {
	bool operator() (std::string const & str1, std::string const & str2) {
		return (str1 < str2);
	}
};
void inicializarListaEstudiantes(tListaEstudiante & l);
bool buscar(tListaEstudiante const & l, std::string const & bus, int & pos);
void desplazarDerecha(tListaEstudiante & l, size_t pos);
void insertar(tListaEstudiante & l, tEstudiante const & est);
void ampliar(tListaEstudiante & l);
void mostrar(std::ostream & salida, tListaEstudiante const & l);
void liberar(tListaEstudiante & l);
#endif
