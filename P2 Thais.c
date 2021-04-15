#include <stdio.h>
/*
Escreva um programa com a estrutura-> produto, quantidade atual e quantidade minima
Defina um vetor de estruturas de 4 elementos como variavel local na funcao main().
Defina um menu com as seguintes opcoes: (Utilize o comando switch)
1 - entra produto
2 - altera produto
3 - exclui produto
4 - pesquisa produto pelo nome. Mostre se existe ou nao na funcao main().
5 - lista todos os produtos
6 - lista todos os produtos abaixo do estoque minimo
7 - sair
*/
struct dados{
    char produto[20];
    int quant;
    int min;
};

main(){
struct dados c[2], *p;
p = &c;
int x;
int op;

    for(;;){
        printf("1 - entra produtos\n");
        printf("2 - altera produtos\n");
        printf("3 - exclui produtos\n");
        printf("4 - comp produtos\n");
        printf("5 - lista produtos\n");
        printf("6 - lista produtos abaixo do minimo\n");
        printf("7 - sair\n");

        scanf("%d",&op);
        getchar();
        if(op == 7)
            break;

        switch(op){
            case 1 :
                entra(p);
                break;

            case 2 :
                x = comp(p);
                if(x >= 0){
                    altera(p,x);
                }
            break;

            case 3 :
                x = comp(p);
                if(x >= 0){
                    exclui(p,x);
                }
            break;

            case 4 :
                x = comp(p);
                if(x >= 0){
                    printf("O produto foi encontrado. \n %d");
                }else{
                        printf("Ta em falta parceiro \n %d");
                }
                     break;
            case 5 :
                imp(p);
                break;

            case 6 :
                imp_min(p);
                break;
       }
    }
}

//#################################
entra(struct dados *p){
    //recebe os 4 registros via teclado

int i;

    for(i=0;i<sizeof(p);i++){

        printf("Produto: ");
        scanf("%s",&p[i].produto);
        printf("Quantidade: ");
        scanf("%d",&p[i].quant);
        printf("Minimo: ");
        scanf("%d",&p[i].min);
        printf("\n");
    }
}

//##################################
altera(struct dados *p, int x){

        printf("Produto: ");
        scanf("%s",&p[x].produto);
        getchar();
        printf("Quantidade: ");
        scanf("%d",&p[x].quant);
        printf("Minimo: ");
        scanf("%d",&p[x].min);
        printf("\n");
}

//##################################
exclui(struct dados *p, int x){
    //apagar registro com * na 1. posicao do nome
	p[x].produto[0] = 42;
}

//##################################
int comp(struct dados *p){
	//recebe o nome a ser pesquisado
	//retorna se existe (n. do registro) se nao existe -1

char busca[20];
int i=0;
int j=0;

	printf("Produto: ");
	scanf("%s",&busca);

	for(i=0;i<sizeof(p);i++){

        for(j=0;p[i].produto[j] != '\0';j++){

            if(p[i].produto[j] != busca[j]){
                break;
                return 0;
            }
        }
	}
    return -1;
}

//####################################
imp(struct dados *p){
    //imprime os 4 registro na tela
    //verifica se esta' apagado. se sim, nao imprime o registro.

int i;

    for(i=0;i<sizeof(p);i++){
        if(p[i].produto[0] != '*'){
            printf("Produto: %s\n",p[i].produto);
            printf("Quantidade: %d\n",p[i].quant);
            printf("Minimo: %d\n\n",p[i].min);
            printf("\n");
        }
    }
}

//####################################
imp_min(struct dados *p){
    //imprime os registro com estoque abaixo do minimo na tela
    //verifica se esta' apagado. se sim, nao imprime o registro.

int i;

    for(int i=0;i<4;i++){

        if(p[i].quant<p[i].min && p[i].produto[0] != '*'){
            printf("Produto: %s\n",p[i].produto);
            printf("Quantidade: %d\n",p[i].quant);
            printf("Minimo: %d\n\n",p[i].min);
        }
    }
}


