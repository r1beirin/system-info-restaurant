#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//	OBS: MAXQTD é uma constante para o tamanho dos vetores de pratos, sobremesas, bebidas, estoque e pedidos.
//	Cuidado ao mexer nela.
#define MAXQTD 100

/*
	Struct de vetores para armazenar os pratos principais.
	Para adicionar mais quantidades de pratos principais, é necessário aumentar o valor 
	da constante MAXQTD.
*/
typedef struct{
	char vet[MAXQTD];
	double price[MAXQTD];
}pratos_principais;

//	Struct de vetores para armazenar as sobremesas
typedef struct{
	char vet[MAXQTD];
	double price[MAXQTD];
}sobremesa;

//	Struct de vetores para armazenar as bebidas
typedef struct{
	char vet[MAXQTD];
	double price[MAXQTD];
}bebida;

//	Struct de vetores para o estoque
typedef struct{
	char vet[MAXQTD];
}estoque;

//	Struct de matrizes para os pedidos
typedef struct{
	char vet[MAXQTD];
}pedido;

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

		//	Adicionar pratos principais
		if(op == 1){
			while(1){
				setbuf(stdin, NULL);
				printf("\nDigite o nome do prato: ");
				scanf("%[^\n]s", P[*qtd_comida].vet);
				printf("Digite o valor do prato: R$");
				scanf("%lf", P[*qtd_comida].price);
				printf("\nDeseja adicionar outro prato ao cardapio?");
				printf("\n1. Sim");
				printf("\n2. Nao");
				printf("\nDigite a opcao: ");
				scanf("%d", &op2);

				*qtd_comida += 1;
				if(op2 == 2) break;
			}
		}

		//	Adicionar sobremesa
		if(op == 2){
			while(1){
				setbuf(stdin, NULL);
				printf("\nDigite o nome da sobremesa: ");
				scanf("%[^\n]s", S[*qtd_sobremesa].vet);
				printf("Digite o valor da sobremesa: R$");
				scanf("%lf", S[*qtd_sobremesa].price);
				printf("\nDeseja adicionar outra sobremesa ao cardapio?");
				printf("\n1. Sim");
				printf("\n2. Nao");
				printf("\nDigite a opcao: ");
				scanf("%d", &op2);

				*qtd_sobremesa += 1;
				if(op2 == 2) break;
			}
		}

		//	Adicionar bebida
		if(op == 3){
			while(1){
				setbuf(stdin, NULL);
				printf("\nDigite o nome da bebida: ");
				scanf("%[^\n]s", B[*qtd_bebida].vet);
				printf("Digite o valor da bebida: R$");
				scanf("%lf", B[*qtd_bebida].price);
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

/*
	Função de remover cardapio recebe 6 parametros, 2 parametros por opção do cardapio.
	A função roda um for que substitui os elementos 1 a 1. O for substitui a posição anterior pela atual.
	No for, substitui-se o nome (string) do anterior pelo atual e o preço (double) do anterior pelo atual.
	String ~> Uso da strcpy para fazer a substituição.
	Double ~> Uso de ponteiro para substituição.
	Ao final da substituição, decrementa 1 de tamanho no vetor.
*/
void remover_cardapio(int *qtd_comida, pratos_principais P[], int *qtd_sobremesa, sobremesa S[], int *qtd_bebida, bebida B[]){
    int op, id;
    while(1){
        setbuf(stdin, NULL);
        printf("\n===== Remover do cardapio =====");
        printf("\n1. Pratos principais");
        printf("\n2. Sobremesas");
        printf("\n3. Bebidas");
        printf("\n4. Voltar");
		printf("\nDigite a opcao: ");
        scanf("%d",&op);

        if(op == 1){
            printf("\n===== PRATOS PRINCIPAIS =====");
            printf("\nDigite o ID: ");
            scanf("%d", &id);

            for(int i = id+1; i <= *qtd_comida; i++){
                strcpy(P[i-1].vet, P[i].vet);
                *P[i-1].price = *P[i].price;
                
            }

            *qtd_comida -= 1;
        }

        if(op == 2){
            printf("\n===== SOBREMESAS =====");
            printf("\nDigite o ID: ");
            scanf("%d", &id);

            for(int i = id+1; i <= *qtd_sobremesa; i++){
                strcpy(S[i-1].vet, S[i].vet);
                *S[i-1].price = *S[i].price;
                
            }

            *qtd_sobremesa -= 1;
        }

        if(op == 3){
            printf("\n===== BEBIDAS =====");
            printf("\nDigite o ID: ");
            scanf("%d", &id);

            for(int i = id+1; i <= *qtd_bebida; i++){
                strcpy(B[i-1].vet, B[i].vet);
                *B[i-1].price = *B[i].price;
                
            }

            *qtd_bebida -= 1;
        }
        
        if(op == 4) return;
    }

}

/*
	Função mostrar cardapio e recebe 6 parametros.
	De modo geral, para cada opção do cardapio, é necessário um ponteiro e um struct.
	Todo ponteiro de quantidade serve como contador para mostrar o cardapio.
	O for vai de 0 até contador printando a parte escolhida do cardapio.
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
				printf("\nID %d - %s - R$%.2lf", i, P[i].vet, *P[i].price);
			}
			printf("\n");
		}

		if(op == 2){
			printf("\n===== SOBREMESAS =====");
			for(int i = 0; i < *qtd_sobremesa; i++){
				printf("\nID %d - %s - R$%.2lf", i, S[i].vet, *S[i].price);
			}
			printf("\n");
		}

		if(op == 3){
			printf("\n===== BEBIDAS =====");
			for(int i = 0; i < *qtd_bebida; i++){
				printf("\nID %d - %s - R$%.2lf", i, B[i].vet, *B[i].price);
			}
			printf("\n");
		}

		if(op == 4) return;
	}
}

/*
	Função para adicionar algum item no estoque. Usa struct e ponteiro.
	O ponteiro serve de contador para a função mostrar_estoque().
*/
void adicionar_estoque(int *qtd_estoque, estoque E[]){
	int op;

	while(1){
		setbuf(stdin, NULL);
		printf("\n===== Cadastro de items no estoque =====");
		printf("\nDigite o item a ser cadastrado: ");
		scanf("%[^\n]s", E[*qtd_estoque].vet);

		printf("\nDeseja cadastrar novamente no estoque?");
		printf("\n1. Sim");
		printf("\n2. Nao");
		printf("\nOpcao: ");
		scanf("%d", &op);

		*qtd_estoque += 1;
		if(op == 2) return;
	}
}

/*
	Função de remoção de itens no estoque. Recebe parametro de um ponteiro e da struct estoque.
	A função roda um for que substitui os elementos 1 a 1. O for substitui a posição anterior pela atual.
	Ao final da substituição, decrementa 1 de tamanho no vetor.
*/
void remover_estoque(int *qtd_estoque, estoque E[]){
	int op, id;
	while(1){
		setbuf(stdin, NULL);
		printf("\n===== Remover algum item do estoque =====");
		printf("\nDigite o ID: ");
		scanf("%d", &id);
		
		for(int i = id+1; i <= *qtd_estoque; i++){
			strcpy(E[i-1].vet, E[i].vet);
		}

		*qtd_estoque -= 1;

		printf("\nDeseja remover novamente?");
		printf("\n1. Sim");
		printf("\n2. Nao");
		printf("\nOpcao: ");
		scanf("%d", &op);

		if(op == 2) return;
	}
}

/*
	Função para mostrar os items cadastrados no estoque usando ponteiro e struct.
	O ponteiro serve como contador.
	O for vai de 0 até o número que está armazenado no ponteiro.
*/
void mostrar_estoque(int *qtd_estoque, estoque E[]){
	printf("\n===== Items em estoque =====");
	for(int i = 0; i < *qtd_estoque; i++){
		printf("\nID %d - %s", i, E[i].vet);
	}
	printf("\n");
}

/*
	Função cadastro de pedidos usando ponteiros e struct.
	O ponteiro de quantidade serve como contador para a função mostrar_pedidos()
	O ponteiro de valorTotal é atualizado a cada pedido e depois é contabilizado e utilizado na função controle_caixa()
*/
void cadastrar_pedido(int *qtd_pedido, pedido P[], double *valor_total){
	int op, op2;
	double valor;

	while(1){
		setbuf(stdin, NULL);
		printf("\n===== Cadastro de pedido =====");
		printf("\nDigite o pedido do cliente: ");
		scanf("%[^\n]s", P[*qtd_pedido].vet);
		printf("Digite o valor do pedido: R$");
		scanf("%lf", &valor);

		printf("\nDeseja cadastrar outro pedido?");
		printf("\n1. Sim");
		printf("\n2. Nao");
		printf("\nDigite a opcao: ");
		scanf("%d", &op2);

		*valor_total += valor;
		*qtd_pedido += 1;
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

/*
	A função controle de caixa mostra a quantidade atual do valor no caixa.
	Caso o usuário deseje resetar o balanço do dia, o ponteiro valor_final será definido como 0.
*/
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

/*
	A função relatorio_gerencial() manipula a criação de dois arquivos txt (estoque e caixa)
	É necessário a inicialização de um ponteiro do tipo FILE.
*/
void relatorio_gerencial(int *qtd_estoque, estoque E[], double *valor_final){
	int op;

	// Cria um ponteiro do tipo FILE para inicializar a manipulação de arquivos
	FILE *relatorio;

	while(1){
		setbuf(stdin, NULL);
		printf("\n===== Gerar relatorio =====");
		printf("\n1. Estoque");
		printf("\n2. Caixa");
		printf("\n3. Voltar");
		printf("\nOpcao: ");
		scanf("%d", &op);

		if(op == 1){
			// Cria/abre um arquivo txt como write
			relatorio = fopen("relatorio_estoque.txt", "w");
			
			// Verificando se houve algum erro ao criar o arquivo - Ex: o disco pode estar sem espaço.
			if(relatorio == NULL){
				printf("\nErro ao criar o arquivo!\n");
			}
			else{
				fputs("===== Items em estoque =====", relatorio);
				for(int i = 0; i < *qtd_estoque; i++){
					// fprintf é uma função que grava no arquivo como se fosse um print
					fprintf(relatorio, "\nID %d - %s", i, E[i].vet);
				}
				printf("\nRelatorio gerado com sucesso!\n");
			}
			fclose(relatorio);
		}

		if(op == 2){
			relatorio = fopen("relatorio_caixa.txt", "w");
			
			if(relatorio == NULL){
				printf("\nErro ao criar o arquivo!\n");
			}
			else{
				fputs("===== Controle do caixa financeiro =====", relatorio);
				fprintf(relatorio, "\nResultado atual do caixa: R$%.2lf", *valor_final);
				printf("\nRelatorio gerado com sucesso!\n");
			}
			fclose(relatorio);
		}

		if(op == 3) return;
	}
}

/*
	Essa função faz a leitura caracter a caracter de dois arquivos txt do relatorio (estoque e caixa)
	e resulta em um output na tela do usuário.
	É necessário declarar um ponteiro do tipo FILE para manipular arquivos.
*/

void ver_relatorio(){
	int op;

	// Cria uma variavel caracter para utilizar na leitura
	char caractere;

	// Cria um ponteiro do tipo FILE para inicializar a manipulação de arquivos
	FILE *relatorio;

	while(1){
		setbuf(stdin, NULL);
		printf("\n===== Ver relatorio =====");
		printf("\n1. Relatorio do estoque");
		printf("\n2. Relatorio do caixa");
		printf("\nOpcao: ");
		scanf("%d",&op);

		if(op == 1){
			//	Abre um arquivo como read
			relatorio = fopen("relatorio_estoque.txt", "r");

			if(relatorio == NULL){
				printf("\nErro ao criar o arquivo!\n");
			}
			else{
				printf("\n");
				//	Enquanto não for o fim do arquivo, le o caracter e imprime.
				while (caractere != EOF){
					//	Faz a leitura do caracter no arquivo apontado no ponteiro relatorio
					caractere = fgetc(relatorio);
					printf("%c", caractere);
				}
				printf("\n");
			}
			fclose(relatorio);
			return;
		}

		if(op == 2){
			relatorio = fopen("relatorio_caixa.txt", "r");

			if(relatorio == NULL){
				printf("\nErro ao criar o arquivo!\n");
			}
			else{
				printf("\n");
				while (caractere != EOF){
					caractere = fgetc(relatorio);
					printf("%c", caractere);
				}
				printf("\n");
			}
			fclose(relatorio);
			return;
		}
	}

}


void menu(){
	int opcao;

	//	Inicialização da variavel das contas do final do dia
	double valor_final = 0;
	//	Inicialização das variaveis de quantidade em 0.
	//	Elas servem para o controle do "contador" do número de "itens adicionados".
	int quantidade_comida = 0, quantidade_sobremesa = 0, quantidade_bebida = 0, quantidade_estoque = 0, quantidade_pedido = 0;
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
	//	Configuração do ponteiro para atualizar valor final
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
		printf("\n2 - Remover do cardapio");
		printf("\n3 - Mostrar o cardapio");
		printf("\n4 - Cadastrar no estoque");
		printf("\n5 - Remover do estoque");
		printf("\n6 - Mostrar o estoque");
		printf("\n7 - Cadastrar pedido");
		printf("\n8 - Mostrar lista de pedidos");
		printf("\n9 - Controle de caixa");
		printf("\n10 - Gerar relatorio gerencial");
		printf("\n11 - Ver relatorio");
		printf("\n12 - Sair");
		printf("\nDigite opcao: ");
		scanf("%d", &opcao);
	
		if(opcao == 1) adicionar_cardapio(quantidadeComida, c, quantidadeSobremesa, s, quantidadeBebida, b);
		if(opcao == 2) remover_cardapio(quantidadeComida, c, quantidadeSobremesa, s, quantidadeBebida, b);
		if(opcao == 3) mostrar_cardapio(quantidadeComida, c, quantidadeSobremesa, s, quantidadeBebida, b);
		if(opcao == 4) adicionar_estoque(quantidadeEstoque, e);
		if(opcao == 5) remover_estoque(quantidadeEstoque, e);
		if(opcao == 6) mostrar_estoque(quantidadeEstoque, e);
		if(opcao == 7) cadastrar_pedido(quantidadePedido, p, valorFinal);
		if(opcao == 8) mostrar_pedidos(quantidadePedido, p);
		if(opcao == 9) controle_caixa(quantidadePedido, valorFinal);
		if(opcao == 10) relatorio_gerencial(quantidadeEstoque, e, valorFinal);
		if(opcao == 11) ver_relatorio();
		if(opcao == 12) return;
	}
}

int main(){
	menu();
}