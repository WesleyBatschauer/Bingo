#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <windows.h>
#include <string.h>

#define BLUE  1
#define BRIGHTWHITE  15
#define TAM 5
#define SOR 75

using namespace std;

void textcolor (int forecolor) {
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), (WORD) (forecolor));
}

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

void sorteio(int num_sor[SOR], int i){///Sorteia o número;
    bool repetido;//verdadeiro se valor já foi sorteado para posição anterior
        num_sor[i]=1+rand()%75;
        if(i>0){
            do{
                repetido=false;
                int i_ant=0;//contadora dos índices anteriores ao atual
                while(i_ant<i&&repetido==false){
                    if(num_sor[i]==num_sor[i_ant]){
                        repetido=true;
                        num_sor[i]=1+rand()%75;
                    }
                    i_ant++;
                }
            }
            while(repetido==true);
        }
}

int confere(int cartela[][TAM], int i, int num_sor[SOR]){
    int ponto=0, cor;
    for(int k=0;k<TAM;k++){
        for(int j=0;j<TAM;j++){
            cor=0;
            for(int l=0;l<i;l++){
                if(cartela[k][j]==num_sor[l]){
                    cor++;
                    ponto++;
                }
            }
            if(cor==1){
                textcolor(1);
                cout<<cartela[k][j]<<"\t";
            }
            else{
                textcolor(15);
                cout<<cartela[k][j]<<"\t";
            }
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    textcolor(15);
    return ponto;
}

void imprime_sor(int num_sor[SOR],int i){///IMPRESSÃO DOS NUMEROS SORTEADOS
    int j,k,key;
    for(j = 1; j < i; j++) {
        key = num_sor[j];
        k = j - 1;
        while(k >= 0 && num_sor[k] > key) {
            num_sor[k + 1] = num_sor[k];
            k = k - 1;
        }
        num_sor[k + 1] = key;
    }
    for(k=0;k<i;k++){
        cout<<num_sor[k]<<"\t";
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
    cartela5[TAM][TAM]={},
    num_sor[SOR]={};
    int cont=6, i=0;
    char inicio;
    bool vencido=false;
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

    do{
        cout<<"Digite S para sortear\n";
        cin>>inicio;
        system ("cls");
        if(inicio=='s'||inicio=='S'){
            sorteio(num_sor,i);
            if(confere(cartela1,i,num_sor)==25){
                cout<<"\n"<<nome1<<" é o vencedor"<<"\n";
                vencido=true;
            }
            if(confere(cartela2,i,num_sor)==25){
                cout<<"\n"<<nome2<<" é o vencedor"<<"\n";
                vencido=true;
            }
            if(confere(cartela3,i,num_sor)==25){
                cout<<"\n"<<nome3<<" é o vencedor"<<"\n";
                vencido=true;
            }
            if(confere(cartela4,i,num_sor)==25){
                cout<<"\n"<<nome4<<" é o vencedor"<<"\n";
                vencido=true;
            }
            if(confere(cartela5,i,num_sor)==25){
                cout<<"\n"<<nome5<<" é o vencedor"<<"\n";
                vencido=true;
            }
            imprime_sor(num_sor,i);

            i++;
        }
        else{
            cout<<"Dígito inválido\n";
        }
    }while(vencido==false);

    return 0;
}
