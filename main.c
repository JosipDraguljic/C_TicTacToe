#include <stdio.h>
#include <stdlib.h>

#define MAX_ROW 3
#define MAX_COLUMN 3

int main()
{
    char TicTacToe[MAX_ROW][MAX_COLUMN] = {};

    for(int IndexRow = 0; IndexRow < MAX_ROW; IndexRow++)
    {
        for(int IndexColumn = 0; IndexColumn < MAX_COLUMN; IndexColumn++)
        {
            printf("| %c |", TicTacToe[IndexRow][IndexColumn]);
        }
        printf("\n");
    }

    return 0;
}
