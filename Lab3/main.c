#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define LEN 10 // Definindo o tamanho máximo do heap

typedef struct // Definindo a estrutura do heap
{
    int valores[LEN]; // Array para armazenar os valores do heap
    int qtde;         // Contador de elementos no heap
} heap;

int filho_esq(int pai) { return 2 * pai + 1; }        // Calcula o índice do filho esquerdo dado o índice do pai
int filho_dir(int pai) { return 2 * pai + 2; }        // Calcula o índice do filho direito dado o índice do pai
int pai(int filho) { return (filho - 1) / 2; }        // Calcula o índice do pai dado o índice do filho
int ultimo_pai(heap *h) { return (h->qtde - 2) / 2; } // Calcula o índice do último pai no heap

void peneirar(heap *h, int pai)
{
    int esq = filho_esq(pai);
    int dir = filho_dir(pai);
    int maior = pai;
    // Verifica se o filho esquerdo é maior que o pai
    if (esq < h->qtde && h->valores[esq] > h->valores[maior])
        maior = esq;
    // Verifica se o filho direito é maior que o maior atual
    if (dir < h->qtde && h->valores[dir] > h->valores[maior])
        maior = dir;

    if (maior != pai)
    {
        // Troca os valores
        int temp = h->valores[pai];
        h->valores[pai] = h->valores[maior];
        h->valores[maior] = temp;

        // Recursivamente peneira o sub-heap afetado
        peneirar(h, maior);
    }
}
// Função para peneirar um elemento para cima (usada na inserção)
void peneirar_para_cima(heap *h, int filho_idx)
{
    int pai_idx = pai(filho_idx);
    if (pai_idx >= 0 && h->valores[filho_idx] > h->valores[pai_idx])
    {
        // Troca os valores
        int temp = h->valores[filho_idx];
        h->valores[filho_idx] = h->valores[pai_idx];
        h->valores[pai_idx] = temp;

        // Recursivamente peneira para cima
        peneirar_para_cima(h, pai_idx);
    }
}
// Função para construir o heap a partir de um array de valores
void construir(heap *h)
{
    for (int i = ultimo_pai(h); i >= 0; i--) // Começa do último pai e vai até a raiz
        peneirar(h, i);                      // Peneira cada sub-heap para garantir a propriedade do heap
}
// Função para inserir um valor no heap
void inserir(heap *h, int valor)
{
    if (h->qtde >= LEN)
    {
        printf("Heap cheio! Não é possível inserir %d\n", valor);
        return;
    }
    h->valores[h->qtde] = valor; // Insere o novo valor na próxima posição disponível
    h->qtde++;
    peneirar_para_cima(h, h->qtde - 1); // Peneira o novo valor para cima para manter a propriedade do heap
}
// Função para remover o elemento de maior prioridade (o máximo) do heap
void remover(heap *h)
{
    if (h->qtde == 0)
    {
        printf("Heap vazio! Não é possível remover.\n");
        return;
    }
    else if (h->qtde == 1) // Se houver apenas um elemento, basta removê-lo
    {
        h->qtde--;
        return;
    }
    h->valores[0] = h->valores[h->qtde - 1]; // Move o último elemento para a raiz
    h->qtde--;
    peneirar(h, 0); // Peneira a raiz para baixo para restaurar a propriedade do heap
}
// Função para exibir os elementos do heap
void mostrar(heap *h)
{
    for (int i = 0; i < h->qtde; i++) // Imprime cada elemento do heap
        printf("%d ", h->valores[i]);
    printf("\n");
}

int main(void)
{
    heap *h = malloc(sizeof(heap));
    h->qtde = 0;

    // TESTE 1: Inserção de elementos
    printf("--- TESTE 1: Insercao de elementos ---\n");
    for (int i = 1; i <= 10; i++)
    {
        inserir(h, i);
        printf("Inserido %d: ", i);
        mostrar(h);
    }

    // TESTE 2: Remoção de elementos
    printf("\n--- TESTE 2: Remocao de elementos ---\n");
    printf("Removendo em ordem de prioridade:\n");

    while (h->qtde > 0)
    {
        int max = h->valores[0];
        printf("Removendo maximo %d: ", max);
        remover(h);
        mostrar(h);
    }

    free(h);
    Sleep(999999);
    return 0;
}