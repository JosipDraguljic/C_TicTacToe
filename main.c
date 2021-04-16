#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

#define MAX_ROW 3
#define MAX_COLUMN 3

int main()
{
    char TicTacToe[MAX_ROW][MAX_COLUMN] = {}, X = 88, O = 79;
    bool start = true;

    for(int IndexRow = 0; IndexRow < MAX_ROW; IndexRow++)
    {
        for(int IndexColumn = 0; IndexColumn < MAX_COLUMN; IndexColumn++)
        {
            TicTacToe[IndexRow][IndexColumn] = (start)? X : O;
            printf("| %c |", TicTacToe[IndexRow][IndexColumn]);
            start = !start;
        }
        printf("\n");
    }

    return 0;
}
