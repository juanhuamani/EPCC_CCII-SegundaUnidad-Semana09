
#include <iostream>
#include <vector>
using namespace std;

class Domino{
	private:
		vector <int>fich;
		int numero;
		
	public:
		void ingresar(int numero){
			fich.push_back(numero);	
		}
		
		bool verificar(){
			if(fich.size()%2 != 0){
        		return false;
    		}
    		return true;
		}
		
		bool par(){
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
		};
		
		void domino(){
			int aux;
		    par();
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
		};
		
		
		void mostrar_vector(){
			cout<<"VECTOR "<<endl;
		    for(int i=0;i<fich.size();i++){
		        if(i==fich.size()-1){
		            cout<<fich[i]<<endl<<endl;
		        }
		        else
		            cout<<fich[i]<<" - ";
		        
		    }
		};
		void mostrar_domino(){
			domino();
		    cout<<"DOMINO  "<<endl;
		    for(int i=0;i<fich.size();i++){
		        if(i%2==0){
		            cout<<" [ "<<fich[i]<<"|";
		        }
		        else
		             cout<<fich[i]<<" ] ";
		        
		    }
		};
};



int main()
{
    string aux;
    int numero;
    Domino fichas;
    
    do{
        cout<<"Ingresar valor : ";cin>>numero;
    	fichas.ingresar(numero);
        cout<<"Quiere continuar ? Si=s / No=n ";
        cin>>aux;
    }
    while(aux != "n");
    
    
    if(fichas.verificar()==false){
        cout<<"El vector debe tener un numero de valores par";
    }
    
    else{
        fichas.mostrar_vector();
        fichas.mostrar_domino();
    }
    
}
