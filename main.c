#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_ROW 3
#define MAX_COLUMN 3
#define MAX_NAMELENGTH 20

char CheckWinner(char Arr[MAX_ROW][MAX_COLUMN]);
int userInput(char Arr[MAX_ROW][MAX_COLUMN], bool start);
int EndGame(char Arr[MAX_ROW][MAX_COLUMN], int *countSpotsFilled);
void FreshStart(char Arr[MAX_ROW][MAX_COLUMN], int *countSpotsFilled);
void DrawGame(char Arr[MAX_ROW][MAX_COLUMN]);
void SaveGame(char _winner);

int main()
{
    char TicTacToe[MAX_ROW][MAX_COLUMN] = {}, startingPlayer;
    bool start = true;
    int countSpotsFilled = 0;

    do
    {
        system("cls");
        printf("Who starts first(x/o)-q- to quit: ");
        scanf("%c", &startingPlayer);
    }while((tolower(startingPlayer) != 'x' && tolower(startingPlayer) != 'o') && tolower(startingPlayer)!='q');

    if('o' == tolower(startingPlayer))
    {
        start = false;
    }
    else if('q' == tolower(startingPlayer))
    {
        return 0;
    }

   while(countSpotsFilled<9)
    {
        if(userInput(TicTacToe, start)==0)
        {
            break;
        }
        start = !start;
        if(EndGame(TicTacToe, &countSpotsFilled) == 0)
        {
            break;
        }
        countSpotsFilled++;
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
int userInput(char Arr[MAX_ROW][MAX_COLUMN], bool start)
{
    int UIRow = 0, UIColumn = 0; //User Input

    do
    {
        DrawGame(Arr);

        do
        {
            printf("Choose Row: ");
            while(scanf("%d", &UIRow)!=1)
            {
                if(tolower(getchar())=='q')
                {
                    return 0;
                }
                system("cls");
                DrawGame(Arr);
                printf("Choose Row: ");
                fflush(stdin);
            }
            --UIRow;
        }while(UIRow < 0 || UIRow > 2);

        do
        {
            printf("Choose Column: ");
            while(scanf("%d", &UIColumn)!=1)
            {
                if(tolower(getchar())=='q')
                {
                    return 0;
                }
                system("cls");
                DrawGame(Arr);
                printf("Choose Column: ");
                fflush(stdin);
            }
            --UIColumn;
        }while(UIColumn < 0 || UIColumn > 2);
        system("cls");
    }while(Arr[UIRow][UIColumn] == 88 || Arr[UIRow][UIColumn] == 79);

    Arr[UIRow][UIColumn] = (start)? 88 : 79;
    system("cls");
    return 1;
}

int EndGame(char Arr[MAX_ROW][MAX_COLUMN], int *countSpotsFilled)
{
    char winner = '\0', NewGame = '\0';

    winner = CheckWinner(Arr);
    if(winner != 'n' && winner != '\0')
    {
        fflush(stdin);
        printf("\n***%c is the winner***\n", winner);
        printf("Do you wish to save the game?(y/n): ");
        if(tolower(getchar()) == 'y')
        {
            fflush(stdin);
            SaveGame(winner);
        }
        fflush(stdin);
        printf("Do you wish to start new game?(y/n): ");
        do
        {
            scanf("%c", &NewGame);
            fflush(stdin);
        }while(tolower(NewGame) != 'y' && tolower(NewGame)!='n');
        fflush(stdin);
    }
    else if(*countSpotsFilled>=9)
    {
        fflush(stdin);
        printf("game finished with no winners");
        printf("Do you wish to save the game?(y/n): ");
        if(tolower(getchar()) == 'y')
        {
            fflush(stdin);
            SaveGame(winner);
        }
        fflush(stdin);
        printf("Do you wish to start new game?(y/n): ");
        do
        {
            scanf("%c", &NewGame);
            fflush(stdin);
        }while(tolower(NewGame) != 'y' && tolower(NewGame)!='n');
        fflush(stdin);
    }

    if(tolower(NewGame) == 'y')
    {
        FreshStart(Arr, &countSpotsFilled);
        return 1;
    }
    else if(tolower(NewGame) == 'n')
    {
        return 0;
    }
    else
    {
        return 2;
    }
}

void FreshStart(char Arr[MAX_ROW][MAX_COLUMN], int *countSpotsFilled)
{
    *countSpotsFilled = 0;
    memset(Arr, 0, sizeof(Arr[0][0])*MAX_ROW*MAX_COLUMN);
}
void DrawGame(char Arr[MAX_ROW][MAX_COLUMN])
{
        for(int IndexRow = 0; IndexRow < MAX_ROW; IndexRow++)
        {
            for(int IndexColumn = 0; IndexColumn < MAX_COLUMN; IndexColumn++)
            {
                printf("| %c |", Arr[IndexRow][IndexColumn]);
            }
            printf("\n");
        }
}

void SaveGame(char _winner)
{
    char firstPlayer[MAX_NAMELENGTH] = {};
    char secondPlayer[MAX_NAMELENGTH] = {};
    char pX = 'X', pO = 'O';
    FILE *fPointer;

    printf("Who was X: ");
    fgets(firstPlayer, MAX_NAMELENGTH, stdin);

    printf("Who was O: ");
    fgets(secondPlayer, MAX_NAMELENGTH, stdin);

    if(firstPlayer[(strlen(firstPlayer)-1)] == '\n')
    {
        firstPlayer[(strlen(firstPlayer)-1)] = 0;
    }
    if(secondPlayer[(strlen(secondPlayer)-1)] == '\n')
    {
        secondPlayer[(strlen(secondPlayer)-1)] = 0;
    }

    if(pX == _winner)
    {
            fPointer = fopen("StoredGameResults.txt", "a");
            fprintf(fPointer, "\n%s(%c) has won over %s(%c)\n", firstPlayer, pX, secondPlayer, pO);
            fclose(fPointer);
    }
    else if(pO == _winner)
    {
        fPointer = fopen("StoredGameResults.txt", "a");
        fprintf(fPointer, "\n%s(%c) has won over %s(%c)\n", secondPlayer, pO, firstPlayer, pX);
        fclose(fPointer);
    }
    else
    {
        fPointer = fopen("StoredGameResults.txt", "a");
        fprintf(fPointer, "\nits a tie between %s and %s\n", firstPlayer, secondPlayer);
        fclose(fPointer);
    }
    system("pause");
    fflush(stdin);
    system("cls");

}
