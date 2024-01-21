#include <iostream>
using namespace std;

bool isSafe(int board[][100], int i, int j, int n) {
	// 1. Current col mei queen nhi honi chahiye
	for (int k = 0; k < i; ++k)
	{
		if (board[k][j] == 1) return false;
	}

	// 2. Left diagonal mei queen nhi honi chahiye
	int original_i = i;
	int original_j = j;

	while (i >= 0 and j >= 0) {
		if (board[i][j] == 1) return false;
		i--;
		j--;
	}
	// 3. Right diagonal mei queen nhi honi chahiye
	i = original_i;
	j = original_j;
	while (i >= 0 and j < n) {
		if (board[i][j] == 1) return false;
		i--;
		j++;
	}
	return true;
}

bool nQueen(int board[][100], int row, int n) {
	// base case
	if (row == n) {
		// Print the board
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (board[i][j] == 1) cout << "Q ";
				else cout << "_ ";
			}
			cout << endl;
		}
		cout << endl;
		return false;
	}

	// recursive case
	for (int col = 0; col < n; ++col)
	{
		if (isSafe(board, row, col, n) == true) {
			board[row][col] = 1; // Queen ko place kar diya
			bool kyaBaakiBaatBani = nQueen(board, row + 1, n);
			if (kyaBaakiBaatBani) return true;

			board[row][col] = 0; // backtracking
		}
	}

	return false;
}

int main() {

	int board[100][100] = {0};

	int n;
	cin >> n;

	nQueen(board, 0, n);



	return 0;
}
















