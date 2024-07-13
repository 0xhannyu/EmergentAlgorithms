#include <iostream>
#include <array>
#include <time.h>

#define GRID_X 50 // Columns
#define GRID_Y 50 // Rows

#define WHITE ' '
#define BLACK '+'
#define ANT '#'

#define index1D(row, tCol, col) (row * tCol + col) // Convert 2D index to 1D

using namespace std;

char grid[GRID_Y * GRID_X];
int y = GRID_Y/2, x = GRID_X/2;
char heading = 'N';

void printGrid(int iteration) {

	system("cls");
	cout << iteration << '\n';
	for (int i = 0; i < GRID_Y; i++) {
		for (int j = 0; j < GRID_X; j++) {
			cout << grid[index1D(i, GRID_X, j)];
		}
		cout << '\n';
	}
}

void initializeArray() {

	srand(time(0));

	for (int i = 0; i < GRID_Y; i++) { // row
		for (int j = 0; j < GRID_X; j++) { // col
			grid[index1D(i, GRID_X, j)] = WHITE;
		}
	}

	// Random BLACK cells generated in grid
	/*for (int i = 0; i < (GRID_X * GRID_Y) / 10; i++) {
		int temp = rand() % (GRID_X * GRID_Y);
		grid[temp] = BLACK;

	}*/
}

void task(int xX, int yY, char hH) {
	x += xX;
	y += yY;
	heading = hH;
}

void updateHeading(char turn) {
	switch(heading) {
		case 'W' :
			turn == 'L' ? task(0, 1, 'S') : task(0, -1, 'N');
			break;
		case 'N' :
			turn == 'L' ? task(-1, 0, 'W') : task(1, 0, 'E');
			break;
		case 'E' :
			turn == 'L' ? task(0, -1, 'N') : task(0, 1, 'S');
			break;
		case 'S' :
			turn == 'L' ? task(1, 0, 'E') : task(-1, 0, 'W');
			break;
	}
}

void move() {

	if(x > GRID_X || x < 0) { x = x > GRID_X ? 0 : GRID_X; }
	if(y > GRID_Y || y < 0) { y = y > GRID_Y ? 0 : GRID_Y; }

	if(grid[index1D(y, GRID_X, x)] == WHITE) {
		grid[index1D(y, GRID_X, x)] = BLACK;
		updateHeading('R'); // 90-Deg Clockwise
	}

	else {
		grid[index1D(y, GRID_X, x)] = WHITE;
		updateHeading('L'); // 90-Deg Anti-Clockwise
	}
}

int main() {

	initializeArray();

	int i = 0;

	for(;;) {
		i++;
		move();
		printGrid(i);
	}
}