#include <iostream>
#include <cmath>
using namespace std;

bool isSafe(int board[][9], int i, int j, int n, int number) {
	// i,j par number ko rakhna safe hai ya nhi hai
	// 1. number row and column mei nahi aana chahiye
	for (int k = 0; k < n; ++k)
	{
		if (board[k][j] == number || board[i][k] == number) {
			return false;
		}
	}
	// 2. number humara chote cell ke andar nahi aana chahiye
	int sqrt_n = sqrt(n);

	int si = (i / sqrt_n) * sqrt_n;
	int sj = (j / sqrt_n) * sqrt_n;

	for (int k = si; k < si + sqrt_n; ++k)
	{
		for (int l = sj; l < sj + sqrt_n; ++l)
		{
			if (board[k][l] == number) return false;
		}
	}

	return true;
}

bool sudokuSolver(int board[][9], int i, int j, int n) {
	// base case
	if (i == n) {
		// Print the sudoku
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
		return true;
	}

	if (j == n) return sudokuSolver(board, i + 1, 0, n);

	// Agar cell already filled hai, toh recursion se bolo aage ka solution
	// bataye, jo vo return krega merko same hi return krna hai
	if (board[i][j] != 0) return sudokuSolver(board, i, j + 1, n);


	// recursive case
	// Hum kaam krenge ek empty cell ka
	for (int number = 1; number <= n; ++number)
	{
		if (isSafe(board, i, j, n, number) == true) {
			board[i][j] = number;
			bool kyaBaatBani = sudokuSolver(board, i, j + 1, n);
			if (kyaBaatBani) return true;

			board[i][j] = 0; // backtracking
		}
	}
	// Ek bhi number nahi rakh paaye
	return false;
}

int main() {

	int mat[9][9] = {
		{5, 3, 0, 0, 7, 0, 0, 0, 0},
		{6, 0, 0, 1, 9, 5, 0, 0, 0},
		{0, 9, 8, 0, 0, 0, 0, 6, 0},
		{8, 0, 0, 0, 6, 0, 0, 0, 3},
		{4, 0, 0, 8, 0, 3, 0, 0, 1},
		{7, 0, 0, 0, 2, 0, 0, 0, 6},
		{0, 6, 0, 0, 0, 0, 2, 8, 0},
		{0, 0, 0, 4, 1, 9, 0, 0, 5},
		{0, 0, 0, 0, 8, 0, 0, 7, 9}
	};

	sudokuSolver(mat, 0, 0, 9);
	return 0;
}
















