#include <iostream>
using namespace std;

bool RatInMaze(char maze[][10], int i, int j, int n, int m, int sol[][10]) {
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
		sol[i][j] = 0;
		return false;
	}

	// recursive case
	sol[i][j] = 1;

	// 1. Right side se check karo (N*M-1)
	if (j + 1 < m and maze[i][j + 1] != 'X' and sol[i][j + 1] != 1) {
		bool kyaRightSeMazeSolveHui = RatInMaze(maze, i, j + 1, n, m, sol);
		if (kyaRightSeMazeSolveHui == true) {
			return true;
		}
	}
	// 2. Downward side se check karo(N-1*M)
	if (i + 1 < n and maze[i + 1][j] != 'X' and sol[i + 1][j] != 1) {
		bool kyaNeecheSeMazeSolveHui = RatInMaze(maze, i + 1, j, n, m, sol);
		if (kyaNeecheSeMazeSolveHui == true) {
			return true;
		}
	}
	// 3. left Side se check karo
	if (j - 1 >= 0 and maze[i][j - 1] != 'X' and sol[i][j - 1] != 1) {
		bool kyaLeftSeMazeSolveHui = RatInMaze(maze, i, j - 1, n, m, sol);
		if (kyaLeftSeMazeSolveHui == true) {
			return true;
		}
	}

	// 4. Top side se check karo
	if (i - 1 >= 0 and maze[i - 1][j] != 'X' and sol[i - 1][j] != 1) {
		bool kyaTopSeMazeSolveHui = RatInMaze(maze, i - 1, j, n, m, sol);
		if (kyaTopSeMazeSolveHui == true) {
			return true;
		}
	}

	sol[i][j] = 0;
	return false;
}

int main() {

	char maze[][10] = {
		"0X000",
		"0X0X0",
		"000X0",
		"000X0",
	};
	int sol[10][10] = {0};

	RatInMaze(maze, 0, 0, 4, 5, sol);


	return 0;
}
















