#include <stdio.h>

#define ex3

#ifdef ex1

/*
1 - Escreva um programa que tem uma estrutura da dados com os membros abaixo.
    receba dados via teclado e imprima estes conteudos no video no seguinte
    formato.
             char, int, long, float, double
             unsigned char, unsigned int, unsigned long,

            10        20        30        40        50        60        70
    1234567890123456789012345678901234567890123456789012345678901234567890
        char      int       long                float               double
              unsigned char       unsigned int        unsigned long
*/

struct tipos {
    char c;
    int i;
    long l;
    float f;
    double d;
    unsigned char uc;
    unsigned int ui;
    unsigned long ul;
};

struct tipos variaveis;

main(){
int fim;

    do{

    printf("Insira um valor do tipo char: ");
    scanf("%c",&variaveis.c);
    printf("Insira um valor do tipo int: ");
    scanf("%d",&variaveis.i);
    printf("Insira um valor do tipo long: ");
    scanf("%ld",&variaveis.l);
    printf("Insira um valor do tipo float: ");
    scanf("%f",&variaveis.f);
    printf("Insira um valor do tipo double: ");
    scanf("%lf",&variaveis.d);
    printf("Insira um valor do tipo unsigned char: ");
    getchar();
    scanf("%c",&variaveis.uc);
    printf("Insira um valor do tipo unsigned int: ");
    scanf("%u",&variaveis.ui);
    printf("Insira um valor do tipo unsigned long: ");
    scanf("%lu",&variaveis.ul);

    printf("\n        10        20        30        40        50        60        70\n");
    printf("1234567890123456789012345678901234567890123456789012345678901234567890\n");
    printf("    char      int       long                float               double\n");
    printf("          unsigned char       unsigned int        unsigned long\n");
    printf("%8c %8d %10ld %20.1f %20.0lf\n",variaveis.c,variaveis.i,variaveis.l,variaveis.f,variaveis.d);
    printf("%23c %18u %20lu\n",variaveis.uc,variaveis.ui,variaveis.ul);


    do{
        printf("\nDeseja sair? (1-sim / 0-nao)\n");
        scanf("%d",&fim);
    }while(fim!=0 && fim!=1);

	}while(fim!=1);
}

#endif // ex1

#ifdef ex2

/*
2 - Escreva um programa com a estrutura abaixo. Defina um vetor de estruturas
    de 4 elementos. Receba os dados pelo teclado e imprima-os no video. Faça um
    menu. (vetor de estruturas)
		nome, end, cidade, estado, cep
*/

struct dados {
    char nome[10];
    char end[50];
    char cidade[20];
    char estado[15];
    char cep[10];
};

struct dados dados[4];

main(){
int i=0;
char esc;

    do{
    printf("Selecione uma opcao\n--------------------\n");
    printf("1-Cadastrar\n");
    printf("2-Imprimir\n");
    printf("3-Sair\n\n");

    esc = getch();

        if(esc=='1'){
            for(i=0;i<4;++i){
                printf("Faca o %d cadastro\n----------------------\n",i+1);
                printf("Insira o nome: ");
                gets(dados[i].nome);

                printf("Insira o endereco: ");
                gets(dados[i].end);

                printf("Insira a cidade: ");
                gets(dados[i].cidade);

                printf("Insira o estado: ");
                gets(dados[i].estado);

                printf("Insira o CEP: ");
                gets(dados[i].cep);

                printf("\n");
            }
        } else if(esc=='2'){
            for(i=0;i<4;++i){
                    printf("Nome: %s\n",dados[i].nome);
                    printf("Endereco: %s\n",dados[i].end);
                    printf("Cidade: %s\n",dados[i].cidade);
                    printf("Estado: %s\n",dados[i].estado);
                    printf("CEP: %s\n\n",dados[i].cep);
                }
        }
    }while(esc!='3');
}

#endif // ex2

#ifdef ex3

/*
3 - Crie uma estrutura para representar as coordenadas de um ponto no plano
    (posicoes X e Y). Em seguida, declare e leia do teclado um ponto e exiba a
    distancia dele ate' a origem das coordenadas, isto é, posição (0, 0). Para
    realizar o cálculo, utilize a fórmula a seguir:
           d = raiz quadrada de  (XB - XA)ao 2 +(YB -YA)ao 2
    Em que:
    d = distância entre os pontos A e B
    X = coordenada X em um ponto
    Y = coordenada Y em um ponto
*/

typedef struct{
    int x;
    int y;
}pontos;

main(){
pontos p;
float d;
int fim;

    do{
    printf("Insira o ponto de X: ");
    scanf("%d",&p.x);

    printf("Insira o ponto de Y: ");
    scanf("%d",&p.y);

    d=sqrt((p.x)*(p.x)+(p.y)*(p.y));

    printf("A distancia entre os pontos e %f\n",d);

        do{
            printf("\nDeseja sair? (1-sim / 0-nao)\n");
            scanf("%d",&fim);
        }while(fim!=0 && fim!=1);

	}while(fim!=1);
}

#endif // ex3
