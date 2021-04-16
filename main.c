#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

#define MAX_ROW 3
#define MAX_COLUMN 3

char CheckWinner(char Arr[MAX_ROW][MAX_COLUMN]);

int main()
{
    char TicTacToe[MAX_ROW][MAX_COLUMN] = {}, X = 88, O = 79, winner = '\0';
    bool start = true;
    int UIRow = 0, UIColumn = 0; //User Input
    int countSpotsFilled = 0;

   while(countSpotsFilled<9)
    {
        do
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
        winner = CheckWinner(TicTacToe);
        system("cls");
        countSpotsFilled++;

        if(winner != 'n' && winner != '\0')
        {
            printf("\n***%c is the winner***\n", winner);
            system("pause");
        }
        else if(countSpotsFilled>=9)
        {
            printf("game finished with no winners");
        }

    }

    return 0;
}

char CheckWinner(char Arr[MAX_ROW][MAX_COLUMN])
{
    if((Arr[0][0] == Arr[0][1]) && (Arr[0][0] == Arr[0][2]))
    {
        return Arr[0][0];
    }
    else if((Arr[1][0] == Arr[1][1]) && (Arr[1][0] == Arr[1][2]))
    {
        return Arr[1][0];
    }
    else if((Arr[2][0] == Arr[2][1]) && (Arr[2][0] == Arr[2][2]))
    {
        return Arr[2][0];
    }
    else if((Arr[0][0] == Arr[1][0]) && (Arr[0][0] == Arr[2][0]))
    {
        return Arr[0][0];
    }
    else if((Arr[0][1] == Arr[1][1]) && (Arr[0][1] == Arr[2][1]))
    {
        return Arr[0][1];
    }
    else if((Arr[0][2] == Arr[1][2]) && (Arr[0][2] == Arr[2][2]))
    {
        return Arr[0][2];
    }
    else if((Arr[0][0] == Arr[1][1]) && (Arr[0][0] == Arr[2][2]))
    {
        return Arr[0][0];
    }
    else if((Arr[0][2] == Arr[1][1]) && (Arr[0][2] == Arr[2][0]))
    {
        return Arr[0][2];
    }
    else
    {
        return 'n';
    }
}
