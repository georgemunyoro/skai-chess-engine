#include "board.h"
#include <bits/stdc++.h>

using namespace std;

void RunPerft(int maxDepth, int debug)
{
    Board MainBoard = Board();
    MainBoard.SetFen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    printf("-------------------------------------------------------------------------------------\n");
    printf("| DEPTH |   NODE   |  CAPTURES | ENPAS | CASTLES | PROMOTIONS | CHECKMATES | CHECKS |\n");
    printf("--------+----------+-----------+-------+---------+------------+------------+---------\n");
    for (int i = 0; i < maxDepth; ++i) {
        auto res = MainBoard.Perft(i, debug);
        printf(
            "|%7d|%10d|%11d|%7d|%9d|%12d|%12d|%8d|\n",
            res.depth, res.nodes, res.captures, res.enPas, res.castles, res.promotions, res.checkmates, res.checks);
    }
    printf("-------------------------------------------------------------------------------------\n");
}

int main()
{
    Board MainBoard = Board();
    MainBoard.SetFen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    // MainBoard.SetFen("r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - 0 1");

    for (;;) {
        auto currentMove = MainBoard.RandomMove();
        MainBoard.MakeMove(currentMove);
        MainBoard.Draw();
        cout << GetRef(currentMove.initial) << GetRef(currentMove.target) << endl;
        MainBoard.UndoMove();

        getchar();
    }

    return 0;
}
