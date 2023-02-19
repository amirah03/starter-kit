// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: TT1L
// Names: NURUL AFIQAH BINTI ISMAIL | AMIRAH HAKIMAH BINTI MASRI
// IDs: 1211103480 | 1211103223
// Emails: 1211103480@student.mmu.edu.my | 1211103223@student.mmu.edu.my
// Phones: 019-9920155 | 011-15631032
// *********************************************************

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // for system() function
#include <ctime>   // for time() in srand( time(NULL) )
#include <iomanip> // for setw
using namespace std;

/*   Zombie Class   */
class Zombie
{
private:
public:
    vector<Zombie> zombies; // make zombies a member of the class

    int life;
    int attack;
    int range;
    int x;
    int y;
    char z;

    void init(int l, int a, int r, int x_cor, int y_cor);
    void displayzom(vector<vector<char>> &map_);

    friend class Board;
};

/*   Board class    */
class Board
{
private:
    int col_ = 9, row_ = 9;
    int numZombie_ = 2;

public:
    vector<vector<char>> map_;
    int getcol()
    {
        return col_;
    }
    int getrow()
    {
        return row_;
    }
    int getzombie()
    {
        return numZombie_;
    }
    Board();
    void init();
    void display();

    void attributes(vector<Zombie> &zombies);

    char getObject(vector<vector<char>> &map_, int x, int y);
    void setObject(vector<vector<char>> &map_, int x, int y, char ch);
    bool isInsideMap(int x, int y);

    char heading_, arrowup = '^', arrowdown = 'v', arrowleft = '<', arrowright = '>';
    char rock = 'r';
};

/*   Alien Class    */
class Alien : public Board
{
private:
public:
    int x_alien = (getcol() / 2) + 1;
    int y_alien = (getrow() / 2) + 1;
    char aliench = 'A';
    int life_ali = 50 + (rand() % 150);
    int attack_ali = 0;
};

int health = 50 + (rand() % 150);
int attack = 50;
int value[2] = {health, attack};

//-----------------------------------------------------------------------------------------------------------------------------------------------------/

char Board::getObject(vector<vector<char>> &map_, int x, int y)
{
    return map_[row_ - y][x - 1];
}

void Board::setObject(vector<vector<char>> &map_, int x, int y, char ch)
{
    map_[row_ - y][x - 1] = ch;
}

Board::Board()
{
    init();
}

bool Board::isInsideMap(int x, int y)
{
    return x <= col_ && x > 0 && y > 0 && y <= row_;
}

/*  To put random objects inside of the map       */
void Board::init()
{
    char objects[] = {'^', '<', '>', 'v', 'h', 'p', 'r', ' ', ' '};
    int noOfObjects = 9; // number of objects in the objects array

    // map_.clear();
    //  create dinamic 2D array using vector
    map_.resize(row_); // create empty rows
    for (int i = 0; i < row_; ++i)
    {
        map_[i].resize(col_); // resize each row
    }

    // put random characters into the vector array
    for (int i = 0; i < row_; ++i)
    {
        for (int j = 0; j < col_; ++j)
        {
            int objNo = rand() % noOfObjects;
            map_[i][j] = objects[objNo];
        }
    }
}

/*   To  display  a  2D array map       */
void Board::display()
{
    cout << " ------------------------------ " << endl;
    cout << " =      ALIEN  VS  ZOMBIE     =" << endl;
    cout << " ------------------------------" << endl;
    cout << endl;

    // for each row
    for (int i = 0; i < row_; ++i)
    {
        // display upper border of the row
        cout << "  ";
        for (int j = 0; j < col_; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;

        // display row number
        cout << setw(2) << (row_ - i);

        // display cell content and border of each column
        for (int j = 0; j < col_; ++j)
        {
            cout << "|" << map_[i][j];
        }
        cout << "|" << endl;
    }

    // display lower border of the last row
    cout << "  ";
    for (int j = 0; j < col_; ++j)
    {
        cout << "+-";
    }
    cout << "+" << endl;

    // display column number
    cout << "  ";
    for (int j = 0; j < col_; ++j)
    {
        int digit = (j + 1) / 10;
        cout << " ";
        if (digit == 0)
            cout << " ";
        else
            cout << digit;
    }

    cout << endl;
    cout << "  ";
    for (int j = 0; j < col_; ++j)
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl
         << endl;
}

//------------------------------------------------------------------------------------------------------------/

void Zombie::init(int l, int a, int r, int x_cor, int y_cor)
{
    Board board;

    life = l;
    attack = a;
    range = r;
    x = x_cor;
    y = y_cor;
}

/*   To make an array of zombies attributes that contains coordinate, life, attack   */
void Zombie::displayzom(vector<vector<char>> &map_)
{
    Board board;

    zombies.resize(board.getzombie()); // resize the zombies array

    for (int i = 0; i < board.getzombie(); i++)
    {
        int l = 50 + (rand() % 200);
        int a = 50 + (rand() % 150);
        int r = 1 + (rand() % board.getcol() % board.getrow());

        int centre_x = (board.getcol() - 1) / 2;
        int centre_y = (board.getrow() - 1) / 2;

        int x_cor, y_cor;
        // char zom;
        do
        {
            x_cor = 1 + (rand() % board.getcol());
            y_cor = 1 + (rand() % board.getrow());

            bool occupied = false;
            for (int j = 0; j < i; j++)
            {
                if (zombies[j].x == x_cor || centre_x == x_cor && zombies[j].y == y_cor || centre_y == y_cor)
                {
                    occupied = true;
                    break;
                }
            }
            if (!occupied)
            {
                break;
            }
        } while (true);

        if (i == 0)
        {
            zombies[0].z = '1';
        }
        else if (i == 1)
        {
            zombies[1].z = '2';
        }
        else if (i == 2)
        {
            zombies[2].z = '3';
        }
        else if (i == 3)
        {
            zombies[3].z = '4';
        }
        else if (i == 4)
        {
            zombies[4].z = '5';
        }
        else if (i == 5)
        {
            zombies[5].z = '6';
        }
        else if (i == 6)
        {
            zombies[6].z = '7';
        }
        else if (i == 7)
        {
            zombies[7].z = '8';
        }
        else if (i == 8)
        {
            zombies[8].z = '9';
        }

        zombies[i].init(l, a, r, x_cor, y_cor);
    }
}

//------------------------------------------------------------------------------------------------------------------------------------------/

void addHealth(vector<vector<char>> &map_, int x, int y)
{
    Board board;
    char what = board.getObject(map_, x, y);

    if (what == 'h')
    {
        int d = value[0];
        if (d < value[0])
        {
            d += 20;
            value[0] = d;
            cout << " Alien's health increased by 20" << endl;
        }
        else if (d >= value[0])
        {
            cout << " Alien's health is full" << endl;
        }
    }
}
void addAttack(vector<vector<char>> &map_, int x, int y)
{
    Board board;
    char what = board.getObject(map_, x, y);
    if (what == '<' || what == '>' || what == 'v' || what == '^')
    {
        int q = value[1];
        q += 20;
        value[1] = q;
        cout << " Alien gains 20 for attack " << endl;
    }
}

void removeZ(vector<vector<char>> &map_, vector<Zombie> &zombies, int x, int y, char ch)
{
    Board board;
    Zombie zombie;

    cout << " Congratulation! You have defeated the zombie(s). " << endl;
    board.setObject(map_, x, y, ' ');
}

void stop(vector<vector<char>> &map_, vector<Zombie> &zombies, int x, int y)
{
    Board board;
    Alien alien;
    Zombie zombie;

    // char what = board.getObject(map_, x, y);

    char t = board.getObject(map_, x, y);
    int i = t - '0';

    i -= 1;

    if (value[1] >= zombie.zombies[i].life)
    {
        cout << "hoiii" << endl;
        removeZ(map_, zombie.zombies, zombie.zombies[i].x, zombie.zombies[i].y, alien.aliench);
    }
    else
    {
        cout << " Alien's attack is less than Zombie's life! " << endl;
        cout << "Alien cannot attack Zombie" << endl;
        return;
    }
}

/*----------------------------------------------------------------------------------------------------------------*/

/*  To move Alien  */
void move_Alien(vector<vector<char>> &map_, int &x_alien, int &y_alien, char aliench)
{
    Board board;
    Zombie zombie;
    Alien alien;

    char object[] = {'^', '<', '>', 'v', 'h', 'p', ' ', ' '};
    int noOfObject = 8;

    int obj = rand() % noOfObject;
    char objec = object[obj];

    string gerak_;
    cout << "Where you want to go? :  ";
    cin >> gerak_;

    if (gerak_ == "up" && (board.isInsideMap(x_alien, y_alien - 1)))
    {
        addAttack(map_, x_alien, y_alien + 1);
        addHealth(map_, x_alien, y_alien + 1);
        if (board.getObject(map_, x_alien, y_alien + 1) != board.rock)
        {
            board.setObject(map_, x_alien, y_alien + 1, aliench);
            board.setObject(map_, x_alien, y_alien, '.');
            y_alien += 1;
        }
        else if (board.getObject(map_, x_alien, y_alien + 1) == board.rock)
        {
            cout << "Alien hit a rock and can't move further." << endl;
            board.setObject(map_, x_alien, y_alien + 1, objec);
        }
        else
        {
            stop(map_, zombie.zombies, x_alien, y_alien + 1);
        }
    }
    else if (gerak_ == "down" && (board.isInsideMap(x_alien, y_alien + 1)))
    {

        addAttack(map_, x_alien, y_alien - 1);
        addHealth(map_, x_alien, y_alien - 1);
        if (board.getObject(map_, x_alien, y_alien - 1) != board.rock)
        {
            board.setObject(map_, x_alien, y_alien - 1, aliench);
            board.setObject(map_, x_alien, y_alien, '.');
            y_alien -= 1;
        }
        else if (board.getObject(map_, x_alien, y_alien - 1) == board.rock)
        {
            cout << "Alien hit a rock and can't move further." << endl;
            board.setObject(map_, x_alien, y_alien - 1, objec);
        }
        else
        {
            stop(map_, zombie.zombies, x_alien, y_alien - 1);
        }
    }
    else if (gerak_ == "right" && (board.isInsideMap(x_alien + 1, y_alien)))
    {

        addAttack(map_, x_alien + 1, y_alien);
        addHealth(map_, x_alien + 1, y_alien);
        if (board.getObject(map_, x_alien + 1, y_alien) == board.rock)
        {
            cout << "Alien hit a rock and can't move further." << endl;
            board.setObject(map_, x_alien + 1, y_alien, objec);
        }
        else
        {
            char Z = board.getObject(map_, x_alien + 1, y_alien);
            if (Z == '1' || Z == '2' || Z == '3' || Z == '4' || Z == '5' || Z == '6' || Z == '7' || Z == '8' || Z == '9')
            {
                cout << "hai" << endl;
                stop(map_, zombie.zombies, alien.x_alien + 1, alien.y_alien);
                cout << "lol" << endl;
            }
            else
            {
                board.setObject(map_, x_alien + 1, y_alien, aliench);
                board.setObject(map_, x_alien, y_alien, '.');
                x_alien += 1;
            }
        }
    }
    else if (gerak_ == "left" && (board.isInsideMap(x_alien - 1, y_alien)))
    {
        addAttack(map_, x_alien - 1, y_alien);
        addHealth(map_, x_alien - 1, y_alien);
        if (board.getObject(map_, x_alien - 1, y_alien) != board.rock)
        {
            board.setObject(map_, x_alien - 1, y_alien, aliench);
            board.setObject(map_, x_alien, y_alien, '.');
            x_alien -= 1;
        }
        else if (board.getObject(map_, x_alien - 1, y_alien) == board.rock)
        {
            cout << "Alien hit a rock and can't move further." << endl;
            board.setObject(map_, x_alien - 1, y_alien, objec);
        }
        else
        {
            stop(map_, zombie.zombies, x_alien - 1, y_alien);
        }
    }
    else
    {
        cout << "Alien try to get out of border" << endl;
        cout << "Check your input" << endl;
    }
    system("pause");
    system("cls");
}

void move_zombie(vector<vector<char>> &map_, vector<Zombie> &zombies, int &x, int &y, char &z)
{
    Board board;
    Alien alien;
    Zombie zombie;

    string gogo;

    char object[] = {'^', '<', '>', 'v', 'h', 'p', 'r', ' ', ' '};
    int noOfObject = 9;

    int obj = rand() % noOfObject;
    char objec = object[obj];

    string moveit[] = {"up", "down", "left", "right"};
    int nomoveit = 4;

    int which = rand() % nomoveit;
    gogo = moveit[which];
    cout << gogo << endl;

    if (gogo == "up" && (board.isInsideMap(x, y - 1)))
    {
        if (board.getObject(map_, x, y + 1) == 'A')
        {
            cout << "Zombie are blocked by the Alien!" << endl
                 << endl;
        }
        else
        {
            board.setObject(map_, x, y, objec);
            board.setObject(map_, x, y + 1, z);
            y += 1;
        }
    }
    else if (gogo == "down" && (board.isInsideMap(x, y + 1)))
    {
        if (board.getObject(map_, x, y - 1) == 'A')
        {
            cout << "Zombie are blocked by the Alien!" << endl
                 << endl;
        }
        else
        {
            board.setObject(map_, x, y - 1, z);
            board.setObject(map_, x, y, objec);
            y -= 1;
        }
    }
    else if (gogo == "right" && (board.isInsideMap(x + 1, y)))
    {
        if (board.getObject(map_, x + 1, y) == 'A')
        {
            cout << "Zombie are blocked by the Alien!" << endl
                 << endl;
        }
        else
        {
            board.setObject(map_, x + 1, y, z);
            board.setObject(map_, x, y, objec);
            x += 1;
        }
    }
    else if (gogo == "left" && (board.isInsideMap(x - 1, y)))
    {
        if (board.getObject(map_, x - 1, y) == 'A')
        {
            cout << "Zombie are blocked by the Alien!" << endl
                 << endl;
        }
        else
        {
            board.setObject(map_, x - 1, y, z);
            board.setObject(map_, x, y, objec);
            x -= 1;
        }
    }
    else
    {
        cout << "Zombie "
             << " is trying to get out of border" << endl;
    }
    system("pause");
    system("cls");
}

/*-----------------------------------------------------------------------------------------------------------------------------------*/

void Board::attributes(vector<Zombie> &zombies)
{
    Zombie zombie;
    Alien alien;

    cout << "Alien     : Life   :" << setw(3) << value[0] << "   Attack    :" << setw(3) << value[1] << endl;

    for (int i = 0; i < numZombie_; i++)
    {
        cout << "Zombie " << i + 1 << "  : Life   :" << setw(3) << zombies[i].life << "   Attack    :" << setw(3) << zombies[i].attack << "   Range   :"<< setw(3) << zombies[i].range << endl;
    }
    cout << endl;
}

void arrow(vector<vector<char>> &map_, int &x, int &y, string &direction)
{
    Board board;
    // Alien alien;

    // cout << "Enter row column direction -> ";
    // cin >> x_cor >> y_cor >> direction;

    char where = board.getObject(map_, x, y);
    cout << where << endl;

    if (where != board.arrowup && where != board.arrowdown && where != board.arrowleft && where != board.arrowright)
    {
        cout << "Wrong Coordinate? Your turn are skipped! " << endl;
        return;
    }
    else
    {
        if (direction == "up")
        {
            board.setObject(map_, x, y, '^');
        }
        else if (direction == "right")
        {
            board.setObject(map_, x, y, board.arrowright);
        }
        else if (direction == "down")
        {
            board.setObject(map_, x, y, board.arrowdown);
        }
        else if (direction == "left")
        {
            board.setObject(map_, x, y, board.arrowleft);
        }
        else
        {
            cout << "Check your input. Is it lowercase and spelled correctly?" << endl;
            // system("cls");
            return;
        }
    }
    system("pause");
    // system("cls");
}

/*---------------------------------------------------------------------------------------------------------*/

//we got errors here :(
/* 
void Board::board_settings(int Inputcol, int Inputrow, int InputZom)
{
    Board board;
    Zombie zombie;
    Alien alien;

    char setInput;

    cout << endl;
    cout << "Please only input an odd digit for both row and column!" << endl;
    cout << "Please enter how many column do you want => " ;
    cin >> Inputrow ;
    cout << endl;
    cout << "Please enter how many row do you want => ";
    cin >> Inputcol;
    cout << endl;

    while ((Inputrow % 2) == 0 || (Inputcol % 2) == 0 || Inputrow == 1 || Inputcol == 1)
    {
        cout << "As stated before, please input an odd number only for both column and row" << endl;
        cout << "Also do remember to put sensible numbers..." << endl;
        cout << "Please confirm your selection again" << endl;
        board_settings(Inputcol, Inputrow, InputZom);
    }

    cout << "Next, please input how many zombie(s) that you want." << endl;
    cout << "Zombies can only have up to 9 zombie(s) only" << endl;
    cout << "Number of Zombie(s) that I want => ";
    cin >> InputZom;

    if (InputZom > 10 || InputZom <= 0)
    {
        cout << "As stated before Zombie(s) can only have from 1 to 9 zombie(s) only" << endl;
        cout << "Please confirm your selection again" << endl;
        board_settings(Inputcol, Inputrow, InputZom);
    }

    cout << " *--*--*--*--*--*--*--*--*--*--*--*--*--* " << endl;
    cout << " *            BOARD SETTINGS            * " << endl;
    cout << " *--*--*--*--*--*--*--*--*--*--*--*--*--* " << endl;
    cout << " *                                      * " << endl;
    cout << " *    Number of columns   : " << setw(2) << Inputcol << "          *" << endl;
    cout << " *    Number of rows      : " << setw(2) << Inputrow << "          *" << endl;
    cout << " *                                      * " << endl;
    cout << " *    Number of zombie(s) : " << setw(2) << InputZom << "          *" << endl;
    cout << " *                                      * " << endl;
    cout << " *--*--*--*--*--*--*--*--*--*--*--*--*--* " << endl;

    cout << " Do you want to change the game settings? " << endl;
    cout << " Please type 'y' for yes and 'n' for no  => ";
    cin >> setInput ;
    if (setInput == 'y')
    {
        //InValue(Inputcol, Inputrow, InputZom);
        board_settings(Inputcol, Inputrow, InputZom);
    }
    else if (setInput == 'n')
    {
        return;
    }
    else
    {
        cout << "Please just type the wanted input, okay?" << endl;
        board_settings(Inputcol, Inputrow, InputZom);
    }
}
*/

void mainMenu();
void Help();

/*   Game  Function   */
void Game(vector<vector<char>> &map_, vector<Zombie> &zombies, int x_alien, int y_alien, char aliench)
{
    Board board;
    Zombie zombie;
    Alien alien;

    int x_co, y_co;
    string directions;
    string answer,move,arrowD,quit,help;

    board.setObject(board.map_, alien.x_alien, alien.y_alien, alien.aliench);
    zombie.displayzom(board.map_);

    for (int j = 0; j < board.getzombie(); j++)
    {
        board.setObject(board.map_, zombie.zombies[j].x, zombie.zombies[j].y, zombie.zombies[j].z);
    }

    bool game = true;
    while (game)
    {
        board.display();
        board.attributes(zombie.zombies);
        cout << " What do you want to do? (move / arrowD / quit/ help) --> " ;
        cin >> answer;

        if (answer == "move")
        {
            board.display();
            board.attributes(zombie.zombies);
            move_Alien(board.map_, alien.x_alien, alien.y_alien, alien.aliench);
            board.display();
            board.attributes(zombie.zombies); 
        }
        else if (answer == "arrowD")
        {
            board.display();
            board.attributes(zombie.zombies);
            cout << "Enter row column direction -> ";
            cin >> x_co >> y_co >> directions;
            arrow(board.map_, x_co, y_co, directions);
            board.display();
            board.attributes(zombie.zombies); 
        }
        else if (answer == "quit")
        {
            system("cls");mainMenu();
        }
        else if (answer == "help")
        {
            Help();
        }    
        for (int i = 0; i < board.getzombie(); i++)
        {
            cout << "It is Zombie " << i + 1 << " turns!" << endl;
            move_zombie(board.map_, zombie.zombies, zombie.zombies[i].x, zombie.zombies[i].y, zombie.zombies[i].z);
            board.display();
            board.attributes(zombie.zombies);
        }
    }
}

void Help()
{
    cout << endl
         << endl;
    cout << "======================" << endl;
    cout << "||   GAME CONTROL   ||" << endl;
    cout << "======================" << endl
         << endl;

    cout << "---------------------------------------------------------------" << endl;
    cout << "||  Command      ||  Description                             ||" << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "||  Arrow        ||                                          ||" << endl;
    cout << "|| -----------                                               ||" << endl; 
    cout << "||  up           ||  Alien to move up                        ||" << endl;
    cout << "||  down         ||  Alien to move down                      ||" << endl;
    cout << "||  left         ||  Alien to move left                      ||" << endl;
    cout << "||  right        ||  Alien to move right                     ||" << endl;
    cout << "||---------------||------------------------------------------||" << endl;
    cout << "||  arrow        ||  Switch the direction of an arrow object ||" << endl;
    cout << "||               ||    in the game board.                    ||" << endl;
    cout << "||               ||  (The player will be asked to enter      ||" << endl;
    cout << "||               ||  the row and column of the arrow object  ||" << endl;
    cout << "||               ||  to switch, followed by the direction of ||" << endl;
    cout << "||               ||  the arrow object to switch to.)         ||" << endl;
    cout << "||---------------||------------------------------------------||" << endl;
    cout << "||  help         ||  List and describe the commands that the ||" << endl;
    cout << "||               ||    player can use in the game.           ||" << endl;
    cout << "||---------------||------------------------------------------||" << endl;
    cout << "||  save         ||  Save the current game to a file.        ||" << endl;
    cout << "||               ||  (The player will be asked to enter the  ||" << endl;
    cout << "||               ||  name of the file to save to.)           ||" << endl;
    cout << "||---------------||------------------------------------------||" << endl;
    cout << "||  load         ||  Load a saved game from a file.          ||" << endl;
    cout << "||               ||  (The player will be asked to enter the  ||" << endl;
    cout << "||               ||  name of the file to load from.)         ||" << endl;
    cout << "||---------------||------------------------------------------||" << endl;
    cout << "||  quit         ||  Quit the game while still in play.      ||" << endl;
    cout << "||               ||  (The player will be asked to confirm    ||" << endl;
    cout << "||               ||  his / her decision.)                    ||" << endl;
    cout << "---------------------------------------------------------------" << endl;

    system("pause");
    system("cls");
}

void Tutorial()
{
    cout << "1. User is provided 3 options which is: " << endl;
    cout << "    1. Play game!   --> to start the game\n    2. How To Play? --> to know the overview of the game\n    3. Help ...     --> to know the keywords\n    4. Exit.        --> back to main menu\n"
         << endl;
    cout << "2. When the user click on 'Play game!', the user will be shown a default setting that contain the number of row and column and the user is given 2 choice which to remain the setting or change it. If he/she wants to change the setting, the user need to key in the value of the number of row, the number of column and also the number of zombies they want within the range stated.\n"
         << endl;
    cout << "3. The gameboard will pop up according to the setting. Alien and zombie(s)'s attribute will be shown under the gameboard. The attribute will change each time the attack is launched.\n"
         << endl;
    cout << "4. The user who is an Alien need to attack the zombie(s) until its lifes become zero to be declared as winner. The user need to use the keywords provided in 'Help...' to make a move which is UP, DOWN, LEFT, RIGHT and ARROW.\n"
         << endl;
    cout << "5. To change the direction of arrow, the user need to tell the coordinate of the arrow and the direction to change it by entering the the row, column and direction (UP, DOWN, RIGHT,LEFT). The arrow direction can be change many times as many as the user wants and the user can proceed to move the Alien. The move of the Alien can be enter once in each turn.\n"
         << endl;
    cout << "6. Remember, the Alien wil be stop once it hits Rock(r), border of the gameboard and zombie whose the lifes is greater than the Alien's attack.\n"
         << endl;
    cout << "7. How to kill the zombie(s)? The Alien can collect Pod objects(p) to inflict 10 damages to the nearest zombie and Arrow objects(<, >, ^, V) to increase the value of attack which is 20 values each Arrows. The Pods (p) and Arrows (<, >, ^, V) can also be hidden under a Rock but to get it, the Alien need to hit it and Alien will stop moving.\n"
         << endl;
    cout << "8. The game will take turn one after another which is start with the Alien first and followed by the zombie(s).\n"
         << endl;
    cout << "9. The zombie(s) can attack the Alien if the Alien is in the range of the zombie. The lifes of Alien will decrease according to the number of attack of the zombie.\n"
         << endl;
    cout << "10. To recharge the Alien's lifes, the user need to collect Health object (h) which is each Health object will add 20 lifes to the Alien if the lifes is not max.\n"
         << endl;
    cout << "11. The game will be continued until the zombie(s)'s lifes become zero and vice versa or the user choose to end the game by entering quit command, the game will end. The user will return to Main Menu.\n"
         << endl;
    cout << "12. The user also can save their games and load it to continue to play the saved game however once the user quit (quit command), the saved game will no longer exist.\n " << endl;

    system("pause");
    system("cls");
}

void mainMenu()
{
    Board board;
    Zombie zombie;
    Alien alien;

    int MenuInput;

    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "|       MAIN MENU        |" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
         << endl;

    cout << "What Do You Want to do ? " << endl;
    cout << "1 - Play Game! " << endl;
    cout << "2 - How To Play? " << endl;
    cout << "3 - Help ... " << endl;
    cout << "4 - Exit." << endl;
    cout << endl;
    cout << "Please insert the number of your choice. => ";
    cin >> MenuInput;

    if (MenuInput == 1)
    {
        Game(board.map_, zombie.zombies, alien.x_alien, alien.y_alien, alien.aliench);
        mainMenu();
    }
    else if (MenuInput == 2)
    {
        Tutorial();
        mainMenu();
    }
    else if (MenuInput == 3)
    {
        Help();
        mainMenu();
    }
    else if (MenuInput == 4)
    {
        char confirm;

        cout << endl;
        cout << "Would you like to quit the program?" << endl;
        cout << "Please type 'y' for yes or 'n' for nope => ";
        cin >> confirm;
        cout << endl
             << endl;

        if (confirm == 'y')
        {
            exit;
        }
        else if (confirm == 'n')
        {
            mainMenu();
        }
        else
        {
            cout << "Please only type the wanted keyword, okay?" << endl;
            mainMenu();
        }
    }
    else
    {
        cout << endl;
        cout << " Please input a number between 1 until 4 only, okay? " << endl;
        mainMenu();
    }
    system("cls");
}

void FirstMenu()
{

    cout << endl
         << endl;
    cout << setw(25);
    cout << "*-----------------******-------------------*" << endl;
    cout << "*                                          *" << endl;
    cout << "*           WELCOME TO OUR GAME            *" << endl;
    cout << "*  HOPE YOU HAVE A FUN EXPERIENCE WITH US  *" << endl;
    cout << "*       LET'S GET STARTED SHALL WE?        *" << endl;
    cout << "*                                          *" << endl;
    cout << "*-----------------******-------------------*" << endl;
    cout << endl;
    cout << endl;
    system("pause");
    system("cls");
}

int main()
{
    Zombie zombie;
    Board board;
    Alien alien;

    // srand(1);
    srand(time(NULL));

    FirstMenu();
    mainMenu();

    // Game(board.map_, zombie.zombies, alien.x_alien, alien.y_alien, alien.aliench);
}
