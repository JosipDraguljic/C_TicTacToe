#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

#define MAX_ROW 3
#define MAX_COLUMN 3

int main()
{
    char TicTacToe[MAX_ROW][MAX_COLUMN] = {}, X = 88, O = 79;
    bool start = true;
    int UIRow = 0, UIColumn = 0; //User Input

   while(1)
    {
        for(int IndexRow = 0; IndexRow < MAX_ROW; IndexRow++)
        {
            for(int IndexColumn = 0; IndexColumn < MAX_COLUMN; IndexColumn++)
            {
                printf("| %c |", TicTacToe[IndexRow][IndexColumn]);
                //start = !start;
            }
            printf("\n");
        }

        printf("Choose Row: ");
        scanf("%d", &UIRow);
        printf("Choose Column: ");
        scanf("%d", &UIColumn);

        TicTacToe[UIRow][UIColumn] = (start)? X : O;
        start = !start;

        system("cls");
    }

    return 0;
}
