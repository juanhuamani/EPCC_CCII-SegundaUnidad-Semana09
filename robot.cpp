#include <iostream>
#include <math.h>
#include <random>
#include <sstream>

using namespace std;

class Robot
{
private:
	string nombre;

public:
	Robot(string) { nombre = " "; };
	~Robot(){};
	string generar_nombre();
	void encender();
	void resetear();
	void nombre_robot();
};

string Robot::generar_nombre()
{

	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<> rad_digits(99, 999);
	uniform_int_distribution<char> rad_acsi('A', 'Z');

	stringstream ss{};

	ss << rad_acsi(gen) << rad_acsi(gen) << rad_digits(gen);

	nombre = ss.str();
	return nombre;
}

void Robot::encender()
{
	generar_nombre();
}

void Robot::resetear()
{
	generar_nombre();
}

void Robot::nombre_robot()
{
	cout << "El nombre del robot es :" << generar_nombre() << endl;
}

int main()
{

	Robot b(" ");
	b.encender();
	b.nombre_robot();

	for (int i = 0; i < 100; i++)
	{
		b.resetear();
		b.nombre_robot();
	}
	return 0;
}
