#include <stdio.h>

#define ex1

#ifdef ex1

char vetor[] = {'b','d','f','h','j','k','m','o','q','s','u','w','y'};

busca(char letra){
int achei=0;
    for(int i=0;i<13;i++){
        if(letra==vetor[i]){
            achei=1;
        }
    }
    return (achei);
}

main(){

char letra, c;

    for(;;){

    printf("Insira uma letra: ");
    scanf("%c",&letra);



    if(busca(letra)==0){
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

#endif

#ifdef ex2

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

main()
{
int a,b;
char c;

    for(;;){
        printf("Insira um numero inteiro: ");
        scanf("%d",&a);

        printf("Insira outro numero inteiro: ");
        scanf("%d",&b);

        printf("\nA soma dos dois numeros e %d\n",soma(a,b));

        printf("A subtracao dos dois numeros e %d\n",subtracao(a,b));

        printf("A multiplicacao dos dois numeros e %d\n",multiplicacao(a,b));

        printf("A divisao dos dois numeros e %.2f\n",divisao(a,b));

            printf("\nDeseja sair? (s/n)\n");
            c = getchar();
            scanf("%c",&c);
            getchar();

            if(c == 's' || c == 'S')
                break;
    }
}

#endif

#ifdef ex3

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

main()
{
int a,b,n,i=0;
char c;

    for(;;){
        printf("Insira a quantidade de termos: ");
        scanf("%d",&n);

        do{
            i++;
            printf("Insira um numero inteiro: ");
            scanf("%d",&a);

            printf("Insira outro numero inteiro: ");
            scanf("%d",&b);
        }while(i<n);

        printf("\nA soma dos numeros e %d\n",soma(a,b));

        printf("A subtracao dos numeros e %d\n",subtracao(a,b));

        printf("A multiplicacao dos numeros e %d\n",multiplicacao(a,b));

        printf("A divisao dos numeros e %.2f\n",divisao(a,b));

            printf("\nDeseja sair? (s/n)\n");
            c = getchar();
            scanf("%c",&c);
            getchar();

            if(c == 's' || c == 'S')
                break;
    }
}


#endif

#ifdef ex4

#include <stdio.h>

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

main()
{
int a,b,n,i=0;
char c,es;

    for(;;){

        printf("Insira um numero inteiro: ");
        scanf("%d",&a);

        printf("Insira outro numero inteiro: ");
        scanf("%d",&b);

        do{
            printf("\nEscolha uma operacao para estes dois numeros\n\n");
            printf("+ para soma\n");
            printf("- para subtracao\n");
            printf("* para multiplicacao\n");
            printf("/ para divisao\n");
            es = getch();

            switch(es){

                case '+': printf("\nA soma dos numeros e %d\n",soma(a,b));
                break;

                case '-': printf("\nA subtracao dos numeros e %d\n",subtracao(a,b));
                break;

                case '*': printf("\nA multiplicacao dos numeros e %d\n",multiplicacao(a,b));
                break;

                case '/': printf("\nA divisao dos numeros e %.2f\n",divisao(a,b));
                break;
            }
        }while(es!='+' && es!='-' && es!='*' && es!='/');

            printf("\nDeseja sair? (s/n)\n");
            c = getchar();
            scanf("%c",&c);
            getchar();

            if(c == 's' || c == 'S')
                break;
    }
}

#endif

#ifdef ex5

#include <stdio.h>

char str1[10];
char str2[10];

int comparacao(){
    int dif=0;

    for(int i=0;i<10;i++){
        if(str1[i]!=str2[i])
            dif=1;
    }
    return (dif);
}

main(){

char c;

    for(;;){

        printf("Insira uma string: ");
        scanf("%s",&str1);

        printf("Insira outra string: ");
        scanf("%s",&str2);

            if(comparacao() == 0)
                printf("\nAs strings sao iguais\n");

            else
                printf("\nAs strings sao diferentes\n");

            printf("\nDeseja sair? (s/n)\n");
            c = getchar();
            scanf("%c",&c);
            getchar();

            if(c == 's' || c == 'S')
                break;
    }
}

#endif
