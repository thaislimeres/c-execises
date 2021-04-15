#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dados {
    char nome[30];
    char data_nasc[12];
    char estado_civil[15];
    float salario;
};

void inclui(struct dados *ps, int tam);
void lista(struct dados *ps, int tam);
int pesquisa(struct dados *ps, int tam);
void pesquisaEstCiv(struct dados *ps, int tam);
void pesquisaAniver(struct dados *ps, int tam);
void pesquisaSalario(struct dados *ps, int tam);
void alteraSalario(struct dados *ps, int tam);
void altera(struct dados *ps, int tam);
void exclui(struct dados *ps, int tam);

int main(){
struct dados info;
struct dados *p;
int op;
int i;
int tam;    //n. de bytes da estrutura

p = & info;
tam = sizeof(info);

    while(1){
    system("cls");
    printf("=======MENU=======\n\n");
    printf(" 1 -Incluir dados\n");
    printf(" 2 -Listar dados\n");
    printf(" 3 -Pesquisar dados por nome\n");
    printf(" 4 -Pesquisar dados por estado civil\n");
    printf(" 5 -Pesquisar dados por mes de nascimento\n");
    printf(" 6 -Pesquisar dados por faixa salarial\n");
    printf(" 7 -Alterar salario\n");
    printf(" 8 -Alterar dados\n");
    printf(" 9 -Excluir dados\n");
    printf("10 -Sair\n");
    printf("\nSelecione: ");
    scanf("%d", &op);
    getchar();

    switch(op){
        case 1 : inclui(p, tam);   //passa como parametro o ponteiro para a estrutura e o n. de bytes da desta
        break;

        case 2: lista(p, tam);
        break;

        case 3: pesquisa(p, tam);
        break;

        case 4: pesquisaEstCiv(p, tam);
        break;

        case 5: pesquisaAniver(p, tam);
        break;

        case 6: pesquisaSalario(p, tam);
        break;

        case 7: alteraSalario(p, tam);
        break;

        case 8: altera(p, tam);
        break;

        case 9: exclui(p, tam);
        break;

        case 10: exit(0);
        break;

        default: printf("\nOpcao invalida\n\n");
        system("pause");
        }
    };
}

void inclui(struct dados *ps, int tam){
FILE *p, *p1;
int cont = 0;
int i;

    system("cls");

    printf("=======INCLUIR=======\n\n");
    p1 = fopen("contador.txt", "r");
    fscanf(p1, "%d", &cont);
    //printf("Contador antes %d\n\n",cont);
    fclose(p1);

    //zera os dados da estrutura
    p = fopen("arquivo.txt", "a");

    if(p == NULL){
        printf("\nERRO");
        exit(1);
    }

   //aqui os dados sao recebidos via teclado
   	printf("Nome: ");
   	gets(ps->nome);
   	printf("Data de nascimento: ");
   	gets(ps->data_nasc);
    printf("Estado civil: ");
    gets(ps->estado_civil);

    do{
        printf("Salario: ");
        scanf("%f", &ps->salario);
        if(ps->salario < 0 || ps->salario > 100000){
            printf("\nDigite um valor entre 0 e 100.000\n");
        }
   	}while(ps -> salario < 0 || ps -> salario > 100000);

    fwrite(ps, tam, 1, p);
    fclose(p);

    cont++;

    p1 = fopen("contador.txt", "w");
    fprintf(p1,"%d",cont);
    //printf("\nContador depois %d\n\n",cont);
    fclose(p1);
    printf("\n");
    system("pause");
}

void lista(struct dados *ps, int tam){
FILE *p, *p1;
int i;
int cont,comp;
int achei=0;

    system("cls");

    printf("=======LISTA=======\n\n");
    p1 = fopen("contador.txt", "r");
    fscanf(p1,"%d",&cont);

    fclose(p1);

    p = fopen("arquivo.txt", "r"); /*r" --> Abre o arquivo apenas para leitura.*/

    if(p == NULL){
        puts("\nERRO\n");
        exit(1);
    }

    for(i=0; i < cont; i++){
        comp = i*tam;   //calcula o n. de bytes para posicionar o ponteiro do arquivo

	    fseek(p, comp, 0);    //posiciona o ponteiro no inicio do registro dentro do arquivo
	    fread(ps, tam, 1, p);   //le o registro
	    if(ps -> nome[0] != '*'){     //verifica se esta apagado
	    //imprimi registro na tela
	    	printf("Nome: %s\n", ps->nome);
	    	printf("Data de nascimento: %s\n", ps->data_nasc);
	    	printf("Estado civil: %s\n", ps->estado_civil);
	    	printf("Salario: %g\n\n", ps->salario);
	    	achei=1;
	    }
    }
    if(achei != 1){
        printf("Nenhum registro encontrado\n\n");
    }
        fclose(p);
        system("pause");
}

int pesquisa(struct dados *ps, int tam){
FILE *p;
FILE *p1;

char busca[30];
int i=0,y, x;
int cont;
int achei=0;

    system("cls");

    printf("=======BUSCA NOME=======\n\n");
    printf("Nome: ");
    gets(busca);

    p1 = fopen("contador.txt", "r");
    fscanf(p1,"%d",&cont);
    fclose(p1);
    //printf("\n%d registros\n",cont);

    p = fopen("arquivo.txt", "r");

    for(y=0;y<cont;y++){
        fread(ps,tam,1,p);
        for(x = 0; busca[x] != '\0';x++){
            if(busca[x] != ps -> nome[x]){
                break;
            }
        }

        if(busca[x] == '\0' && ps -> nome[x] == '\0'){
            //printf("\nN. do reg.: %d\n\n",y);
            printf("\nNome: %s\n", ps->nome);
            printf("Data de nascimento: %s\n", ps->data_nasc);
            printf("Estado civil: %s\n", ps->estado_civil);
            printf("Salario: %g\n\n", ps->salario);
            achei = 1;
            system("pause");
            return y;
        }
    }

    fclose(p);

    if(achei != 1){
        printf("\nNenhum registro encontrado\n\n");
        system("pause");
        return -1;
    }
}

void pesquisaEstCiv(struct dados *ps, int tam){
FILE *p;
FILE *p1;

char busca[15];
int i=0,y, x;
int cont;
int achei=0;

    system("cls");

    printf("====BUSCA ESTADO CIVIL====\n\n");
    printf("Estado civil: ");
    gets(busca);

    p1 = fopen("contador.txt", "r");
    fscanf(p1,"%d",&cont);
    fclose(p1);
    //printf("\n%d registros\n",cont);

    p = fopen("arquivo.txt", "r");

    for(y=0;y<cont;y++){
        fread(ps,tam,1,p);
        for(x = 0; busca[x] != '\0';x++){
            if(busca[x] != ps -> estado_civil[x]){
                break;
            }
        }

        if(busca[x] == '\0' && ps -> estado_civil[x] == '\0' && ps -> nome[0] != '*'){
            //printf("\nN. do reg.: %d\n\n",y);
            printf("\nNome: %s\n", ps->nome);
            printf("Data de nascimento: %s\n", ps->data_nasc);
            printf("Estado civil: %s\n", ps->estado_civil);
            printf("Salario: %g\n", ps->salario);
            achei=1;
        }
    }
    if(achei != 1){
        printf("\nNenhum registro encontrado\n");
    }
    printf("\n");
    system("pause");
}

void pesquisaAniver(struct dados *ps, int tam){
FILE *p;
FILE *p1;

char busca[3];
int i=0,y, x;
int cont;
int achei=0;

    system("cls");

    printf("====BUSCA ANIVERSARIO====\n\n");
    printf("Mes do ano: ");
    gets(busca);
    printf("\n");

    p1 = fopen("contador.txt", "r");
    fscanf(p1,"%d",&cont);
    fclose(p1);
    //printf("\n%d registros\n",cont);

    p = fopen("arquivo.txt", "r");

    for(y=0;y<cont;y++){
        fread(ps,tam,1,p);
        if(ps -> data_nasc[3] == busca[0] && ps -> data_nasc[4] == busca[1] && ps -> nome[0] != '*'){
            //printf("N. do reg.: %d\n\n",y);
            printf("Nome: %s\n", ps->nome);
            printf("Data de nascimento: %s\n", ps->data_nasc);
            printf("Estado civil: %s\n", ps->estado_civil);
            printf("Salario: %g\n\n", ps->salario);
            achei=1;
            }
    }
    fclose(p);
    if(achei != 1){
        printf("Nenhum registro encontrado\n\n");
    }
    system("pause");
}

void pesquisaSalario(struct dados *ps, int tam){
FILE *p;
FILE *p1;

float busca;
int i=0,y, x;
int cont;
int achei=0;

    system("cls");

    printf("====BUSCA SALARIO====\n\n");
    printf("Salario: ");
    scanf("%f",&busca);
    printf("\n");

    p1 = fopen("contador.txt", "r");
    fscanf(p1,"%d",&cont);
    fclose(p1);
    //printf("\n%d registros\n",cont);

    p = fopen("arquivo.txt", "r");

    for(y=0;y<cont;y++){
        fread(ps,tam,1,p);
        if(ps -> salario == busca && ps -> nome[0] != '*'){
                //printf("N. do reg.: %d\n\n",y);
                printf("Nome: %s\n", ps->nome);
                printf("Data de nascimento: %s\n", ps->data_nasc);
                printf("Estado civil: %s\n", ps->estado_civil);
                printf("Salario: %g\n\n", ps->salario);
                achei=1;
        }
    }
    fclose(p);
    if(achei != 1){
        printf("Nenhum registro encontrado\n\n");
    }
    system("pause");
}

void alteraSalario(struct dados *ps, int tam){

FILE *p;
int n_reg;
int n_bytes;

    n_reg = pesquisa(ps, tam);     //pesquisa o registro no arquivo

    if(n_reg != -1){
        system("cls");

        printf("=======ALTERA=======\n\n");

        //printf("Alterando reg n.: %d\n",n_reg);
        n_bytes = tam * n_reg;

        p = fopen("arquivo.txt", "r+");

        fseek(p,n_bytes,0);       //posioiona o ponteiro do arquivo no registro a ser alterado
        fread(ps, tam, 1, p);  //le registro do arquivo

        printf("Insira o novo salario\n\n");
        //recebe via teclado todos os dados do registro
        printf("Salario: ");
        scanf("%f", &ps->salario);

        fseek(p,n_bytes,0);    //posiciona o ponteiro do arquivo no inicio do regisro a ser alterado
        fwrite(ps, tam,1,p);  //escreve o registro no arquivo

        fclose(p);
        printf("\nRegistro alterado\n\n");
        system("pause");
    }
}

void altera(struct dados *ps, int tam){
FILE *p;
int n_reg;
int n_bytes;

    n_reg = pesquisa(ps, tam);     //pesquisa o registro no arquivo

    if(n_reg != -1){
        system("cls");

        printf("=======ALTERA=======\n\n");

        //printf("Alterando reg n.: %d\n",n_reg);
        n_bytes = tam * n_reg;

        p = fopen("arquivo.txt", "r+");

        fseek(p,n_bytes,0);       //posioiona o ponteiro do arquivo no registro a ser alterado
        fread(ps, tam, 1, p);  //le registro do arquivo

        printf("Insira os novos dados\n\n");
        //recebe via teclado todos os dados do registro
        printf("Nome: ");
        gets(ps->nome);
        printf("Data de nascimento: ");
        gets(ps->data_nasc);
        printf("Estado civil: ");
        gets(ps->estado_civil);
        printf("Salario: ");
        scanf("%f", &ps->salario);

        fseek(p,n_bytes,0);    //posiciona o ponteiro do arquivo no inicio do regisro a ser alterado
        fwrite(ps, tam,1,p);  //escreve o registro no arquivo

        printf("\nRegistro alterado\n\n");

        fclose(p);
        system("pause");
    }
}

void exclui(struct dados *ps, int tam){
FILE *p;
int n_reg;
int n_bytes;

    n_reg = pesquisa(ps, tam);  //pesquisa o registro no arquivo

    if(n_reg != -1){
        system("cls");

        printf("=======EXCLUI=======\n\n");

        p = fopen("arquivo.txt", "r+");
        n_bytes = tam * n_reg;

        fseek(p,n_bytes,0);       //posioiona o ponteiro do arquivo no registro a ser apagado
        fread(ps, tam, 1, p );   //le o registro do arquivo

        printf("Apagando: %s\n",ps -> nome);
        //apaga o registro do arquivo

        ps->nome[0]='*';

        getchar();

        fseek(p,n_bytes,0);  //posiciona o ponteiro do arquivo no inicio do regisro a ser apagado
        fwrite(ps,tam,1,p);  //escreve o registro

        printf("Registro apagado\n\n");

        fclose(p);

        system("pause");
    }
}
