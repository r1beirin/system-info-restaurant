// Bibliotecas padrão
#include <stdio.h>
#include <stdlib.h>

// UTF-8
#include <locale.h>

struct a_definir{
	//inserir código aqui
};

void cadastro(struct a_definir T[]){
	//inserir código aqui
}

void mostra(struct a_definir T[]){
	//inserir código aqui
}

void mostra1(struct a_definir T[]){
	//inserir código aqui
}

void menu(){
	int opcao;
	struct a_definir P[30];
    setlocale(LC_ALL,"");

	while(1){
		printf("\nBem vindo ao Sistema de Gerenciamento de Restaurante");
		printf("\n1 - Mostrar o cardapio");
		printf("\n2 - Mostrar o estoque");
		printf("\n3 - Cadastrar pedido");
		printf("\n4 - Mostrar pedidos");
		printf("\n5 - Controle de caixa");
		printf("\n6 - Relatorio gerencial");
		printf("\n7 - Ver relatorio");
		printf("\n9 - Sair");
		printf("\nDigite opção: ");
		scanf("%d", &opcao);
	
		if(opcao == 1) cadastro(P);
		if(opcao == 2) mostra(P);
		if(opcao == 3) mostra1(P);
		if(opcao == 9) return;
	}
}


int main(){
	menu();
}