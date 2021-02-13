/*
 * Dove vs Hawks.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_X 10
#define MAX_Y 10

#define FREE 0
#define DOVE 1
#define HAWK 2

#define MAX_POPULATION 12

void initTab(int matriz[MAX_X][MAX_Y]) {
	for (int i = 0; i < MAX_POPULATION; i++) {
		int x = rand() % MAX_X;
		int y = rand() % MAX_Y;

		while (matriz[x][y] < 0) {
			x = rand() % MAX_X;
			y = rand() % MAX_Y;
		}

		int val = rand() % 3;
		while (val == 0) {
			val = rand() % 3;
		}
		matriz[x][y] = val;
	}
}

void printTab(int matriz[MAX_X][MAX_Y]) {
	for (int i = 0; i < MAX_X; i++) {
		for (int j = 0; j < MAX_Y; j++) {
			printf("%i ", matriz[i][j]);
		}
		printf("\n");
	}
}

/*
 * printTab round saida padrão.
 */
void printRound(int pround) {
	printf("#-------------------#\n");
	printf("|-----Round: %i-----|\n", pround);
	printf("#-------------------#\n");
}

int processConflito(int ave, int vizinho) {
	int result;
	if (ave == DOVE && vizinho == DOVE) {
		result = DOVE;
	} if (ave != vizinho) {
		result = HAWK;
	} else {
		result = DOVE;
	}
	return result;
}

void processVizinhos(int matriz[MAX_X][MAX_Y],  int x, int y) {
	int index = 0;

	int ave = matriz[x][y];
	for (int i =-1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			int novoX = x + i;
			int novoY = y + j;
			if ((i == 0 && j == 0) || (novoX < 0 || novoX >= MAX_X) || (novoY < 0 || novoY >= MAX_Y)) {
				continue;
			}
			int vizinho = matriz[novoX][novoY];
			int result = processConflito(ave, vizinho);
			matriz[novoX][novoY] = result;
		}
	}
}


void process(int matriz[MAX_X][MAX_Y]) {
	for (int i = 0; i < MAX_X; i++) {
		for (int j = 0; j < MAX_Y; j++) {
			processVizinhos(matriz, i, j);
		}
	}
}

int qtdDove(int matriz[MAX_X][MAX_Y]) {
	int qtde = 0;

	for (int i = 0; i < MAX_X; i++) {
		for (int j = 0; j < MAX_Y; j++) {
			if (matriz[i][j] == DOVE) {
				qtde++;
			}
		}
	}

	return qtde;
}

int qtdHawk(int matriz[MAX_X][MAX_Y]) {
	int qtde = 0;

	for (int i = 0; i < MAX_X; i++) {
		for (int j = 0; j < MAX_Y; j++) {
			if (matriz[i][j] == HAWK) {
				qtde++;
			}
		}
	}

	return qtde;
}

void printTabPop(int matriz[MAX_X][MAX_Y]) {
	int DOVEs = qtdDove(matriz);
	int gavioes = qtdHawk(matriz);

	printf("\nDove: %i\nHawk: %i\n", DOVEs, gavioes);

}

int main() {

	int round = 1;

	int tabuleiro[MAX_X][MAX_Y] = {0};

	initTab(tabuleiro);

	while (1) {

		system("clear");

		printRound(round);

		printTab(tabuleiro);

		printTabPop(tabuleiro);

		process(tabuleiro);

		int op;
		printf("\nNext round?\n1 - Y\n");
		scanf("%i", &op);
		if (op != 1) {
			return 0;
		}

		round += 1;
	}

	return 0;
}
