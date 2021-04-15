#include <stdio.h>

#define ex1

#ifdef ex1

main(){

char nome1[8];
char nome2[8];
char nome3[8];
char nome4[8];
char nome5[8];
char c;

    for(;;){
        printf("Digite o 1 nome: ");
        scanf("%s",&nome1);
        printf("Digite o 2 nome: ");
        scanf("%s",&nome2);
        printf("Digite o 3 nome: ");
        scanf("%s",&nome3);
        printf("Digite o 4 nome: ");
        scanf("%s",&nome4);
        printf("Digite o 5 nome: ");
        scanf("%s",&nome5);

        printf("        10        20        30        40        50\n");
        printf("12345678901234567890123456789012345678901234567890\n");
        printf("%7s %39s\n",nome1,nome5);
        printf("%17s %19s\n",nome2,nome4);
        printf("%27s\n",nome3);

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

char palavra1[3][3][3];
char palavra2[3][3][3];
char palavra3[3][3][3];
char c;

    for(;;){

        printf("Digite uma palavra: ");
        scanf("%s",&palavra1);
        printf("Digite uma palavra: ");
        scanf("%s",&palavra2);
        printf("Digite uma palavra: ");
        scanf("%s",&palavra3);


        printf("        10        20        30        40        50        60\n");
        printf("123456789012345678901234567890123456789012345678901234567890\n");
        printf("    string1             string2             string3\n");
        printf("%11s %19s %19s",palavra1,palavra2,palavra3);

        printf("\n\nDeseja sair? (s/n)\n");
        scanf("%c",&c);
        c = getchar();

        if(c == 's' || c == 'S')
            break;
    }
}

#endif

#ifdef ex3

main(){

char str1[10];
char str2[10];
char c;
int i;

    for(;;){

        printf("Insira uma string: ");
        scanf("%s",&str1);

        printf("Insira outra string: ");
        scanf("%s",&str2);

        for(i=0;i<10;i++){

            if(str1[i] == str2[i]){
                printf("As strings sao iguais\n");
                break;
            }
            else{
                printf("As strings sao diferentes\n");
                break;
            }
        }

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

char str[10];
char c;
int i;

    for(;;){
        printf("Insira uma string: ");
        scanf("%s",&str);

        for(i=0;i<10;i++){
            if(str[i]=='a')
                str[i]='A';
            if(str[i]=='b')
                str[i]='B';
            if(str[i]=='c')
                str[i]='C';
            if(str[i]=='d')
                str[i]='D';
            if(str[i]=='e')
                str[i]='E';
            if(str[i]=='f')
                str[i]='F';
            if(str[i]=='g')
                str[i]='G';
            if(str[i]=='h')
                str[i]='H';
            if(str[i]=='i')
                str[i]='I';
            if(str[i]=='j')
                str[i]='J';
            if(str[i]=='k')
                str[i]='K';
            if(str[i]=='l')
                str[i]='L';
            if(str[i]=='m')
                str[i]='M';
            if(str[i]=='n')
                str[i]='N';
            if(str[i]=='o')
                str[i]='O';
            if(str[i]=='p')
                str[i]='P';
             if(str[i]=='q')
                str[i]='Q';
            if(str[i]=='r')
                str[i]='R';
             if(str[i]=='s')
                str[i]='S';
            if(str[i]=='t')
                str[i]='T';
            if(str[i]=='u')
                str[i]='U';
            if(str[i]=='v')
                str[i]='V';
            if(str[i]=='x')
                str[i]='X';
            if(str[i]=='y')
                str[i]='Y';
            if(str[i]=='w')
                str[i]='W';
            if(str[i]=='z')
                str[i]='Z';
        }

        printf("\n%s",str);

        printf("\n\nDeseja sair? (s/n)\n");
        scanf("%c",&c);
        c = getchar();

        if(c == 's' || c == 'S')
            break;
    }

}

#endif

#ifdef ex5

main(){

char str[10];
char c;
int i;

    for(;;){
        printf("Insira uma string: ");
        scanf("%s",&str);

        for(i=0;i<10;i++){
            if(str[i]=='A')
                str[i]='a';
            if(str[i]=='B')
                str[i]='b';
            if(str[i]=='C')
                str[i]='c';
            if(str[i]=='D')
                str[i]='d';
            if(str[i]=='E')
                str[i]='e';
            if(str[i]=='F')
                str[i]='f';
            if(str[i]=='G')
                str[i]='g';
            if(str[i]=='H')
                str[i]='h';
            if(str[i]=='I')
                str[i]='i';
            if(str[i]=='J')
                str[i]='j';
            if(str[i]=='K')
                str[i]='k';
            if(str[i]=='L')
                str[i]='l';
            if(str[i]=='M')
                str[i]='m';
            if(str[i]=='N')
                str[i]='n';
            if(str[i]=='O')
                str[i]='o';
            if(str[i]=='P')
                str[i]='p';
             if(str[i]=='Q')
                str[i]='q';
            if(str[i]=='R')
                str[i]='r';
             if(str[i]=='S')
                str[i]='s';
            if(str[i]=='T')
                str[i]='t';
            if(str[i]=='U')
                str[i]='u';
            if(str[i]=='V')
                str[i]='v';
            if(str[i]=='X')
                str[i]='x';
            if(str[i]=='Y')
                str[i]='y';
            if(str[i]=='W')
                str[i]='w';
            if(str[i]=='Z')
                str[i]='z';
        }

        printf("\n%s",str);

        printf("\n\nDeseja sair? (s/n)\n");
        scanf("%c",&c);
        c = getchar();

        if(c == 's' || c == 'S')
            break;
    }

}

#endif
