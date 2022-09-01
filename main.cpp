#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <windows.h>

#define TAM 5

using namespace std;

void matriz(int cartela[][TAM]){///CRIAÇÃO DA MATRIZ
    int intervalo=0, varial, k=0;
    for(int i=0;i<TAM;i++){
        for(int j=0;j<TAM;j++){
                    do{
                        cartela[i][j]=intervalo+1+rand()%15;
                    }
                    while(cartela[i][j+1]==cartela[i][k]);

        intervalo+=15;
        }
    }
}

void imprime(int cartela[][TAM]){///IMPREÇÃO DA MATRIZ
    for(int i=0;i<TAM;i++){
        for(int j=0;j<TAM;j++){
            cout<<cartela[i][j]<<"\t";
        }
        cout<<endl;
    }
}

int main()
{
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL));
    int cartela[TAM][TAM]={};
    matriz(cartela);
    imprime(cartela);

    return 0;
}
