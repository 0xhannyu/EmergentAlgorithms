#include <iostream>

#define index1D(row, tCol, col) (row * tCol + col) // Convert 2D index to 1D

const int GRID_X = 100;
const int GRID_Y = 50;

using namespace std;

int grid[GRID_X * GRID_Y];

void printGrid() {
	system("cls");
	for (int i = 0; i < GRID_Y * GRID_X; i++) {
		cout << (grid[index1D(i % GRID_X, GRID_Y, i / GRID_X)] == 0 ? '-' : '#');
		if ((i + 1) % GRID_X == 0) cout << '\n';
	}
}

void fillGrid() {
	for (int i = 0; i < GRID_X * GRID_Y; i++) {
		grid[i] = 0;
	}
}

int main() {
	fillGrid();
	grid[index1D(GRID_X/2, GRID_Y, 0)] = 1;
	for(int h = 0; h < GRID_Y; h++) {
		for (int w = 0; w < GRID_X; w++) {
			int a = w - 1 < 0 ? GRID_X-1 : w - 1;
			int b = w + 1 > GRID_X-1 ? 0 : w + 1;
			a = grid[index1D(a, GRID_Y, h)];
			b = grid[index1D(b, GRID_Y, h)];
			grid[index1D(w, GRID_Y, h+1)] = a ^ b;
		}
	}
	printGrid();
	return 0;
}