#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <omp.h>

#define BOARD_SIZE 8

bool eight_queens(int *board);
int get_next_position(int *board);
bool is_valid(int *board, int pos);
void print_board(int board[BOARD_SIZE][BOARD_SIZE]);

int main()
{
    int board[BOARD_SIZE * BOARD_SIZE] = { 0 };

    print_board(board);

    return 0;
}

bool eight_queens(int *board)
{
    int pos = get_next_position(board);
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
        if (is_valid_position)
    }
}

int get_next_position(int *board)
{
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++)
        if (board[i] == 0)
            return i;
    return -1;
}

bool is_valid_position(int *board, int pos)
{
    // Checa a linha
    for (int i = 0; i < BOARD_SIZE; i++)
        if (board[i] == 1)
            return false;
    // Checa a coluna e diagonal
    for (int i = 0; i < BOARD_SIZE; i++)
        if (i)
}

void print_board(int board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}