/*
Programa do passo do cavalo.</br>
Dada uma posição no tabuleiro, o cavalo deve percorrer todas
as 64 casas sem repetir nenhuma.

Compilar:
gcc cavalo.c -o cavalo
Digite uma posicao inicial entre {0 0} e {7 7}
*/
#include <stdio.h>

void inicializarTabuleiro(int *tabuleiro){
	int i = 0, j = 0;
	for(i = 0; i < 8 ; i ++){
		for(j = 0; j < 8; j++){
			tabuleiro[i*8 + j] = 0;
		}
	}	

}

void imprimeTabuleiro(int rodada, int tabuleiro[8][8]){
	system("cls");
	printf("*****Rodada %i*****\n\n", rodada);
	int i = 0, j = 0;
	for(i = 0; i < 8 ; i ++){
		for(j = 0; j < 8; j++){
			printf("%i\t", tabuleiro[i][j]);
		}
		printf("\n");
	}
}

int menor(int vetor[8])
{
	int i;
	for(i = 0; i < 8 ; i++)
	{
		printf("%i ", vetor[i]);
	}
	printf("\n\n");
	
	int min = 7;
	int indice = 0;	
	for(i = 0; i < 8 ; i++)
	{
		if(vetor[i] < min && vetor[i] != 0)
		{
			min = vetor[i];
			indice = i;
		}
	}
	return indice;
}

void jogadas(int x, int y, int tabuleiro[8][8], int *vet)
{
	int vetor[8] = { 0, 0, 0, 0, 0, 0, 0, 0};
	int qtde = 0;
	if(((x-1 > 0) || (y-2 > 0) || (x-1 < 8) || (y-2 < 8)))
	{
		if(tabuleiro[x-1][y-2] == 0 && (x-1 >= 0) && (y-2 >= 0)){
			x = x - 1;
			y = y - 2;
			qtde = 0;
			if(tabuleiro[x-1][y-2] == 0 && (x-1 >= 0) && (y-2 >= 0)){
				qtde++;
			}
			if(tabuleiro[x+1][y-2] == 0 && (x+1 <= 7) && (y -2 >= 0)){
				qtde++;
			}
			if(tabuleiro[x+2][y-1] == 0 && (x+2 <= 7) && (y -1 >= 0)){
				qtde++;
			}
			if(tabuleiro[x+2][y+1] == 0 && (x+2 <= 7) && (y+1 <= 7)){
				qtde++;
			}
			if(tabuleiro[x+1][y+2] == 0 && (x+1 <= 7) && (y+2 <= 7)){
				qtde++;
			}
			if(tabuleiro[x-1][y+2] == 0 && (x-1 >= 0) && (y+2 <= 7)){
				qtde++;
			}
			if(tabuleiro[x-2][y+1] == 0 && (x-2>= 0) && (y+1 <= 7)){
				qtde++;
			}
			if(tabuleiro[x-2][y-1] == 0 && (x-2 >= 0) && (y-1 >= 0)){
				qtde++;
			}
			x = x + 1;
			y = y +	2;
			vetor[0] = qtde;
		}
		if(tabuleiro[x+1][y-2] == 0 && (x+1 <= 7) && (y -2 >= 0)){
			x = x + 1;
			y = y - 2;
			qtde = 0;
			if(tabuleiro[x-1][y-2] == 0 && (x-1 >= 0) && (y-2 >= 0)){
				qtde++;
			}
			if(tabuleiro[x+1][y-2] == 0 && (x+1 <= 7) && (y -2 >= 0)){
				qtde++;
			}
			if(tabuleiro[x+2][y-1] == 0 && (x+2 <= 7) && (y -1 >= 0)){
				qtde++;
			}
			if(tabuleiro[x+2][y+1] == 0 && (x+2 <= 7) && (y+1 <= 7)){
				qtde++;
			}
			if(tabuleiro[x+1][y+2] == 0 && (x+1 <= 7) && (y+2 <= 7)){
				qtde++;
			}
			if(tabuleiro[x-1][y+2] == 0 && (x-1 >= 0) && (y+2 <= 7)){
				qtde++;
			}
			if(tabuleiro[x-2][y+1] == 0 && (x-2>= 0) && (y+1 <= 7)){
				qtde++;
			}
			if(tabuleiro[x-2][y-1] == 0 && (x-2 >= 0) && (y-1 >= 0)){
				qtde++;
			}
			x = x - 1;
			y = y +	2;
			vetor[1] = qtde;
		}
		if(tabuleiro[x+2][y-1] == 0 && (x+2 <= 7) && (y -1 >= 0)){
			x = x + 2;
			y = y - 1;
			qtde = 0;
			if(tabuleiro[x-1][y-2] == 0 && (x-1 >= 0) && (y-2 >= 0)){
				qtde++;
			}
			if(tabuleiro[x+1][y-2] == 0 && (x+1 <= 7) && (y -2 >= 0)){
				qtde++;
			}
			if(tabuleiro[x+2][y-1] == 0 && (x+2 <= 7) && (y -1 >= 0)){
				qtde++;
			}
			if(tabuleiro[x+2][y+1] == 0 && (x+2 <= 7) && (y+1 <= 7)){
				qtde++;
			}
			if(tabuleiro[x+1][y+2] == 0 && (x+1 <= 7) && (y+2 <= 7)){
				qtde++;
			}
			if(tabuleiro[x-1][y+2] == 0 && (x-1 >= 0) && (y+2 <= 7)){
				qtde++;
			}
			if(tabuleiro[x-2][y+1] == 0 && (x-2>= 0) && (y+1 <= 7)){
				qtde++;
			}
			if(tabuleiro[x-2][y-1] == 0 && (x-2 >= 0) && (y-1 >= 0)){
				qtde++;
			}
			x = x - 2;
			y = y +	1;
			vetor[2] = qtde;
		}
		if(tabuleiro[x+2][y+1] == 0 && (x+2 <= 7) && (y+1 <= 7)){
			x = x + 2;
			y = y + 1;
			qtde = 0;
			if(tabuleiro[x-1][y-2] == 0 && (x-1 >= 0) && (y-2 >= 0)){
				qtde++;
			}
			if(tabuleiro[x+1][y-2] == 0 && (x+1 <= 7) && (y -2 >= 0)){
				qtde++;
			}
			if(tabuleiro[x+2][y-1] == 0 && (x+2 <= 7) && (y -1 >= 0)){
				qtde++;
			}
			if(tabuleiro[x+2][y+1] == 0 && (x+2 <= 7) && (y+1 <= 7)){
				qtde++;
			}
			if(tabuleiro[x+1][y+2] == 0 && (x+1 <= 7) && (y+2 <= 7)){
				qtde++;
			}
			if(tabuleiro[x-1][y+2] == 0 && (x-1 >= 0) && (y+2 <= 7)){
				qtde++;
			}
			if(tabuleiro[x-2][y+1] == 0 && (x-2>= 0) && (y+1 <= 7)){
				qtde++;
			}
			if(tabuleiro[x-2][y-1] == 0 && (x-2 >= 0) && (y-1 >= 0)){
				qtde++;
			}
			x = x - 2;
			y = y - 1;
			vetor[3] = qtde;
		}
		if(tabuleiro[x+1][y+2] == 0 && (x+1 <= 7) && (y+2 <= 7)){
			x = x + 1;
			y = y + 2;
			qtde = 0;
			if(tabuleiro[x-1][y-2] == 0 && (x-1 >= 0) && (y-2 >= 0)){
				qtde++;
			}
			if(tabuleiro[x+1][y-2] == 0 && (x+1 <= 7) && (y -2 >= 0)){
				qtde++;
			}
			if(tabuleiro[x+2][y-1] == 0 && (x+2 <= 7) && (y -1 >= 0)){
				qtde++;
			}
			if(tabuleiro[x+2][y+1] == 0 && (x+2 <= 7) && (y+1 <= 7)){
				qtde++;
			}
			if(tabuleiro[x+1][y+2] == 0 && (x+1 <= 7) && (y+2 <= 7)){
				qtde++;
			}
			if(tabuleiro[x-1][y+2] == 0 && (x-1 >= 0) && (y+2 <= 7)){
				qtde++;
			}
			if(tabuleiro[x-2][y+1] == 0 && (x-2>= 0) && (y+1 <= 7)){
				qtde++;
			}
			if(tabuleiro[x-2][y-1] == 0 && (x-2 >= 0) && (y-1 >= 0)){
				qtde++;
			}
			x = x - 1;
			y = y -	2;
			vetor[4] = qtde;
		}
		if(tabuleiro[x-1][y+2] == 0 && (x-1 >= 0) && (y+2 <= 7)){
			x = x - 1;
			y = y + 2;
			qtde = 0;
			if(tabuleiro[x-1][y-2] == 0 && (x-1 >= 0) && (y-2 >= 0)){
				qtde++;
			}
			if(tabuleiro[x+1][y-2] == 0 && (x+1 <= 7) && (y -2 >= 0)){
				qtde++;
			}
			if(tabuleiro[x+2][y-1] == 0 && (x+2 <= 7) && (y -1 >= 0)){
				qtde++;
			}
			if(tabuleiro[x+2][y+1] == 0 && (x+2 <= 7) && (y+1 <= 7)){
				qtde++;
			}
			if(tabuleiro[x+1][y+2] == 0 && (x+1 <= 7) && (y+2 <= 7)){
				qtde++;
			}
			if(tabuleiro[x-1][y+2] == 0 && (x-1 >= 0) && (y+2 <= 7)){
				qtde++;
			}
			if(tabuleiro[x-2][y+1] == 0 && (x-2>= 0) && (y+1 <= 7)){
				qtde++;
			}
			if(tabuleiro[x-2][y-1] == 0 && (x-2 >= 0) && (y-1 >= 0)){
				qtde++;
			}
			x = x + 1;
			y = y -	2;
			vetor[5] = qtde;
		}
		if(tabuleiro[x-2][y+1] == 0 && (x-2>= 0) && (y+1 <= 7)){
			x = x - 2;
			y = y + 1;
			qtde = 0;
			if(tabuleiro[x-1][y-2] == 0 && (x-1 >= 0) && (y-2 >= 0)){
				qtde++;
			}
			if(tabuleiro[x+1][y-2] == 0 && (x+1 <= 7) && (y -2 >= 0)){
				qtde++;
			}
			if(tabuleiro[x+2][y-1] == 0 && (x+2 <= 7) && (y -1 >= 0)){
				qtde++;
			}
			if(tabuleiro[x+2][y+1] == 0 && (x+2 <= 7) && (y+1 <= 7)){
				qtde++;
			}
			if(tabuleiro[x+1][y+2] == 0 && (x+1 <= 7) && (y+2 <= 7)){
				qtde++;
			}
			if(tabuleiro[x-1][y+2] == 0 && (x-1 >= 0) && (y+2 <= 7)){
				qtde++;
			}
			if(tabuleiro[x-2][y+1] == 0 && (x-2>= 0) && (y+1 <= 7)){
				qtde++;
			}
			if(tabuleiro[x-2][y-1] == 0 && (x-2 >= 0) && (y-1 >= 0)){
				qtde++;
			}
			x = x + 2;
			y = y - 1;
			vetor[6] = qtde;
		}
		if(tabuleiro[x-2][y-1] == 0 && (x-2 >= 0) && (y-1 >= 0)){
			x = x - 2;
			y = y - 1;
			qtde = 0;
			if(tabuleiro[x-1][y-2] == 0 && (x-1 >= 0) && (y-2 >= 0)){
				qtde++;
			}
			if(tabuleiro[x+1][y-2] == 0 && (x+1 <= 7) && (y -2 >= 0)){
				qtde++;
			}
			if(tabuleiro[x+2][y-1] == 0 && (x+2 <= 7) && (y -1 >= 0)){
				qtde++;
			}
			if(tabuleiro[x+2][y+1] == 0 && (x+2 <= 7) && (y+1 <= 7)){
				qtde++;
			}
			if(tabuleiro[x+1][y+2] == 0 && (x+1 <= 7) && (y+2 <= 7)){
				qtde++;
			}
			if(tabuleiro[x-1][y+2] == 0 && (x-1 >= 0) && (y+2 <= 7)){
				qtde++;
			}
			if(tabuleiro[x-2][y+1] == 0 && (x-2>= 0) && (y+1 <= 7)){
				qtde++;
			}
			if(tabuleiro[x-2][y-1] == 0 && (x-2 >= 0) && (y-1 >= 0)){
				qtde++;
			}
			x = x + 2;
			y = y +	1;
			vetor[7] = qtde;
		}
	}

	int i = 0;
	for(i = 0; i < 8; i++){
		//printf("qntd de opcoes = %i\n", vetor[i]);
		*vet = vetor[i];
		vet++;
	}
}

void mudarXY(int op, int *x, int *y){
	switch(op){
		case 0:
			*x -= 1;
			*y -= 2;
		break;
		
		case 1:
			*x += 1;
			*y -= 2;
		break;
		
		case 2:
			*x += 2;
			*y -= 1;
		break;
		
		case 3:			
			*x += 2;
			*y += 1;
		break;
		
		case 4:
			*x += 1;
			*y += 2;
		break;
		
		case 5:
			*x -= 1;
			*y += 2;
		break;
		
		case 6:
			*x-= 2;
			*y += 1;
		break;
				
		case 7:
			*x -= 2;
			*y -= 1;
		break;	
	}
}

void voltarXY(int op, int *x, int *y){
	switch(op){
		case 0:
			*x += 1;
			*y += 2;
		break;
		
		case 1:
			*x -= 1;
			*y += 2;
		break;
		
		case 2:
			*x -= 2;
			*y += 1;
		break;
		
		case 3:			
			*x -= 2;
			*y -= 1;
		break;
		
		case 4:
			*x -= 1;
			*y -= 2;
		break;
		
		case 5:
			*x += 1;
			*y -= 2;
		break;
		
		case 6:
			*x += 2;
			*y -= 1;
		break;
				
		case 7:
			*x += 2;
			*y += 1;
		break;	
	}
}

int main(){
	int tabuleiro[8][8];
	inicializarTabuleiro(tabuleiro);
	
	system("cls");
	int rodadas = 0;	
	imprimeTabuleiro(rodadas, tabuleiro);
	rodadas++;
	
	int x = 0, y = 0;
	printf("Digite a posicao inicial:\n");
	scanf("%i %i", &x, &y);
	tabuleiro[x][y] = rodadas;
	imprimeTabuleiro(rodadas, tabuleiro);
	
	while(rodadas < 65){
		int vetor[8] = {0, 0, 0, 0, 0, 0, 0, 0};
		jogadas(x,y, tabuleiro, &vetor);
		int op = menor(vetor);
		
		mudarXY(op, &x, &y);		
	
		rodadas++;
		if(rodadas == 64){
			int i, j;
			for(i = 0; i < 8; i++){
				for(j = 0; j < 8; j++){
					if(tabuleiro[i][j] == 0){
						tabuleiro[i][j] = 64;
					}
				}
			}
			imprimeTabuleiro(rodadas, tabuleiro);
			printf("FIM\n");
			return 0;
		}	
		
		tabuleiro[x][y] = rodadas;
		printf("(%i,%i)\n", x,y);
		imprimeTabuleiro(rodadas, tabuleiro);
		/*printf("prox rodada?\n");
		char ch;
		scanf("%c", &ch);*/
		system("pause");
	}
	return 0;
}
