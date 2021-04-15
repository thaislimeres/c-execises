#define ex2

#include "stdio.h"

//o usuario e' quem decide sair do programa

#ifdef ex1
/*
1 - Escreva um programa para uma calculadora que recebe os dados do
    tipo int na funcao main() que tem as seguintes operacoes:
    soma, subtracao, multiplicacao, divisao, elevado um numero ao 2 e
    calcula a fatorial.
*/

int soma(int a, int b){
return a+b;
}

int subtracao(int a, int b){
return a-b;
}

int multiplicacao(int a, int b){
return a*b;
}

float divisao(int a, int b){
return (float)a/(float)b;
}

int potencia(int a){
return a*a;
}

int fatorial(int a){
int i=a-1;
	while(i>=1){
		a*=i;
		i--;
	}
	return a;
}

main(){

int a,b,fim;
char es;

printf("Digite um numero, o operador, e em seguida outro numero\n");
printf("Para mostrar o resultado pressione =\n\n");
printf("Operadores:\n");
printf("\n= para o resultado\n");
printf("+ para soma\n");
printf("- para subtracao\n");
printf("* para multiplicacao\n");
printf("/ para divisao\n");
printf("^ para potencia\n");
printf("! para fatorial\n");

    do{
        printf("\nDigite um numero inteiro: ");
        scanf("%d", &a);
        getchar();

        while(es != '='){
            do{
                printf("Digite o operador: ");
                es = getchar();
                getchar();
            }while(es!='+' && es!='-' && es!='*' && es!='/' && es!='=' && es!='^' && es!= '!');

            if(es!='=' && es!='^' && es!='!'){
                printf("Digite um numero inteiro: ");
                scanf("%d", &b);
                getchar();
            }
                switch(es){

                    case '+': a=soma(a,b);
                    break;

                    case '-': a=subtracao(a,b);
                    break;

                    case '*': a=multiplicacao(a,b);
                    break;

                    case '/': a=divisao(a,b);
                    break;

                    case '^': a=potencia(a);
                    break;

                    case '!': a=fatorial(a);
                    break;

                    case '=': printf("\nResultado e %d\n",a);
                    break;
                }
        }
		do{
			printf("\nDeseja sair? (1-sim / 0-nao)\n");
			scanf("%d", &fim);
		}while(fim != 0 && fim !=1);
		es='0';

	}while(fim != 1);
}

#endif // ex1

#ifdef ex2
/*
2 - Escreva um programa que receba na funcao main() 2 strings de ate' 10 caracteres.
    Escreva uma funcao que compare estas 2 strings e retorne:
    0 se DIFERENTES
    1 se sao IGUAIS
    Se forem DIFERENTES, retorne
    2 se o comprimento da 1. string for maior que a 2 string
    3 se o comprimento da 2. string for maior que a 1 string
    4 se as 2 strings tem o comprimento igual
     Declare as strings como variavel global.
*/

char str[2][10];

int comparacao(){

    for(int i=0;i<10;i++){

        if(str[0][i] == str[1][i]){
                return 1;
        } else{
            return 0;
        }
    }
}

int compmaior(){
int i = 0,
	j = 0;

	while(str[0][i] != '\0'){
		i++;
	}
	while(str[1][j] != '\0'){
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

int i,fim;

    do{
        printf("Insira uma string: ");
        scanf("%s",&str[0]);

        printf("Insira outra string: ");
        scanf("%s",&str[1]);

        if(comparacao()==1){
            printf("\nAs strings sao iguais\n");
        } else{
            printf("\nAs strings sao diferentes\n");
                if(compmaior()==2){
                    printf("O comprimento da primeira string e maior\n");
                } else if(compmaior()==3){
                    printf("O comprimento da segunda string e maior\n");
                } else if(compmaior()==4){
                    printf("O comprimento das strings e igual\n");
                }
        }

		do{
			printf("\nDeseja sair? (1-sim / 0-nao)\n");
			scanf("%d", &fim);
		}while(fim != 0 && fim !=1);

	}while(fim != 1);
}

#endif // ex2
