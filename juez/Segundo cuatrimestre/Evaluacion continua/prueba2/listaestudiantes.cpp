//DG206
//Jorge del valle

//*********************
//
// Declaracion de una lista de estudiantes
//
//****************************

#include "listaestudiantes.h"

void inicializarListaEstudiantes(tListaEstudiante & l){
	l.lista = new tEstudiante[TM];
	l.cont = 0;
	l.capacidad = TM;
}
bool buscar(tListaEstudiante const & l, std::string const & bus, int & pos){
		size_t	ini = 0, fin = l.cont, mitad;
		bool	encontrado = false;
		//	0	<=	ini	<=	fin	<=	N	
		//	array[0..ini)	<	buscado	Y	buscado	<	array[fin..N)
		while (ini	<	fin	&&	!encontrado)	{
			mitad = (ini + fin - 1) / 2;	//	división	entera	
			if (bus < l.lista[mitad].NIF)	fin = mitad;
			else	if (l.lista[mitad].NIF < bus)	ini = mitad + 1;
			else	encontrado = true;
		}
		if (encontrado)	pos = mitad;	//	en	la	posición	mitad					
		else	pos = ini;		//	No encontrado,	le	corresponde	la	posición	ini	(=fin)					
		return	encontrado;
}
void desplazarDerecha(tListaEstudiante & l, size_t pos)	{
	for (size_t i = l.cont; i > pos; --i)
		l.lista[i] = l.lista[i - 1];
}
void insertar(tListaEstudiante & l, tEstudiante const & est){
	int pos;
	if (buscar(l, est.NIF, pos)){
		if (l.cont == l.capacidad)ampliar(l);
		desplazarDerecha(l, pos);
		l.lista[pos] = est;
		++l.cont;
	}
}
void ampliar(tListaEstudiante & l){
	/*tEstudiante* aux = l.lista;
	l.lista = new tEstudiante[l.capacidad * 2];
	for (int i = 0; i < l.cont; ++i)
		l.lista[i] = aux[i];
	delete[] aux;
	l.capacidad = l.capacidad * 2;*/
}
void mostrar(std::ostream & salida, tListaEstudiante const & l){
	for (int i = 0; i < l.cont; --i)
		salida << l.lista[i].NIF << ' ' << l.lista[i].fechaMatricula << ' ' << l.lista[i].nota << ' ' << l.lista[i].nombre << '\n';
}
void liberar(tListaEstudiante & l){
	delete[] l.lista;
	l.lista = nullptr;
	l.cont = 0;
	l.capacidad = 0;
}