#include <stdio.h>

#define ex1

#ifdef ex1

main()

{
short s;
long l;
int i;
float f;
double d;
char c, ch;

    for(;;){

        printf("Digite um valor do tipo short: ");
        scanf("%d",&s);

        printf("Digite um valor do tipo long: ");
        scanf("%ld",&l);

        printf("Digite um valor do tipo int: ");
        scanf("%d",&i);

        printf("Digite um valor do tipo float: ");
        scanf("%f",&f);

        printf("Digite um valor do tipo double: ");
        scanf("%lf",&d);

        printf("Digite um valor do tipo char: ");
        scanf("%c",&c);
        c = getchar();

            printf("        10        20        30        40        50        60\n");
            printf("12345678901234567890123456789012345678901234567890123456789012345\n");

                printf("%9d %18d %18d\n",s,l,i);
                printf("%19.2f %21.0lf %16c\n",f,d,c);

        printf("\nDeseja sair? (s/n)\n");
        scanf("%c",&ch);
        ch = getchar();
        if(ch=='s' || ch=='S')
            break;
    }

}

#endif

#ifdef ex2

main()

{
int a,b;
char c;

    for(;;){

        printf("Insira o valor de a: ");
        scanf("%d",&a);

        printf("Insira o valor de b: ");
        scanf("%d",&b);

        a=a+b;
        b=a-b;
        a=a-b;

        printf("O valor de a e %d e o valor de b e %d\n",a,b);

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

int tempo;
int hora;
int minuto;
int segundo;
char c;

    for(;;){

        printf("Insira um tempo em segundos: ");
        scanf("%d",&tempo);

        hora = tempo/3600;

        minuto = (tempo-(hora*3600))/60;

        segundo = tempo-(hora*3600+minuto*60);
        printf("O tempo e %dh %dmin %ds\n",hora,minuto,segundo);

            printf("\nDeseja sair? (s/n)\n");
            scanf("%c",&c);
            c = getchar();
            if(c=='s' || c=='S')
                break;
    }
}

#endif

#ifdef ex4

main(){

int a,a1,a2,a3;
char c;

    for(;;){

        do{
            printf("Insira um numero de 3 digitos: ");
            scanf("%d",&a);
        }while(a<100 || a>999);

        a1=a/100;
        a2=(a-a1*100)/10;
        a3=a-(a1*100+a2*10);

        printf("%d%d%d\n",a3,a2,a1);

            printf("\nDeseja sair? (s/n)\n");
            scanf("%c",&c);
            c = getchar();
            if(c=='s' || c=='S')
                break;
        }
}


#endif

#ifdef ex5

main()

{

int valor, num100=0, num50=0, num10=0, num1=0;
char c;

    for(;;){

        printf("Escreva um valor em reais: ");
        scanf("%d",&valor);

        if(valor>=100){
        num100=valor/100;
        num50=(valor-num100*100)/50;
        num10=(valor-(num100*100+num50*50))/10;
        num1=valor-(num100*100+num50*50+num10*10);}

        if(valor>=50 && valor<100){
        num100=valor/100;
        num50=(valor-num100*100)/50;
        num10=(valor-(num100*100+num50*50))/10;
        num1=valor-(num100*100+num50*50+num10*10);}

        if(valor>=10 && valor<50){
        num100=valor/100;
        num50=(valor-num100*100)/50;
        num10=(valor-(num100*100+num50*50))/10;
        num1=valor-(num100*100+num50*50+num10*10);}

        if(valor>1 && valor<10){
        num100=valor/100;
        num50=(valor-num100*100)/50;
        num10=(valor-(num100*100+num50*50))/10;
        num1=valor-(num100*100+num50*50+num10*10);}

        printf("\nO valor pode ser dividido em\n");
        printf("%d notas de 100\n",num100);
        printf("%d notas de 50\n",num50);
        printf("%d notas de 10\n",num10);
        printf("%d notas de 1\n",num1);

            printf("\nDeseja sair? (s/n)\n");
            scanf("%c",&c);
            c = getchar();
            if(c=='s' || c=='S')
                break;
    }
}


#endif
