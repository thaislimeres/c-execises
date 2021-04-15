#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ex1

#ifdef ex1

/*
1 - Faça um programa para:
    1 - criar/abrir um arquivo texto de nome ”arq.txt”,
    2 - receba via teclado diversos caracteres (um por vezes)e armazene nesse
        arquivo. O caracter '0' finaliza a entrada de dados.
    3 - abra o arquivo. Leia e imprima na tela todos os caracteres armazenados.
*/

main(){

FILE *p;

int fim=0;

    do{

        char letra=1;

            // cria o arquivo arq.txt

            if((p = fopen("arq.txt","w"))==NULL){
                printf("Erro na abertura do arquivo\n");
                exit(0);
            }

            // recebe caracteres

            printf("Insira caracteres\n");
            while(letra!='0'){
                scanf("%c",&letra);
                if(letra!='0'){
                   putc(letra,p);
                }
            }
            fclose(p); // fecha o arquivo

            if((p = fopen("arq.txt","r"))==NULL){ // abre arquivo novamente
                printf("Erro na abertura do arquivo\n");
                exit(0);
            }

            // mostra os caracteres digitados

            while(1){
                letra = getc(p);
                if(letra != EOF){
                    putchar(letra);
                } else{
                    break;
                }
            }

            fclose(p); // fecha o arquivo

        do{
            printf("\n\nDeseja sair? (1-sim / 0-nao)\n");
            scanf("%d",&fim);
            getchar();
        }while(fim!=0 && fim!=1);

	}while(fim!=1);
}

#endif // ex1

#ifdef ex2

/*
2 - Faça um programa para gerenciar uma agenda de contatos. Para cada contato
    armazene o nome, o telefone e o aniversário (dia e mês). O programa deve ter
    as opções:
    1 - inserir contato,
    2 - remover contato,
    3 - pesquisar um contato pelo nome,
    4 - listar todos os contatos,
    5 - listar os contatos cujo nome inicia com uma dada letra,
    6 - imprimir os aniversariantes do mês.
    Sempre que o programa for encerrado, os contatos devem ser escritos no arquivo.
    Quando o programa iniciar os contatos devem ser lidos do arquivo.
*/

struct cadastro{
    char nome[50];
    char tel[15];
    int dia;
    int mes;
};

void insere(struct cadastro *dados, int tam);
void exclui(struct cadastro *dados, int tam);
void pesquisa(struct cadastro *dados, int tam);
void lista(struct cadastro *dados, int tam);
void listaletra(struct cadastro *dados, int tam);
void aniversario(struct cadastro *dados, int tam);

main(){

FILE *arquivo;
int tam;
int esc;
struct cadastro dados[2];
struct cadastro *p;
p = &dados;
tam = sizeof(dados);

    if((arquivo = fopen("cadastro.txt","w"))==NULL){
        printf("Erro na abertura do arquivo\n\n");
        exit(0);
    }

    fread(dados, tam, 1, arquivo);

    fclose(arquivo);

    for(;;){

        system("cls");

        printf(" 1- Inserir contato\n");
        printf(" 2- Remover contato\n");
        printf(" 3- Pesquisar um contato pelo nome\n");
        printf(" 4- Listar todos os contatos\n");
        printf(" 5- Listar todos os contatos cujo nome inicia com a letra\n");
        printf(" 6- Imprimir os aniversariantes do mes\n");
        printf(" 7- Sair\n");
        printf("\nSelecione: ");
        scanf("%d",&esc);
        printf("\n");
        getchar();

        switch(esc){

            case 1: insere(p, tam);
            break;

            case 2: exclui(p, tam);
            break;

            case 3: pesquisa(p, tam);
            break;

            case 4: lista(p, tam);
            break;

            case 5: listaletra(p, tam);
            break;

            case 6: aniversario(p, tam);
            break;

            case 7:
            if((arquivo = fopen("cadastro.txt","w"))==NULL){
                printf("Erro na abertura do arquivo\n\n");
                exit(0);
            }

            fwrite(dados, tam, 1, arquivo);

            fclose(arquivo);

            exit(0);
            break;

            default: printf("\nOpcao invalida\n");
        }
    }
}

void insere(struct cadastro *dados, int tam){

int i;

    for(i=0;i<2;i++){

        printf("Nome: ");
        scanf("%s",(dados+i)->nome);
        printf("Telefone: ");
        scanf("%s",(dados+i)->tel);
        printf("Dia nascimento: ");
        scanf("%d",&(dados+i)->dia);
        printf("Mes nascimento: ");
        scanf("%d",&(dados+i)->mes);
        printf("\n");
    }

    system("pause");
}

void exclui(struct cadastro *dados, int tam){

int i;
int j;
int achei=0;
char busca[50];

    printf("Insira o nome: ");
    scanf("%s",&busca);
    printf("\n");

    for(i=0;i<2;i++){

        for(j=0;(dados+i)->nome[j] != '\0';j++){

            if((dados+i)->nome[j] == busca[j] && (dados+i) != '*'){

                (dados+i)->nome[0]='*';
                achei=1;
                printf("\nRegistro excluido\n\n");
                break;
            }
        }
    }

    if(achei!=1){
        printf("\nNenhum registro encontrado\n\n");
    }

    system("pause");
}

void pesquisa(struct cadastro *dados, int tam){

int i;
int j;
char busca[50];
int achei;

    printf("Insira o nome: ");
    scanf("%s",&busca);
    printf("\n");

    for(i=0;i<2;i++){

        for(j=0;busca[j] != '\0';j++){
            if(busca[j] != dados[i].nome[j]){
                break;
            }
        }
        if(busca[j] == '\0' && dados[i].nome[j] ==  '\0' && dados[i].nome[0] != '*'){
            printf("Nome: %s\n",dados[i].nome);
            printf("Telefone: %s\n",dados[i].tel);
            printf("Nascimento: %d/%d\n\n",dados[i].dia,dados[i].mes);
            achei=1;
            system("pause");
            break;
        }
    }

    if(achei!=1){

        printf("\nNenhum registro encontrado\n\n");
        system("pause");
    }
}

void lista(struct cadastro *dados, int tam){

int i;
int achei=0;

    for(i=0;i<2;i++){

        if((dados+i)->nome[0] != '*'){

            printf("Nome: %s\n",(dados+i)->nome);
            printf("Telefone: %s\n",(dados+i)->tel);
            printf("Nascimento: %d/%d\n",(dados+i)->dia,(dados+i)->mes);
            printf("\n");
            achei=1;
        }
    }
        if(achei!=1){

        printf("\nNenhum registro encontrado\n\n");
    }

    system("pause");
}

void listaletra(struct cadastro *dados, int tam){

char letra;
int achei=0;
int i;

    printf("Insira uma letra inicial: ");
    scanf("%c",&letra);

    for(i=0;i<2;i++){

        if((dados+i)->nome[0] == letra && ((dados+i)->nome[0] != '*')){

            printf("\nNome: %s\n",(dados+i)->nome);
            printf("Telefone: %s\n",(dados+i)->tel);
            printf("Nascimento: %d/%d\n\n",(dados+i)->dia,(dados+i)->mes);
            achei=1;
        }
    }

    if(achei!=1){

        printf("\nNenhum registro encontrado\n\n");
    }

    system("pause");
}

void aniversario(struct cadastro *dados, int tam){

int i;
int j;
int mes;
int achei=0;

    printf("Insira um mes: ");
    scanf("%d",&mes);
    printf("\n");

    for(i=0;i<2;i++){

        if(dados[i].mes == mes && (dados+i) != '*'){

                printf("Nome: %s\n",dados[i].nome);
                printf("Telefone: %s\n",dados[i].tel);
                printf("Nascimento: %d/%d\n",dados[i].dia,dados[i].mes);
                printf("\n");
                achei=1;
        }
    }

    if(achei!=1){

        printf("\nNenhum registro encontrado\n\n");
    }

    system("pause");
}

#endif // ex2

#ifdef ex3

/*
3 - Implemente um controle simples de mercadorias em uma despensa doméstica.
    Cada produto será armazenado um código numérico, descrição e quantidade atual.
    O programa deve ter as opções:
    1 - entrada de produtos
    2 - retirada de produtos
    3 - pesquisar uma mercadoria pela descrição
    4 - listar todos os produtos
    5 - listar os produtos não disponíveis.
    Escreva os itens das mercadorias direto no arquivo. (utilize a funcao fseek).
*/

struct estoque{
    int cod;
    char nome[30];
    int saldo;
};

void inserir(struct estoque *produtos, int tam);
void retirar(struct estoque *produtos, int tam);
int pesquisar(struct estoque *produtos, int tam);
void listartodos(struct estoque *produtos, int tam);
void listarnaodisp(struct estoque *produtos, int tam);

main(){

struct estoque produtos;
struct estoque *p;
int opc;
int tam;

p=&produtos;
tam=sizeof(produtos);

    for(;;){
        system("cls");

        printf(" 1- Inserir produto\n");
        printf(" 2- Inserir retirada\n");
        printf(" 3- Pesquisar mercadoria pela descricao\n");
        printf(" 4- Listar todos os produtos\n");
        printf(" 5- Listar produtos nao disponiveis\n");
        printf(" 6- Sair\n");
        printf("\nSelecione: ");

        scanf("%d",&opc);
        printf("\n");
        getchar();

        switch(opc){
            case 1: inserir(p, tam);
            break;

            case 2: retirar(p, tam);
            break;

            case 3: pesquisar(p, tam);
            break;

            case 4: listartodos(p, tam);
            break;

            case 5: listarnaodisp(p, tam);
            break;

            case 6: exit(0);
            break;

            default: printf("\nOpcao invalida\n\n");
            system("pause");
        }
    }
}

void inserir(struct estoque *produtos, int tam){

FILE *p, *pcont;
int cont=0;

    pcont = fopen("contador.txt", "r");
    fscanf(pcont, "%d", &cont);
    printf("Contador antes %d\n\n",cont);
    fclose(pcont);

    //zera os dados da estrutura

    p = fopen("controle.txt", "a");

    if(p == NULL){
        printf("\nERRO");
        exit(1);
    }

    printf("Codigo do produto: ");
    scanf("%d",&produtos->cod);
    getchar();
    printf("Descricao: ");
    scanf("%s",&produtos->nome);
    printf("Saldo: ");
    scanf("%d",&produtos->saldo);

    fwrite(produtos, tam, 1, p);
    fclose(p);

    cont++;

    pcont = fopen("contador.txt", "w");
    fprintf(pcont,"%d",cont);
    printf("\nContador depois %d\n\n",cont);
    fclose(pcont);

    system("pause");
}

void retirar(struct estoque *produtos, int tam){

FILE *p;

int n_reg;
int n_bytes;
int retirada;

    n_reg = pesquisar(produtos, tam);     //pesquisa o registro no arquivo

    if(n_reg != -1){

        n_bytes = tam * n_reg;

        if((p = fopen("controle.txt","r+"))==NULL){
                printf("Erro na abertura do arquivo\n\n");
                exit(0);
        }

        fseek(p,n_bytes,0);    //posioiona o ponteiro do arquivo no registro a ser alterado
        fread(produtos, tam, 1, p);  //le registro do arquivo

        printf("\nInserir quantidade da retirada: ");
        scanf("%d",&retirada);

        fscanf(p,"%d",&produtos -> saldo);

        produtos -> saldo = produtos -> saldo - retirada;

        fseek(p,n_bytes,0);
        fwrite(produtos, tam, 1, p);

        printf("\nSaldo ajustado\n\n");

        fclose(p);
        system("pause");
    }
}

int pesquisar(struct estoque *produtos, int tam){

FILE *p, *pcont;

char busca[30];
int achei=0;
int cont;
int x,y;

    printf("Insira o nome: ");
    gets(busca);

    pcont = fopen("contador.txt", "r");
    fscanf(pcont,"%d",&cont);
    fclose(pcont);

    p = fopen("controle.txt", "r");

    for(y=0;y<cont;y++){
        fread(produtos, tam, 1, p);
        for(x = 0; busca[x] != '\0';x++){
            if(busca[x] != produtos -> nome[x]){
                break;
            }
        }

        if(busca[x] == '\0' && produtos -> nome[x] == '\0'){
            //printf("\nN. do reg.: %d\n\n",y);
            printf("\nCodigo: %d\n", produtos->cod);
            printf("Nome: %s\n", produtos->nome);
            printf("Saldo: %d\n\n", produtos->saldo);
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

void listartodos(struct estoque *produtos, int tam){

FILE *p, *pcont;
int cont;
int i;
int comp;
int achei=0;

    pcont = fopen("contador.txt", "r");
    fscanf(pcont,"%d",&cont);

    fclose(pcont);

    if((p = fopen("controle.txt","r"))==NULL){
        printf("Erro na abertura do arquivo\n");
        exit(0);
    }

    for(i=0; i < cont; i++){
        comp = i*tam;   //calcula o n. de bytes para posicionar o ponteiro do arquivo

	    fseek(p, comp, 0);    //posiciona o ponteiro no inicio do registro dentro do arquivo
	    fread(produtos, tam, 1, p);   //le o registro
	    if(produtos -> nome[0] != '*'){     //verifica se esta apagado
	    //imprimi registro na tela
	    	printf("Codigo: %d\n", produtos->cod);
	    	printf("Descricao: %s\n", produtos->nome);
	    	printf("Saldo: %d\n\n", produtos->saldo);
	    	achei=1;
	    }
    }
    if(achei != 1){
        printf("Nenhum registro encontrado\n\n");
    }

    fclose(p);
    system("pause");

}

void listarnaodisp(struct estoque *produtos, int tam){

FILE *p, *pcont;
int cont;
int i;
int comp;
int achei=0;

    pcont = fopen("contador.txt", "r");
    fscanf(pcont,"%d",&cont);

    fclose(pcont);

    if((p = fopen("controle.txt","r"))==NULL){
        printf("Erro na abertura do arquivo\n");
        exit(0);
    }

    for(i=0; i < cont; i++){
        comp = i*tam;   //calcula o n. de bytes para posicionar o ponteiro do arquivo

	    fseek(p, comp, 0);    //posiciona o ponteiro no inicio do registro dentro do arquivo
	    fread(produtos, tam, 1, p);   //le o registro
	    if(produtos -> saldo <= 0 && produtos -> nome[0] != '*'){     //verifica se esta apagado
	    //imprimi registro na tela
	    	printf("Codigo: %d\n", produtos->cod);
	    	printf("Descricao: %s\n", produtos->nome);
	    	printf("Saldo: %d\n\n", produtos->saldo);
	    	achei=1;
	    }
    }
    if(achei != 1){
        printf("Nenhum registro encontrado\n\n");
    }

    fclose(p);

    system("pause");
}

#endif // ex3

#ifdef ex4

/*
4 - A partir do exercico 6 do capitulo de funcoes, retire o vetor de estrutura e
    escreva e leia os registros direto no arquivo. (utilize a funcao fseek).
*/

/*
                       EXERCICIO 5 E 6 DA LISTA 9
5 - Escreva um programa com a estrutura abaixo. Defina um vetor de estruturas
    de 4 elementos.Receba os 4 registros sequencialmente pelo teclado numa
    função e imprima todos os registros no video em outra função. Faça um menu.
    Coloque no menu a opção de sair também. Utilize o comando switch.
    (vetor de estruturas)
                nome, end, cidade, estado, cep

6 - Acrescente ao menu do exercicio anterior as funcoes de procura, altera e
    exclui um registro.
*/

FILE *p;


struct cadastro {
    char nome[50];
    char end[50];
    char cidade[20];
    char estado[15];
    char cep[10];
};

void recebe(struct cadastro *dados, int tam);
void imprime(struct cadastro *dados, int tam);
int procura(struct cadastro *dados, int tam);
void altera(struct cadastro *dados, int tam);
void exclui(struct cadastro *dados, int tam);

main(){

struct cadastro dados;
struct cadastro *pdados;
int i;
int opc;
int tam;    //n. de bytes da estrutura

pdados=&dados;
tam = sizeof(dados);

    for(;;){
        system("cls");
        printf("1-Cadastrar\n");
        printf("2-Imprimir\n");
        printf("3-Procurar\n");
        printf("4-Alterar\n");
        printf("5-Excluir\n");
        printf("6-Sair\n\n");
        printf("Selecione: ");

        scanf("%d",&opc);
        getchar();

        switch(opc){

            case 1: recebe(pdados, tam);
            break;

            case 2: imprime(pdados, tam);
            break;

            case 3: procura(pdados, tam);
            break;

            case 4: altera(pdados, tam);
            break;

            case 5: exclui(pdados, tam);
            break;

            case 6: exit(0);
            break;

            default: printf("\nOpcao invalida\n\n");
            system("pause");
        }
    }
}

void recebe(struct cadastro *dados, int tam){

FILE *p, *pcont;
int cont=0;

    pcont = fopen("contador.txt", "r");
    fscanf(pcont, "%d", &cont);
    //printf("Contador antes %d\n\n",cont);
    fclose(pcont);

    if((p = fopen("cadastro.txt","a"))==NULL){
            printf("Erro na abertura do arquivo\n\n");
            exit(0);
    }

    //aqui os dados sao recebidos via teclado

    printf("\nNome: ");
    gets(dados->nome);
    printf("Endereco: ");
    gets(dados->end);
    printf("Cidade: ");
    gets(dados->cidade);
    printf("Estado: ");
    gets(dados->estado);
    printf("CEP: ");
    gets(dados->cep);

    fwrite(dados, tam, 1, p);
    fclose(p);

    cont++;

    pcont = fopen("contador.txt", "w");
    fprintf(pcont,"%d",cont);
    //printf("\nContador depois %d\n\n",cont);
    fclose(pcont);
    printf("\n");
    system("pause");
}

void imprime(struct cadastro *dados, int tam){
FILE *p, *pcont;
int i;
int cont;
int comp;
int achei=0;

    pcont = fopen("contador.txt", "r");
    fscanf(pcont,"%d",&cont);

    fclose(pcont);

    if((p = fopen("cadastro.txt","r"))==NULL){
            printf("Erro na abertura do arquivo\n\n");
            exit(0);
    }

    for(i=0;i<cont;i++){
        comp = i*tam;

        fseek(p, comp, 0);
        fread(dados, tam, 1, p);
        if(dados -> nome[0] != '*'){
            printf("\nNome: %s\n",dados->nome);
            printf("Endereco: %s\n",dados->end);
            printf("Cidade: %s\n",dados->cidade);
            printf("Estado: %s\n",dados->estado);
            printf("CEP: %s\n",dados->cep);
            achei=1;
        }
    }
    if(achei != 1){
        printf("\nNenhum registro encontrado\n\n");
    }

    fclose(p);
    printf("\n");
    system("pause");
}

int procura(struct cadastro *dados, int tam){
FILE *p, *pcont;
char busca[50];
int i;
int j;
int cont;
int achei=0;

    printf("\nInsira o nome: ");
    gets(busca);

    pcont = fopen("contador.txt", "r");
    fscanf(pcont,"%d",&cont);
    fclose(pcont);

    if((p = fopen("cadastro.txt","r"))==NULL){
            printf("Erro na abertura do arquivo\n\n");
            exit(0);
    }

    for(i=0;i<cont;i++){
        fread(dados, tam, 1, p);
        for(j=0;busca[j] != '\0';j++){
            if(busca[j] != dados -> nome[j]){
                break;
            }
        }

        if(busca[j] == '\0' && dados->nome[j] == '\0'){
            printf("\nNome: %s\n",dados->nome);
            printf("Endereco: %s\n",dados->end);
            printf("Cidade: %s\n",dados->cidade);
            printf("Estado: %s\n",dados->estado);
            printf("CEP: %s\n\n",dados->cep);
            achei = 1;
            system("pause");
            return i;
        }
    }

    fclose(p);

    if(achei != 1){
        printf("\nNenhum registro encontrado\n\n");
        system("pause");
        return -1;
    }
}

void altera(struct cadastro *dados, int tam){
FILE *p;
int n_reg;
int n_bytes;

    n_reg = procura(dados, tam);

    if(n_reg != -1){

        n_bytes = tam * n_reg;

        p = fopen("cadastro.txt","r+");

        fseek(p, n_bytes, 0);
        fread(dados, tam, 1, p);

        printf("\nInsira os novos dados\n\n");
        //recebe via teclado todos os dados do registro
        printf("Nome: ");
        gets(dados->nome);
        printf("Endereco: ");
        gets(dados->end);
        printf("Cidade: ");
        gets(dados->cidade);
        printf("Estado: ");
        gets(dados->estado);
        printf("CEP: ");
        gets(dados->cep);

        fseek(p, n_bytes, 0);   //posiciona o ponteiro do arquivo no inicio do regisro a ser alterado
        fwrite(dados, tam, 1, p);  //escreve o registro no arquivo

        printf("\nRegistro alterado\n\n");

        fclose(p);
        system("pause");
    }
}

void exclui(struct cadastro *dados, int tam){
FILE *p;
int n_reg;
int n_bytes;

    n_reg = procura(dados, tam);  //pesquisa o registro no arquivo

    if(n_reg != -1){

        n_bytes = tam * n_reg;

        p = fopen("cadastro.txt","r+");

        fseek(p, n_bytes ,0);
        fread(dados, tam, 1, p);

        dados->nome[0]='*';

        fseek(p, n_bytes, 0);   //posiciona o ponteiro do arquivo no inicio do regisro a ser alterado
        fwrite(dados, tam, 1, p);  //escreve o registro no arquivo

        printf("\nRegistro apagado\n\n");

        fclose(p);
        system("pause");
    }
}

#endif // ex4
