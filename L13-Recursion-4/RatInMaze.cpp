#include <iostream>
using namespace std;

bool RatInMaze(char maze[][5], int i, int j, int n, int m, int sol[][10]) {
	// base case
	if (i == n - 1 and j == m - 1) {
		sol[i][j] = 1; // Desitination is part of the solution
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cout << sol[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;

		return false;
	}

	// recursive case
	// Initially current cell ka kaam mujhe krna hai
	// Assume it to be a part of the solution
	sol[i][j] = 1;
	// 1. Right side se check karo (N*M-1)
	if (j + 1 < m and maze[i][j + 1] != 'X') {
		bool kyaRightSeMazeSolveHui = RatInMaze(maze, i, j + 1, n, m, sol);
		if (kyaRightSeMazeSolveHui == true) {
			return true;
		}
	}
	// 2. Downward side se check karo(N-1*M)
	if (i + 1 < n and maze[i + 1][j] != 'X') {
		bool kyaNeecheSeMazeSolveHui = RatInMaze(maze, i + 1, j, n, m, sol);
		if (kyaNeecheSeMazeSolveHui == true) {
			return true;
		}
	}

	sol[i][j] = 0;
	return false;
}

int main() {

	char maze[][5] = {
		"0000",
		"00XX",
		"0000",
		"XX00"
	};
	int sol[10][10] = {0};

	RatInMaze(maze, 0, 0, 4, 4, sol);


	return 0;
}
















