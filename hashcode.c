#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 15

unsigned int hashCode(char texto[10]) {
	unsigned int hash = 29;
	int index = 0;
	while (texto[index] != '\0') {
		hash *= texto[index];
		index++;
	}
	return hash;
}

int main() {

	char texto[10];
	printf("Digite um texto: ");
	scanf("%s", texto);

	unsigned int hash = hashCode(texto);

	printf("HashCode: %u\n", hash);

	hash = hash % MAX_SIZE;

	printf("HashCode: %u\n", hash);

	return 0;
}
