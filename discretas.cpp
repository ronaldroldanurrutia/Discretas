#include<iostream>

using namespace std;


class cesarcode{
    private:
        string codigo;
    public:
        cesarcode(string _codigo){
            codigo = _codigo;
        }
        void encriptar(void){
            int n = codigo.size();
            string parte1="";
            string parte2="";
            string parte3="";
            int n1 = (n/4)*4;
            for(int i=0;i<n1;i+=4){
                parte1+=codigo[i];
                parte2+=codigo[i+1];
                parte3+=codigo[i+2];
                parte2+=codigo[i+3];
            }
            n=n%4;
            if(n==1){
                parte1+=codigo[codigo.size()-1];
            }
            if(n==2){
                parte1+=codigo[codigo.size()-2];
                parte2+=codigo[codigo.size()-1];
            }
            if(n==3){
                parte1+=codigo[codigo.size()-3];
                parte2+=codigo[codigo.size()-2];
                parte3+=codigo[codigo.size()-1];
            }
            codigo = parte1+parte2+parte3;
            return ;
        }
        void desencriptar(void){
            string elemento="";
            int l = codigo.size()%4;
            if(l==1){
                int n = codigo.size()/4 +1,m=n+2*(codigo.size()/4),o=n-1;
                for(int i=0;i<o;i++){
                    elemento+=codigo[i];
                    elemento+=codigo[n];
                    n++;
                    elemento+=codigo[m];
                    m++;
                    elemento+=codigo[n];
                    n++;
                }
                elemento+=codigo[o];
                codigo=elemento;
                return ;

            }
            if(l==2){
                int n = codigo.size()/4 +1,m=n+2*(codigo.size()/4)+1,o=codigo.size()/4;
                for(int i=0;i<o;i++){
                    elemento+=codigo[i];
                    elemento+=codigo[n];
                    n++;
                    elemento+=codigo[m];
                    m++;
                    elemento+=codigo[n];
                    n++;
                }
                elemento+=codigo[o];
                elemento+=codigo[3*((codigo.size())/4) +1];
                codigo=elemento;
                return ;

            }
            if(l==3){
                int n = codigo.size()/4 +1,m=n+2*(codigo.size()/4)+1,o=n-1;
                for(int i=0;i<o;i++){
                    elemento+=codigo[i];
                    elemento+=codigo[n];
                    n++;
                    elemento+=codigo[m];
                    m++;
                    elemento+=codigo[n];
                    n++;
                }
                elemento+=codigo[o];
                elemento+=codigo[3*((codigo.size())/4) +1];
                elemento+=codigo[codigo.size()-1];
                codigo=elemento;
                return ;

            }
            int n= codigo.size()/4,m=n+codigo.size()/2,o=n;
            for(int i=0;i<o;i++){
                    elemento+=codigo[i];
                    elemento+=codigo[n];
                    n++;
                    elemento+=codigo[m];
                    m++;
                    elemento+=codigo[n];
                    n++;
            }
            codigo = elemento;
            return ;
        }
        string codigoencriptado(void){
            return codigo;
        }
        string codigodesencriptado(void){
            return codigo;
        }

};

int main(){
    string elemento4;
    cin>>elemento4;
    class cesarcode elemento(elemento4);
    elemento.encriptar();
    cout << elemento.codigoencriptado() << endl;
    elemento.desencriptar();
    cout << elemento.codigodesencriptado()<<endl;
    return 0;
}
