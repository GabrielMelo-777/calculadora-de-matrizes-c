# Calculadora de Matrizes em C

## Descrição

Este projeto consiste em uma calculadora de matrizes desenvolvida em linguagem C, permitindo realizar operações matemáticas entre matrizes por meio de um menu interativo.

O programa foi desenvolvido utilizando funções para organizar o código e facilitar sua compreensão.

## Funcionalidades

- Escolher a quantidade de matrizes (2 a 5).
- Informar os valores das matrizes.
- Realizar soma de matrizes.
- Realizar subtração de matrizes.
- Realizar multiplicação matricial.
- Realizar divisão elemento por elemento.
- Exibir a matriz resultante.
- Tratar entradas e operações inválidas.

## Organização do código

O programa utiliza funções separadas para cada funcionalidade:

- `menu()` — exibe o menu principal.
- `lerInteiro()` — valida entradas inteiras.
- `lerDecimal()` — valida entradas decimais.
- `escolherQuantidade()` — define a quantidade de matrizes.
- `informarMatrizes()` — recebe os valores das matrizes.
- `somarMatrizes()` — realiza a soma.
- `subtrairMatrizes()` — realiza a subtração.
- `multiplicarMatrizes()` — realiza a multiplicação.
- `dividirMatrizes()` — realiza a divisão.
- `mostrarResultado()` — apresenta o resultado.
- `main()` — controla a execução do programa.

## Regras do programa

- São permitidas de 2 a 5 matrizes.
- Todas as matrizes possuem dimensão 2×2.
- A multiplicação utiliza as regras da multiplicação matricial.
- A divisão é realizada elemento por elemento, não sendo a divisão matricial por inversa.
- Não é permitida divisão por zero.
- O usuário precisa informar as matrizes antes de realizar operações.

## Como executar

1. Acesse https://www.onlinegdb.com/.
2. Selecione a linguagem C.
3. Copie o conteúdo do arquivo `main.c`.
4. Cole no editor do OnlineGDB.
5. Clique em Run.
6. Utilize o menu para realizar as operações.

## Testes realizados

O programa foi executado e testado utilizando o compilador OnlineGDB.

Foram realizados os seguintes testes:

1. **Soma de matrizes:** operação realizada corretamente.
2. **Subtração de matrizes:** operação realizada corretamente.
3. **Multiplicação de matrizes:** resultado correto.
4. **Divisão de matrizes:** divisão elemento por elemento realizada corretamente.
5. **Quantidade inválida:** o programa identificou uma quantidade fora do limite permitido.
6. **Entrada inválida:** o programa identificou uma letra digitada no menu.
7. **Divisão por zero:** o programa impediu a operação e apresentou uma mensagem de erro.
8. **Resultado inexistente:** o programa impediu a exibição antes da realização de uma operação.

Todos os oito testes apresentados foram concluídos com sucesso.

As capturas de tela estão disponíveis na pasta `evidencias` do repositório.


## Tecnologias utilizadas

- Linguagem C
- OnlineGDB
- GitHub

## Identificação

**Aluno:** Gabriel Cardozo de Melo

**Disciplina:** Algoritmos e pensamentos computacionais

**Professora:** Karla 

