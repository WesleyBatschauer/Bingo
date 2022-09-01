#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <windows.h>

#define tam 5

using namespace std;

void matriz(int cartela[][tam]){///CRIAÇÃO DA MATRIZ
    int intervalo=0;
    for(int i=0;i<tam;i++){
        for(int j=0;j<tam;j++){
            do{
                cartela[i][j]=intervalo+1+rand()%15;
            }
        }
        intervalo+=15;
    }
}

void imprime(int cartela[][tam]){///IMPREÇÃO DA MATRIZ
    for(int i=0;i<tam;i++){
        for(int j=0;j<tam;j++){
            cout<<cartela[i][j]<<"\t";
        }
        cout<<endl;
    }
}

int main()
{
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL));
    int cartela[tam][tam]={};
    matriz(cartela);
    imprime(cartela);

    return 0;
}
