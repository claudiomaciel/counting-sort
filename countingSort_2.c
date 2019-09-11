#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_LENGTH 100000
#define MAX_VALUE 10000

void countingSort(int *arr) {
	
	int i, aux[MAX_VALUE], out[MAX_LENGTH];
	
	//inicializando vetor auxiliar(aux)
	for(i = 0; i < MAX_VALUE; i++)
		aux[i] = 0;
	//contagem da ocorrencia dos valores do vetor principal(arr)
	for(i = 0; i < MAX_LENGTH; i++)
		aux[arr[i]]++;
	//soma dos valores no vetor auxiliar(aux)(ex: valorAtual = valorAtual - valorAnterior)
	for(i = 1; i < MAX_VALUE; i++)
		aux[i] += aux[i - 1];
	//ordenando no vetor de saida(out)
	//o valor no vetor principal(arr) servira de indice no vetor auxiliar(aux) e o valor neste indice no vetor auxiliar
	//servira de indice - 1 no vetor de saida, assim, ordenando o valor do vetor principal no vetor de saida
	for(i = 0; i < MAX_LENGTH; i++) {
		out[aux[arr[i]] - 1] = arr[i];
		aux[arr[i]]--;
	}
	//imprimindo
//	for(i = 0; i < MAX_LENGTH; i++)
//		printf("%d ", out[i]);
}

int main() {
	
	srand(time(NULL));
	
	int i, n[MAX_LENGTH];
	clock_t start, end;
	double tempo;
	
//	printf("Aleatorio\n");
	for(i = 0; i < MAX_LENGTH; i++) {
		n[i] = rand() % MAX_VALUE;
//		printf("%d ", n[i]);
	}
//	printf("\n");

	//calculando tempo
	start = clock();
	countingSort(n);
	end = clock();
	tempo = ((double) (end - start)) / CLOCKS_PER_SEC;
	
	printf("Tempo: %lf", tempo);
	
	return 0;
}
