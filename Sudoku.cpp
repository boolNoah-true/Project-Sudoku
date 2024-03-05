// Sudoku.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

void sleep(int milliseconds) {
    this_thread::sleep_for(chrono::milliseconds(milliseconds));
}

void menu(string &name)
{
    int num = 90;

    cout << "What is your name?" << endl;
    getline(cin, name);
    char answer;
    cout << "Hello " << name << "!" << endl;
    sleep(num);
    cout << "Thank you for checking out Project Sudoku." << endl;
    sleep(num);
    cout << "Would you like more detail on how this program works? y for yes, n for no." << endl;
    cin >> answer;

    if (answer == 'y') {
        cout << "This program generates a Sudoku via randomely shuffling an already valid board. ";
            sleep(num);
            cout << "There are checks in place that make sure the shuffled board remains valid. ";
                sleep(num);
         cout   << "Once a board is generated it is then prepared for play. " << endl;
            sleep(num);
            cout << "Random positions of the board are set to 0 which represents an empty space that needs to be filled. ";
            sleep(num);
            cout << "You are then able to view the board and attempt solving the puzzle yourself. ";
                sleep(num);
                cout << "Keep in mind there is no interactive element for you to solve the puzzle directly. ";
                sleep(num);
            cout << "Instead you can indirectly solve it with a pencil and paper and then see if your answer matches the programs solution." << endl;
            sleep(num);
            cout << "Programs solution? Yes this program is designed to solve the board itself using a recursive algorithm. ";
            sleep(60);
            cout << "When the prepared board is shown to you there will be a prompt asking you to enter specific letter to have this program solve the board itself. ";
                sleep(num);
                cout << "The goal of this program was to make a Sudoku solver that generates a board and solves it on its own. " << endl;
                sleep(num);
           cout << "Here we go!" << endl;
            sleep(num);
            
    }

    else  {
        cout << "Ok. Here we go!" << endl;
    }
}


void shuffleBoard(int sudoku[9][9], int holdRows[9][9], int holdCols[9][9],  int cols) 
{
    int choice1, choice2;
   
    for (int i = 0; i < 9; i++) {                           //randomizes sudoku board by swapping rows 
        int threeByThree = rand() % 3;
        choice1 = rand() % 3 + threeByThree * 3;
        do {
            choice2 = rand() % 3 + threeByThree * 3;
           
        } while (choice2 == choice1);


        for (int j = 0; j < cols; j++) {
            holdRows[i][j] = sudoku[choice1][j];
            sudoku[choice1][j] = sudoku[choice2][j];
            sudoku[choice2][j] = holdRows[i][j];

        }
    }
    for (int i = 0; i < 9; i++) {                           //randomizes sudoku board by swapping columns
        int threeByThree = rand() % 3;
        choice1 = rand() % 3 + threeByThree * 3;
        do {
            choice2 = rand() % 3 + threeByThree * 3;
            
        } while (choice2 == choice1);


        for (int j = 0; j < cols; j++) {

            holdCols[j][i] = sudoku[j][choice1];
            sudoku[j][choice1] = sudoku[j][choice2];
            sudoku[j][choice2] = holdCols[j][i];

        }

    }
}
void printBoard(int sudoku[9][9], int rows, int cols) 
{
    sleep(150);

    for (int i = 0; i < rows; i++) { 

        for (int j = 0; j < cols; j++) {
            sleep(80);
            cout << sudoku[i][j] << "  ";
        }

        cout << endl;
    }

}

bool validBoardCheck(int sudoku[9][9], int rows, int cols)
{
    int checkSum1 = 0, checkSum2 = 0, checkSum3 = 0;
    int totalSum = 0;
    int sum[27];

    for (int i = 0; i < rows; i++) {
        checkSum1 = 0;

        for (int j = 0; j < cols; j++) {

            checkSum1 += sudoku[i][j];
        }
        sum[i] = checkSum1;
    }

    for (int j = 0; j < cols; j++) {
        checkSum2 = 0;

        for (int i = 0; i < rows; i++) {
            checkSum2 += sudoku[i][j];
        }
        sum[j + 9] = checkSum2;

    }
    checkSum1 = 0;
    checkSum2 = 0;
    checkSum3 = 0;


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            checkSum1 += sudoku[i][j];

        }
        for (int j = 3; j < 6; j++) {
            checkSum2 += sudoku[i][j];
        }
        for (int j = 6; j < 9; j++) {
            checkSum3 += sudoku[i][j];

        }
    }
    sum[18] = checkSum1;
    sum[19] = checkSum2;
    sum[20] = checkSum3;

    checkSum1 = 0;
    checkSum2 = 0;
    checkSum3 = 0;

    for (int i = 3; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            checkSum1 += sudoku[i][j];

        }
        for (int j = 3; j < 6; j++) {
            checkSum2 += sudoku[i][j];
        }
        for (int j = 6; j < 9; j++) {
            checkSum3 += sudoku[i][j];

        }
    }
    sum[21] = checkSum1;
    sum[22] = checkSum2;
    sum[23] = checkSum3;
   
    checkSum1 = 0;
    checkSum2 = 0;
    checkSum3 = 0;

    for (int i = 6; i < 9; i++) {
        for (int j = 0; j < 3; j++) {
            checkSum1 += sudoku[i][j];

        }
        for (int j = 3; j < 6; j++) {
            checkSum2 += sudoku[i][j];
        }
        for (int j = 6; j < 9; j++) {
            checkSum3 += sudoku[i][j];

        }
    }
    sum[24] = checkSum1;
    sum[25] = checkSum2;
    sum[26] = checkSum3;

    for (int i = 0; i < 27; i++) {

        totalSum += sum[i];
    }

    if (totalSum == 1215) {
        return true; 

    }

    else {
        return false;
    }

 
}

void removeDigits(int sudoku[9][9], int digitsRemoved)
{
    for (int i = 0; i < digitsRemoved; i++)
    {
        int row = rand() % 9;
        int col = rand() % 9;

        while (sudoku[row][col] == 0)
        {
            row = rand() % 9;
            col = rand() % 9;
        }
        sudoku[row][col] = 0;
    }
}

bool isSafe(int sudoku[9][9], int row, int col, int num)
{
    for (int x = 0; x <= 8; x++)
        if (sudoku[row][x] == num)
            return false;

    for (int x = 0; x <= 8; x++)
        if (sudoku[x][col] == num)
            return false;

    int startRow = row - row % 3, startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (sudoku[i + startRow][j + startCol] == num)
                return false;

    return true;
}

bool solveSudoku(int sudoku[9][9], int row, int col)
{
    if (row == 8 && col == 9)
        return true;

    if (col == 9) {
        row++;
        col = 0;
    }

    if (sudoku[row][col] > 0)
        return solveSudoku(sudoku, row, col + 1);

    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(sudoku, row, col, num))
        {
            sudoku[row][col] = num;

            if (solveSudoku(sudoku, row, col + 1))
                return true;
        }

        sudoku[row][col] = 0;
    }
    return false;
}


int main()
{
    
    string userName;
    menu(userName);
	srand(time(0));
    int holdRows[9][9];
    int holdCols[9][9];
    int digitsRemoved = rand() % 16 +20; //set number of digits to be removed between 20 and 35

	int sudoku[9][9] = {
       
    {5, 3, 4, 6, 7, 8, 9, 1, 2},
    {6, 7, 2, 1, 9, 5, 3, 4, 8},
    {1, 9, 8, 3, 4, 2, 5, 6, 7},
    {8, 5, 9, 7, 6, 1, 4, 2, 3},
    {4, 2, 6, 8, 5, 3, 7, 9, 1},
    {7, 1, 3, 9, 2, 4, 8, 5, 6},
    {9, 6, 1, 5, 3, 7, 2, 8, 4},
    {2, 8, 7, 4, 1, 9, 6, 3, 5},
    {3, 4, 5, 2, 8, 6, 1, 7, 9}

	};

    const int rows = 9;
    const int cols = 9;
    int input;

    cout << "Type 1 and press enter to start." << endl;
    sleep(90);
    cout << "Type 0 and press enter to exit." << endl;
    cin >> input;
    
    if (input == 1) {
        do
        {
            shuffleBoard(sudoku, holdRows, holdCols, cols);

        } while (validBoardCheck(sudoku, rows, cols) == false);

        removeDigits(sudoku, digitsRemoved);
        
        cout << "Here is the unsolved valid Sudoku Board:" << endl << endl;

        printBoard(sudoku, rows, cols);

        do {
            cout << endl;
            cout << "To have the program solve this puzzle enter 1." << endl;
            cin >> input;
        } while (input != 1);

        if (solveSudoku(sudoku, 0, 0)) {
            cout << "Here is the solution for this board:" << endl << endl;
            printBoard(sudoku, rows, cols);
            cout << endl;
            cout << "Thank you for participating in this project " << userName << "!" << endl;
       
        }

        else {
            cout << "ERROR, NO SOLUTION FOUND" << endl;
        }


    }
    
    else {
        cout << "Bye " << userName << "!";
        
    }
	return 0;
}


