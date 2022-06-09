#include <iostream>
#include <math.h>
#include <sstream>
using namespace std;

bool diagonales(int matriz[][8], int blancax, int blancay, int negrax, int negray)
{
    for (int i = 0; i < 8; i++)
    {
        if ((blancax == negrax + i && blancay == negray + i) || (blancax == negrax - i && blancay == negray - i))
        {
            return true;
        }
    }
    for (int i = 0; i < 8; i++)
    {
        if ((blancax + blancay == negrax + negray))
        {
            return true;
        }
    }

    if (blancax == negrax)
    {
        return true;
    }

    if (blancay == negray)
    {
        return true;
    }
    return false;
}

void imprimir(int matriz[][8], int blancax, int blancay, int negrax, int negray)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (i == blancax && j == blancay)
            {
                cout << " B ";
            }
            else if (i == negrax && j == negray)
            {
                cout << " N ";
            }
            else
                cout << " - ";
        }
        cout << endl;
    }
}

void verificar(int matriz[][8], int blancax, int blancay, int negrax, int negray)
{

    if (blancax < 8 && blancay < 8 && negrax < 8 && negray < 8)
    {
        if (diagonales(matriz, blancax, blancay, negrax, negray) == true)
        {
            cout << "Si se pueden atacar" << endl;
        }
        else
            cout << "No se pueden atacar" << endl;
    }
    else
        cout << "ERROR - NO EXISTE UNA REINA" << endl;
}

int main()
{
    int matriz[8][8];

    int blancax, blancay, negrax, negray;
    cout << "Reyna blanca (max 7)" << endl;
    cin >> blancax >> blancay;
    cout << "Reyna Negra (max 7)" << endl;
    cin >> negrax >> negray;

    imprimir(matriz, blancax, blancay, negrax, negray);

    verificar(matriz, blancax, blancay, negrax, negray);
}