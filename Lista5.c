#include <stdio.h>

#define ex1

#ifdef ex1

main(){

int a,b;
char c;

    for(;;){

        printf("Insira um numero inteiro: ");
        scanf("%d",&a);

        printf("Insira outro numero inteiro: ");
        scanf("%d",&b);

        printf("\nSoma %d + %d = %d\n",a,b,a+b);
        printf("Subtracao %d - %d = %d\n",a,b,a-b);
        printf("Multiplicacao %d * %d = %d\n",a,b,a*b);
        printf("Divisao %d / %d = %.2f\n",a,b,(float)a/b);

        printf("\nDeseja sair? (s/n)\n");
        scanf("%c",&c);
        c = getchar();

        if(c == 's' || c == 'S')
            break;
    }
}


#endif

#ifdef ex2

main(){

int a,b,aux;
char c;

    for(;;){

        printf("Insira um numero inteiro: ");
        scanf("%d",&a);
        aux=a;

        printf("Insira outro numero inteiro: ");
        scanf("%d",&b);

        printf("\nSoma %d += %d = %d\n",aux,b,a+=b);
        a=aux;
        printf("Subtracao %d -= %d = %d\n",aux,b,a-=b);
        a=aux;
        printf("Multiplicacao %d *= %d = %d\n",aux,b,a*=b);
        a=aux;
        printf("Divisao %d /= %d = %.2f\n",aux,b,(float)(a/=b));

        printf("\nDeseja sair? (s/n)\n");
        scanf("%c",&c);
        c = getchar();

        if(c == 's' || c == 'S')
            break;
    }
}

#endif

#ifdef ex3

main () {

int num1,num2;
char c;

    for(;;){

        printf("Digite um numero inteiro: ");
        scanf("%d",&num1);

        printf("Digite outro numero inteiro: ");
        scanf("%d",&num2);

        printf("\nAND\nDecimal: %d\nHexadecimal: %x\n",num1 & num2, num1 & num2);

        printf("\nOU\nDecimal: %d\nHexadecimal: %x\n",num1 | num2, num1 | num2);

        printf("\nOU EXCLUSIVO\nDecimal: %d\nHexacidemal: %x\n",num1 ^ num2, num1 ^ num2);

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

int num;
char c;

    for(;;){
            printf("Insira um numero inteiro: ");
            scanf("%d",&num);

            printf("Multiplicado por 8 = %d\n",num<<3);
            printf("Dividido por 8 = %d\n",num>>3);

        printf("\nDeseja sair? (s/n)\n");
        scanf("%c",&c);
        c = getchar();

        if(c == 's' || c == 'S')
            break;
    }
}

#endif

#ifdef ex5

main()

{

int anonasc,mesnasc,dianasc,anoat,mesat,diaat,anodif,mesdif,diadif,totaldias,totalmes,diames;
char c;

    for(;;){
            do{
                printf("Insira a sua data de nascimento\n");
                printf("Dia: ");
                scanf("%d",&dianasc);

                printf("Mes: ");
                scanf("%d",&mesnasc);

                printf("Ano: ");
                scanf("%d",&anonasc);

                printf("\nInsira o dia atual\n");
                printf("Dia: ");
                scanf("%d",&diaat);

                printf("Mes: ");
                scanf("%d",&mesat);

                printf("Ano: ");
                scanf("%d",&anoat);
                if(anonasc>anoat){
                    printf("\nA data de nascimento e maior que a data atual\n");
                    printf("Digite novos valores\n\n");
                }
            }while(anonasc>anoat);

            anodif=anoat-anonasc;

            mesdif=12-(mesnasc-mesat);
            if(mesdif>=12)
                mesdif=(mesdif-12);

            if(dianasc==diaat)
                diadif=0;
                else if (dianasc>diaat)
                    diadif=30-dianasc+diaat;

            if(mesnasc==mesat){
                    if(dianasc==diaat){
                            mesdif=0;
                    }
                        else if(dianasc>diaat){
                            anodif--;
                            mesdif=11;
                            diadif=dianasc;
                        }
                            else if(dianasc<diaat){
                                mesdif=0;
                                diadif=dianasc-diaat;
                            }
            }
                else if(mesnasc>mesat)
                    anodif--;

        printf("A sua idade e %d anos %d meses e %d dias\n",anodif,mesdif,diadif);

        printf("\nDeseja sair? (s/n)\n");
        scanf("%c",&c);
        c = getchar();

        if(c == 's' || c == 'S')
            break;
    }
}

#endif

#ifdef ex6

main()
{
int chavemeses[] = {1, 4, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6};
int maxdiasmes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char *diassemana[] = {"domingo", "segunda", "terca", "quarta", "quinta", "sexta", "sabado"};
int dia, mes, ano;
int bissexto = 0;
int chaveano = 0;
int chavemes = 0;
int diasemana = 0;
int soma = 0;
char c;

    for(;;){
                printf("Insira o ano: ");
                scanf("%d", &ano);

                printf("Digite o mes: ");
                scanf("%d", &mes);

                chavemes=chavemeses[mes-1];

            for(;;){
                printf("Digite o dia: ");
                scanf("%d", &dia);

                bissexto=0;

                if(mes==2&&ano%4==0&&(ano%400==0||ano%100!= 0))
                    bissexto=1;

                if (dia>= 1&&dia<=maxdiasmes[mes-1]+bissexto)
                    break;

                printf("Insira um dia entre 1 e %d\n",maxdiasmes[mes-1]+bissexto);
            }

            if (ano<2000){
                chaveano=((ano%100)/4+((ano%100)%7))%7;
            } else {
                ano-=100;
                chaveano=(((ano%100)/4)+((ano%100)%7))%7-1;
            }

            if(bissexto==1&&(mes==1||mes==2)){
                chaveano-=1;
            }
            soma=dia+chavemes+chaveano;

            int i;
            for(i=soma;i>=1;i--){
                if(i%7==0){
                    diasemana=soma-i==0?7:soma-i;
                    break;
                }
            }
            printf("O dia da semana e %s\n", diassemana[diasemana-1]);

            printf("\nDeseja sair? (s/n)\n");
            scanf("%c",&c);
            c = getchar();

            if(c == 's' || c == 'S')
                break;
    }
}

#endif
