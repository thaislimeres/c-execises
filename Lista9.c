#include <stdio.h>

#define ex6

#ifdef ex1

/*
1 - Escreva um programa que tem uma estrutura da dados com os membros abaixo.
    A estrutura é uma variavel local na função main().Receba via teclado o
    conteudo de cada um dos membros numa função e imprima-os no video no
    seguinte fomato(também numa função).

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

recebe(struct tipos *pvariaveis){

    printf("Insira um valor do tipo char: ");
    scanf("%c",&pvariaveis->c);

    printf("Insira um valor do tipo int: ");
    scanf("%d",&pvariaveis->i);

    printf("Insira um valor do tipo long: ");
    scanf("%ld",&pvariaveis->l);

    printf("Insira um valor do tipo float: ");
    scanf("%f",&pvariaveis->f);

    printf("Insira um valor do tipo double: ");
    scanf("%lf",&pvariaveis->d);

    printf("Insira um valor do tipo unsigned char: ");
    getchar();
    scanf("%c",&pvariaveis->uc);

    printf("Insira um valor do tipo unsigned int: ");
    scanf("%u",&pvariaveis->ui);

    printf("Insira um valor do tipo unsigned long: ");
    scanf("%lu",&pvariaveis->ul);
}

imprime(struct tipos *pvariaveis){

        printf("        10        20        30        40        50        60        70\n");
        printf("1234567890123456789012345678901234567890123456789012345678901234567890\n");
        printf("    char      int       long                float               double\n");
        printf("          unsigned char       unsigned int        unsigned long\n");
        printf("%8c %8d %10ld %20.1f %20.0lf\n",pvariaveis->c,pvariaveis->i,pvariaveis->l,pvariaveis->f,pvariaveis->d);
        printf("%23c %18u %20lu\n",pvariaveis->uc,pvariaveis->ui,pvariaveis->ul);
}

main(){

static struct tipos variaveis;
struct tipos *pvariaveis;

pvariaveis=&variaveis;

int fim;

    do{
        recebe(pvariaveis);

        imprime(pvariaveis);

        do{
            printf("\nDeseja sair? (1-sim / 0-nao)\n");
            scanf("%d",&fim);
            getchar();
        }while(fim!=0 && fim!=1);

	}while(fim!=1);
}

#endif //ex1

#ifdef ex2

/*
2 - Escreva um programa que receba n valores via teclado, receba também a
    operação a ser executada. Quando for digitado "=" o programa deve mostrar
    o resultado acumulado dos n valores. As operações aritmeticas e a entrada
    de dados devem ser funções que recebe os valores usando ponteiros.
*/

char sinais(){
char sinal;

    do{
        printf("Insira um operador: ");
        getchar();
        scanf("%s",&sinal);
        if(sinal!='+' && sinal!='-' && sinal!='*' && sinal!='/' && sinal!='='){
            printf("Digite + para soma, - para subtracao, * para multiplicacao e / para divisao e = para mostrar o resultado\n");
        }
    }while(sinal!='+' && sinal!='-' && sinal!='*' && sinal!='/' && sinal!='=');
    getchar();

    return sinal;
}

float entrada(float num){

    printf("Insira um numero: ");
    scanf("%f",&num);

    return num;
}

float calculo(float result, float num, char sinal){

    if(sinal=='+'){
        result+=num;
    }
    if(sinal=='-'){
        result-=num;
    }
    if(sinal=='*'){
        result*=num;
    }
    if(sinal=='/'){
        result/=num;
    }

    return result;
}

main(){
char sinal;
sinal='+';
float  num, result=0;
char *psinal = &sinal;
float *pnum = &num;
float *presult = &result;
int fim;

    do{
        result=0;
        num=0;

        for(;*psinal != '=';){
            *pnum = entrada(*pnum);
            *presult = calculo(*presult,*pnum,*psinal);
            *psinal=sinais();

        }

        printf("O resultado e %f\n",*presult);

        do{
            printf("\nDeseja sair? (1-sim / 0-nao)\n");
            scanf("%d",&fim);
            getchar();
        }while(fim!=0 && fim!=1);
        sinal='0';

    }while(fim!=1);
}

#endif //ex2

#ifdef ex3

/*
3 - Escreva um programa que receba uma letra via teclado. Escreva uma funcao que
    pesquise esta letra dentro do vetor abaixo. Imprima o resultado da pesquisa no
    video na funcao main(). O vetor é uma variavel local na função main().Passe
    como parametro para a funcao o vetor e a letra digitada usando ponteiros.
    (utilize o comando return)
    vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y
*/

busca(char letra, char *vetor){
int achei=0;
    for(int i=0;i<sizeof(vetor);i++){
        if(letra==vetor[i]){
            achei=1;
        }
    }
    return (achei);
}

main(){

char vetor[] = {'b','d','f','h','j','k','m','o','q','s','u','w','y'};
char letra, c;

    for(;;){

    printf("Insira uma letra: ");
    scanf("%c",&letra);

    if(busca(letra,vetor)==0){
        printf("\nA letra nao foi encontrada\n");
    } else{
        printf("\nA letra se encontra na matriz\n");
        }
            printf("\nDeseja sair? (s/n)\n");
            c = getchar();
            scanf("%c",&c);
            getchar();

            if(c == 's' || c == 'S')
                break;
    }
}

#endif //ex3

#ifdef ex4

/*
4 - Escreva um programa que receba em 2 funcao 2 strings de ate' 10 caracteres.
    Os vetores sao declaradas como variavel local na função main().
    Escreva uma funcao que recebe as strings com parametros usando ponteiros
    e compare estas 2 strings.
    Retorne como resultado da comparacao 0 se forem DIFERENTES, 1 se forem
    IGUAIS, 2 se a string 1 for maior que a string 2, 3 se a string 2 for maior
    que a string 1 e 4 se as string tem tamanhos iguais mas são diferentes.
*/

void recebe1(char *vetor1){

    scanf("%s",vetor1);
    getchar();
}

void recebe2(char *vetor2){

    scanf("%s",vetor2);
}

int comparacao(char *vetor1, char *vetor2){
int i=0;

    for(i=0;vetor1[i] != '\0';i++){
        if(vetor1[i] != vetor2[i] && vetor2[i] != vetor1[i]){
            return 0;
        }
    }
    return 1;
}

int compmaior(char *vetor1, char *vetor2){
int i = 0;
int j = 0;

	while(vetor1[i] != '\0'){
		i++;
	}
	while(vetor2[j] != '\0'){
		j++;
	}

	if(i > j){
		return 2;
	} else if(j > i){
		return 3;
	} else{
		return 4;
	}
}

main(){

    char vetor1[10];
    char vetor2[10];
    int fim;

    do{

        printf("Insira uma string: ");
        recebe1(vetor1);

        printf("Insira outra string: ");
        recebe2(vetor2);

        if(comparacao(vetor1,vetor2)!=0){
            printf("\nAs strings sao iguais\n");
        } else {
            printf("\nAs strings sao diferentes\n");

            if(compmaior(vetor1,vetor2)==2){
                printf("A string 1 e maior\n");
            } else if(compmaior(vetor1,vetor2)==3){
                printf("A string 2 e maior\n");
            } else if(compmaior(vetor1,vetor2)==4){
                printf("As strings possuem o mesmo tamanho\n");
            }
        }

        do{
            printf("\nDeseja sair? (1-sim / 0-nao)\n");
            scanf("%d",&fim);
            getchar();
        }while(fim!=0 && fim!=1);

    }while(fim!=1);
}

#endif //ex4

#ifdef ex5

/*
5 - Escreva um programa com a estrutura abaixo. Defina um vetor de estruturas
    de 4 elementos.Receba os 4 registros sequencialmente pelo teclado numa
    função e imprima todos os registros no video em outra função. Faça um menu.
    Coloque no menu a opção de sair também. Utilize o comando switch.
    (vetor de estruturas)
                nome, end, cidade, estado, cep
*/

struct cadastro {
    char nome[50];
    char end[50];
    char cidade[20];
    char estado[15];
    char cep[10];
};

void recebe(struct cadastro *dados){

    for(int i=0;i<4;++i){
        printf("Faca o %d cadastro\n----------------------\n",i+1);
        printf("Insira o nome: ");
        scanf("%s",dados[i].nome);

        printf("Insira o endereco: ");
        scanf("%s",dados[i].end);

        printf("Insira a cidade: ");
        scanf("%s",dados[i].cidade);

        printf("Insira o estado: ");
        scanf("%s",dados[i].estado);

        printf("Insira o CEP: ");
        scanf("%s",dados[i].cep);

        system("cls");
    }

}

void imprime(struct cadastro *dados){

    for(int i=0;i<4;++i){
        printf("Nome: %s\n",dados[i].nome);
        printf("Endereco: %s\n",dados[i].end);
        printf("Cidade: %s\n",dados[i].cidade);
        printf("Estado: %s\n",dados[i].estado);
        printf("CEP: %s\n\n",dados[i].cep);
    }

}

main(){

static struct cadastro dados[4];

int i, esc;

    for(;;){

        printf("Selecione uma opcao\n--------------------\n");
        printf("1-Cadastrar\n");
        printf("2-Imprimir\n");
        printf("3-Sair\n\n");

        scanf("%d",&esc);
        getchar();

        if(esc==3){
            break;
        }

            switch(esc){

                case 1:
                    system("cls");
                    recebe(dados);
                    continue;

                case 2:
                    system("cls");
                    imprime(dados);
                    continue;

            }
    }
}

#endif //ex5

#ifdef ex6

/*
6 - Acrescente ao menu do exercicio anterior as funcoes de procura, altera e
    exclui um registro.
*/

struct cadastro {
    char nome[50];
    char end[50];
    char cidade[20];
    char estado[15];
    char cep[10];
};

recebe(struct cadastro *dados){

    for(int i=0;i<4;++i){
        printf("Faca o %d cadastro\n----------------------\n",i+1);
        printf("Insira o nome: ");
        gets((dados+i)->nome);

        printf("Insira o endereco: ");
        gets((dados+i)->end);

        printf("Insira a cidade: ");
        gets((dados+i)->cidade);

        printf("Insira o estado: ");
        gets((dados+i)->estado);

        printf("Insira o CEP: ");
        gets((dados+i)->cep);

        system("cls");
    }
}

imprime(struct cadastro *dados){

    for(int i=0;i<4;++i){
        printf("Nome: %s\n",dados[i].nome);
        printf("Endereco: %s\n",dados[i].end);
        printf("Cidade: %s\n",dados[i].cidade);
        printf("Estado: %s\n",dados[i].estado);
        printf("CEP: %s\n\n",dados[i].cep);
    }
}

int procura(struct cadastro *dados){
char busca[50], *pbusca;
int i, j;

pbusca = busca;

        printf("Insira a busca: ");
        scanf("%s",pbusca);

        for(i=0;i<4;i++){
            for(j=0;*(pbusca+j)!= '\0';j++){
                if(*(pbusca+j) != (dados+i)->nome[j]){
                    break;
                }
            }
            if(*(pbusca+j) == '\0' && (dados+i)->nome[j] == '\0'){

                return i;
            }
        }
        return -1;
}

int altera(struct cadastro *dados){
int i;

    i=procura(dados);

    if(i == -1){
        printf("Nenhum registro encontrado\n\n");
        return -1;
    }

    getchar();

    printf("Insira o nome: ");
    gets((dados+i)->nome);

    printf("Insira o endereco: ");
    gets((dados+i)->end);

    printf("Insira a cidade: ");
    gets((dados+i)->cidade);

    printf("Insira o estado: ");
    gets((dados+i)->estado);

    printf("Insira o CEP: ");
    gets((dados+i)->cep);

    system("cls");
}

int exclui(struct cadastro *dados){
int i;

    i=procura(dados);

    if(i == -1){
        printf("Nenhum registro encontrado\n\n");
        return -1;
    }

    getchar();

    (dados+i)->nome[0] = '\0';
    (dados+i)->end[0] = '\0';
    (dados+i)->cidade[0] = '\0';
    (dados+i)->estado[0] = '\0';
    (dados+i)->cep[0] = '\0';

    printf("O registro foi excluido\n\n");
}

main(){

static struct cadastro dados[4], *pdados;

int i, esc;

pdados=&dados[0];

    for(;;){

        printf("Selecione uma opcao\n--------------------\n");
        printf("1-Cadastrar\n");
        printf("2-Imprimir\n");
        printf("3-Procurar\n");
        printf("4-Alterar\n");
        printf("5-Excluir\n");
        printf("6-Sair\n");

        scanf("%d",&esc);
        getchar();

        if(esc==6){
            break;
        }
            switch(esc){

                case 1:
                    system("cls");
                    recebe(pdados);
                    continue;

                case 2:
                    system("cls");
                    imprime(pdados);
                    continue;

                case 3:
                    system("cls");
                    i = procura(pdados);
                    if(i != -1){
                        printf("Sua busca gerou resultados\n\n");
                    } else{
                        printf("Sua busca nao gerou resultados\n\n");
                    }
                    continue;

                case 4:
                    system("cls");
                    altera(pdados);
                    continue;

                case 5:
                    system("cls");
                    exclui(pdados);
                    continue;
            }
    }
}

#endif //ex6
