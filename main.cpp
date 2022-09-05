#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <windows.h>

#define TAM 5

using namespace std;

void ordena(int cartela[][TAM],int i);///PROTÓTIPO DE ORDENAÇÃO DA MATRIZ

void matriz(int cartela[][TAM]){///CRIAÇÃO DA MATRIZ
    int intervalo=0;//valor inicial de cada linha
    bool repetido;//verdadeiro se valor já foi sorteado para posição anterior
    for(int i=0;i<TAM;i++){
        for(int j=0;j<TAM;j++){
            cartela[i][j]=intervalo+1+rand()%15;
            if(j>0){
                do{
                    repetido=false;
                    int j_ant=0;//contadora dos índices anteriores ao atual
                    while(j_ant<j&&repetido==false){
                        if(cartela[i][j]==cartela[i][j_ant]){
                            repetido=true;
                            cartela[i][j]=intervalo+1+rand()%15;
                        }
                        j_ant++;
                    }
                }
                while(repetido==true);
            }
        }
        ordena(cartela,i);
        intervalo+=15;
    }
}

void ordena(int cartela[][TAM],int i){///ORDENAÇÃO DA MATRIZ
    //ordenação é feita por seleção
    for(int j=0;j<TAM-1;j++){
        int min=j;
        for(int j_pos=j+1;j_pos<TAM;j_pos++){
            if(cartela[i][j_pos]<cartela[i][min])
                min=j_pos;
        }
        if(j!=min){
            int temp=cartela[i][j];
            cartela[i][j]=cartela[i][min];
            cartela[i][min]=temp;
        }
    }
}

void imprime(int cartela[][TAM]){///IMPRESSÃO DA MATRIZ
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
