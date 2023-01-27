#define N 4
#include <stdbool.h>
#include <stdio.h>
//funksioni me printu zgjidhjen
void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}

int main() {

    printf("Working just fine");
	return 0;
}