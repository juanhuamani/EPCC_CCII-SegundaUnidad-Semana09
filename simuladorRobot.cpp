#include <iostream>
#include <math.h>
using namespace std;

class Robot
{
private:
    int x, y;
    string letras, direccion;

public:
    Robot(int, int, string, string);
    bool verificar();
    void ejecutar();
    void mostrar();
};

Robot::Robot(int _x, int _y, string _direccion, string _letras)
{
    x = _x;
    y = _y;
    letras = _letras;
    direccion = _direccion;
}

bool Robot::verificar()
{
    for (int i = 0; i < letras.length(); i++)
    {
        if (letras[i] != 'D' && letras[i] != 'I' && letras[i] != 'A')
            return false;
    }
    return true;
}

void Robot::ejecutar()
{
    if (verificar())
    {
        for (int i = 0; i < letras.length(); i++)
        {
            if (letras[i] == 'D')
            {
                if (direccion == "norte")
                    direccion = "este";
                else if (direccion == "este")
                    direccion = "sur";
                else if (direccion == "sur")
                    direccion = "oeste";
                else if (direccion == "oeste")
                    direccion = "norte";
            }

            if (letras[i] == 'I')
            {
                if (direccion == "norte")
                    direccion = "oeste";
                else if (direccion == "oeste")
                    direccion = "sur";
                else if (direccion == "sur")
                    direccion = "este";
                else if (direccion == "este")
                    direccion = "norte";
            }

            if (letras[i] == 'A')
            {
                if (direccion == "norte")
                    y++;
                else if (direccion == "sur")
                    y--;
                else if (direccion == "este")
                    x++;
                else if (direccion == "sur")
                    x--;
            }
        }
    }
}

void Robot::mostrar()
{
    ejecutar();
    cout << " ( " << x << " , " << y << " ) " << endl
         << "Mirando al " << direccion;
}

int main()
{
    Robot robot(7, 3, "norte", "DAAIAI");
    robot.mostrar();
}
