#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
// Estrutura de uma célula da lista duplamente ligada
typedef struct Celula
{
    int valor;               // Valor armazenado na célula
    struct Celula *proximo;  // Ponteiro para o próximo elemento
    struct Celula *anterior; // Ponteiro para o elemento anterior
} Celula;

// Estrutura da fila com ponteiros para início e fim
typedef struct
{
    Celula *head; // Ponteiro para o primeiro elemento (início da fila)
    Celula *tail; // Ponteiro para o último elemento (fim da fila)
    int qtde;     // Contador de elementos na fila
} Queue;

// === PROTÓTIPOS DAS FUNÇÕES ===
Celula *cria_celula(int valor);
Queue *cria_queue();
void enqueue(Queue *queue, int valor);
int dequeue(Queue *queue);
void show(Queue *queue);

// Cria uma nova célula com o valor especificado
Celula *cria_celula(int valor)
{
    Celula *nova = (Celula *)malloc(sizeof(Celula)); // Malloc dinamico com o valor da celula inputado por valor
    nova->valor = valor;                             // Jogando o novo valor para a variavel que armazena o valor da celula
    nova->proximo = NULL;                            // Ponteiro da proxima celula null
    nova->anterior = NULL;                           // Ponteiro da celula anterior aponta para null
    return nova;
}

// Cria uma nova fila vazia
Queue *cria_queue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue)); // Aloca memória para a estrutura Queue
    queue->head = NULL;                            // Iniciando com o head null
    queue->tail = NULL;                            // iniciando com a tail null
    queue->qtde = 0;                               // Iniciando com 0 itens na fila
    return queue;                                  // Retorna a fila criada
}

// Operação ENQUEUE: insere elemento no final da fila (FIFO)
void enqueue(Queue *queue, int valor)
{
    Celula *nova = cria_celula(valor); // Cria uma nova celula com o valor inputado

    if (queue->tail == NULL)
    { // Se tail estiver vazio(fila vazia)
        // Fila vazia: head e tail apontam para a nova célula
        queue->head = nova;
        queue->tail = nova;
    }
    else
    {
        // Caso nao esteja adiciona no final
        nova->anterior = queue->tail; // A nova célula aponta para o antigo tail
        queue->tail->proximo = nova;  // O antigo tail aponta para a nova celula
        queue->tail = nova;           // Atualiza tail para a nova última célula
    }
    queue->qtde++; // Conta mais uma celula na fila

    // Imprime a fila após inserção
    printf("Inserido %d: ", valor);
    show(queue);
}

// Operação DEQUEUE: remove elemento do início da fila (FIFO)
int dequeue(Queue *queue)
{
    if (queue->head == NULL)
    { // se head estiver vazio
        // Fila vazia
        printf("Erro: fila vazia!\n");
        return -1;
    }

    Celula *remover = queue->head; // Joga a celula a remover para head
    int valor = remover->valor;    //

    if (queue->head == queue->tail)
    {
        // Único elemento na fila
        queue->head = NULL;
        queue->tail = NULL;
    }
    else
    {
        // Remove do início
        queue->head = queue->head->proximo;
        queue->head->anterior = NULL;
    }

    free(remover);
    queue->qtde--;

    // Imprime a fila após remoção
    printf("Valor removido: %d, Fila restante: ", valor);
    show(queue);

    return valor;
}

// Exibe todos os elementos da fila (do início ao fim)
void show(Queue *queue)
{
    Celula *atual = queue->head;
    while (atual != NULL)
    {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

int main(void)
{
    Queue *queue = cria_queue();

    printf("=== INSERINDO ELEMENTOS ===\n");
    enqueue(queue, 10);
    enqueue(queue, 2);
    enqueue(queue, 0);
    enqueue(queue, 4);
    enqueue(queue, 5);
    enqueue(queue, 5);
    enqueue(queue, 6);
    enqueue(queue, 2);
    enqueue(queue, 8);
    enqueue(queue, 1);
    enqueue(queue, 9);

    printf("\n=== REMOVENDO ELEMENTOS ===\n");
    while (queue->head != NULL)
    {
        dequeue(queue);
    }
    Sleep(999999);
    return 0;
}