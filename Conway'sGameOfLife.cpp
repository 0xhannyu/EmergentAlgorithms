#include <iostream>
#include <array>
#include <time.h>

#define GRID_X 30 // Columns
#define GRID_Y 30 // Rows

#define LIFE '+'
#define DEATH ' '

using namespace std;

char grid[GRID_Y * GRID_X];

void printGrid(int gen, int  population) {

	system("cls");
	cout << "GEN: " << gen << "\t\t" << "POPULATION: " << population << '\n';
	for (int i = 0; i < GRID_Y; i++) {
		for (int j = 0; j < GRID_X; j++) {
			cout << grid[i * GRID_X + j];
		}
		cout << '\n';
	}
}


void initializeArray() {

	srand(time(0));

	for (int i = 0; i < GRID_Y; i++) { // row
		for (int j = 0; j < GRID_X; j++) { // col
			grid[GRID_X * i + j] = DEATH;
		}
	}

	// Random LIFE cells generated in grid
	for (int i = 0; i < (GRID_X * GRID_Y) / 10; i++) {
		int temp = rand() % (GRID_X * GRID_Y);
		grid[temp] = LIFE;

	}
}

int rowOffsets[] = {-1, 0, 1};
int colOffsets[] = {-1, 0, 1};


int checkCells() {

	int n = 0;
	int x , y;
	int population = 0;

	for (int i = 0; i < GRID_X * GRID_Y; i++) {
		x = i % GRID_X; // col
		y = i / GRID_X; // row

		if(grid[i] == LIFE) { population++; }

		for (int r = 0; r < 3; r++) {
			for (int c = 0; c < 3; c++) {
			// Skip the center element (i, j)
				if (r == 1 && c == 1) {
					continue;
				}

				// Calculate neighbor index with boundary checks
				int neighborRow = y + rowOffsets[r];
				int neighborCol = x + colOffsets[c];

				// Check if neighbor is within valid bounds
				bool isValidNeighbor = neighborRow >= 0 && neighborRow < GRID_Y && neighborCol >= 0 && neighborCol < GRID_X;

				if (isValidNeighbor) {
					if(grid[GRID_X * neighborRow + neighborCol] == LIFE) {
						n++;
					}
				}
			}
		}

		if (n < 2) {
			grid[i] = DEATH;
		}

	    else if(n > 3) {
	    	grid[i] = DEATH;
	    }

	    else if(n == 3 && grid[i] == DEATH) {
	    	grid[i] = LIFE;
	    }

	    n = 0;
	}

	return population;
}


int main() {

	initializeArray();

	int gen = 0;
	int population;

	for(;;) {
		gen++;
		population = checkCells();
		printGrid(gen, population);
	}

	return 0;
}