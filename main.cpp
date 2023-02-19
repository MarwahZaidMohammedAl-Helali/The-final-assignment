// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: T13L
// Names: Marwah Zaid Mohammed AL-helali| | Thabit Mahmood Thabit Ahmed Ibrahim| khaled saeed yaslam joban| 
// IDs: (1211307415)  | (1211305813) |(1211306821)| 
// Emails: 1211307415@student.mmu.edu.my|1211305813@student.mmu.edu.my|
// Phones: +60166287972 | +60109189556 | +601140088286 |
// *********************************************************

#include <iostream>
#include "pf/helper.h"
//#include "pf/helper.cpp"
#include <vector>    ///// this for vector;
#include <cstdlib>  ////// this for rand();
#include <iomanip>  ////// this for setw() ;
#include <string>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <sstream>



using namespace std;
void game_initializer();
void new_setting(string) ;
void print_setting() ;
void commander(vector<pf::Position>);
void zombie_found(int);
void trail_remover();
void print_Alien_active();
void arrow();
void help();
void quite();
void up() ;
void down();
void left();
void right();
void health();
void find_left();
void find_right();
void find_down();
void find_up();
void rock();
void Pod();
void saveToFile();
void loadFromFile();
bool isStopType(char);
void selectWeapon();

class Weapon{

    private:
        int range ;
        int attack ;
        int strike ;
        bool selected ;
        string name ;
    public :
        Weapon(){
            range = 0 ;
            attack = 0 ;
            strike = 0 ;
            selected = false ;
            name = "no weapons" ;
        }
        Weapon(int r , int a , int s , bool se , string n){
            range = r ;
            attack = a ;
            strike = s ;
            selected = se ;
            name = n ;
        }
        int get_range(){
            return range ;
        }
        int get_attack() {
            return attack ;
        }

        string get_name() {
            return name ;
        }
        void printW() {
        cout << "weapon ==> " << name << ", range ==> " << range << ", attack ==> " << attack << endl;
    }




};

Weapon Sword(2,10, 100 , true , "Sword");
Weapon Axe(1,20, 3 ,false ,"Axe");

class Alien{

        int life = 50 ;
        int attack ;
        int range ;
        int x , y ;
        Weapon weapon;

    public :
        void printA(){
            cout<< "Alien     :  " << "life ==> " << char(3) << setfill('0') << setw(3)<<life <<
            ", attack ==> " << setfill('0') << setw(3)<< attack
            << ", range ==> " <<setfill('0') << setw(3)<< weapon.get_range() << " ==> " << weapon.get_name() <<endl;
        }
        void life_plus(){
            if(life + 20 > 100) life = 100;
            else life += 20 ;
        }
        void attack_plus(){
            attack += 20 ;
        }
        int get_attack(){
            return attack ;
        }
        void print_attack(){
            cout << attack ;
        }
        void life_minus(int x){
            life -= x ;
        }
        int get_life(){
            return life ;
        }
        void select_weapon(Weapon w) {
        weapon = w;
        attack += weapon.get_attack();
        range = weapon.get_range();
    }

};
//////////////////////
// Global Variables
//////////////////////
int board_row =3 ;
int board_col =19;
int zombi_count = 2  ;
int Health_count = 2 ;
int Pod_count = 1 ;
int Rock_count = 2 ;
bool next_arrow = false ;
bool stop ;
int newx ;
int newy ;
string GO_to = "stop" ;
bool A_active ;
Alien A ;
vector<bool> Z_active(zombi_count) ;
vector<pf::Position> POS ;
string Filename = "myFile.txt";
////////////////////////
///////////////////////
////objects///////////


class Zombie{

    private :
        int life ;
        int attack ;
        int range ;
    public :
        Zombie(int l , int a , int r ){
            life = l ; attack = a , range = r ;
        }

        static void printZombies(vector<Zombie> zombies) {
            for (int i = 0; i < zombies.size(); i++) {
                cout<<"      " ;
                cout << "Zombie " << setfill('0') << setw(2) << i+1 << " :  " ;
                if (zombies[i].life <= 0) {
                    cout << "Zombie is dead" << endl;
                } else {
                    cout << "life ==> " <<  char(3) <<setfill('0') << setw(3) <<zombies[i].life ;
                    cout << ", attack ==> " << setfill('0') << setw(3) << zombies[i].attack ;
                    cout << ", range ==> " << setfill('0') << setw(3) << zombies[i].range ;
                    cout << endl;
                }
            }
        }
        static void printZombies(vector<Zombie> zombies , int i) {

                cout << "Zombie " << setfill('0') << setw(2) << i+1 << " :  " ;
                if (zombies[i].life <= 0) {
                    cout << "Zombie is dead" << endl;
                } else {
                    cout << "life ==> " << char(3) <<setfill('0') << setw(3) << zombies[i].life ;
                    cout << ", attack ==> " << setfill('0') << setw(3) << zombies[i].attack ;
                    cout << ", range ==> " << setfill('0') << setw(3) << zombies[i].range ;
                    cout << endl;
                }
        }
        static void printZombiesesc(vector<Zombie> zombies , int x){

            for (int i = 0; i < zombies.size(); i++) {
                if(i == x ) continue ;
                cout<<"      " ;
                cout << "Zombie " << setfill('0') << setw(2) << i+1 << " :  " ;
                if (zombies[i].life < 0) {
                    cout << "Zombie is dead" << endl;
                } else {
                    cout << "life ==> " << char(3) <<setfill('0') << setw(3) << zombies[i].life ;
                    cout << ", attack ==> " << setfill('0') << setw(3) << zombies[i].attack ;
                    cout << ", range ==> " << setfill('0') << setw(3) << zombies[i].range ;
                    cout << endl;
                }
            }

        }

        void reduceLife(int amount) {
            life -= amount;
            if(life <= 0) life = 0 ;
        }
        int get_life(){
            return life ;
        }
        int get_range(){
            return range ;
        }
        void attack_alien(){
            A.life_minus(attack);
        }
        int get_attack(){
            return attack ;
        }
};
vector<Zombie> createZombies(int count) {
    std::vector<Zombie> zombies;
    for (int i = 0; i < count; i++) {
        int life = 50 + rand() % 151;  // random number between 50 and 200
        int attack = rand() % 26;  // random number between 0 and 25
        int range = 1 + rand() % 3;  // random number between 1 and 3
        // Get values for life, attack, and range from the user
        zombies.push_back(Zombie(life, attack, range));
    }
    return zombies;
}
vector<Zombie> zombies ;

////////////////////////////
/////////////////////////////
////////////main/////////////
int main()
{
    game_initializer();

    pf::ClearScreen();
    pf::CreateGameBoard(board_row,board_col,zombi_count,Health_count,Pod_count,Rock_count);

    POS = pf::getPOS() ;
    commander(POS) ;


    cout<<"Alien "<< char(1) <<" is Dead " << endl << endl ;


    cout<<"........:: GAME OVER ::........"  << endl << endl ;

    return 0;
}
//////////////////////////////
/////////////////////////////
//////////functions//////////
void game_initializer(){

    string state ;
    cout<< "Default Game Setting"<< endl;
    cout<< "--------------------"<< endl ;
    print_setting() ;
    cout<< "Do you wish to change Game setting (Y/N) => " ;
    cin >> state ;
    new_setting(state) ;

}
void new_setting(string st){
    string state = st ;
    if( (state == "Y") || (state=="y")) {
        pf::ClearScreen();
        cout << "Board Setting" << endl ;
        cout << "-------------" << endl ;
        cout<< endl;
        do{
            cout<< "Enter new Board Rows and must be odd Number      : " ;
            cin >> board_row ;
        }while(board_row%2 == 0);

        do{
            cout<< "Enter new Board Columns and must be odd Number   : " ;
            cin >> board_col ;
        }while(board_col%2 == 0);

        cout<< "Enter new Zombie Count     : " ;
        cin >> zombi_count ;
        cout << endl <<"Setting updated ......." << endl << endl;
    }
    cout << endl ;
    pf::Pause();

}
void print_setting(){

    cout<< "Board Rows       : " << board_row << endl;
    cout<< "Board Columns    : " << board_col << endl;
    cout<< "Zombie Count     : " << zombi_count << endl << endl ;
}
void commander(vector<pf::Position> POS){
    zombies = createZombies(zombi_count) ;
    string command ;
    int t = 0 ;
    while(true && A.get_life()> 0 ){
        t++;
        A_active = true ;
        pf::ClearScreen();
        pf::ShowGameBoard(board_row,board_col);
        print_Alien_active() ;
        A.printA();
        Zombie::printZombies(zombies);
     //   cout << POS[0].x+1 << " , " <<POS[0].y+1 << " "<< GO_to << "  " << A.get_attack() ;
        cout << endl <<"command > " ;
      //  GO_to = "stop" ;
        cin >> command ;
        if(command == "help"){
                help() ;
                continue;
        }
        else if(command == "quite") quite();
        else if(command == "arrow"){
            arrow() ;
            continue;
        }
        else if(command == "selectW") {

                selectWeapon();
                continue;
        }

     //   std::string myString = std::to_string(A.get_attack);

        else if(command == "save") saveToFile() ;
        else if(command == "load") loadFromFile() ;

        else if(command == "up" || command == "down"||command == "left"||command == "right")
        {

            do{
                if(command == "up" || GO_to == "up") {
                   up() ;
                   POS[0].x = newx ;
                 //  cout << GO_to << endl;
                   pf::Pause();
                }
                else if(command == "down" || GO_to == "down"){
                    down() ;
                    POS[0].x = newx ;
                 //   cout << GO_to << endl;
                    pf::Pause();
                }
                else if(command == "left" || GO_to == "left" ){
                    left() ;
                    POS[0].y = newy ;
                //    cout << GO_to << endl;
                    pf::Pause();
                }
                else if(command == "right" || GO_to == "right" ){
                    right() ;
                    POS[0].y = newy ;
               //     cout << GO_to << endl;
                    pf::Pause();
                }
                command = "stop";
                cout<<endl ;
            }while( next_arrow == true );

        }
        else {
            cout<<"Wrong Command please Try again with thoes commands : " << endl;
            help();
            continue;
        }
        cout<<endl ;

        pf::ClearScreen();

        pf::ShowGameBoard(board_row,board_col);
        print_Alien_active() ;
        A.printA();
        Zombie::printZombies(zombies);
        cout<<endl;
        pf::Pause() ;

        trail_remover();
        pf::ClearScreen();
        pf::ShowGameBoard(board_row,board_col);


/////////////////////////////////// pass zombies ////////////////////////////

        for(int j = 0 ; j < zombies.size() ; j ++){

            if(zombies[j].get_life()==0) continue ;

            A_active = false ;
            print_Alien_active() ;
            A.printA();
            Z_active[j]= true ;



            /////////////////// for printing only //////////////////////////
            for(int i = 0 ; i < zombies.size() ; i++){

                if(Z_active[i]== true) cout<<" ===> " ;
                else cout<<"      " ;
                Zombie::printZombies(zombies,i);

                Z_active[i]= false ;
            }

            ////////////////////////////////////////////////////////

            int z = j+1 ;
            cout<< endl <<"NOW IT'S ZOMBIE "<< z <<"'S TURN "<<endl << endl ;
            cout<<"Zombie in " <<POS[z].x+1 << " , " << POS[z].y+1 <<endl;

            srand((time(0)+j));
            int random_move = std::rand() % 4;
            pf::set_board(' ',POS[z].x,POS[z].y) ;

            switch (random_move) {
                int rowid  , colid ;

              case 0:
                  rowid = POS[z].x +1 ;
             //     cout<<POS[z].x+1 <<" ==> "<<rowid+1 << endl;

            //      cout<< "I see now at : " << pf::get_board(rowid,POS[z].y) ;
           //       cout<< "AT this pos  " << rowid+1 << " "<< POS[z].y << endl;
           //       cout<<( rowid+1 <= 0 ) << "  " << (isStopType(pf::get_board(rowid,POS[z].y)) )<< endl;

                  if(rowid+1 > board_row || isStopType(pf::get_board(rowid,POS[z].y)))
           //             cout<<"STOP " << endl ;
                            break;
                    else
                        POS[z].x = rowid ;

                break;
              case 1:
                  rowid = POS[z].x -1 ;
                  cout<<POS[z].x+1 <<" ==> "<<rowid +1<< endl;

          //        cout<< "I see now at : " << pf::get_board(rowid,POS[z].y) ;
         //         cout<< "AT this pos  " << rowid+1 << " "<< POS[z].y << endl;
         //         cout<<( rowid+1 <= 0 ) << "  " << (isStopType(pf::get_board(rowid,POS[z].y)) )<< endl;

                  if(rowid+1 <= 0 || isStopType(pf::get_board(rowid,POS[z].y)))
         //               cout<<"STOP " << endl ;
                            break;
                    else
                        POS[z].x = rowid ;

                break;
              case 2 :
                    colid = POS[z].y +1 ;
       //             cout<<POS[z].y+1 <<" ==> "<<colid+1 << endl;

       //             cout<< "I see now at : " << pf::get_board(POS[z].x,colid) ;
       //             cout<< "AT this pos  " << POS[z].x << " "<< colid+1 << endl;
       //             cout<<( colid+1 <= 0 )<<  "  "  <<( isStopType(pf::get_board(POS[z].x,colid)) )<< endl;

                    if(colid+1 > board_col || isStopType(pf::get_board(POS[z].x,colid)))
       //                 cout<<"STOP " << endl ;
                            break;
                    else
                        POS[z].y = colid ;


                break ;
              case 3 :
                  colid = POS[z].y -1 ;
        //          cout<<POS[z].y +1<<" ==> "<<colid+1 << endl ;

       //           cout<< "I see now a : " <<pf::get_board(POS[z].x,colid) ;
        //          cout<< "AT this pos  " << POS[z].x << " "<< colid+1 << endl;
      //            cout<<( colid+1 <= 0 )<<  "  "  <<( isStopType(pf::get_board(POS[z].x,colid)) )<< endl;


                  if(colid+1 <= 0 || isStopType(pf::get_board(POS[z].x,colid)))
      //                  cout<<"STOP " << endl ;
                            break;
                    else
                        POS[z].y = colid ;

                break;
              default:
      //              cout<<"No Move " ;
                break;
            }
            cout<< endl;
            pf::set_board(char(j+49),POS[z].x,POS[z].y) ;

            cout<<"Zombie now at " <<POS[z].x+1 << " , " << POS[z].y+1 <<endl;

            //cout<<"Zombie try to attack alien " << endl ;

            if(POS[0].x == POS[z].x){
                if(abs(POS[0].y - POS[z].y) <= zombies[j].get_range()){
                    cout<<"Zombie will attack alien " << endl ;
                    zombies[j].attack_alien();

                }
                else cout<<"OUT OF RANGE " << endl ;
            }
            else if(POS[0].y == POS[z].y){

                if(abs(POS[0].x - POS[z].x )<= zombies[j].get_range()){
                    cout<<"Zombie will attack alien " << endl ;
                    zombies[j].attack_alien();
                }
                else cout<<"OUT OF RANGE " << endl ;
            }
            else {
                    cout<<"OUT OF RANGE " << endl ;
            }


            pf::Pause();
            pf::ClearScreen();
            pf::ShowGameBoard(board_row,board_col);
        }
        pf::Pause();
        pf::ClearScreen();
        pf::ShowGameBoard(board_row,board_col);

    }
}
void help(){
    cout << endl ;
    cout << "1. UP      -  Move up." << endl ;
    cout << "2. Down    -  Move down." << endl ;
    cout << "3. left    -  Move left." << endl ;
    cout << "4. Right   -  Move right." << endl ;
    cout << "5. arrow   -  Change direction of arrow." << endl ;
    cout << "6. help    -  Display these user commands." << endl ;
    cout << "7. save    -  Save the game." << endl ;
    cout << "8. load    -  Load a game." << endl ;
    cout << "9. quite   -  Quite the game." << endl ;
    cout << "10. selectW   -  Select Weapon." << endl ;
    cout << endl ;
    pf::Pause();
}
void quite(){
    string state ;
    cout << endl;
    cout << "Are you sure to quite game (Y/N) : " ;
    cin >> state ;
    if((state == "Y") || (state=="y")){
        exit(0);
    }
    else{
        pf::Pause();
    }
}
void up(){
    GO_to = "stop" ;
    stop = false;
    next_arrow = false ;
    while(POS[0].x != 0 && (stop == false )){
        int rowid = POS[0].x - 1 ;
        for(int i=0 ; i < int(POS.size()) ; i++){
            if( (POS[i].x == rowid) && (POS[i].y==POS[0].y))
            {
                if(POS[i].type == 'h') {
                        health();
                }
                else if(POS[i].type == '>'){
                        find_right();
                        stop = true;
                        POS[i].x= 100 ;
                        break;
                }
                else if(POS[i].type == '<'){
                        find_left();
                        stop = true;
                        POS[i].x= 100 ;
                        break;
                }
                else if(POS[i].type == '^'){
                        find_up();
                        POS[i].x= 100 ;
                        break;
                       // GO_to = "up" ;
                }
                else if(POS[i].type == 'v'){
                        find_down();
                        stop = true;
                        POS[i].x= 100 ;
                        break;
                }
                else if(POS[i].type == 'r'){
                        stop = true ;
                        rock();
                }
                else if(POS[i].type == 'P'){
                        Pod();
                }
                else if(POS[i].type == 'Z'){
                        zombie_found(i);
                        if(zombies[i-1].get_life() >= 0 ) break;

                }
                POS[i].type = 'x' ;
            }
            else {
                    next_arrow = false ;
                }
        }
        pf::set_board('.',POS[0].x,POS[0].y);
        POS[0].x = POS[0].x - 1 ;

        newx = POS[0].x ;
        cout<< newx +1 << " , " << POS[0].y+1 <<endl ;

    }
    cout<<endl ;
    pf::set_board('A',POS[0].x,POS[0].y);
  //  cout<< "up is done" << endl;


}
void down(){
    GO_to = "stop" ;
    stop = false;
    next_arrow = false ;
    while(POS[0].x != board_row-1 && (stop == false )){
        int rowid = POS[0].x + 1 ;
        for(int i=0 ; i < POS.size() ; i++){
            if( (POS[i].x == rowid) && (POS[i].y==POS[0].y))
            {
                if(POS[i].type == 'h') {
                        health();
                }
                else if(POS[i].type == '>'){
                        find_right();
                        stop = true;
                        POS[i].x= 100 ;
                        break;
                }
                else if(POS[i].type == '<'){
                        find_left();
                        stop = true;
                        POS[i].x= 100 ;
                        break;
                }
                else if(POS[i].type == '^'){
                        find_up();
                        stop = true;
                        POS[i].x= 100 ;
                        break;
                }
                else if(POS[i].type == 'v'){
                        find_down();
                        POS[i].x= 100 ;
                        break;
                      //  GO_to = "down" ;
                }
                else if(POS[i].type == 'r'){
                        stop = true ;
                        rock();
                }
                else if(POS[i].type == 'P'){
                    Pod();
                }
                else if(POS[i].type == 'Z'){
                        zombie_found(i);
                        if(zombies[i-1].get_life() >= 0 ) break;

                }

                POS[i].type = 'x' ;
            }
            else {
                    next_arrow = false ;
                }
        }
        pf::set_board('.',POS[0].x,POS[0].y);
        POS[0].x = POS[0].x + 1 ;
        newx = POS[0].x ;
        cout<< POS[0].x +1<< " , " << POS[0].y +1 <<endl ;


    }
    pf::set_board('A',POS[0].x,POS[0].y);
    cout<<endl ;
  //  cout<< "down is done" << endl;


}
void left(){
    GO_to = "stop" ;
    stop = false ;
    next_arrow = false ;
    while( (POS[0].y != 0) && (stop == false )){
        int colid = POS[0].y - 1 ;
        for(int i=0 ; i < POS.size() ; i++){
            if( (POS[i].x == POS[0].x) && (POS[i].y==colid))
            {
                if(POS[i].type == 'h') {
                        health();
                }
                else if(POS[i].type == '>'){
                        find_right();
                        stop = true;
                        POS[i].x= 100 ;
                        break;

                }
                else if(POS[i].type == '<'){
                        find_left();
                        POS[i].x= 100 ;
                        break;
                    //    GO_to = "left" ;
                    //    stop = true;
                }
                else if(POS[i].type == '^'){
                        find_up();
                        stop = true;
                        POS[i].x= 100 ;
                        break;

                }
                else if(POS[i].type == 'v'){
                        find_down();
                        stop = true;
                        POS[i].x= 100 ;
                        break;
                }
                else if(POS[i].type == 'r'){
                        stop = true ;
                        rock();
                }
                else if(POS[i].type == 'P'){
                    Pod();
                }
                else if(POS[i].type == 'Z'){
                        zombie_found(i);
                        if(zombies[i-1].get_life() >= 0 ) break;
                }

                POS[i].type = 'x' ;
            }
            else {
                    next_arrow = false ;
                }
        }
        pf::set_board('.',POS[0].x,POS[0].y);
        POS[0].y = POS[0].y - 1 ;
        newy = POS[0].y ;
        cout<< POS[0].x+1 << " , " << POS[0].y+1 << endl;


    }
    cout<<endl ;
    pf::set_board('A',POS[0].x,POS[0].y);

   // cout<< "left is done" << endl;

}
void right(){
    GO_to = "stop" ;
    stop = false;
    next_arrow = false ;
    while(  (POS[0].y != board_col-1) && (stop == false )){
        int colid = POS[0].y + 1 ;
        for(int i=0 ; i < POS.size() ; i++){
            if( (POS[i].x == POS[0].x) && (POS[i].y==colid))
            {
                if(POS[i].type == 'h') {
                    health();
                }
                else if(POS[i].type == '>'){
                        find_right();
                        POS[i].x= 100 ;
                        break;
                     //   GO_to = "right";
                     //   stop == true ;

                }
                else if(POS[i].type == '<'){
                        find_left();
                        stop = true ;
                        POS[i].x= 100 ;
                        break;

                }
                else if(POS[i].type == '^'){
                        find_up();
                        stop = true ;
                        POS[i].x= 100 ;
                        break;

                }
                else if(POS[i].type == 'v'){
                        find_down();
                        stop = true ;
                        POS[i].x= 100 ;
                        break;
                }
                else if(POS[i].type == 'r'){
                        stop = true ;
                        rock();
                }
                else if(POS[i].type == 'P'){
                    Pod();
                }
                else if(POS[i].type == 'Z'){

                        zombie_found(i);
                        if(zombies[i-1].get_life() >= 0 ) break;
                }
                POS[i].type = 'x' ;
            }
            else {
                    next_arrow = false ;
                }
        }
        pf::set_board('.',POS[0].x,POS[0].y);
        POS[0].y = POS[0].y + 1 ;
        newy = POS[0].y ;
        cout<< POS[0].x+1 << " , " << POS[0].y+1 <<endl ;


    }
    cout<<endl ;
    pf::set_board('A',POS[0].x,POS[0].y);
 //   cout<< "right is done" << endl;


}
void health(){
    A.life_plus() ;
    cout << "You've found a health pack"<< (char) 3 <<" +20 ";
}
void Pod(){
    cout << "you've found a Pod pack, -10" <<(char) 3 << " life for All Zombies ";
    for (int i = 0; i < zombies.size(); i++) {
        zombies[i].reduceLife(10);
    }
}
void find_left(){
    A.attack_plus() ;
    GO_to = "left";
    next_arrow = true ;
    cout << "move to the left, you've gained 20 attack points ";

}
void find_right(){

    A.attack_plus() ;
    GO_to = "right";
    next_arrow = true ;
    cout << "move to the right, you've gained 20 attack points ";

}
void find_up(){
    A.attack_plus() ;
    GO_to = "up";
    next_arrow = true ;
    cout << "move up, you've gained 20 attack points ";

}
void find_down(){

    A.attack_plus() ;
    GO_to = "down";
    next_arrow = true ;
    cout << "move down, you've gained 20 attack points ";

}
void rock(){
    cout << "it's a rock ==> ";
    int random_object = std::rand() % 7 +1 ;
    switch(random_object){
          case 1 :
                health();
            break ;
          case 2 :
                Pod() ;
            break ;
          default:
            cout<<" empty  " ;
    }

}
void zombie_found(int i){

    cout<<"IT's a ZOMBIE "<< i <<"! " <<(char) 3<<zombies[i-1].get_life() << endl << " Attack it with ===> " <<  A.get_attack() << " attack points. " << endl;

    zombies[i-1].reduceLife(A.get_attack());

    cout <<"The zombie is now " <<zombies[i-1].get_life() << " " ;

    if( zombies[i-1].get_life()> 0 ){
        cout<<"STOP ZOMBIE IS STILL ALIVE " ;
        stop = true ;
        POS[0].y = POS[0].y - 1 ;

        }

}
void arrow(){
    int row_pos , col_pos ;
    char arrow_dir ;
    cout <<"Enter ROW : " ; cin >> row_pos ;
    cout <<"Enter COL : " ; cin >> col_pos ;
    cout <<"Enter DIR : " ; cin >> arrow_dir ;

    for(int i=0 ; i < POS.size() ; i++){
        if(POS[i].x == row_pos-1 && POS[i].y == col_pos-1){
            cout<<"find element " << POS[i].type << endl ;
            if(POS[i].type == '<' || POS[i].type == '>' || POS[i].type == 'v' || POS[i].type == '^'){
                cout<<"find arrow " << POS[i].type << endl ;
                POS[i].type = arrow_dir ;
                pf::set_board(arrow_dir,POS[i].x,POS[i].y);
            }
        }

    }
    pf::Pause();
}
void trail_remover(){

    cout<<"start " ;
    for(int i=0 ; i < board_row ; i++){
        for(int j=0 ; j < board_col ; j++){

                char trail = pf::get_board(i,j);
                if(trail == '.'){
                 //   cout<<"founds dot " ;
                    pf::set_board(' ',i,j);

                }
        }

    }
}
void print_Alien_active(){

    if(A_active == true) cout<<" ===> " ;
    else cout << "      " ;
}

bool isStopType(char type) {
  //  return (type == 'Z' || type == 'A' || type == 'P' || type == 'h' || type == '>' || type == '<' || type == '^' || type == 'v');
        return ((type == 'A'|| type == '>' || type == '<' || type == '^' || type == 'v'));
}

void saveToFile() {

    ofstream myfile;
    myfile.open("myfile.txt");

    myfile << "board : " <<board_row << "," <<board_col <<endl;
    myfile << "Zombie : "<< zombi_count << endl ;
    for(int i = 0 ; i < POS.size() ; i++)
    {
        myfile << POS[i].type << "(" <<POS[i].x << "," << POS[i].y << ") | " ;
    }
    myfile << endl;

    myfile << "Alien "  << A.get_life() << " , " << A.get_attack() << endl ;

    for(int i = 0 ; i < zombies.size() ; i++)
    {
        myfile <<"Z"<<i+1<<" " <<zombies[i].get_life() << " , " << zombies[i].get_attack() << " , " << zombies[i].get_range() << endl;
    }

    myfile << endl;

    myfile.close();

    pf::Pause();
}
void loadFromFile() {

    ifstream myfile("myfile.txt");
    if (!myfile) {
        cout << "Failed to open file for reading." << endl;
        return;
    }
    string line;
    int zombi_count = 0;
    while (getline(myfile, line)) {
        if (line.find("Zombie") != string::npos) {
            istringstream ss(line);
            string tmp;
            ss >> tmp >> zombi_count;
            break;
        }
    }
    cout << "Zombie count: " << zombi_count << endl;
    myfile.close();
}

void selectWeapon(){

        int select ;
        Weapon w ;
        Sword.printW();
        Axe.printW();

        cout << endl <<"Select Weapon 1 for Sword , 2 for Axe ===> : " ;
        cin >> select ;

        switch(select){
        case 1 :
            w = Sword ;
            break;
        case 2 :
            w = Axe ;
            break;
        }

        A.select_weapon(w);

        pf::Pause();
}
