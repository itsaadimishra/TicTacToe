#include <iostream>
using namespace std;

char turn = 'x';
int row, col;
bool draw = false;

char game[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

void displaygame()
{
    system("cls");

    cout << "     T I C K   T A C   T O E " << endl;
    cout << "/nPlayer[X]" << endl;
    cout << "/nPlayer[O]" << endl;
    cout << "     |     |          " << endl;
    cout << "  " << game[0][0] << "  | " << game[0][1] << "   | " << game[0][2] << endl;
    cout << "_____|_____|_____     " << endl;
    cout << "     |     |          " << endl;
    cout << "  " << game[1][0] << "  | " << game[1][1] << "   | " << game[1][2] << endl;
    cout << "_____|_____|_____     " << endl;
    cout << "     |     |          " << endl;
    cout << "  " << game[2][0] << "  | " << game[2][1] << "   | " << game[2][2] << endl;
    cout << "_____|_____|_____     " << endl;
    cout << "     |     |          " << endl;
}
void player_turn()
{

    if (turn == 'x')
    {
        cout << "Player 1 [X] Turn";
    }
    if (turn == 'o')
    {
        cout << "Player  [o] Turn";
    }

    int chance;
    cin >> chance;

    switch (chance)
    {
    case 1:
        row = 0;
        col = 0;
        break;
    case 2:
        row = 0;
        col = 1;
        break;
    case 3:
        row = 0;
        col = 2;
        break;
    case 4:
        row = 1;
        col = 0;
        break;
    case 5:
        row = 1;
        col = 1;
        break;
    case 6:
        row = 1;
        col = 2;
        break;
    case 7:
        row = 2;
        col = 0;
        break;
    case 8:
        row = 2;
        col = 1;
        break;
    case 9:
        row = 2;
        col = 2;
        break;
    default:
        cout << "invalid choice";
        break;
    }
    if (game[row][col] > 48 && game[row][col] < 58)
    {
        if (turn == 'x')
        {
            game[row][col] = 'x';
            turn = 'o';
        }
        else if (turn == 'o')
        {
            game[row][col] = 'o';
            turn = 'x';
        }
    }
    else
    {
        cout << "Box is already filled." << endl;
    }
    displaygame();
}
bool gameover()
{
    for (int i = 0; i < 3; i++)
    {
        if ((game[i][0] == game[i][1] && game[i][0] == game[i][2]) || (game[0][i] == game[1][i] && game[0][i] == game[2][i]) || (game[0][i] == game[1][i] && game[0][i] == game[2][i]))
        {
            return false;
        }
        if ((game[0][0] == game[1][1] && game[0][0] == game[2][2]) || (game[0][2] == game[1][1] && game[0][2] == game[2][0]))
        {
            return false;
        }
        //game playing
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (game[i][j] != 'x' && game[i][j] != 'o')
                {
                    return true;
                }
        //game draw
        draw = true;
        return false;
    }
}

int main()
{
    while (gameover())
    {
        displaygame();
        player_turn();
        gameover();
    }
    if (turn == 'x' && draw == false)
    {
        cout << "player 2[O] WINS!!!" << endl;
    }
    else if (turn == 'o' && draw == false)
    {
        cout << "player 1[X] WINS!!!" << endl;
    }
    else
    {
        cout << "GAME DRAW!!" << endl;
    }
    return 0;
}