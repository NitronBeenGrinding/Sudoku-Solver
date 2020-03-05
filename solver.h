#pragma once
#include <vector>
#include <iostream>

using namespace std;

struct point {
	int r;
	int c;
};

void readIn(vector<vector<int>> &sudoku, vector<point> &total) {
	cout << "Make sure to put your sudoku puzzle in this format:\n";
	cout << "1 2 3 | 4 5 6 | 7 8 9\n";
	cout << "2 3 4 | 5 6 7 | 8 9 1\n";
	cout << "3 4 5 | 6 7 8 | 9 1 2\n";
	cout << "- - - - - - - - - - -\n";
	cout << "4 5 6 | 7 8 9 | 1 2 3\n";
	cout << "5 6 7 | 8 9 1 | 2 3 4\n";
	cout << "6 7 8 | 9 1 2 | 3 4 5\n";
	cout << "- - - - - - - - - - -\n";
	cout << "7 8 9 | 1 2 3 | 4 5 6\n";
	cout << "8 9 1 | 2 3 4 | 5 6 7\n";
	cout << "9 1 2 | 3 4 5 | 6 7 8\n";
	cout << "---------------------\n";
	cout << "If you have an empty space, put a 0 in its place.\n\n";
	cout << "Sudoku Puzzle: \n";
	char waste;
	for (size_t r = 0; r < 9; r++) {
		if (r == 3 || r == 6) {
			for (size_t c = 0; c < 11; c++) {
				cin >> waste;
			}
		}
		for (size_t c = 0; c < 9; c++) {
			cin >> sudoku[r][c];
			if (sudoku[r][c] == 0) {
				total.push_back({(int)r,(int)c});
			}
			if (c == 2 || c == 5) {
				cin >> waste;
			}
		}
	}

	cout << "\nPuzzle inputted: \n";
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

bool check(int insert, int r, int c, vector<vector<int>> &sudoku) {
	//row-column check
	for (size_t i = 0; i < sudoku.size(); i++) {
		if (insert == sudoku[r][i]) {
			return false;
		}
		if (insert == sudoku[i][c]) {
			return false;
		}
	}
	//find box
	int boxr = r / 3; int boxc = c / 3;
	for (int r1 = 0; r1 < 3; r1++) {
		for (int c1 = 0; c1 < 3; c1++) {
			if (insert == sudoku[boxr * 3 + r1][boxc * 3 + c1]) {
				return false;
			}
		}
	}
	return true;
}

void solver(vector<vector<int>> &sudoku, vector<point> &total) {
	auto it = total.begin();
	int insert = 1;
	while (it != total.end()) {
		if (check(insert, (*it).r, (*it).c, sudoku)) {
			sudoku[(*it).r][(*it).c] = insert;
			insert = 1;
			it++;
		}
		else if (insert == 9 && it == total.begin()) {
			cout << "No solutions found\n";
			break;
		}
		else if (insert == 9) {
			while (insert >= 9) {
				sudoku[(*it).r][(*it).c] = 0;
				it--;
				insert = sudoku[(*it).r][(*it).c];
			}
			insert++;
		}
		else {
			insert++;
		}
	}
}