#include <stdio.h>

#define ex1

#ifdef ex1

main(){

float i=0, num, soma=0;
char c;

    for(;;){

        do{
            printf("Insira um numero: ");
            scanf("%f",&num);
            if(num>0){
            soma+=num;
            i++;}
            }while(num>=0);

        printf("A media dos numeros positivos e %f\n\n",soma/i);

                printf("Deseja sair? (s/n)\n");
                scanf("%c",&c);
                c = getchar();
                if(c=='s' || c=='S')
                    break;
                        else
                            soma=0;
                            i=0;
    }
}

#endif

#ifdef ex2

main(){

int menor=1;
int maior=99;
int tentativa=0;
int i=0;
char simbolo;
char c;

    for(;;){

        printf("Pense em um numero entre %d e %d\n",menor,maior);

        do{
            tentativa = (maior-menor)/2+menor;
            i++;
            printf("%d e maior, menor ou igual ao numero que vc pensou?\n",tentativa);
            printf("Maior >\n");
            printf("Menor <\n");
            printf("Igual =\n");
            scanf("%c",&simbolo);
            simbolo == getchar();

            if (simbolo == '<'){
                menor = tentativa+1;
            }
                else if (simbolo == '>'){
                    maior = tentativa-1;
                }
                    else if (simbolo == '='){
                        printf("Acertei! Levou %d tentativas\n",i);
                    }

        }while(simbolo != '=');

            printf("Deseja sair? (s/n)\n");
            scanf("%c",&c);
            getchar();

            if(c == 's' || c == 'S'){
                break;
            }
                    else{
                        i = 0;
                        tentativa = 0;
                        menor = 1;
                        maior = 99;
                    }
    }
}

#endif

#ifdef ex3

main(){

int menor=1;
int maior=99;
int tentativa=0;
int i=0;
char simbolo;
char c;

    for(;;){

        printf("Pense em um numero entre %d e %d\n",menor,maior);

        do{
            tentativa = (maior-menor)/2+menor;
            i++;
            printf("%d e maior, menor ou igual ao numero que vc pensou?\n",tentativa);
            printf("Maior >\n");
            printf("Menor <\n");
            printf("Igual =\n");
            scanf("%c",&simbolo);
            simbolo == getchar();

            switch (simbolo){

                case '<' :
                    {
                    menor = tentativa+1;
                    break;
                    }

                case '>' :
                    {
                    maior = tentativa-1;
                    break;
                    }

                case '=' :
                    {
                    printf("Acertei! Levou %d tentativas\n",i);
                    break;
                    }
            }
        }while(simbolo != '=');


            printf("Deseja sair? (s/n)\n");
            scanf("%c",&c);
            getchar();

            if(c == 's' || c == 'S'){
                break;
            }
                    else{
                        i = 0;
                        tentativa = 0;
                        menor = 1;
                        maior = 99;
                    }
    }
}

#endif

#ifdef ex4

main()

{

int hi,mi,si,hf,mf,sf,h,m,s,ti,tf;
char c;

    for(;;){

        do{
            printf("Insira a hora de inicio: ");
            scanf("%d",&hi);
            if(hi<0 || hi>24)
                printf("Insira a hora de inicio: ");
        }while(hi<0 || hi>24);

        do{
            printf("Insira o minuto de inicio: ");
            scanf("%d",&mi);
            if(mi<0 || mi>59)
                printf("Insira o minuto de inicio: ");
        }while(mi<0 || mi>59);

        do{
            printf("Insira o segundo de inicio: ");
            scanf("%d",&si);
            if(si<0 || si>59)
                printf("Insira o segundo de inicio: ");
        }while(si<0 || si>59);

        hi = hi*3600;
        mi = mi*60;
        ti = hi+mi+si;

        do{
            printf("Insira a hora final: ");
            scanf("%d",&hf);
            if(hf<0 || hf>24)
                printf("Insira a hora final: ");
        }while(hf<0 || hf>24);

        do{
            printf("Insira o minuto final: ");
            scanf("%d",&mf);
            if(mf<0 || mf>59)
                printf("Insira o minuto final: ");
        }while(mf<0 || mf>59);

        do{
            printf("Insira o segundo final: ");
            scanf("%d",&sf);
            if(sf<0 || sf>59)
                printf("Insira o segundo final: ");
        }while(sf<0 || sf>59);

        hf = hf*3600;
        mf = mf*60;
        tf = hf+mf+sf;

        if(tf>tf)
            printf("A hora de inicio e posterior a hora final. Insira valores para ligacoes do mesmo dia\n");

            else{
                ti=tf-ti;
                h=ti/3600;
                s=ti%3600;
                m=s/60;
                s=s-(m*60);
            }

                            printf("A ligacao durou %dh %dm %ds\n",h,m,s);

        printf("\nDeseja sair? (s/n)\n");
        scanf("%c",&c);
        c=getchar();

        if(c == 's' || c == 'S')
            break;
    }
}

#endif

#ifdef ex5

main()

{

int hi,mi,si,hf,mf,sf,h,m,s,ti,tf;
char c;

    for(;;){

        do{
            printf("Insira a hora de inicio: ");
            scanf("%d",&hi);
            if(hi<0 || hi>24)
                printf("Insira a hora de inicio: ");
        }while(hi<0 || hi>24);

        do{
            printf("Insira o minuto de inicio: ");
            scanf("%d",&mi);
            if(mi<0 || mi>59)
                printf("Insira o minuto de inicio: ");
        }while(mi<0 || mi>59);

        do{
            printf("Insira o segundo de inicio: ");
            scanf("%d",&si);
            if(si<0 || si>59)
                printf("Insira o segundo de inicio: ");
        }while(si<0 || si>59);

        hi = hi*3600;
        mi = mi*60;
        ti = hi+mi+si;

        do{
            printf("Insira a hora final: ");
            scanf("%d",&hf);
            if(hf<0 || hf>24)
                printf("Insira a hora final: ");
        }while(hf<0 || hf>24);

        do{
            printf("Insira o minuto final: ");
            scanf("%d",&mf);
            if(mf<0 || mf>59)
                printf("Insira o minuto final: ");
        }while(mf<0 || mf>59);

        do{
            printf("Insira o segundo final: ");
            scanf("%d",&sf);
            if(sf<0 || sf>59)
                printf("Insira o segundo final: ");
        }while(sf<0 || sf>59);

        hf = hf*3600;
        mf = mf*60;
        tf = hf+mf+sf;

        if(tf>tf)
            printf("A hora de inicio e posterior a hora final. Insira valores para ligacoes do mesmo dia\n");

            else{
                ti=tf-ti;
                h=ti/3600;
                s=ti%3600;
                m=s/60;
                s=s-(m*60);
            }

                            printf("A ligacao durou %dh %dm %ds\n",h,m,s);

        printf("\nDeseja sair? (s/n)\n");
        scanf("%c",&c);
        c=getchar();

        if(c == 's' || c == 'S')
            break;
    }
}

#endif
