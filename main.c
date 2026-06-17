#include <stdio.h>
#include <string.h>

#define MAX_REGISTROS 10

typedef struct {
    int id;
    char nome[50];
    int quantidade;
    float preco;
} Produto;

int main() {
    Produto produtos[MAX_REGISTROS] = {
        {101, "Caneta Azul", 25, 2.50},
        {102, "Caderno Universitario", 12, 18.90},
        {103, "Borracha Branca", 30, 1.75},
        {104, "Lapis HB", 40, 1.20},
        {105, "Estojo Escolar", 8, 24.99}
    };
    int quantidadeAtual = 5;
    int opcao = 0;
    int entradaValida = 0;
    int i = 0;
    int posicao = -1;
    int idBusca = 0;
    int idDuplicado = 0;
    char confirmar = 'n';
    int c = 0;

    do {
        printf("\n=====================================\n");
        printf("      SISTEMA DE CADASTRO - CRUD\n");
        printf("=====================================\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Listar produtos\n");
        printf("3 - Buscar produto por ID\n");
        printf("4 - Atualizar produto\n");
        printf("5 - Remover produto\n");
        printf("0 - Sair\n");
        printf("-------------------------------------\n");
        printf("Escolha uma opcao: ");

        entradaValida = scanf("%d", &opcao);
        while ((c = getchar()) != '\n' && c != EOF) {
        }

        if (entradaValida != 1) {
            printf("\nOpcao invalida. Digite apenas numeros.\n");
            opcao = -1;
        } else if (opcao < 0 || opcao > 5) {
            printf("\nOpcao inexistente. Escolha uma opcao entre 0 e 5.\n");
        } else if (opcao == 1) {
            if (quantidadeAtual >= MAX_REGISTROS) {
                printf("\nNao ha espaco para novos registros. Limite de %d produtos atingido.\n", MAX_REGISTROS);
            } else {
                do {
                    printf("\nDigite o ID do produto (numero inteiro positivo): ");
                    entradaValida = scanf("%d", &produtos[quantidadeAtual].id);
                    while ((c = getchar()) != '\n' && c != EOF) {
                    }

                    idDuplicado = 0;
                    if (entradaValida != 1 || produtos[quantidadeAtual].id <= 0) {
                        printf("ID invalido. O ID deve ser um numero inteiro positivo.\n");
                    } else {
                        for (i = 0; i < quantidadeAtual; i++) {
                            if (produtos[i].id == produtos[quantidadeAtual].id) {
                                idDuplicado = 1;
                            }
                        }

                        if (idDuplicado == 1) {
                            printf("ID ja cadastrado. Informe um identificador unico.\n");
                        }
                    }
                } while (entradaValida != 1 || produtos[quantidadeAtual].id <= 0 || idDuplicado == 1);

                do {
                    printf("Digite o nome do produto: ");
                    entradaValida = scanf(" %49[^\n]", produtos[quantidadeAtual].nome);
                    while ((c = getchar()) != '\n' && c != EOF) {
                    }

                    if (entradaValida != 1 || strlen(produtos[quantidadeAtual].nome) == 0) {
                        printf("Nome invalido. O nome nao pode ficar vazio.\n");
                    }
                } while (entradaValida != 1 || strlen(produtos[quantidadeAtual].nome) == 0);

                do {
                    printf("Digite a quantidade em estoque (0 ou maior): ");
                    entradaValida = scanf("%d", &produtos[quantidadeAtual].quantidade);
                    while ((c = getchar()) != '\n' && c != EOF) {
                    }

                    if (entradaValida != 1 || produtos[quantidadeAtual].quantidade < 0) {
                        printf("Quantidade invalida. Digite um numero inteiro igual ou maior que zero.\n");
                    }
                } while (entradaValida != 1 || produtos[quantidadeAtual].quantidade < 0);

                do {
                    printf("Digite o preco do produto (0 ou maior): R$ ");
                    entradaValida = scanf("%f", &produtos[quantidadeAtual].preco);
                    while ((c = getchar()) != '\n' && c != EOF) {
                    }

                    if (entradaValida != 1 || produtos[quantidadeAtual].preco < 0) {
                        printf("Preco invalido. Digite um valor igual ou maior que zero.\n");
                    }
                } while (entradaValida != 1 || produtos[quantidadeAtual].preco < 0);

                quantidadeAtual++;
                printf("\nProduto cadastrado com sucesso.\n");
            }
        } else if (opcao == 2) {
            if (quantidadeAtual == 0) {
                printf("\nNao ha produtos cadastrados para listar.\n");
            } else {
                printf("\n=========== PRODUTOS CADASTRADOS ===========\n");
                for (i = 0; i < quantidadeAtual; i++) {
                    printf("\nRegistro %d\n", i + 1);
                    printf("ID: %d\n", produtos[i].id);
                    printf("Nome: %s\n", produtos[i].nome);
                    printf("Quantidade: %d\n", produtos[i].quantidade);
                    printf("Preco: R$ %.2f\n", produtos[i].preco);
                }
            }
        } else if (opcao == 3) {
            if (quantidadeAtual == 0) {
                printf("\nNao ha produtos cadastrados para buscar.\n");
            } else {
                do {
                    printf("\nDigite o ID que deseja buscar: ");
                    entradaValida = scanf("%d", &idBusca);
                    while ((c = getchar()) != '\n' && c != EOF) {
                    }

                    if (entradaValida != 1 || idBusca <= 0) {
                        printf("ID invalido. Digite um numero inteiro positivo.\n");
                    }
                } while (entradaValida != 1 || idBusca <= 0);

                posicao = -1;
                for (i = 0; i < quantidadeAtual; i++) {
                    if (produtos[i].id == idBusca) {
                        posicao = i;
                    }
                }

                if (posicao == -1) {
                    printf("\nProduto nao encontrado.\n");
                } else {
                    printf("\n=========== PRODUTO ENCONTRADO ===========\n");
                    printf("ID: %d\n", produtos[posicao].id);
                    printf("Nome: %s\n", produtos[posicao].nome);
                    printf("Quantidade: %d\n", produtos[posicao].quantidade);
                    printf("Preco: R$ %.2f\n", produtos[posicao].preco);
                }
            }
        } else if (opcao == 4) {
            if (quantidadeAtual == 0) {
                printf("\nNao ha produtos cadastrados para atualizar.\n");
            } else {
                do {
                    printf("\nDigite o ID do produto que deseja atualizar: ");
                    entradaValida = scanf("%d", &idBusca);
                    while ((c = getchar()) != '\n' && c != EOF) {
                    }

                    if (entradaValida != 1 || idBusca <= 0) {
                        printf("ID invalido. Digite um numero inteiro positivo.\n");
                    }
                } while (entradaValida != 1 || idBusca <= 0);

                posicao = -1;
                for (i = 0; i < quantidadeAtual; i++) {
                    if (produtos[i].id == idBusca) {
                        posicao = i;
                    }
                }

                if (posicao == -1) {
                    printf("\nProduto nao encontrado. Atualizacao cancelada.\n");
                } else {
                    printf("\nAtualizando produto: %s\n", produtos[posicao].nome);

                    do {
                        printf("Digite o novo nome do produto: ");
                        entradaValida = scanf(" %49[^\n]", produtos[posicao].nome);
                        while ((c = getchar()) != '\n' && c != EOF) {
                        }

                        if (entradaValida != 1 || strlen(produtos[posicao].nome) == 0) {
                            printf("Nome invalido. O nome nao pode ficar vazio.\n");
                        }
                    } while (entradaValida != 1 || strlen(produtos[posicao].nome) == 0);

                    do {
                        printf("Digite a nova quantidade em estoque (0 ou maior): ");
                        entradaValida = scanf("%d", &produtos[posicao].quantidade);
                        while ((c = getchar()) != '\n' && c != EOF) {
                        }

                        if (entradaValida != 1 || produtos[posicao].quantidade < 0) {
                            printf("Quantidade invalida. Digite um numero inteiro igual ou maior que zero.\n");
                        }
                    } while (entradaValida != 1 || produtos[posicao].quantidade < 0);

                    do {
                        printf("Digite o novo preco do produto (0 ou maior): R$ ");
                        entradaValida = scanf("%f", &produtos[posicao].preco);
                        while ((c = getchar()) != '\n' && c != EOF) {
                        }

                        if (entradaValida != 1 || produtos[posicao].preco < 0) {
                            printf("Preco invalido. Digite um valor igual ou maior que zero.\n");
                        }
                    } while (entradaValida != 1 || produtos[posicao].preco < 0);

                    printf("\nProduto atualizado com sucesso.\n");
                }
            }
        } else if (opcao == 5) {
            if (quantidadeAtual == 0) {
                printf("\nNao ha produtos cadastrados para remover.\n");
            } else {
                do {
                    printf("\nDigite o ID do produto que deseja remover: ");
                    entradaValida = scanf("%d", &idBusca);
                    while ((c = getchar()) != '\n' && c != EOF) {
                    }

                    if (entradaValida != 1 || idBusca <= 0) {
                        printf("ID invalido. Digite um numero inteiro positivo.\n");
                    }
                } while (entradaValida != 1 || idBusca <= 0);

                posicao = -1;
                for (i = 0; i < quantidadeAtual; i++) {
                    if (produtos[i].id == idBusca) {
                        posicao = i;
                    }
                }

                if (posicao == -1) {
                    printf("\nProduto nao encontrado. Remocao cancelada.\n");
                } else {
                    printf("\nProduto encontrado: %s\n", produtos[posicao].nome);
                    printf("Confirma a remocao? (s/n): ");
                    entradaValida = scanf(" %c", &confirmar);
                    while ((c = getchar()) != '\n' && c != EOF) {
                    }

                    if (entradaValida == 1 && (confirmar == 's' || confirmar == 'S')) {
                        for (i = posicao; i < quantidadeAtual - 1; i++) {
                            produtos[i] = produtos[i + 1];
                        }
                        quantidadeAtual--;
                        printf("\nProduto removido com sucesso.\n");
                    } else {
                        printf("\nRemocao cancelada.\n");
                    }
                }
            }
        } else if (opcao == 0) {
            printf("\nEncerrando o sistema. Ate mais!\n");
        }
    } while (opcao != 0);

    return 0;
}
