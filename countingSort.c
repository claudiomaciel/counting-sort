#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100000

void countingSort(int *arr) {
	
	int i, aux[MAX], out[MAX];
	
	//inicializando vetor auxiliar(aux)
	for(i = 0; i < MAX; i++)
		aux[i] = 0;
	//contagem da ocorrencia dos valores do vetor principal(arr)
	for(i = 0; i < MAX; i++)
		aux[arr[i]]++;
	//soma dos valores no vetor auxiliar(aux)(ex: valorAtual = valorAtual - valorAnterior)
	for(i = 1; i < MAX; i++)
		aux[i] += aux[i - 1];
	//ordenando no vetor de saida(out)
	//o valor no vetor principal(arr) servira de indice no vetor auxiliar(aux) e o valor neste indice no vetor auxiliar
	//servira de indice - 1 no vetor de saida, assim, ordenando o valor do vetor principal no vetor de saida
	for(i = 0; i < MAX; i++) {
		out[aux[arr[i]] - 1] = arr[i];
		aux[arr[i]]--;
	}
	//imprimindo
//	for(i = 0; i < MAX; i++)
//		printf("%d ", out[i]);
}

int main() {
	
	int i, n[MAX];
	clock_t start, end;
	double cre_t, dec_t, cd_t, dc_t;
	
	//Crescente
	for(i = 0; i < MAX; i++) {
		n[i] = i;
//		printf("%d ", n[i]);
	}
//	printf("\n");

	//calculando tempo
	start = clock();
	countingSort(n);
	end = clock();
	cre_t = ((double) (end - start)) / CLOCKS_PER_SEC;
	
	//Decrescente
	for(i = MAX - 1; i >= 0; i--) {
		n[i] = i;
//		printf("%d ", n[i]);
	}
//	printf("\n");

	//calculando tempo	
	start = clock();
	countingSort(n);
	end = clock();
	dec_t = ((double) (end - start)) / CLOCKS_PER_SEC;
	
	//Crescente Descrescente
	int j;
	for(i = 0; i < MAX / 2; i++) {
		n[i] = i;
//		printf("%d ", n[i]);
	}
	for(i = MAX / 2, j = MAX - 1; i < MAX; i++, j--) {
		n[i] = j;
//		printf("%d ", n[i]);
	}
//	printf("\n");

	//calculando tempo
	start = clock();
	countingSort(n);
	end = clock();
	cd_t = ((double) (end - start)) / CLOCKS_PER_SEC;
	
	//Decrescente Crescente
	for(i = 0, j = MAX - 1; i < MAX / 2; i++, j--) {
		n[i] = j;
//		printf("%d ", n[i]);
	}
	for(i = MAX / 2, j = 0; i < MAX; i++, j++) {
		n[i] = j;
//		printf("%d ", n[i]);
	}
//	printf("\n");

	//calculando tempo
	start = clock();
	countingSort(n);
	end = clock();
	dc_t = ((double) (end - start)) / CLOCKS_PER_SEC;
	
	printf("Crescente: %lf\n", cre_t);
	printf("Decrescente: %lf\n", dec_t);
	printf("Crescente Decrescente: %lf\n", cd_t);
	printf("Decrescente Crescente: %lf\n", dc_t);
	
	return 0;
}
