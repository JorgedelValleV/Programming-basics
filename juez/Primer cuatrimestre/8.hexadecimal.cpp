#include <iostream>
#include <iomanip>
#include <fstream>

int main() 
{
	char c = ' '; char c2 = ' ';
	std::cin >> c >> c2;
	while (!(c == '0' && c2 == '0'))
	{
		int valor1 = 0, valor2 = 0, valor3 = 0, valor4 = 0;

		if (isdigit(c))
		{
			valor1 = int(c) - int('0');
			valor2 = valor1 * 16;
		}
		else if (isalpha(c))
		{
			valor1 = (int(c) - int('A')) + 10;
			valor2 = valor1 * 16;
		}

		if (isdigit(c2))
		{
			valor3 = int(c2) - int('0');
		}
		else if (isalpha(c2))
		{
			valor3 = (int(c2) - int('A')) + 10;
		}
		else;
		valor4 = valor2 + valor3;
		// escribir sol
		std::cout << valor4 << '\n';
		std::cin >> c >> c2;
	}
	system("PAUSE");

	return 0;
}