//DG206
//Jorge del valle

//*********************
//
// Declaracion de una lista de grupos
//
//****************************
#include "listagrupos.h"
void inicializarListaGrupos(tListaGrupos & l){
	l.cont = 0;
	for (int c = 0; c < TM; ++c){
		l.array[c] = new tGrupo;
		inicializarListaEstudiantes(l.array[c]->estudiantes);
	}
}
bool buscar(tListaGrupos const & l, std::string  const & bus, int & pos){
	pos = 0;
	while (pos < l.cont	&& l.array[pos]->identificador != bus)
		++pos;
	return pos < l.cont;
}
bool insertar(tListaGrupos & l, std::string  const & id, tListaEstudiante const & est){
	bool ok = true;
	if (l.cont == TAM)ok = false;//esta lleno
	else {
		l.array[l.cont]->estudiantes = est;
		++l.cont;
	}
	return ok;
}
void mostrarNotas(tListaGrupos const & l, std::string  const & nif){
	int pos;
	std::cout << "Alumno " << nif << "Grupos\n";
	for (int i = 0; i < l.cont; ++i){
		if (buscar(l.array[i]->estudiantes, nif, pos)){
			std::cout << l.array[i]->identificador << " - " << l.array[i]->estudiantes.lista[pos].nota;
		}
	}
}
void mostrarSuspensos(tListaGrupos const & l, std::string  const & id){
	int pos;
	std::cout << "Estudiantes suspensos n el grupo " << id << '\n';
	if (buscar(l, id, pos)){
		for (int i = 0; i < l.array[pos]->estudiantes.cont; ++i){
			if (l.array[pos]->estudiantes.lista[i].nota < 5){
				std::cout << l.array[pos]->estudiantes.lista[i].NIF << ' ' << l.array[pos]->estudiantes.lista[i].fechaMatricula << ' ' << l.array[pos]->estudiantes.lista[i].nota << ' ' << l.array[pos]->estudiantes.lista[i].nombre << '\n';
			}
		}
	}
}
void liberar(tListaGrupos & l){
	for (int i = 0; i < TM; ++i){
		liberar(l.array[i]->estudiantes);//funcion liberar del modulo lista estudiantes
		delete l.array[i];
	}
	l.cont = 0;
}