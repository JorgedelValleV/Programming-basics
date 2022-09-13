#include <iostream>
#include <vector>
using tmatriz = std::vector<std::vector<int>>;
void leer(tmatriz & matriz) {
	for (int f = 0; f < matriz.size(); ++f)
		for (int c = 0; c < matriz[f].size(); ++c)
			std::cin >> matriz[f][c];
}
void mostrar(tmatriz const& matriz) {
	for (int f = 0; f < matriz.size(); ++f) {
		for (int c = 0; c < matriz[f].size(); ++c) {
			std::cout << matriz[f][c] << '	';
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}
tmatriz traspuesta(tmatriz const & m) {
	tmatriz sol(m[0].size(), std::vector<int>(m.size()));
	for (int f = 0; f < sol.size(); ++f) {
		for (int c = 0; c < sol[f].size(); ++c) {
			sol[f][c] = m[c][f];
		}
	}
	return sol;
}
int main() {
	int f = 0; int c = 0;
	std::cin >> f >> c;
	tmatriz m(f, std::vector<int>(c));
	tmatriz sol(c, std::vector<int>(f));
	leer(m);
	mostrar(m);
	sol=traspuesta(m);
	mostrar(sol);
	system("PAUSE");
	return 0;
}