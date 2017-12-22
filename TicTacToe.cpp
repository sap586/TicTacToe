#include <iostream>
#include <utility>
#include <stdlib.h>
using namespace std;

int victoryFlag = 0;

class TicTacToe {
    public:
        TicTacToe();
        pair<int, int> Location;
        enum Player {NoPlayer=0, Player1, Player2} p;
        enum Result {NoWin=0, Win, InvalidMove} r;
        Result MakeMove(Player player, int x, int y);
        void ResetGame();
        void ChangePlayer();
    private:
        void Draw();
        char matrix[3][3];
        void CheckResult(Player p);
};

void TicTacToe::ResetGame() {
    matrix[0][0] = '.';
    matrix[0][1] = '.';
    matrix[0][2] = '.';
    matrix[1][0] = '.';
    matrix[1][1] = '.';
    matrix[1][2] = '.';
    matrix[2][0] = '.';
    matrix[2][1] = '.';
    matrix[2][2] = '.';
    Draw();
    p = Player1;
    cout<<"Player"<<p<<"'s turn\n";
}

void TicTacToe::CheckResult(Player p) {
    if (p == Player1) {
        if (matrix[0][0] == 'X' && matrix[0][1] == 'X' && matrix[0][2] == 'X' || matrix[1][0] == 'X' && matrix[1][1] == 'X' && matrix[1][2] == 'X' || matrix[2][0] == 'X' && matrix[2][1] == 'X' && matrix[2][2] == 'X' || matrix[0][0] == 'X' && matrix[1][0] == 'X' && matrix[2][0] == 'X' || matrix[0][1] == 'X' && matrix[1][1] == 'X' && matrix[2][1] == 'X' || matrix[0][2] == 'X' && matrix[1][2] == 'X' && matrix[2][2] == 'X' || matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X' || matrix[2][0] == 'X' && matrix[1][1] == 'X' && matrix[0][2] == 'X') {
            this->r = Win;
        }
    } else {
        if (matrix[0][0] == 'O' && matrix[0][1] == 'O' && matrix[0][2] == 'O' || matrix[1][0] == 'O' && matrix[1][1] == 'O' && matrix[1][2] == 'O' || matrix[2][0] == 'O' && matrix[2][1] == 'O' && matrix[2][2] == 'O' || matrix[0][0] == 'O' && matrix[1][0] == 'O' && matrix[2][0] == 'O' || matrix[0][1] == 'O' && matrix[1][1] == 'O' && matrix[2][1] == 'O' || matrix[0][2] == 'O' && matrix[1][2] == 'O' && matrix[2][2] == 'O' || matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O' || matrix[2][0] == 'O' && matrix[1][1] == 'O' && matrix[0][2] == 'O') {
            this->r = Win;
        }
    }
}

TicTacToe::Result TicTacToe::MakeMove(Player player, int x, int y) {
    if (matrix[x][y] == '.') {
        if (this->p == Player1) {
            matrix[x][y] = 'X';
        } else {
            matrix[x][y] = 'O';
        }
        Draw();
        CheckResult(p);
        if (this->r == Win) {
            victoryFlag = 1;
            cout<<"Player"<<this->p<<" Wins\n";
            return this->r;
        }
        ChangePlayer();
    } else {
        cout<<"Invalid move, try again.\n";
        this->r = InvalidMove;
    }
    return this->r;
}

void TicTacToe::ChangePlayer() {
    if (p == Player1) {
        p = Player2;
    } else {
        p = Player1;
    }
    cout<<"Player"<<p<<"'s turn\n";
}

void TicTacToe::Draw() {
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
}

TicTacToe::TicTacToe() {
    Player p = Player1;
    Result r = NoWin;
    ResetGame();
}



int main() {
    TicTacToe game;
    while(1) {
        cout<<"Enter X : ";
        cin>>game.Location.first;
        cout<<"Enter Y : ";
        cin>>game.Location.second;
        game.MakeMove(game.p, game.Location.first, game.Location.second);
        if (victoryFlag == 1) {
            break;
        }
        
    }
    return 0;
}

