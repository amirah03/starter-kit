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

int InputdimX;
int InputdimY;
char ch1 = 'A';
int numZombie;

class Board
{
private:
    vector<vector<char>> map_; // convention to put trailing underscore
    int dimX_, dimY_;          // to indicate private data

public:
    Board(int dimX = InputdimX, int dimY = InputdimY);
    void init(int dimX, int dimY);
    void display() ;

    int getDimX() const; // ni
    int getDimY() const; // ni

    char getObject(int x, int y) const; // kat sini

    void setObject(int x, int y, char ch);

    bool isEmpty(int x, int y);
    bool isInsideMap(int x, int y);

    void test1() ;
    void attributes() const;
    void InsertValue();
};

class Alien
{
private:
    char gerak_; // either '^', '>', '<' or 'v'
    int x1_, y1_;

public:
    Alien();
    void land(Board &board);
    int getX() const;
    int getY() const;

    char getHeading() const;

    void turnLeft(Board &board);
    void turnRight(Board &board);
    void move_Alien(Board &board);
};


int Pause()
{
#if defined(_WIN32)
    return std::system("pause");
#elif defined(__linux__) || defined(__APPLE__)
    return std::system(R"(read -p "Press any key to continue . . . " dummy)");
#endif
}

// ni klau nk masukkan dlm map tu
// or nak edit / tambah (ch) dekat kedudukan (x,y)

void Board::setObject(int x, int y, char ch)
{
    map_[dimY_ - y][x - 1] = ch;
}

bool Board::isEmpty(int x, int y) 
{
    if ((map_[dimY_ - y][x - 1]) == ' ')
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Board::isInsideMap(int x, int y) // 1.6
{
    if (x > dimX_ || x < dimX_ && y > dimY_ || y < dimY_)
    {
        return false;
    }
    else
    {
        return true;
    }
}

char Board::getObject(int x, int y) const ///////////// ni klau nanti utk kita access coordinate x,y tu utk tukar simbol
{
    return map_[dimY_ - y][x - 1];
}

int Board::getDimX() const
{
    return dimX_; // ni
}

int Board::getDimY() const
{
    return dimY_; // ni
}

Board::Board(int dimX, int dimY)
{
    init(dimX, dimY);
}

void Board::init(int dimX, int dimY)
{
    dimX_ = dimX;
    dimY_ = dimY;

    char objects[] = {'^', '<', '>', 'v', 'h', 'p', 'r', ' ', ' '};
    int noOfObjects = 9; // number of objects in the objects array

    // create dinamic 2D array using vector
    map_.resize(dimY_); // create empty rows
    for (int i = 0; i < dimY_; ++i)
    {
        map_[i].resize(dimX_); // resize each row
    }

    // put random characters into the vector array
    for (int i = 0; i < dimY_; ++i)
    {
        for (int j = 0; j < dimX_; ++j)
        {
            int objNo = rand() % noOfObjects;
            map_[i][j] = objects[objNo];
        }
    }
}

void Board::display() 
{
    // comment this out during testing
    // system('cls');  // OR system("clear"); for Linux / MacOS

    cout << " --__--__--__--__--__--__--__--_" << endl;
    cout << " =       ALIEN VS ZOMBIE       =" << endl;
    cout << " __--__--__--__--__--__--__--__-" << endl;
    cout << endl;

    // for each row
    for (int i = 0; i < dimY_; ++i)
    {
        // display upper border of the row
        cout << "  ";
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;

        // display row number
        cout << setw(2) << (dimY_ - i);

        // display cell content and border of each column
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "|" << map_[i][j];
        }
        cout << "|" << endl;
    }

    // display lower border of the last row
    cout << "  ";
    for (int j = 0; j < dimX_; ++j)
    {
        cout << "+-";
    }
    cout << "+" << endl;

    // display column number
    cout << "  ";
    for (int j = 0; j < dimX_; ++j)
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
    for (int j = 0; j < dimX_; ++j)
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl
         << endl;
}

void Board::test1() 
{
    Board board;

    int x1 = (dimX_ + 1) / 2;
    int y1 = (dimY_ + 1) / 2;
    char ch1 = 'A';
    board.setObject(x1, y1, ch1);

    int x2 = 1 + (rand() % dimX_);
    int y2 = 1 + (rand() % dimY_);
    char ch2 = '1';
    board.setObject(x2, y2, ch2);

    int x3 = 1 + (rand() % dimX_);
    int y3 = 1 + (rand() % dimY_);
    char ch3 = '2';
    board.setObject(x3, y3, ch3);

    board.display();

    cout << "The Alien  " << ch1 << " is at column "
         << x1 << " and row " << y1 << endl;

    cout << "The Zombie " << ch2 << " is at column "
         << x2 << " and row " << y2 << endl;

    cout << "The Zombie " << ch3 << " is at column "
         << x3 << " and row " << y3 << endl;
    cout << " " << endl;
}

void Board::attributes() const
{
    int alienLife = 50 + (rand() % 300);
    int alienAtt = 0;

    int zombie1Life = 50 + (rand() % 200);
    int zombie1Att = 50 + (rand() % 150);
    int zombie1Ran = 1 + rand() % dimX_ % dimY_;

    int zombie2Life = 50 + (rand() % 200);
    int zombie2Att = 50 + (rand() % 150);
    int zombie2Ran = 1 + rand() % dimX_ % dimY_;

    int zombie3Life = 50 + (rand() % 200);
    int zombie3Att = 50 + (rand() % 150);
    int zombie3Ran = 1 + rand() % dimX_ % dimY_;

    int zombie4Life = 50 + (rand() % 200);
    int zombie4Att = 50 + (rand() % 150);
    int zombie4Ran = 1 + rand() % dimX_ % dimY_;

    int zombie5Life = 50 + (rand() % 200);
    int zombie5Att = 50 + (rand() % 150);
    int zombie5Ran = 1 + rand() % dimX_ % dimY_;

    int zombie6Life = 50 + (rand() % 200);
    int zombie6Att = 50 + (rand() % 150);
    int zombie6Ran = 1 + rand() % dimX_ % dimY_;

    int zombie7Life = 50 + (rand() % 200);
    int zombie7Att = 50 + (rand() % 150);
    int zombie7Ran = 1 + rand() % dimX_ % dimY_;

    int zombie8Life = 50 + (rand() % 200);
    int zombie8Att = 50 + (rand() % 150);
    int zombie8Ran = 1 + rand() % dimX_ % dimY_;

    int zombie9Life = 50 + (rand() % 200);
    int zombie9Att = 50 + (rand() % 150);
    int zombie9Ran = 1 + rand() % dimX_ % dimY_;

    if ((zombie1Att > zombie1Life) || (zombie2Att > zombie2Life))
    {
        zombie1Att = 50 + (rand() % zombie1Life);
        zombie2Att = 50 + (rand() % zombie2Life);
    }

    cout << "Alien     : Life   " << setw(3) << alienLife << ", Attack    " << setw(3) << alienAtt << endl;
    cout << "Zombie 1  : Life   " << setw(3) << zombie1Life << ", Attack    " << setw(3) << zombie1Att << ", Range  " << setw(3) << zombie1Ran << endl;
    cout << "Zombie 2  : Life   " << setw(3) << zombie2Life << ", Attack    " << setw(3) << zombie2Att << ", Range  " << setw(3) << zombie2Ran << endl;
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
    cout << "||  up           ||  Alien to move up                        ||" << endl;
    cout << "||---------------||------------------------------------------||" << endl;
    cout << "||  down         ||  Alien to move down                      ||" << endl;
    cout << "||---------------||------------------------------------------||" << endl;
    cout << "||  left         ||  Alien to move left                      ||" << endl;
    cout << "||---------------||------------------------------------------||" << endl;
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

    Pause();
}

void Tutorial()
{
    cout << "1. User is provided 3 options which is: "<< endl;
    cout <<     "    1. Play game!   --> to start the game\n    2. How To Play? --> to know the overview of the game\n    3. Help ...     --> to know the keywords\n    4. Exit.        --> back to main menu\n" << endl; 
    cout << "2. When the user click on 'Play game!', the user will be shown a default setting that contain the number of row and column and the user is given 2 choice which to remain the setting or change it. If he/she wants to change the setting, the user need to key in the value of the number of row, the number of column and also the number of zombies they want within the range stated.\n" << endl;
    cout << "3. The gameboard will pop up according to the setting. Alien and zombie(s)'s attribute will be shown under the gameboard. The attribute will change each time the attack is launched.\n" << endl;
    cout << "4. The user who is an Alien need to attack the zombie(s) until its lifes become zero to be declared as winner. The user need to use the keywords provided in 'Help...' to make a move which is UP, DOWN, LEFT, RIGHT and ARROW.\n" << endl;
    cout << "5. To change the direction of arrow, the user need to tell the coordinate of the arrow and the direction to change it by entering the the row, column and direction (UP, DOWN, RIGHT,LEFT). The arrow direction can be change many times as many as the user wants and the user can proceed to move the Alien. The move of the Alien can be enter once in each turn.\n" << endl;
    cout << "6. Remember, the Alien wil be stop once it hits Rock(r), border of the gameboard and zombie whose the lifes is greater than the Alien's attack.\n" << endl;
    cout << "7. How to kill the zombie(s)? The Alien can collect Pod objects(p) to inflict 10 damages to the nearest zombie and Arrow objects(<, >, ^, V) to increase the value of attack which is 20 values each Arrows. The Pods (p) and Arrows (<, >, ^, V) can also be hidden under a Rock but to get it, the Alien need to hit it and Alien will stop moving.\n" << endl;
    cout << "8. The game will take turn one after another which is start with the Alien first and followed by the zombie(s).\n" << endl;
    cout << "9. The zombie(s) can attack the Alien if the Alien is in the range of the zombie. The lifes of Alien will decrease according to the number of attack of the zombie.\n" << endl;
    cout << "10. To recharge the Alien's lifes, the user need to collect Health object (h) which is each Health object will add 20 lifes to the Alien if the lifes is not max.\n" << endl;
    cout << "11. The game will be continued until the zombie(s)'s lifes become zero and vice versa or the user choose to end the game by entering quit command, the game will end. The user will return to Main Menu.\n" << endl;
    cout << "12. The user also can save their games and load it to continue to play the saved game however once the user quit (quit command), the saved game will no longer exist.\n " << endl;

    Pause();
}

void Board::InsertValue()
{
    char setInput;

    cout << endl;
    cout << "Remember to input an odd digit for both row and column!" << endl;
    cout << "Please enter how many row do you want => ";
    cin >> InputdimY;
    cout << "Please enter how many column do you want => ";
    cin >> InputdimX;
    cout << endl;

    dimX_ = InputdimX;
    dimY_ = InputdimY;

    while ((InputdimY % 2) == 0 || (InputdimX % 2) == 0)
    {
        cout << "As stated before, please input an odd number only for both column and row" << endl;
        InsertValue();
    }

    cout << "Zombies can only have up to 9 zombies" << endl;
    cout << "Please enter how many zombie(s) do you want => ";
    cin >> numZombie;

    if (numZombie > 10 || numZombie < 1)
    {
        cout << "No more than 9!";
    }

    cout << " *--*--*--*--*--*--*--*--*--*--*--*--*--* " << endl;
    cout << " *            BOARD SETTINGS            * " << endl;
    cout << " *--*--*--*--*--*--*--*--*--*--*--*--*--* " << endl;
    cout << " *                                      * " << endl;
    cout << " *    Number of columns   : " << setw(2) << dimY_ << "          *" << endl;
    cout << " *    Number of row       : " << setw(2) << dimX_ << "          *" << endl;
    cout << " *    Number of zombie(s) : " << setw(2) << numZombie << "          *" << endl;
    cout << " *                                      * " << endl;
    cout << " *--*--*--*--*--*--*--*--*--*--*--*--*--* " << endl;

    cout << " Do you want to change the game settings? " << endl;
    cout << " Please type 'y' for yes and 'n' for no  => ";
    cin >> setInput;

    setInput = toupper(setInput);
    if (setInput == 'Y')
    {
        InsertValue();
    }
    else if (setInput == 'N')
    {
        return;
    }
    else
    {
        cout << "Please just type the wanted input, okay?" << endl;
        InsertValue();
    }

    return;

    InsertValue();
}

void Game()
{
    Board board;
    Alien alien;
    srand(time(NULL));

    board.InsertValue();
    board.test1();

    board.attributes();
    Pause();
    
    while(true)
    {
        alien.move_Alien(board);
    }
    board.test1();
}

void MainMenu()
{
    int MenuInput;
    Board board;

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
        Game();
        MainMenu();
    }
    else if (MenuInput == 2)
    {
        Tutorial();
        MainMenu();
    }
    else if (MenuInput == 3)
    {
        Help();
        MainMenu();
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
            MainMenu();
        }
        else
        {
            cout << "Please type the wanted keyword only, okay?" << endl;
            MainMenu();
        }
    }

    else
    {
        cout << "Please input a number between 1 until 4 only, okay? " << endl;
        MainMenu();
    }
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
    Pause();
    cout << endl;
}

Alien::Alien()
{
}

int Alien::getX() const
{
    return x1_;
}

int Alien::getY() const
{
    return y1_;
}

char Alien::getHeading() const
{
    return ch1;
}

void Alien::move_Alien(Board &board)
{   
    char ch1 = 'A';

    string gerak_;
    cout << "Where you want to go? :  ";
    cin >> gerak_;

    if (gerak_ == "UP" )
    {
        board.setObject(x1_, y1_ + 1, ch1);
        board.setObject(x1_, y1_, '.');
        y1_ = y1_+1;
    }
    else if (gerak_ == "DOWN" )
    {
        board.setObject(x1_, y1_ - 1, ch1);
        board.setObject(x1_, y1_, '.');
        y1_ = y1_-1;
    }
    else if (gerak_ == "RIGHT" )
    {
        board.setObject(x1_ + 1, y1_, ch1);
        board.setObject(x1_, y1_, '.');
        x1_ = x1_+1;
    }
    else if (gerak_ == "LEFT" )
    {
        board.setObject(x1_ - 1, y1_, ch1);
        board.setObject(x1_, y1_, '.');
        x1_ = x1_-1;
    }
}

int main()
{
    Board board;
    Alien alien;

    FirstMenu();
    MainMenu();

    // board.InsertValue();
    // srand(time(NULL));
    // board.test1();
    // board.attributes();
    // Pause();
}

//  attack should not be higher than life
// and zombie range must not larger than the board dimension
