/**
 * Design a Tic-tac-toe game that is played between two players on a n x n grid.
 * 
 * You may assume the following rules:
 *  1- A move is guaranteed to be valid and is placed on an empty block.
 *  2- Once a winning condition is reached, no more moves is allowed.
 *  3- A player who succeeds in placing n of their marks in a horizontal, 
 * vertical, or diagonal row wins the game.
 */

class TicTacToe {
private:
    vector<int> rowJudge;
    vector<int> colJudge;
    int diag, anti, total;

public:
    TicTacToe(int n) : total(n), rowJudge(n), colJudge(n), diag(0), anti(0){}
    
    int move(int row, int col, int player) {
        int add = player == 1 ? 1 : -1;

        diag += row == col ? add : 0;
        anti += row == total - col - 1 ? add : 0;

        rowJudge[row] += add;
        colJudge[col] += add;

        if (abs(rowJudge[row]) == total || abs(colJudge[col]) == total || abs(diag) == total || abs(anti) == total) 
            return player;
        return 0;
    }
};