#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//	OBS: MAXQTD é uma constante para os vetores de pratos, sobremesas, bebidas e estoque.
//	Cuidado ao mexer nela.
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

//	Struct de vetores para armazenar as bebidas
typedef struct{
	char vet[MAXQTD];
}bebida;

//	Struct de vetores para o estoque
typedef struct{
	char vet[MAXQTD];
}estoque;

//	Struct de matrizes para os pedidos. ~> São n linhas e 2 colunas (comida e bebida).
typedef struct{
	char vet[MAXQTD];
}pedido;


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

		if(op == 4) return;
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
				printf("\nDeseja adicionar outro prato ao cardapio?");
				printf("\n1. Sim");
				printf("\n2. Nao");
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
				printf("\nDeseja adicionar outra sobremesa ao cardapio?");
				printf("\n1. Sim");
				printf("\n2. Nao");
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
				printf("\nDeseja adicionar outra bebida ao cardapio?");
				printf("\n1. Sim");
				printf("\n2. Nao");
				printf("\nDigite a opcao: ");
				scanf("%d", &op2);

				*qtd_bebida += 1;
				if(op2 == 2) break;
			}
		}

		if(op == 4) return;
	}
}

//	O ponteiro serve de contador para a função mostrar_estoque().
void adicionar_estoque(int *qtd_estoque, estoque E[]){
	int op;

	while(1){
		setbuf(stdin, NULL);
		printf("\n===== Cadastro de items no estoque =====");
		printf("\nDigite o item a ser cadastrado: ");
		scanf("%[^\n]s", E[*qtd_estoque].vet);
		*qtd_estoque += 1;

		printf("\nDeseja cadastrar novamente no estoque?");
		printf("\n1. Sim");
		printf("\n2. Nao");
		printf("\nOpcao: ");
		scanf("%d", &op);

		if(op == 2) return;
	}
}

//	Função para mostrar os items cadastrados no estoque usando ponteiro e struct.
void mostrar_estoque(int *qtd_estoque, estoque E[]){
	printf("\n===== Items em estoque =====");
	for(int i = 0; i < *qtd_estoque; i++){
		printf("\nID %d - %s", i, E[i].vet);
	}
	printf("\n");
}

// Função Cadastro de pedidos usando ponteiros e struct.
void cadastrar_pedido(int *qtd_pedido, pedido P[], double *valor_total){
	int op, op2;
	double valor;

	while(1){
		setbuf(stdin, NULL);
		printf("\n===== Cadastro de pedido =====");
		printf("\nDigite o pedido do cliente: ");
		scanf("%[^\n]s", P[*qtd_pedido].vet);
		printf("\nDigite o valor do pedido: R$");
		scanf("%lf", &valor);
		*valor_total += valor;

		*qtd_pedido += 1;

		printf("\nDeseja cadastrar outro pedido?");
		printf("\n1. Sim");
		printf("\n2. Nao");
		printf("\nDigite a opcao: ");
		scanf("%d", &op2);

		if(op2 == 2) return;
	}
}

void mostrar_pedidos(int *qtd_pedido, pedido P[]){
	printf("\n===== Lista de pedidos do restaurante =====");
	for(int i = 0; i < *qtd_pedido; i++){
		printf("\nPEDIDO n. %d -> %s", i, P[i].vet);
	}
	printf("\n");
}

void controle_caixa(int *qtd_pedido, double *valor_final){
	int op;

	printf("\n===== Controle do caixa financeiro =====");
	printf("\nResultado atual do caixa: R$%.2lf", *valor_final);
	printf("\n========================================");
	printf("\nDeseja resetar o resultado atual do dia?");
	printf("\n1. Sim");
	printf("\n2. Nao");
	printf("\nOpcao: ");
	scanf("%d", &op);

	if(op == 1){
		*valor_final = 0;
		printf("\nO valor do caixa foi resetado para R$%.0lf\n", *valor_final);
	}
}

void remover_estoque(int *qtd_estoque, estoque E[]){
	int op, id;
	while(1){
		setbuf(stdin, NULL);
		printf("\n===== Remover algum item do estoque =====");
		printf("\nDigite o ID: ");
		scanf("%d", &id);
		
		/*for(int i = id+1; i <= *qtd_estoque; i++){
			E[i-1].vet = E[i].vet;
		}*/

		printf("\nDeseja remover novamente?");
		printf("\n1. Sim");
		printf("\n2. Nao");
		scanf("%d", &op);

		if(op == 2) return;
	}
}

void menu(){
	int opcao;

	//	Inicialização da variavel das contas do final do dia
	double valor_final = 0;
	//	Inicialização das variaveis de quantidade em 0.
	//	Elas servem para o controle do "contador" do número de "itens adicionados".
	int quantidade_comida = 0, quantidade_sobremesa = 0, quantidade_bebida = 0, quantidade_estoque = 0;
	int quantidade_pedido = 0;
	//	Inicialização dos ponteiros de quantidade
	int *quantidadeComida, *quantidadeSobremesa, *quantidadeBebida, *quantidadeEstoque, *quantidadePedido;
	//	Inicialização do ponteiro para manipular o resultado financeiro do dia.
	double *valorFinal;
	//	Configuração dos ponteiros para receber determinado endereço de certa variavel.
	quantidadeComida = &quantidade_comida;
	quantidadeSobremesa = &quantidade_sobremesa;
	quantidadeBebida = &quantidade_bebida;
	quantidadeEstoque = &quantidade_estoque;
	quantidadePedido = &quantidade_pedido;
	//	Inicialização do ponteiro para atualizar valor final
	valorFinal = &valor_final;

	pratos_principais c[MAXQTD];
	sobremesa s[MAXQTD];
	bebida b[MAXQTD];
	estoque e[MAXQTD];
	pedido p[MAXQTD];

	while(1){
		setbuf(stdin, NULL);
		printf("\nBem vindo ao Sistema de Gerenciamento de Restaurante");
		printf("\n1 - Adicionar no cardapio");
		//printf("\n2 - Remover do cardapio");
		printf("\n2 - Mostrar o cardapio");
		printf("\n3 - Cadastrar no estoque");
		//printf("n11 - Remover do estoque");
		printf("\n4 - Mostrar o estoque");
		printf("\n5 - Cadastrar pedido");
		printf("\n6 - Mostrar lista de pedidos");
		printf("\n7 - Controle de caixa");
		/*printf("\n8 - Relatorio gerencial");
		printf("\n9 - Ver relatorio");*/
		printf("\n10 - Sair");
		printf("\nDigite opcao: ");
		scanf("%d", &opcao);
	
		if(opcao == 1) adicionar_cardapio(quantidadeComida, c, quantidadeSobremesa, s, quantidadeBebida, b);
		if(opcao == 2) mostrar_cardapio(quantidadeComida, c, quantidadeSobremesa, s, quantidadeBebida, b);
		if(opcao == 3) adicionar_estoque(quantidadeEstoque, e);
		//if(opcao == 11) remover_estoque(quantidadeEstoque, e);
		if(opcao == 4) mostrar_estoque(quantidadeEstoque, e);
		if(opcao == 5) cadastrar_pedido(quantidadePedido, p, valorFinal);
		if(opcao == 6) mostrar_pedidos(quantidadePedido, p);
		if(opcao == 7) controle_caixa(quantidadePedido, valorFinal);
		if(opcao == 10) return;
	}
}


int main(){
	menu();
}