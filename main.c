#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
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
    int NIF;
    int veiculo;
    int tempo;
    int distancia;
}  Fatura;

//assinaturas
int menu();

int insVeiculo(Veiculo V[vSize],int tamanho,int cod, char tp[50], float ct, int autono);
int rmVeiculo(Veiculo V[vSize],int tamanho, int cod);
void listv(Veiculo V[vSize],int tamanho);

int insFatura(Fatura F[fSize],int tamanhof ,int n_ord ,int nif , Veiculo V[vSize], int codVeiculo ,int tamanhov,int temp, int dist);
int rmFatura(Fatura F[fSize],int tamanhof, int cod);
void listf(Fatura F[fSize],int tamanhof);



//remover veiculo eletricos do array
int rmVeiculo(Veiculo V[vSize],int tamanho, int cod){
    if(cod <= tamanho){
        // cod-1 e tamanho-1 para diminuir o tamanho do array 
        for(int i = cod-1; i<tamanho-1 ;i++){
            V[i].codigo = V[i+1].codigo;
            strcpy(V[i].tipo, V[i+1].tipo);
            V[i].custo = V[i+1].custo;
            V[i].autonomia = V[i+1].autonomia ;
        }
        return(1);
    }else return(0);
    
}

// lista todos os veiculos eletricos 
void listv(Veiculo V[vSize],int tamanho){
    printf("####Veiculos Eletricos####\n");
    for(int i=0; i<tamanho;i++){
        printf("Codigo:%d\n",V[i].codigo);
        printf("Tipo:%s\n",V[i].tipo);
        printf("Custo:%.2f\n",V[i].custo);
        printf("Autonomia:%d\n",V[i].autonomia);
        printf("######################\n");
    }
}

void listf(Fatura F[fSize],int tamanhof){
    printf("####Faturas####\n");
    for(int i=0; i<tamanhof;i++){
        printf("Numero ordem:%d\n",F[i].num_ord);
        printf("NIF:%d\n",F[i].NIF);
        printf("Veiculo:%d\n",F[i].veiculo);
        printf("Tempo:%d\n",F[i].tempo);
        printf("Distancia:%d\n",F[i].distancia);
        printf("######################\n");
    }
}

//fun????o para inserir veiculo eletrico
int insVeiculo(Veiculo V[fSize],int tamanho,int cod, char tp[50], float ct, int autono){
    if(tamanho<vSize){
        V[tamanho].codigo = cod;
        strcpy(V[tamanho].tipo, tp);
        V[tamanho].custo = ct;
        V[tamanho].autonomia = autono;
        return(1);
    }else return(0);
}

//Fun????i inserir fatura 
int insFatura(Fatura F[fSize],int tamanhof ,int n_ord ,int nif , Veiculo V[vSize], int codVeiculo ,int tamanhov,int temp, int dist){

    if(tamanhof<fSize){
        
        F[tamanhof].num_ord = n_ord;
        F[tamanhof].NIF = nif;
        F[tamanhof].veiculo = codVeiculo;
        F[tamanhof].tempo = temp;
        F[tamanhof].distancia = dist;
        return(1);
    }else return(0);
}

int rmFatura(Fatura F[fSize],int tamanhof, int codf){
    if(codf <= tamanhof){
        for(int i = codf-1; i<tamanhof-1;i++){
            F[i].num_ord = F[i+1].num_ord;
            F[i].NIF = F[i+1].NIF;
            F[i].veiculo = F[i+1].veiculo;
            F[i].tempo = F[i+1].tempo;
            F[i].distancia = F[i+1].distancia;
        }
        return(1);
    }else return(0);
}
 
//MENU
int menu(){
    int opcao;
    do{
        printf("---------MENU-------\n");
        printf("1 - Inser????o de um novo meio de mobilidade el??trica\n");
        printf("2 - Remo????o de um meio de mobilidade el??trica a partir do seu c??digo\n");
        printf("3 - Inser????o de um novo pedido de utiliza????o\n");
        printf("4 - Remo????o de um pedido de utiliza????o a partir do seu c??digo\n");
        printf("5 - Listagem dos dados de todos os meios de mobilidade el??trica\n");
        printf("6 - Listagem de todo os pedidos de utiliza????o\n");
        printf("7 - C??lculo do custo associado a um pedido de utiliza????o a partir da indica????o do seu n??mero de ordem\n");
        printf("8 - Distribui????o dos meios de mobilidade pelos v??rios utilizadores\n");
        printf("9-  Listagem do plano de utiliza????o de um determinado meio de mobilidade el??trica\n");
        printf("10- Guardar \n");
        printf("11- Guardar \n");
        printf("0 - Sair\n");
        printf("Opcao?");
        scanf("%d",&opcao); 
    }
    while ((opcao>12)||(opcao<0));
    return(opcao);
}


int main(){
    Fatura fatura[fSize];
    Veiculo veiculo[vSize];
    int opcao;
    int codigov,codV,resV, res3;
    char tipov[50];
    float custov;
    int autonomiav = 0;
    int nif,cod,temp,dist = 0;
    int nord=0;
    int tamanhov,tamanhof = 0;
    int codF, resF = 0;
    int num_ordem = 0;
    int cal_custo = 0;
    int codVeiculo = 0;
    FILE *fp;
    FILE *fp1;
    setlocale(LC_ALL, "Portuguese");







    do{
        opcao = menu();
        switch(opcao){
            case 1: 
                printf("##Inserir veiculo##\n");
                rollback:       //ponto de retorno se o if for verdadeiro!!
                printf("Inserir codigo:\n");
                scanf("%d", &codigov);

                //valida????o de input
                if(codigov<0){
                    printf("codigo tem de ser a cima de 0!\n");
                    goto rollback; 
                };
                printf("Inserir tipo:\n");
                scanf("%s", tipov);        
                printf("Inserir custo (custo abaixo de 1 tem de ser divido com Ponto):\n");
                scanf("%f", &custov);
                if(custov<0){
                    printf("Custo tem de ser a cima de 0!\n");
                    goto rollback;
                };
                printf("Inserir Autonomia:\n");
                scanf("%d", &autonomiav);
                if(autonomiav<0){ 
                    printf("Autonomia tem de ser a cima de 0!\n");
                    goto rollback;
                };

                insVeiculo(veiculo ,tamanhov ,codigov, tipov, custov, autonomiav);
                tamanhov++;

                break;
            case 2: 
                printf("Insira o codigo do Veiculo eletrico que deseja remover:");
                scanf("%d", &codV);
                resV = rmVeiculo(veiculo,tamanhov,codV);
                if(resV==1){
                    printf("Veiculo eletrico removido com sucesso!\n");
                    tamanhov--;
                } else printf("Veiculo eletrico n??o removido!\n");
                
                break;
            case 3: 
                printf("##Inserir Fatura##\n");
                printf("NIF:");
                scanf("%d", &nif);

                againcodveiculo:
                printf("Codigo:");
                scanf("%d", &cod);
                printf("Codigos Disponiveis:");
                for(int h=0; h<tamanhov;h++){
                   printf("%d\n",veiculo[h].codigo);
                }
                //verifica????o se codigo existe 
                for(int i = 0; i<tamanhov ;i++){
                if(cod == veiculo[i].codigo){
                    fatura[tamanhof].veiculo = veiculo[i].codigo;
                }else {
                    printf("N??o existe este codigo de veiculo eletrico\n");
                    goto againcodveiculo;
                } 
                }
                printf("tempo:");
                scanf("%d", &temp);
                printf("Dist??ncia:");
                scanf("%d", &dist);
                printf("%dnumord", nord);

                res3 = insFatura(fatura, tamanhof, nord, nif, veiculo, cod, tamanhov, temp, dist);
                if(res3==1) printf("Inserido com sucesso!\n");
                    else printf("Fatura n??o inserida!\n");
                nord++;
                tamanhof++;
                printf("%dnumord", nord);
                break;
            case 4: 
                printf("Insira o codigo do Veiculo eletrico que deseja remover:");
                scanf("%d", &codF);
                resF = rmFatura(fatura,tamanhof,codF);
                if(resF==1){
                    printf("Fatura removida com sucesso!\n");
                    tamanhof--;
                } else printf("Fatura n??o removida!\n");
                
                break;
            case 5: 
                listv(veiculo,tamanhov);
                break;
            case 6: 
                listf(fatura,tamanhof);
                break;
            case 7: 
            voltarcusto:
                printf("N??mero de ordem que deseja?");
                scanf("%d", &num_ordem);
                for(int i = 0; i<tamanhof ;i++){
                    if(num_ordem == fatura[i].num_ord){
                  
                    for (int h = 0; h < tamanhov; h++)
                    {
                    if (fatura[i].veiculo == veiculo[h].codigo){
                        printf("t%d\n",fatura[i].tempo);
                        printf("c%f\n",veiculo[h].custo);
                        cal_custo = fatura[i].tempo*veiculo[h].custo;
                    }
                    }
                }else 
                    {
                    printf("N??o existe este numero de ordem nas faturas\n");
                    goto voltarcusto;
                    }
                }

                printf("O custo da fatura %d ?? de: %d \n", num_ordem,cal_custo);
                break;
                
            case 8:
                for(int o=0; o <tamanhof; o++){
                    for(int j = 0; j < tamanhov; j++){
                        if (fatura[o].distancia <= veiculo[j].autonomia){
                            fatura[o].veiculo = veiculo[j].codigo;
                            veiculo[j].autonomia -= fatura[o].distancia;
                        }
                    } 
                }
                listf(fatura,tamanhof);

            break;

            case 9:
                
                    printf("Codigo do veiculo");
                    scanf("%d", &codVeiculo);
                    for(int j=0;j<tamanhov;j++){

                        for(int f=0;f<tamanhof;f++){
                         if(fatura[f].veiculo == veiculo[j].codigo)   
                            printf("######Veiculo n??:%d#######",j);
                            printf("Num_ordem:%d\n",fatura[f].num_ord);
                            printf("NIF:%d\n",fatura[f].NIF);
                            printf("Distancia%d\n",fatura[f].distancia);
                            printf("Codigo:%d\n",veiculo[j].codigo);
                        }
                    }
                 
            break;
            
            case 10:
                
                fp = fopen("Pedido.txt", "a+");
                for(int i=0; i<tamanhov;i++){
                    fprintf(fp, "NIF:%d \nVeiculo:%d \nTempo:%d \nDistancia:%d \n", fatura[i].NIF, fatura[i].veiculo, fatura[i].tempo, fatura[i].distancia);
                
                }
                fclose(fp);
                printf("Ficheiros Guardado com Sucesso");
            break;

            case 11:

                fp1 = fopen("MeiosDeMobilidade.txt", "a+");
                for(int i=0; i <tamanhov;i++){
                       fprintf(fp1, "Cod-%d \nTipo:%s \nCusto:%f \nAutonomia:%d \n", veiculo[i].codigo, veiculo[i].tipo, veiculo[i].custo, veiculo[i].autonomia);
                }
                
                fclose(fp1);
                printf("Ficheiros Guardado com Sucesso");

            break;
        }   
    }while(opcao != 0);

    return(0);
  
   
} 
