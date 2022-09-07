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

bool comparaMatriz(int cartela1[][TAM],int cartela2[][TAM]){///COMPARAÇÃO DAS MATRIZES (2ª CARTELA)
    bool igual=true;//se duas matrizes são iguais
    for(int i=0;i<TAM;i++){
        for(int j=0;j<TAM;j++){
            if(cartela1[i][j]!=cartela2[i][j]){
                igual=false;
                return igual;
            }
        }
    }
    return igual;
}

bool comparaMatriz(int cartela1[][TAM],int cartela2[][TAM],int cartela3[][TAM]){///COMPARAÇÃO DAS MATRIZES (3ª CARTELA)
    bool igual=true;//se duas matrizes são iguais
    for(int i=0;i<TAM;i++){
        for(int j=0;j<TAM;j++){
            if(cartela1[i][j]!=cartela3[i][j]&&cartela2[i][j]!=cartela3[i][j]){
                igual=false;
                return igual;
            }
        }
    }
    return igual;
}

bool comparaMatriz(int cartela1[][TAM],int cartela2[][TAM],int cartela3[][TAM],int cartela4[][TAM]){///COMPARAÇÃO DAS MATRIZES (4ª CARTELA)
    bool igual=true;//se duas matrizes são iguais
    for(int i=0;i<TAM;i++){
        for(int j=0;j<TAM;j++){
            if(cartela1[i][j]!=cartela4[i][j]&&cartela2[i][j]!=cartela4[i][j]&&cartela3[i][j]!=cartela4[i][j]){
                igual=false;
                return igual;
            }
        }
    }
    return igual;
}

bool comparaMatriz(int cartela1[][TAM],int cartela2[][TAM],int cartela3[][TAM],int cartela4[][TAM],int cartela5[][TAM]){///COMPARAÇÃO DAS MATRIZES (5ª CARTELA)
    bool igual=true;//se duas matrizes são iguais
    for(int i=0;i<TAM;i++){
        for(int j=0;j<TAM;j++){
            if(cartela1[i][j]!=cartela5[i][j]&&cartela2[i][j]!=cartela5[i][j]&&cartela3[i][j]!=cartela5[i][j]&&cartela4[i][j]!=cartela5[i][j]){
                igual=false;
                return igual;
            }
        }
    }
    return igual;
}

void sorteio(int num_sor[SOR],int i){///SORTEIO DOS NÚMEROS
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

void imprimeMatriz(int cartela[][TAM],int i,int num_sor[SOR],string nome){///IMPRESSÃO DA MATRIZ
    int cor;
    cout<<nome<<endl;
    for(int k=0;k<TAM;k++){
        for(int j=0;j<TAM;j++){
            cor=0;
            for(int l=0;l<i;l++){
                if(cartela[k][j]==num_sor[l]){
                    cor++;
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
}

int confere(int cartela[][TAM],int i,int num_sor[SOR]){///CONFERÊNCIA DOS NÚMEROS SORTEADOS
    int ponto=0;
    for(int k=0;k<TAM;k++){
        for(int j=0;j<TAM;j++){
            for(int l=0;l<i;l++){
                if(cartela[k][j]==num_sor[l]){
                    ponto++;
                }
            }
        }
    }
    return ponto;
}

void ordenaSorteio(int num_sor[SOR],int i){///OREDNAÇÃO DOS NÚMEROS SORTEADOS
    int j,k,key;
    for(j=1;j<i;j++) {
        key=num_sor[j];
        k=j-1;
        while(k>=0&&num_sor[k]>key) {
            num_sor[k+1]=num_sor[k];
            k=k-1;
        }
        num_sor[k+1]=key;
    }
}

void imprimeSorteio(int num_sor[SOR],int i){///IMPRESSÃO DOS NÚMEROS SORTEADOS
    cout<<"Números sorteados: ";
    for(int j=0;j<i;j++){
        cout<<num_sor[j]<<" ";
    }
    cout<<endl;
}

void vencedor(string nome,int num_sor[SOR],int i){///IMPRESSÃO DO VENCEDOR
    cout<<"Bingo! "<<nome<<" vence com o número "<<num_sor[i-1]<<endl;
}

int main()
{
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL));
    textcolor(15);

    int cartela1[TAM][TAM]={},
    cartela2[TAM][TAM]={},
    cartela3[TAM][TAM]={},
    cartela4[TAM][TAM]={},
    cartela5[TAM][TAM]={},
    num_sor[SOR]={};//armazena os números sorteados
    int i=0;//número de rodadas realizadas
    char inicio;//entrada que inicia uma nova rodada
    bool vencido=false;
    string nome1=nomes(1);
    string nome2=nomes(2);
    string nome3=nomes(3);
    string nome4=nomes(4);
    string nome5=nomes(5);

    matriz(cartela1);
    do{
        matriz(cartela2);
    }
    while(comparaMatriz(cartela1,cartela2)==true);
    do{
        matriz(cartela3);
    }
    while(comparaMatriz(cartela1,cartela2,cartela3)==true);
    do{
        matriz(cartela4);
    }
    while(comparaMatriz(cartela1,cartela2,cartela3,cartela4)==true);
    do{
        matriz(cartela5);
    }
    while(comparaMatriz(cartela1,cartela2,cartela3,cartela4,cartela5)==true);

    do{
        if(i>0){
            cout<<"Digite S para sortear: ";
            cin>>inicio;
        }
        system("cls");
        if(i==0||inicio=='s'||inicio=='S'){
            sorteio(num_sor,i);

            imprimeMatriz(cartela1,i,num_sor,nome1);
            imprimeMatriz(cartela2,i,num_sor,nome2);
            imprimeMatriz(cartela3,i,num_sor,nome3);
            imprimeMatriz(cartela4,i,num_sor,nome4);
            imprimeMatriz(cartela5,i,num_sor,nome5);

            if(confere(cartela1,i,num_sor)==25){
                vencido=true;
                vencedor(nome1,num_sor,i);
            }
            if(confere(cartela2,i,num_sor)==25){
                vencido=true;
                vencedor(nome2,num_sor,i);
            }
            if(confere(cartela3,i,num_sor)==25){
                vencido=true;
                vencedor(nome3,num_sor,i);
            }
            if(confere(cartela4,i,num_sor)==25){
                vencido=true;
                vencedor(nome4,num_sor,i);
            }
            if(confere(cartela5,i,num_sor)==25){
                vencido=true;
                vencedor(nome5,num_sor,i);
            }
            ordenaSorteio(num_sor,i);
            imprimeSorteio(num_sor,i);
            i++;
        }
        else{
            cout<<"Dígito inválido"<<endl;
        }
    }
    while(vencido==false);

    return 0;
}
