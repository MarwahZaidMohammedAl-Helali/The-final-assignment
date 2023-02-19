
#include "helper.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <ctime>
#include <string>


namespace pf
{
    const int kRows = 30;
    const int kColumns = 30;
    char kBoard[kRows][kColumns];

    std::vector<Position> POS;

    char set_board(char c , int x , int y){

        kBoard[x][y] = c;

    }
    char get_board( int x , int y){

        return kBoard[x][y]  ;

    }
    int ClearScreen()
    {
        #if defined(_WIN32)
            return std::system("cls");
        #elif defined(__linux__) || defined(__APPLE__)
            return std::system("clear");
        #endif
    }

    int Pause()
    {
        #if defined(_WIN32)
            return std::system("pause");
        #elif defined(__linux__) || defined(__APPLE__)
            return std::system(R"(read -p "Press any key to continue . . . " dummy)");
        #endif
    }
    void empty_board(int brow , int bcol){

        for (int row = 0; row < brow; ++row)
        for (int col = 0; col < bcol; ++col)
        {
                kBoard[row][col] = ' ';
        }
        int middle_row = ((1+brow)/2)-1 ;
        int middle_col = ((1+bcol)/2)-1 ;
        POS.push_back({1, middle_row,middle_col,'A'});
        kBoard[middle_row][middle_col] = 'A';

    }
    void object_pos(int brow , int bcol , int zc , int hc , int Pc , int rc){
//////////////////////zombie//////////////
        for(int i = 0 ; i<zc ; i++){
            srand((i+2)*i+time(0));
            int r1 = rand() % (brow);
            int c1 = rand() % (bcol);
            if((r1 == POS[0].x) && (c1 == POS[0].y)){
                i--;
                continue ;

            }
            kBoard[r1][c1] = i+49 ;
            POS.push_back({i+1 , r1, c1 , 'Z'});
        }
//////////////////////health///////////
        for(int i = 0 ; i<hc ; i++){
            srand(i+time(0)+POS.size());
            int r1 = rand() % (brow);
            int c1 = rand() % (bcol);
            if((r1 == POS[0].x) && (c1 == POS[0].y)){
                i--;
                continue ;

            }
            bool found = false;
            for (int j = 0; j < POS.size(); j++) {
                if (POS[j].x == r1 && POS[j].y == c1) {
                  found = true;
                  break;
                }
            }
            if (found) {
                i--;
                continue;
              }
            kBoard[r1][c1] = 'h' ;
            POS.push_back({i+1,r1, c1 , 'h'});
        }
/////////////////////////////////////////////
        for(int i = 0 ; i<Pc ; i++){
            srand(i+time(0)+POS.size());
            int r1 = rand() % (brow);
            int c1 = rand() % (bcol);
            if((r1 == POS[0].x) && (c1 == POS[0].y)){
                i--;
                continue ;

            bool found = false;
            for (int j = 0; j < POS.size(); j++) {
                if (POS[j].x == r1 && POS[j].y == c1) {
                  found = true;
                  break;
                }
            }
            if (found) {
                i--;
                continue;
              }

            }
            kBoard[r1][c1] = 'P' ;
            POS.push_back({i+1,r1, c1 , 'P'});
        }
        for(int i = 0 ; i<rc ; i++){
            srand(i+time(0)+POS.size());
            int r1 = rand() % (brow);
            int c1 = rand() % (bcol);
            if((r1 == POS[0].x) && (c1 == POS[0].y)){
                i--;
                continue ;

            }
            bool found = false;
            for (int j = 0; j < POS.size(); j++) {
                if (POS[j].x == r1 && POS[j].y == c1) {
                  found = true;
                  break;
                }
            }
            if (found) {
                i--;
                continue;
              }
            kBoard[r1][c1] = 'r' ;
            POS.push_back({i+1,r1, c1 , 'r'});
        }


    }
    void Arrows_pos(int brow , int bcol , int ArC){
        for(int i = 0 ; i<ArC ; i++){
            srand(i+time(0)+POS.size());
            int r1 = rand() % (brow);
            int c1 = rand() % (bcol);
            if((r1 == POS[0].x) && (c1 == POS[0].y)){
                i--;
                continue ;

            }
            bool found = false;
            for (int j = 0; j < POS.size(); j++) {
                if (POS[j].x == r1 && POS[j].y == c1) {
                  found = true;
                  break;
                }
            }
            if (found) {
                i--;
                continue;
              }

            int random_arrow = std::rand() % 4;
            switch (random_arrow) {
              case 0:
                  kBoard[r1][c1] = '>' ;
                  POS.push_back({i+1,r1, c1 , '>'});
                break;
              case 1:
                  kBoard[r1][c1] = '<' ;
                  POS.push_back({i+1,r1, c1 , '<'});
                break;
              case 2 :
                  kBoard[r1][c1] = '^' ;
                  POS.push_back({i+1,r1, c1 , '^'});
                break ;
              case 3 :
                  kBoard[r1][c1] = 'v' ;
                  POS.push_back({i+1,r1, c1 , 'v'});
                break;
              default:

                break;
            }

        }
    }
    void CreateGameBoard(int brow , int bcol , int zc , int hc , int Pc , int rc)
    {
        empty_board(brow , bcol);
        object_pos(brow , bcol , zc , hc , Pc , rc);
        int random_count = std::rand() % bcol/1+2;
        Arrows_pos(brow , bcol,random_count);

   //     for (int i = 0; i < POS.size(); i++) {
   //         std::cout << POS[i].type << POS[i].i << ": (" << POS[i].x << ", " << POS[i].y << ")" << std::endl;
  //         }
    }

    void ShowGameBoard(int board_row, int board_col)
    {

        for(int j = 0 ; j < board_col/2+2 ; j ++){std::cout<<" " ;}
        std::cout<< ".: Alien VS Zombie :." << std::endl ;
        for (int row = 0; row < board_row; ++row)
        {
            std::cout<<"    ";
            for(int i = 0 ; i < board_col ; i++){
                std::cout<<"+-" ;
            }
            std::cout<<"+" <<std::endl;
            if(row<9) std::cout<< " " << row+1 <<"  ";
            else std::cout<< " " << row+1 <<" ";

            for (int col = 0; col < board_col; ++col)
            {
                std::cout << "|" << kBoard[row][col] ;
            }
            std::cout <<"|" <<std::endl;
        }
        std::cout<<"    ";
        for(int i = 0 ; i < board_col ; i++){
                std::cout<<"+-" ;
            }
            std::cout<<"+" << std::endl ;

                if(board_col<9){
                    std::cout<<std::endl;
                    std::cout<<"     " ;
                    for(int i=0 ; i<board_col ; i++){
                        std::cout<< i+1 <<" " ;
                    }
                }
                else{
                    int x = 0 ;
                    for(int i=0 ; i< 23 ; i++){
                        std::cout<<" " ;
                    }
                    for(int i=0 ; i< board_col-9 ; i++){
                        if(i<10) std::cout<< 1 <<" " ;
                        else if (i>=10 && i < 20) std::cout<< 2 <<" " ;
                        else std::cout<< 3 <<" " ;
                    }
                    std::cout<<std::endl;
                    std::cout<<"     " ;

                    while(true){
                        for(int i=0 ; i<9 ; i++){
                            if( x >= board_col){
                                break;
                            }
                            std::cout<< i+1 <<" " ;
                            x++ ;
                        }
                        if( x >= board_col){
                            break;
                        }
                        std::cout<<0<<" " ;
                        x++;
                    }
                }
        std::cout<<std::endl<<std::endl ;
    }
    std::vector<pf::Position> getPOS(){
        return POS ;
    }

}

