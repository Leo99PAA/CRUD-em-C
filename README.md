# Sistema de Cadastro CRUD em C

Projeto simples de cadastro de produtos usando apenas a funcao `main()`, uma `struct` personalizada e um vetor com 10 posicoes.

O programa ja inicia com 5 produtos cadastrados para facilitar os testes de listagem, busca, atualizacao e remocao.

## Funcionalidades

- Cadastrar produto
- Listar produtos
- Buscar produto por ID unico
- Atualizar produto
- Remover produto
- Validar entradas invalidas, IDs duplicados e operacoes sem registros

## Produtos iniciais para teste

| ID | Produto | Quantidade | Preco |
| --- | --- | --- | --- |
| 101 | Caneta Azul | 25 | R$ 2.50 |
| 102 | Caderno Universitario | 12 | R$ 18.90 |
| 103 | Borracha Branca | 30 | R$ 1.75 |
| 104 | Lapis HB | 40 | R$ 1.20 |
| 105 | Estojo Escolar | 8 | R$ 24.99 |

## Como compilar

```bash
gcc main.c -o cadastro
```

## Como executar

```bash
./cadastro
```

No Windows, se estiver usando PowerShell:

```powershell
.\cadastro.exe
```
