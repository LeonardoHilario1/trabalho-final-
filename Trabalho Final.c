#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int codigo;
    char descricao[100];
    int quantidade;
    float valor;
} Produto;


void inicializarEstoque(Produto *estoque, int *numProdutos) {
    *numProdutos = 0;
}


void adicionarProduto(Produto *estoque, int *numProdutos) {
    Produto produto;
    
    printf("Digite o código do produto: ");
    scanf("%d", &produto.codigo);
    
    printf("Digite a descrição do produto: ");
    scanf(" %[^\n]s", produto.descricao);
    
    printf("Digite a quantidade do produto: ");
    scanf("%d", &produto.quantidade);
    
    printf("Digite o valor do produto: ");
    scanf("%f", &produto.valor);
    
    estoque[*numProdutos] = produto;
    (*numProdutos)++;
    
    printf("Produto cadastrado com sucesso!\n");
}


void imprimirRelatorio(Produto *estoque, int numProdutos) {
    if (numProdutos == 0) {
        printf("Estoque vazio!\n");
        return;
    }
    
    printf("Relatório de produtos:\n");
    printf("Código\tDescrição\tQuantidade\tValor\n");
    
    for (int i = 0; i < numProdutos; i++) {
        Produto produto = estoque[i];
        printf("%d\t%s\t%d\t\t%.2f\n", produto.codigo, produto.descricao, produto.quantidade, produto.valor);
    }
}


void pesquisarProduto(Produto *estoque, int numProdutos) {
    int codigo;
    printf("Digite o código do produto: ");
    scanf("%d", &codigo);
    
    int produtoEncontrado = 0;
    
    for (int i = 0; i < numProdutos; i++) {
        Produto produto = estoque[i];
        if (produto.codigo == codigo) {
            printf("Produto encontrado:\n");
            printf("Código\tDescrição\tQuantidade\tValor\n");
            printf("%d\t%s\t%d\t\t%.2f\n", produto.codigo, produto.descricao, produto.quantidade, produto.valor);
            produtoEncontrado = 1;
            break;
        }
    }
    
    if (!produtoEncontrado) {
        printf("Produto não encontrado!\n");
    }
}


void removerProduto(Produto *estoque, int *numProdutos) {
    int codigo;
    printf("Digite o código do produto a ser removido: ");
    scanf("%d", &codigo);
    
    for (int i = 0; i < *numProdutos; i++) {
        Produto produto = estoque[i];
        if (produto.codigo == codigo) {
           
            for (int j = i; j < (*numProdutos - 1); j++) {
                estoque[j] = estoque[j + 1];
            }
            
            (*numProdutos)--;
            printf("Produto removido com sucesso!\n");
            return;
        }
    }
    
    printf("Produto não encontrado!\n");
}

int main() {
    Produto estoque[100];
    int numProdutos = 0;
    int opcao;
    
    do {
        printf("\n==== MENU ====\n");
        printf("1. Adicionar produto\n");
        printf("2. Imprimir relatório de produtos\n");
        printf("3. Pesquisar produto\n");
        printf("4. Remover produto\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                adicionarProduto(estoque, &numProdutos);
                break;
            case 2:
                imprimirRelatorio(estoque, numProdutos);
                break;
            case 3:
                pesquisarProduto(estoque, numProdutos);
                break;
            case 4:
                removerProduto(estoque, &numProdutos);
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 0);
    
    return 0;
}
