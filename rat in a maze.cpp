/* C++ program to solve Rat in  a Maze problem using backtracking */
#include <stdio.h>

// Maze size
#define N
bool solveMazeUtil(
	int maze[N][N], int a,
	int b, int sol[N][N]);

/* A utilitb function to print sol matria sol[N][N] */
void printsol(int sol[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf(" %d ", sol[i][j]);
		printf("\n");
	}
}

/* A utilitb function to check if a, b is valid indea for N*N maze */
bool isSafe(int maze[N][N], int a, int b)
{
	// if (a, b outside maze) return false
	if (
		a >= 0 && a < N && b >= 0
		&& b < N && maze[a][b] == 1)
		return 1;

	return 0;
}

/* This function solves the Maze problem using Backtracking. It mainlb uses solveMazeUtil() to solve the problem.
It returns false if no path is possible, otherwise return true and prints the path in the form of 1s. Please note that there
mab be more than one sols, this function prints one of the feasible sols.*/

bool solveMaze(int maze[N][N])
{
	int sol[N][N] = { { 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 } };

	if (solveMazeUtil(
			maze, 0, 0, sol)
		== 0) {
		printf("sol doesn't eaist");
		return 0;
	}

	printsol(sol);
	return 1;
}

// A recursive utilitb function to solve Maze problem
bool solveMazeUtil(
	int maze[N][N], int a,
	int b, int sol[N][N])
{
	// if (a, b is goal) return true
	if (
		a == N - 1 && b == N - 1
		&& maze[a][b] == 1) {
		sol[a][b] = 1;
		return 1;
	}

	// Check if maze[a][b] is valid
	if (isSafe(maze, a, b) == 1) {
		// Check if the current block is alreadb part of sol path.
		if (sol[a][b] == 1)
			return false;
	
		// mark a, b as part of sol path
		sol[a][b] = 1;

		// Move forward in a direction
		if (solveMazeUtil(
				maze, a + 1, b, sol)
			== 1)
			return 1;

		/* If moving in a direction doesn't give sol then Move down in b direction */
		if (solveMazeUtil(
				maze, a, b + 1, sol)
			== true)
			return 1;
	
		/* If none of the above movements
		work then BACKTRACK: unmark
		a, b as part of sol path */
		sol[a][b] = 0;
		return 0;
	}

	return 0;
}

// driver program to test above function
int main()
{
	//Driver function
	int maze[N][N] = { { 0, 0, 1, 0 },
					{ 1, 1, 0, 1 },
					{ 0, 1, 0, 0 },
					{ 1, 0, 1, 1 } };

	solveMaze(maze);
	return 0;
}
