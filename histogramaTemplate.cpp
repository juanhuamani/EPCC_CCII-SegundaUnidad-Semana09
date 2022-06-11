
#include <iostream>
#include <vector>
using namespace std;



template <typename T>

class Histograma{
    private:
        vector<T>hist;
        vector<T>retornar;
        int intervalo;
        
    public:
        Histograma(){
            for(int i=0;i<10;i++){
                hist.push_back(0);
            }
        };
        Histograma(T _intervalo){
            intervalo = _intervalo;
        }
        
        T insertar(T numero){
            hist.push_back(numero);
        }
        
        int histo(int numero){
            T aux=0;
            for(int i=0;i<hist.size();i++){
                if(hist[i]==numero ){
                    aux++;
                }
            }
            return aux;
        }
        
        void histo2(){
            
            for(int j=1;j<hist.size()+1;j++){
            	T aux2=0;
                for(int i=j;i<intervalo+j;i++){
                    aux2=histo(i)+aux2;
                }
                retornar.push_back(aux2);
                j = j+intervalo-1;
                
            }
        }
        
        void mostrar_vector(){
        	cout<<"\tVECTOR "<<endl;
        	for(int i=0;i<hist.size();i++){
        		if(i==hist.size()-1){
        			cout<<hist[i]<<endl<<endl;
				}
				else
                	cout<<hist[i]<<" - ";
            }
		}
		
		void mostrar(){
            
            histo2();
            cout<<"\tHISTOGRAMA"<<endl;
            for(int i=0;i<retornar.size();i++){
            	if(i==retornar.size()-1){
        			cout<<retornar[i]<<endl<<endl;
				}
				else
                	cout<<retornar[i]<<" - ";
            }
        }
        
        void mostrar_grafico(){
        	for(int i=0;i<retornar.size();i++){
        		cout<<"["<<(intervalo*i)+1<<" - "<<intervalo*(i+1)<<"]"<< " : ";
        		for(int j=0;j<retornar[i];j++){
        			if(j== retornar[i] -1 ){
        				cout<<"=|";
					}
					else 
						cout<<"=";
				}
				cout<<endl;
			}
        	
		}
        
       
        
};



int main()
{
    Histograma <int> histo(2);
    histo.insertar(10);
    histo.insertar(2);
    histo.insertar(9);
    histo.insertar(7);
    histo.insertar(5);
    histo.insertar(6);
    histo.insertar(1);
    histo.insertar(8);
    histo.insertar(8);
    histo.insertar(4);
    histo.mostrar_vector();
    cout<<endl;
    histo.mostrar();
    histo.mostrar_grafico();
    
    
    
}
