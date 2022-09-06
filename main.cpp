#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <windows.h>

#define TAM 5

using namespace std;

void ordena(int cartela[][TAM],int i);///PROTÓTIPO DE ORDENAÇÃO DA MATRIZ

string nomes(int i){///ENTRADA DOS NOMES
    string nome;
    cout<<"Digite o nome do "<<i<<"º jogador: ";
    cin>>nome;
    return nome;
}

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

void imprime(int cartela[][TAM],string nome){///IMPRESSÃO DA MATRIZ
    cout<<nome<<endl;
    for(int i=0;i<TAM;i++){
        for(int j=0;j<TAM;j++){
            cout<<cartela[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main()
{
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL));

    int cartela1[TAM][TAM]={},
    cartela2[TAM][TAM]={},
    cartela3[TAM][TAM]={},
    cartela4[TAM][TAM]={},
    cartela5[TAM][TAM]={};
    string nome1=nomes(1);
    string nome2=nomes(2);
    string nome3=nomes(3);
    string nome4=nomes(4);
    string nome5=nomes(5);

    system ("cls");

    matriz(cartela1);
    matriz(cartela2);
    matriz(cartela3);
    matriz(cartela4);
    matriz(cartela5);

    imprime(cartela1,nome1);
    imprime(cartela2,nome2);
    imprime(cartela3,nome3);
    imprime(cartela4,nome4);
    imprime(cartela5,nome5);

    return 0;
}
