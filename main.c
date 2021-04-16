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
        do
        {
            for(int indexRow = 0; indexRow < MAX_ROW; indexRow++)
            {
                for(int IndexColumn = 0; IndexColumn < MAX_COLUMN; IndexColumn++)
                {
                    printf("| %c |", TicTacToe[IndexRow][IndexColumn]);
                    //start = !start;
                }
                printf("\n");
            }

            do
            {
                printf("Choose Row: ");
                scanf("%d", &UIRow);
                --UIRow;
            }while(UIRow < 0 || UIRow > 2);

            do
            {
                printf("Choose Column: ");
                scanf("%d", &UIColumn);
                --UIColumn;
            }while(UIColumn < 0 || UIColumn > 2);
            system("cls");
        }while(TicTacToe[UIRow][UIColumn] == X || TicTacToe[UIRow][UIColumn] == O);

        TicTacToe[UIRow][UIColumn] = (start)? X : O;
        start = !start;

        system("cls");
    }

    return 0;
}
