#include <iostream>
#include <cstdlib>
#include<windows.h>
#include<bits/stdc++.h>
#include <cstring>
#include <conio.h>
using namespace std;

const int N = 9;

void menu(int board[N][N]);
void condition(int board[N][N]);

bool isSafe(int board[N][N], int row, int col, int num)
{

    for (int i = 0; i < N; i++)
        if (board[row][i] == num)
            return false;


    for (int i = 0; i < N; i++)
        if (board[i][col] == num)
            return false;


    int boxRowStart = row - row % 3;
    int boxColStart = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i + boxRowStart][j + boxColStart] == num)
                return false;

    return true;
}

void printBoard(int grid[N][N])
{

    system("cls");
    cout << "\t\t\t<================================================================================>" << endl;
    cout << "\t\t\t|                        WELCOME TO SUDOKU Game!                                 |" << endl;
    cout << "\t\t\t|       Fill in the missing numbers(represented by 0) to solve the puzzle.       |" << endl;
    cout << "\t\t\t<================================================================================>" << endl;
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            if(col == 3 || col == 6)
                cout << " | ";
            cout << grid[row][col] <<" ";
        }
        if(row == 2 || row == 5)
        {
            cout << endl;
            for(int i = 0; i<N; i++)
                cout << "---";
        }
        cout << endl;
    }

}
void load()
{
    system("Color 0e");
    system("cls");
    printf("\e[?251]");
    SetConsoleCP(437);
    SetConsoleOutputCP(437);

    int b1=177,b2=219;
    cout<<"\n\n\n\t\t\t\t\t\t\tLoading....";
    \
    cout<<"\n\n\n\t\t\t\t";
    for(int i=0; i<60; i++)
    {
        cout<<(char)b1;

    }
    cout<<"\r";
    cout<<"\t\t\t\t";
    for(int i=0; i<60; i++)
    {
        cout<<(char)b2;
        Sleep(150);
    }
    cout<<"\n\t\t\t\t"<<(char)1<<"!";
    system("Pause");
}


bool solveSudoku(int board[N][N], int row, int col)
{




    if (row == N - 1 && col == N)
        return true;


    if (col == N)
    {
        row++;
        col = 0;

    }


    if (board[row][col] != 0)
        return solveSudoku(board, row, col + 1);


    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(board, row, col, num))
        {
            board[row][col] = num;

            if (solveSudoku(board, row, col + 1))
                return true;

            board[row][col] = 0;
        }
    }
    return false;
}

bool isSolvedCompletely(int grid[N][N])
{
    for (int row = 0; row < N; row++)
        for (int col = 0; col < N; col++)
            if (grid[row][col] == 0)
                return false;

    return true;
}


void playGame(int board[N][N])
{
    int ch;
    int row, col, num;
    while(true)
    {
        printBoard(board);
        cout << endl << endl;
        cout << "Unable to solve? Enter -1 as row, col and num to view the solved sudoku."<<endl;
        cout << "Enter row: ";
        cin >> row;
        cout << "Enter column: ";
        cin >> col;
        cout << "Enter number: ";
        cin >> num;


        if(row == -1 || col == -1 || num == -1)
        {
            solveSudoku(board, 0, 0);
            printBoard(board);
            cout << endl;
            cout << "Better luck next time!!!" << endl;
            return;
        }
        if (isSolvedCompletely(board))
            break;
        row--;
        col--;
        if (!isSafe(board, row, col, num))
        {
            cout << "Invalid move. Try again." << endl;
            getch();
            continue;
        }
        board[row][col] = num;
    }

    // Check if the user has solved it correctly or not
    bool solved = true;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 0)
            {
                solved = false;
                break;
            }
        }
    }

    if (solved)
    {
        cout << "Congratulations! You have solved the puzzle." << endl;
        printBoard(board);
    }
    else
    {
        cout << "Puzzle not solved. Better luck next time." << endl;
    }
condition(board);
}

void condition(int board[N][N])
{
    while (true)
    {
        int choice;
        cout << endl << endl;
        cout<<  "\t\t[1] RETURN "<<endl;
        cout << "\t\t[0] EXIT" << endl;
        cout << "\n\t\t\t\t ENTER YOUR CHOICE :  ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            system("cls");
            menu(board);
            break;
        case 0:
            exit(0);

        default:
            cout << "Invalid choice" << endl;
        }
    }
}

void instructions(int board[N][N])
{
    system("cls");
    cout<<"\t  1-> Solve 4x4 Sudoku puzzles using only the numbers 1-4 "<<endl;
    cout<<"\t\tIn a 4x4 Sudoku puzzle, answer every square with a whole number."<<endl;
    cout<<"\t\tExamine the \e clues\e (or, the numbers provided by the puzzle). "<<endl;
    cout<<"\t\tThe clues will also always be a whole number between 1 and 4 "<<endl;
    cout<<endl;

cout<<"\t 2-> Use each number just once in a single row."<<endl;
cout<<"\t\t  To solve a 4x4 puzzle, arrange the numbers so no number repeats" <<endl;
cout<<"\t\t  So for example, a row filled in with the sequence "<<endl;
cout<<"\t\t  for example, a row filled in with the sequence (1, 3, 1, 4) "<<endl;
cout<<"\t\t The sequence (1, 3, 2, 4), though, works for a single row."<<endl;
cout<<endl;

cout<<"\t 3->  Use each number just once in a single square."<<endl;
cout<<"\t\t  In addition to rows and columns, there are also four boxes "<<endl;
cout<<"\t\t Within these squares, arrange the numbers 1-4 so that no number "<<endl;
cout<<"\t\t  Ensure that each number appears once in each box."<<endl;
cout<<endl;

cout<<"\t 4->  Fill in every square to solve the puzzle."<<endl;
cout<<"\t\t  Every box, row, and column needs to be filled in completely. "<<endl;
cout<<"\t\t  To ensure you have the correct solution, double-check that no numbers repeating"<<endl;


    condition(board);
}

void welcome()
{
    cout << "\t\t\t #################################################################################" << endl;
    cout << "\t\t\t #################################################################################" << endl;
    cout<<endl;
    cout << "\t\t\t |                             WELCOME TO SUDOKU !                               |" << endl;
    cout<<endl;
    cout << "\t\t\t |       Fill in the missing numbers(represented by 0) to solve the puzzle.      |" << endl;
    cout<<endl;
    cout<<  "\t\t\t\t\t\t\t\t\t\t ~INVENTED BY ARYAMAN VISHNOI" <<endl;
    cout<<endl;
    cout << "\t\t\t #################################################################################" << endl;
    cout << "\t\t\t #################################################################################" << endl;
}

void menu(int board[N][N])
{
    while (true)
    {
        int choice;
        cout << endl << endl;
        cout<<  "\t\t\t\t[1] INSTRUCTIONS TO PLAY "<<endl;
        cout << "\t\t\t\t[2] PLAY THE GAME" << endl;
        cout << "\t\t\t\t[3] VIEW THE SOLVED SODOKU" << endl;
        cout << "\t\t\t\t[4] EXIT THE GAME" << endl;
        cout << "\n\t\t\t\t ENTER YOUR CHOICE :  ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            system("cls");
            instructions(board);
            break;
        case 2:
            system("cls");
            playGame(board);
            break;
        case 3:
            system("cls");
            if (solveSudoku(board, 0, 0))
            {
                cout << "Completely Solved Sudoku is: "<< endl;
                cout << endl << endl;
                for (int row = 0; row < N; row++)
                {
                    for (int col = 0; col < N; col++)
                    {
                        if(col == 3 || col == 6)
                            cout << " | ";
                        cout << board[row][col] <<" ";
                    }
                    if(row == 2 || row == 5)
                    {
                        cout << endl;
                        for(int i = 0; i<N; i++)
                            cout << "---";
                    }
                    cout << endl;
                }
                cout << endl;
                cout << "Better luck next time!!!" << endl;
            }
            else
                cout << "No solution found" << endl;
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
        }
        cout<<"\nPRESS ANY KEY TO CONTINUE ";
        getch();
    }
}

int main()
{
    load();
    system("cls");
    system("color 0e");

    int board[N][N] =
    {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };
    welcome();
    menu(board);

    return 0;
}


