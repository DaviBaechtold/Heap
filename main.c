// Davi Baechtold Campos
//Atividade 7 - Heap

#include <stdio.h>
#include <time.h>

void heapify(int arr[], int n, int i);
void troca(int *a, int *b);

void criaHeap(int arr[], int n) {
    int ultimaFolha = (n/2) - 1;

    for (int i=ultimaFolha; i>-0; i--)
        heapify(arr, n, i);
}

void heapify(int arr[], int n, int i) {
    int maior = i;
    int Esquerdo = 2*i + 1;
    int Direito = 2*i + 2;

    if (Esquerdo < n && arr[Esquerdo] > arr[maior])
        maior = Esquerdo;
    if (Direito < n && arr[Direito] > arr[maior])
        maior = Direito;
    if (maior != i) {
        troca(&arr[i], &arr[maior]);
        heapify(arr, n, maior);
    }
        
}
void buscar(int numero, int arr[], int n) {
    for (int i=0; i<n; i++) {
        if (arr[i]==numero) {
            printf("\nNumero encontrado!");
            return;
        }
    }
    printf("\nNumero nao encontrado...");
}

void troca(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void imprimirArray(int arr[], int n) {
    for (int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main() {
    srand(time(NULL));

    int arr[500];

    // printf("\n\nArray gerado: [");
    for (int i=0; i<500; i++) {
        arr[i] = 1 + rand()%100; 
        
    }

    printf("Array gerado: \n");
    imprimirArray(arr, 500);
    
    criaHeap(arr, 500);
    printf("\n");
    
    printf("Heap criado: \n");
    imprimirArray(arr, 500);

    int numero = 1 + rand()%100;
    printf("\nNumero sorteado: %d", numero);
    buscar(numero, arr, 500);

    return 0;
}