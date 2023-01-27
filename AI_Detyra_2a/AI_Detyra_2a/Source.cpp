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

// functioni me shiku poziten se a eshte e sigurt me vendose mretereshen a jo
bool isSafe(int board[N][N], int row, int col)
{
    int i, j;
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQUtil(int board[N][N], int col)
{
    if (col >= N)
        return true;


    for (int i = 0; i < N; i++) {
        // nese eshte sigurt me vendose mbretereshen ne poziten i,col, vendose
        if (isSafe(board, i, col)) {

            board[i][col] = 1;


            if (solveNQUtil(board, col + 1))
                return true;

            //backtrack nese kushti lart eshte false
            board[i][col] = 0; // BACKTRACK 
        }
    }


    return false;
}

int main() {
    int board[N][N] = { { 0, 0, 0, 0 },
                       { 0, 0, 0, 0 },
                       { 0, 0, 0, 0 },
                       { 0, 0, 0, 0 } };

    printSolution(board);
    return true;
	return 0;
}