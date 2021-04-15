#include <stdio.h>

#define ex1

#ifdef ex1

main(){

int i[3];
long l[3];
unsigned u[3];
float f[3];
double d[3];
int cont;
char c;

    for(;;){

        printf("Insira 3 numeros inteiros\n");
        scanf("%d",&i[0]);
        scanf("%d",&i[1]);
        scanf("%d",&i[2]);

        printf("Insira 3 numeros long\n");
        scanf("%ld",&l[0]);
        scanf("%ld",&l[1]);
        scanf("%ld",&l[2]);

        printf("Insira 3 numeros unsigned\n");
        scanf("%u",&u[0]);
        scanf("%u",&u[1]);
        scanf("%u",&u[2]);

        printf("Insira 3 numeros float\n");
        scanf("%f",&f[0]);
        scanf("%f",&f[1]);
        scanf("%f",&f[2]);

        printf("Insira 3 numeros double\n");
        scanf("%lf",&d[0]);
        scanf("%lf",&d[1]);
        scanf("%lf",&d[2]);

        printf("        10        20        30        40        50\n");
        printf("12345678901234567890123456789012345678901234567890\n");

        printf("%5d %20d %23d\n",i[0],l[0],u[0]);
        printf("%17.01f %20.2f\n",f[0],d[0]);

        printf("%5d %20d %23d\n",i[1],l[1],u[1]);
        printf("%17.01f %20.2f\n",f[1],d[1]);

        printf("%5d %20d %23d\n",i[2],l[2],u[2]);
        printf("%17.01f %20.2f\n",f[2],d[2]);

                    printf("\nDeseja sair? (s/n)\n");
                    scanf("%c",&c);
                    c = getchar();
                    if(c=='s' || c=='S')
                    break;
         }
}

#endif

#ifdef ex2

main()
{

int vetor[10];
int i=0;
char c;

    for(;;){

        for(i=0;i<10;i++){
            printf("Insira o %d numero: ",i+1);
            scanf("%d",&vetor[i]);
        }
    if(vetor[0]==vetor[9] && vetor[1]==vetor[8] && vetor[2]==vetor[7] && vetor[3]==vetor[6] && vetor[4]==vetor[5])
        printf("O vetor e um palindromo!\n");

        else
            printf("O vetor nao e um palindromo!\n");

            printf("\nDeseja sair? (s/n)\n");
            scanf("%c",&c);
            c = getchar();
            if(c=='s' || c=='S')
                break;

    }

}

#endif

#ifdef ex3

main()
{

int A[2][3];
int B[2][3];
int C[2][3];
int linha, coluna;
char c;


    for(;;){

            for(linha=0;linha<2;linha++){
                for(coluna=0;coluna<3;coluna++){

            printf("Digite o numero da linha %d coluna %d vetor A: ",linha+1,coluna+1);
            scanf("%d",&A[linha][coluna]);

                }
            }

        printf("\n");

                for(linha=0;linha<2;linha++){
                    for(coluna=0;coluna<3;coluna++){

                printf("Digite o numero da linha %d coluna %d vetor B: ",linha+1,coluna+1);
                scanf("%d",&B[linha][coluna]);

                    }
                }

        printf("\n");

        for(linha=0;linha<2;linha++){
            for(coluna=0;coluna<3;coluna++){

            C[linha][coluna]=A[linha][coluna]*B[linha][coluna];

            printf("Linha %d coluna %d resulta em %d * %d = %d\n",linha+1,coluna+1,A[linha][coluna],B[linha][coluna],C[linha][coluna]);
            }
        }

        printf("\nIndice vetor A\n");
        printf("[%d] [%d]\n",A[0][0],A[1][0]);
        printf("[%d] [%d]\n",A[0][1],A[1][1]);
        printf("[%d] [%d]\n",A[0][2],A[1][2]);

        printf("\nIndice vetor B\n");
        printf("[%d] [%d]\n",B[0][0],B[1][0]);
        printf("[%d] [%d]\n",B[0][1],B[1][1]);
        printf("[%d] [%d]\n",B[0][2],B[1][2]);

        printf("\nIndice vetor C\n");
        printf("[%d] [%d]\n",C[0][0],C[1][0]);
        printf("[%d] [%d]\n",C[0][1],C[1][1]);
        printf("[%d] [%d]\n",C[0][2],C[1][2]);

            printf("\nDeseja sair? (s/n)\n");
            scanf("%c",&c);
            c = getchar();

            if(c == 's' || c == 'S')
                break;
    }
}

#endif

#ifdef ex4

main(){

int a,b,x,d,e;
int vetor[5][5];
int posicao[5][5];
int null=0;
char c;

    for(;;){
        for(a=0;a<5;a++){
            for(b=0;b<5;b++){
                printf("Insira um numero para %d %d: ",a+1,b+1);
                scanf("%d",&vetor[a][b]);
            }
        }
                printf("\nInsira um numero qualquer: ");
                scanf("%d",&x);
                printf("\n");

            for(a=0;a<5;a++){
                for(b=0;b<5;b++){
                    if(vetor[a][b]==x){
                        null=1;
                        d=a;
                        e=b;
                    }
                }
            }

        if(null==0)
            printf("O numero nao esta na matriz\n");

                else
                    printf("O numero esta na posicao %d %d\n",d+1,e+1);

        printf("\nDeseja sair? (s/n)\n");
        scanf("%c",&c);
        c = getchar();

        if(c == 's' || c == 'S')
            break;
    }
}

#endif

#ifdef ex5

main(){

int i, j, aux;
int vetor[10];
char c;

    for(;;){

        for(i=0;i<10;i++){
            printf("Digite o %d numero: ",i+1);
            scanf("%d",&vetor[i]);
        }

        for(i=0;i<10;i++){
            for(j=i;j<10;++j){
                if(vetor[i]>vetor[j]){

                    aux=vetor[i];
                    vetor[i]=vetor[j];
                    vetor[j]=aux;
                }
            }
        }

        for(i=0;i<10;i++){
        printf("%d ",vetor[i]);
        }

        printf("\n\nDeseja sair? (s/n)\n");
        scanf("%c",&c);
        c = getchar();

        if(c == 's' || c == 'S')
            break;
    }
}

#endif
