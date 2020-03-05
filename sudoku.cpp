// sudoku.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "solver.h"

using namespace std;

int main()
{
    cout << "Welcome to Sudoku Solver!\n";
    cout << "This product is created by Abinav Sadhneni of UofM Engineering\n";
    cout << "Version 1.0 (3/1/20)\n\n";
    cout << "What would you like to do today?\n";
    cout << "[0] Sudoku Solver\n";
    int option; cin >> option;
    if (option == 0) {
        vector<vector<int>> sudoku(9,vector<int>(9,0));
        vector<point> list;
        readIn(sudoku, list);
        solver(sudoku, list);
        //output result
        cout << "\nSolution: \n";
        for (size_t r = 0; r < 9; r++) {
            if (r == 3 || r == 6) {
                cout << "- - - - - - - - - - -\n";
            }
            for (size_t c = 0; c < 9; c++) {
                cout << sudoku[r][c] << " ";
                if (c == 2 || c == 5) {
                    cout << "| ";
                }
            }
            cout << "\n";
        }
    }
    else {
        cout << "Not valid option...\n";
        cout << "Ending Program\n";
    }
    return 0;
}