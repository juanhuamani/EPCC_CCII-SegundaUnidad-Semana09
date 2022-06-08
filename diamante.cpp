#include <iostream>
#include <math.h>
#include <sstream>
using namespace std;

void Linea(int x, int valor)
{
	stringstream ss{};
	string h = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	if (x == 0)
	{
		for (int z = 1; z < valor; z++)
		{
			ss << "*";
		}
		ss << h[x];
		for (int z = 1; z < valor ; z++)
		{
			ss << "*";
		}

		string nombre = ss.str();
		cout << nombre << " " << endl;
	}

	if (x != 0)
	{
		stringstream kk{};
		stringstream ll{};

		for (int z = 1; z < valor - x; z++)
		{
			kk << "*";
		}
		kk << h[x];

		for (int g = 0; g < ((x + 1) * 2) - 3; g++)
		{
			ll << "*";
		}

		string parte1 = kk.str();
		string parte2 = ll.str();
		string parte3(parte1.rbegin(), parte1.rend());
        
        cout<<parte1<<parte2<<parte3<<endl;
		
	}
}

void imprimir(int valor)
{
	for (int i = 0; i < valor; i++)
	{
		Linea(i, valor);
		
	}
	for (int i = valor - 2; i > -1; i--)
	{
		Linea(i, valor);
		
	}
}

int main()
{
	string h = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string letra;
	int valor;

	cout << "Letra mayuscula = ";
	cin >> letra;

	for (int i = 0; i < 26; i++)
	{
		if (h[i] == letra[0])
			valor = i + 1;
	}

	imprimir(valor);
}
