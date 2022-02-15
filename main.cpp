// Bibliotecas padrão
#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char vet[100];
}pratos_principais;

void mostrar_cardapio(int *qtd_comida, pratos_principais T[]){
	int op;
	while(1){
		printf("\n===== Mostrar cardapio =====");
		setbuf(stdin, NULL);
		printf("\n1. Mostrar pratos principais");
		printf("\n2. Mostrar sobremesas");
		printf("\n3. Mostrar bebidas");
		printf("\n4. Voltar");
		printf("\nDigite a opcao: ");
		scanf("%d", &op);

		if(op == 1){
			printf("\n===== PRATOS PRINCIPAIS =====");
			for(int i = 0; i < *qtd_comida; i++){
				printf("\n%s", T[i].vet);
			}
			printf("\n");
		}

		if(op == 4) break;
	}
}

void adicionar_cardapio(int *qtd_comida, pratos_principais T[]){
	int op, op2;

	while(1){
		printf("\n===== Adicionar no cardapio =====");
		setbuf(stdin, NULL);
		printf("\n1. Adicionar em pratos principais");
		//printf("\n2. Adicionar em sobremesas");
		//printf("\n3. Adicionar em bebidas");
		printf("\n4. Voltar");
		printf("\nDigite a opcao: ");
		scanf("%d", &op);

		if(op == 1){
			while(1){
				setbuf(stdin, NULL);
				printf("\nDigite o nome do prato: ");
				scanf("%[^\n]s", T[*qtd_comida].vet);
				printf("\n1. Para adicionar outro prato");
				printf("\n2. Para sair");
				printf("\nDigite a opcao: ");
				scanf("%d", &op2);

				*qtd_comida += 1;
				if(op2 == 2) break;
			}
		}

		if(op == 4) break;
	}
}


void menu(){
	int opcao, quantidade_comida = 0;;
	int *quantidadeComida;
	quantidadeComida = &quantidade_comida;

	pratos_principais c[50];

	while(1){
		setbuf(stdin, NULL);
		printf("\nBem vindo ao Sistema de Gerenciamento de Restaurante");
		printf("\n1 - Mostrar o cardapio");
		printf("\n2 - Adicionar no cardapio");
		/*printf("\n3 - Mostrar o estoque");
		printf("\n4 - Cadastrar pedido");
		printf("\n5 - Mostrar pedidos");
		printf("\n6 - Controle de caixa");
		printf("\n7 - Relatorio gerencial");
		printf("\n8 - Ver relatorio");
		printf("\n9 - Sair");
		*/

		printf("\nDigite opcao: ");
		scanf("%d", &opcao);
	
		if(opcao == 1) mostrar_cardapio(quantidadeComida, c);
		if(opcao == 2) adicionar_cardapio(quantidadeComida, c);
		if(opcao == 9) return;
	}
}


int main(){
	menu();
}