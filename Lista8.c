#include <stdio.h>
#include <stdlib.h>

#define ex6
#ifdef ex1

/*
1 - Escreva um programa que receba via teclado um char, int, long, unsigned,
    float, double, unsigned long e unsigned char, declare ponteiros para os
    mesmos e imprima-os no video utilizando o operador de conteudo * no
    seguinte formato:

            10        20        30        40        50        60
    123456789012345678901234567890123456789012345678901234567890
        int                 long                unsigned
                  float               double              char
             unsigned long       unsigned char
             */

main(){
    char *pc, c;
    int *pi, i;
    long *pl, l;
    unsigned *pu, u;
    float *pf, f;
    double *pd, d;
    unsigned long *pul, ul;
    unsigned char *puc, uc;
    int fim;

    pc = &c;
    pi = &i;
    pl = &l;
    pu = &u;
    pf = &f;
    pd = &d;
    pul = &ul;
    puc = &uc;

do{
    printf("Insira um valor do tipo char: ");
    scanf("%c",pc);
    printf("Insira um valor do tipo int: ");
    scanf("%d",pi);
    printf("Insira um valor do tipo long: ");
    scanf("%ld",pl);
    printf("Insira um valor do tipo unsigned: ");
    scanf("%u",pu);
    printf("Insira um valor do tipo float: ");
    scanf("%f",pf);
    printf("Insira um valor do tipo double: ");
    scanf("%lf",pd);
    printf("Insira um valor do tipo unsigned long: ");
    scanf("%lu",pul);
    printf("Insira um valor do tipo unsigned char: ");
    getchar();
    scanf("%c",puc);

    printf("        10        20        30        40        50        60\n");
    printf("123456789012345678901234567890123456789012345678901234567890\n");
    printf("    int                 long                unsigned\n");
    printf("             float               double              char\n");
    printf("         unsigned long       unsigned char\n");
    printf("%7d %20ld %23u\n",*pi,*pl,*pu);
    printf("%18.1f %20.0lf %17c\n",*pf,*pd,*pc);
    printf("%22lu %19c\n",*pul,*puc);

        do{
            printf("\nDeseja sair? (1-sim / 0-nao)\n");
            scanf("%d",&fim);
        }while(fim!=0 && fim!=1);

	}while(fim!=1);
}

#endif //ex1

#ifdef ex2

/*2 - Com a estrutura abaixo, defina um vetor de estruturas de 4 elementos.
    Receba os dados pelo teclado usando ponteiros e imprima-os no video
    também usando ponteiros. Utilize um comando de loop. (vetor de estruturas)
              nome, end, cidade, estado, cep
*/

typedef struct {
    char nome[20];
    char end[50];
    char cidade[20];
    char estado[15];
    char cep[10];
}dados;

main(){

dados d[4];

dados *pd[4];

pd[0]=&d[0];

int i, esc;

    do{
    printf("Selecione uma opcao\n--------------------\n");
    printf("1-Cadastrar\n");
    printf("2-Imprimir\n");
    printf("3-Sair\n\n");

    scanf("%d",&esc);
    getchar();

        if(esc==1){
            for(i=0;i<4;++i){
                printf("Faca o %d cadastro\n----------------------\n",i+1);
                printf("Insira o nome: ");
                gets(pd[i]->nome);

                printf("Insira o endereco: ");
                gets(pd[i]->end);

                printf("Insira a cidade: ");
                gets(pd[i]->cidade);

                printf("Insira o estado: ");
                gets(pd[i]->estado);

                printf("Insira o CEP: ");
                gets(pd[i]->cep);

                printf("\n");
            }
        } else if(esc==2){
            for(i=0;i<4;++i){
                printf("Nome: %s\n",pd[i]->nome);
                printf("Endereco: %s\n",pd[i]->end);
                printf("Cidade: %s\n",pd[i]->cidade);
                printf("Estado: %s\n",pd[i]->estado);
                printf("CEP: %s\n\n",pd[i]->cep);
            }
        }
    }while(esc!=3);
}

#endif // ex2

#ifdef ex3

/*
3 - Receba um caracter via teclado usando ponteiros e compara com o vetor abaixo
    usando ponteiros. mostre como resultado se são IGUAIS ou DIFERENTES.
    vetor -> b,d,f,h,j,l,m,o,q,s,u,w,y]
*/

char vetor[] = {'b','d','f','h','j','l','m','o','q','s','u','w','y'};


busca(char letra){
int achei=0;
    for(int i=0;i<sizeof(vetor);i++){
        if(letra==vetor[i]){
            achei=1;
        }
    }
    return achei;
}

main(){

char *pletra, letra;
int fim;

    do{
        pletra = &letra;
        printf("Insira uma letra: ");
        scanf("%c",pletra);

        if(busca(*pletra)==0){
            printf("\nA letra nao foi encontrada\n");
        } else{
            printf("\nA letra se encontra na matriz\n");
        }
            do{
                printf("\nDeseja sair? (1-sim / 0-nao)\n");
                scanf("%d",&fim);
            }while(fim!=0 && fim!=1);
            getchar();
	}while(fim!=1);
}

#endif // ex3

#ifdef ex4

char str[2][10];
char *pstr[2][10];

main(){

pstr[0][10]=&str[0][10];

int i,cont=0,fim;

    do{
        printf("Insira uma string: ");
        scanf("%s",pstr[0]);

        printf("Insira outra string: ");
        scanf("%s",pstr[1]);

        for(i=0;i<10;i++){
            if(pstr[0][i] != pstr[1][i]){
                cont++;
            }
        }

        if(cont!=0){
            printf("\nAs strings sao diferentes\n");
        } else{
            printf("\nAs strings sao iguais\n");
        }

		do{
			printf("\nDeseja sair? (1-sim / 0-nao)\n");
			scanf("%d", &fim);
		}while(fim != 0 && fim !=1);
		cont=0;
	}while(fim != 1);
}

#endif // ex4

#ifdef ex5

/*
5 - Escreva um programa que receba via teclado numeros inteiros positivos usando
    ponteiros. Quando o numero digitado for negativo o programa deve parar e calcula
    a media dos valores digitados e mostrar o resultado.
    */

main(){

float num,*pnum,soma=0;
int i,cont=0,fim;

pnum=&num;

    do{
        for(i=0;*pnum>0;i++){
            printf("Insira um numero: ");
            scanf("%f",pnum);
            if(num>0){
                cont++;
                soma+=*pnum;
            }
        }
        printf("A media dos numeros positivos e %g\n",soma/cont);
        *pnum=1;
        soma=0;
        cont=0;

        do{
            printf("\nDeseja sair? (1-sim / 0-nao)\n");
            scanf("%d",&fim);
        }while(fim!=0 && fim!=1);

	}while(fim!=1);
}

#endif // ex5

#ifdef ex6

/*
6 - Escreva um programa que contenha uma estrutura representando uma data
    valida. Essa estrutura deve conter os campos dia, mes e ano. Em seguida,
    leia duas datas e armazene nessa estrutura usando ponteiros. Calcule e exiba o
    numero de dias que decorrem entre as duas datas usando ponteiros.
*/

typedef struct{
    int dia;
    int mes;
    int ano;
}data;

main(){

    int i, fim, dias, dias1=0, dias2=0;

    data dia1, dia2;     // declara as variaveis da data inicial e data final
    data *pdia1, *pdia2; // declara os ponteiros das variaveis data inicial e data final

    pdia1 = &dia1;       // atribui o ponteiro pdia1 ao endereco de dia1
    pdia2 = &dia2;       // atribui o ponteiro pdia2 ao endereco de dia2

    do{
        // recebe a data inicial

        do{
            printf("Insira a data inicial no formato dia/mes/ano\n");
            scanf("%d/%d/%d", &pdia1->dia, &pdia1->mes, &pdia1->ano);
        }while(pdia1->dia <= 0 || pdia1->dia > 31 || pdia1->mes <= 0 || pdia1->mes > 12
               || pdia1->ano <= 0 || pdia1->ano > 3000);

        // recebe a data final

        do{
            printf("\nInsira a data final no formato dia/mes/ano\n");
            scanf("%d/%d/%d", &pdia2->dia, &pdia2->mes, &pdia2->ano);
            if(pdia1->ano > pdia2->ano){
                printf("A data final nao pode ser maior que a data inicial\n");
        }
        }while(pdia2->dia <= 0 || pdia2->dia > 31 || pdia2->mes <= 0 || pdia2->mes > 12
                || pdia2->ano <= 0 || pdia2->ano > 3000 || pdia1->ano > pdia2->ano);

        // calcula a diferenca de dias

        dias1+=((pdia1->ano-1) * 365);
        dias1+=(((pdia1->mes-1) * 30));
        dias1+=(pdia1->dia);

        dias2+=((pdia2->ano-1) * 365);
        dias2+=(((pdia2->mes-1) * 30));
        dias2+=(pdia2->dia);

        dias=dias2-dias1;

        // mostra o resultado

        printf("O numero de dias decorridos entre as datas e %d\n",dias);

        // repete o programa

        do{
            printf("\nDeseja sair? (1-sim / 0-nao)\n");
            scanf("%d",&fim);

        }while(fim!=0 && fim!=1);

    }while(fim!=1);
}

#endif // ex6
