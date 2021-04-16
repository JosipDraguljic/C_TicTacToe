#include <stdio.h>
#include <stdlib.h>

int main()
{
    char TicTacToe[3][3] = {{'a', 'b', 'c'}, {'a', 'b', 'c'}, {'a', 'b', 'c'}};

    printf("%c", TicTacToe[0][0]);
    printf("%c", TicTacToe[1][1]);

    return 0;
}
