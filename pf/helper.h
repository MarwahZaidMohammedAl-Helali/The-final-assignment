#ifndef PF_HELPER_H
#define PF_HELPER_H
#include <vector>


namespace pf
{
    struct Position {
        int i , x, y;
        char type ;

    };
    int ClearScreen();
    int Pause();
    std::vector<Position> getPOS();
    void CreateGameBoard(int , int , int ,int , int , int);
    void ShowGameBoard(int,int);
    char set_board(char,int ,int );
    char get_board(int,int);
}

#endif
