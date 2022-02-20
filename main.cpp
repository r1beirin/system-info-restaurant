#include <stdio.h>
#include <stdlib.h>
#define MAXQTD 100

/*
	Struct de vetores para armazenar os pratos principais.
	Para adicionar mais quantidades de pratos principais, é necessário aumentar o valor 
	da constante MAXQTD.
*/
typedef struct{
	char vet[MAXQTD];
}pratos_principais;

//	Struct de vetores para armazenar as sobremesas
typedef struct{
	char vet[MAXQTD];
}sobremesa;

typedef struct{
	char vet[MAXQTD];
}bebida;


/*
	Função mostrar cardapio e recebe 6 parametros.
	De modo geral, para cada opção do cardapio, é necessário um ponteiro e um struct.
*/
void mostrar_cardapio(int *qtd_comida, pratos_principais P[], int *qtd_sobremesa, sobremesa S[], int *qtd_bebida, bebida B[]){
	int op;
	while(1){
		setbuf(stdin, NULL);
		printf("\n===== Mostrar cardapio =====");
		printf("\n1. Mostrar pratos principais");
		printf("\n2. Mostrar sobremesas");
		printf("\n3. Mostrar bebidas");
		printf("\n4. Voltar");
		printf("\nDigite a opcao: ");
		scanf("%d", &op);

		if(op == 1){
			printf("\n===== PRATOS PRINCIPAIS =====");
			for(int i = 0; i < *qtd_comida; i++){
				printf("\nID %d - %s", i, P[i].vet);
			}
			printf("\n");
		}

		if(op == 2){
			printf("\n===== SOBREMESAS =====");
			for(int i = 0; i < *qtd_sobremesa; i++){
				printf("\nID %d - %s", i, S[i].vet);
			}
			printf("\n");
		}

		if(op == 3){
			printf("\n===== BEBIDAS =====");
			for(int i = 0; i < *qtd_bebida; i++){
				printf("\nID %d - %s", i, B[i].vet);
			}
			printf("\n");
		}

		if(op == 4) break;
	}
}

/*
	Função cadastrar algo no cardapio e recebe 6 parametros.
	De modo geral, para cada opção do cardapio, é necessário um ponteiro e um struct.
	O ponteiro serve como contador para opções na função mostrar_cardapio().
*/
void adicionar_cardapio(int *qtd_comida, pratos_principais P[], int *qtd_sobremesa, sobremesa S[], int *qtd_bebida, bebida B[]){
	int op, op2;

	while(1){
		setbuf(stdin, NULL);
		printf("\n===== Adicionar no cardapio =====");
		printf("\n1. Adicionar pratos principais");
		printf("\n2. Adicionar sobremesas");
		printf("\n3. Adicionar bebidas");
		printf("\n4. Voltar");
		printf("\nDigite a opcao: ");
		scanf("%d", &op);

		if(op == 1){
			while(1){
				setbuf(stdin, NULL);
				printf("\nDigite o nome do prato: ");
				scanf("%[^\n]s", P[*qtd_comida].vet);
				printf("\n1. Para adicionar outro prato");
				printf("\n2. Para sair");
				printf("\nDigite a opcao: ");
				scanf("%d", &op2);

				*qtd_comida += 1;
				if(op2 == 2) break;
			}
		}

		if(op == 2){
			while(1){
				setbuf(stdin, NULL);
				printf("\nDigite o nome da sobremesa: ");
				scanf("%[^\n]s", S[*qtd_sobremesa].vet);
				printf("\n1. Para adicionar outra sobremesa");
				printf("\n2. Para sair");
				printf("\nDigite a opcao: ");
				scanf("%d", &op2);

				*qtd_sobremesa += 1;
				if(op2 == 2) break;
			}
		}

		if(op == 3){
			while(1){
				setbuf(stdin, NULL);
				printf("\nDigite o nome da bebida: ");
				scanf("%[^\n]s", B[*qtd_bebida].vet);
				printf("\n1. Para adicionar outra bebida");
				printf("\n2. Para sair");
				printf("\nDigite a opcao: ");
				scanf("%d", &op2);

				*qtd_bebida += 1;
				if(op2 == 2) break;
			}
		}

		if(op == 4) break;
	}
}


void menu(){
	int opcao;
	//	Inicialização das variaveis de quantidade em 0
	int quantidade_comida = 0, quantidade_sobremesa = 0, quantidade_bebida = 0;
	//	Inicialização dos ponteiros de quantidade
	int *quantidadeComida, *quantidadeSobremesa, *quantidadeBebida;
	//	Configuraçãoo dos ponteiros para receber determinado endereço de certa variavel.
	quantidadeComida = &quantidade_comida;
	quantidadeSobremesa = &quantidade_sobremesa;
	quantidadeBebida = &quantidade_bebida;

	pratos_principais c[MAXQTD];
	sobremesa s[MAXQTD];
	bebida b[MAXQTD];

	while(1){
		setbuf(stdin, NULL);
		printf("\nBem vindo ao Sistema de Gerenciamento de Restaurante");
		printf("\n1 - Adicionar no cardapio");
		//printf("\n2 - Remover do cardapio");
		printf("\n3 - Mostrar o cardapio");
		/*printf("\n4 - Mostrar o estoque");
		printf("\n5 - Cadastrar pedido");
		printf("\n6 - Mostrar pedidos");
		printf("\n7 - Controle de caixa");
		printf("\n8 - Relatorio gerencial");
		printf("\n9 - Ver relatorio");*/
		printf("\n10 - Sair");
		printf("\nDigite opcao: ");
		scanf("%d", &opcao);
	
		if(opcao == 1) adicionar_cardapio(quantidadeComida, c, quantidadeSobremesa, s, quantidadeBebida, b);
		if(opcao == 3) mostrar_cardapio(quantidadeComida, c, quantidadeSobremesa, s, quantidadeBebida, b);
		if(opcao == 10) return;
	}
}


int main(){
	menu();
}