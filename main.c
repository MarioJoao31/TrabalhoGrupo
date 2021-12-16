#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define fSize 9
#define vSize 5

//Estrutura dos dados
typedef struct {    
    int codigo;
    char tipo[50]; 
    float custo;
    int autonomia;
} Veiculo;

typedef struct{
    int num_ord;
    int NIF[fSize];
    Veiculo veiculo[3];
    int tempo;
    int distancia;
}  Fatura;

//assinaturas
int menu();
int insVeiculo(Veiculo V[fSize],int tamanho,int cod, char tp[50], float ct, int autono);

//função para inserir veiculo eletrico
int insVeiculo(Veiculo V[fSize],int tamanho,int cod, char tp[50], float ct, int autono){
    if(tamanho<vSize){
        V[tamanho].codigo = cod;
        strcpy(V[tamanho].tipo, tp);
        V[tamanho].custo = ct;
        V[tamanho].autonomia = autono;
        return(1);
    }else return(0);
    
    
}

//MENU
int menu(){
    int opcao;
    do{
        printf("---------MENU-------\n");
        printf("1 - Inserção de um novo meio de mobilidade elétrica\n");
        printf("2 - Remoção de um meio de mobilidade elétrica a partir do seu código\n");
        printf("3 - Inserção de um novo pedido de utilização\n");
        printf("4 - Remoção de um pedido de utilização a partir do seu código\n");
        printf("5 - Listagem dos dados de todos os meios de mobilidade elétrica\n");
        printf("6 - Listagem de todo os pedidos de utilização\n");
        printf("7 - Cálculo do custo associado a um pedido de utilização a partir da indicação do seu número de ordem\n");
        printf("0 - Sair\n");
        printf("Opcao?");
        scanf("%d",&opcao); 
    }
    while ((opcao>7)||(opcao<0));
    return(opcao);
}




int main(){
    Fatura fatura[fSize];
    Veiculo veiculo[vSize];
    int opcao;
    int codigov;
    char tipov[50];
    float custov;
    int autonomiav,tamanhov;

    do{
        opcao = menu();
        switch(opcao){
            case 1: 
                printf("#Novo veiculo#\n");
                rollback:
                printf("Inserir codigo:\n");
                scanf("%d", &codigov);
                if(codigov<0) goto rollback;
                printf("Inserir tipo:\n");
                scanf("%s", tipov);
                printf("Inserir custo:\n");
                scanf("%f", &custov);
                printf("Inserir Autonomia:\n");
                scanf("%d", &autonomiav);
                insVeiculo(veiculo ,tamanhov ,codigov, tipov, custov, autonomiav);
                tamanhov++;

            break;
            case 2: break;
            case 3: break;
            case 4: break;
            case 5: break;
            case 6: break;
        }   
    }while(opcao != 0);

    return(0);

}