# 📚 Estrutura de Dados em C

Repositório dedicado aos laboratórios e implementações práticas da disciplina de Estrutura de Dados. O objetivo é servir como material de consulta para algoritmos clássicos, manipulação de memória e estruturas lineares/não lineares em C.

## 📂 Estrutura do Repositório

Aqui você encontrará a implementação do zero das seguintes estruturas:

- **[Lab 1: Lista Duplamente Encadeada (LDDE)](./Lab1/)**
  - Inserção ordenada, remoção e busca.
  - Impressão crescente e decrescente.
- **[Lab 2: Fila (Queue)](./Lab2/)**
  - Implementação FIFO (First-In, First-Out) com ponteiros de início e fim.
  - Operações de `enqueue` e `dequeue`.
- **[Lab 3: Fila de Prioridades e Heaps](./Lab3/)**
  - Implementação de Max-Heap utilizando vetor estático.
  - Algoritmos de ordenação estrutural: `peneirar para cima` (sift up) e `peneirar para baixo` (sift down).
  - Inserção e remoção mantendo a regra de prioridade (nó pai sempre maior que os filhos).

## 🚀 Como testar localmente

Como o código é fornecido em linguagem C pura, você precisará de um compilador como o GCC para rodar os testes na sua máquina.

1. Clone o repositório:
   `git clone https://github.com/SEU_USUARIO/Estrutura-de-Dados-C.git`

2. Navegue até a pasta do laboratório desejado (exemplo):
   `cd lab1`

3. Compile o código executando:
   `gcc main.c -o listaencadeada`

4. Execute o arquivo gerado:
   `.\listaencadeada.exe` (No Windows) ou `./listaencadeada` (No Linux/Mac)
