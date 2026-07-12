static void _explore(char **grid, int rowSize, int columnSize, int row, int column)
{
	if (row < 0 || row > rowSize - 1)
		return;

	if (column < 0 || column > columnSize - 1)
		return;

	if (grid[row][column] != '1')
		return;

	// reach here with grid[row][column] == '1'
	grid[row][column] = '2';
	// south
	_explore(grid, rowSize, columnSize, row + 1, column);
	// east
	_explore(grid, rowSize, columnSize, row, column + 1);
	// west
	_explore(grid, rowSize, columnSize, row, column - 1);
	// north
	_explore(grid, rowSize, columnSize, row - 1, column);
}

int numIslands(char** grid, int gridSize, int* gridColSize){
	int i, j;
	int islands;

	islands = 0;
	for (i = 0; i < gridSize; i++)
		for (j = 0; j < *gridColSize; j++)
			if (grid[i][j] == '1') {
				islands++;
				_explore(grid, gridSize, *gridColSize, i, j);
			}

	return islands;
}
