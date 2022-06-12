
#include <iostream>
#include <vector>
using namespace std;


bool par(vector<int> &fich )
{
    for(int i=0;i<fich.size();i++){
        int aux=1;
        for(int j=0;j<fich.size();j++){
            if(fich[i] == fich[j] && i!=j){
                aux++;
            }
        }
        if(aux %2!=0){
            return false;
        }
    }
    return true;
}

void domino(vector<int> &fich){
    int aux;
    if(par(fich)){
        for(int i=0;i<fich.size();i++){
           for(int j=0;j<fich.size();j++){
                if(fich[0]==fich[j] && i!=j ){
                    aux=fich[fich.size()-1];
                    fich[fich.size()-1]=fich[j];
                    fich[j]=aux;
                }
                else if (fich[i]==fich[j] && i!=j){
                    aux=fich[i+1];
                    fich[i+1]=fich[j];
                    fich[j]=aux;
                    i++;
                }       
           }
        }
    }
        
    else
        cout<<"El domino no se puede armar ";
}

void mostrar_vector(vector<int> &fich){
    cout<<"VECTOR "<<endl;
    for(int i=0;i<fich.size();i++){
        if(i==fich.size()-1){
            cout<<fich[i]<<endl<<endl;
        }
        else
            cout<<fich[i]<<" - ";
        
    }
}

void mostrar_domino(vector<int> &fich){
    domino(fich);
    cout<<"DOMINO  "<<endl;
    for(int i=0;i<fich.size();i++){
        if(i%2==0){
            cout<<" [ "<<fich[i]<<"|";
        }
        else
             cout<<fich[i]<<" ] ";
        
    }
}

int main()
{
    string aux;
    int numero;
    vector <int>fichas;
    
    do{
        cout<<"Ingresar valor : ";cin>>numero;
        fichas.push_back(numero);
        cout<<"Quiere continuar ? Si=s / No=n ";
        cin>>aux;
    }
    while(aux != "n");
    
    
    if(fichas.size()%2 != 0){
        cout<<"El vector debe tener un numero de valores par";
    }
    
    else{
        mostrar_vector(fichas);
        mostrar_domino(fichas);
    }
    
}
