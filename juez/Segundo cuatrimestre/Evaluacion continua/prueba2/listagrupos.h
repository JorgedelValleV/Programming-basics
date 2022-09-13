//DG206
//Jorge del valle

//*********************
//
// Declaracion de una lista de grupos
//
//****************************

#ifndef LISTAGRUPOS
#define LISTAGRUPOS

#include "listaestudiantes.h"

const int TAM = 10;//Tam es distinto la otra constante TM

struct tGrupo {
	std::string identificador;
	tListaEstudiante estudiantes;
};
struct tListaGrupos {
	tGrupo * array[TAM];
	int	cont;;
};

void inicializarListaGrupos(tListaGrupos & l);
bool buscar(tListaGrupos const & l, std::string  const & bus, int & pos);
bool insertar(tListaGrupos & l, std::string  const & id, tListaEstudiante const & est);
void mostrarNotas(tListaGrupos const & l, std::string  const & nif);
void mostrarSuspensos(tListaGrupos const & l, std::string  const & id);
void liberar(tListaGrupos & l);
#endif
