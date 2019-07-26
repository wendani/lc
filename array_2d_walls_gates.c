void updateDist(int **rooms, int rowSize, int colSize, int i, int j, int distToGate)
{
	if (i < 0 || i > rowSize - 1) {
		return;
	}

	if (j < 0 || j > colSize - 1) {
		return;
	}

	if (rooms[i][j] == -1) {
		return;
	}

	if (distToGate < rooms[i][j]) {
		rooms[i][j] = distToGate;
	}

	distToGate++;
	// East
	updateDist(rooms, rowSize, colSize, i, j + 1, distToGate);
	// South
	updateDist(rooms, rowSize, colSize, i + 1, j, distToGate);
	// North
	updateDist(rooms, rowSize, colSize, i - 1, j, distToGate);
	// West
	updateDist(rooms, rowSize, colSize, i, j - 1, distToGate);
}

void wallsAndGates(int** rooms, int roomsSize, int* roomsColSize){
	int i, j;
	if (!room || !*room || roomsSize < 1 || *roomsColSize < 1) {
		return;
	}

	for (i = 0; i < roomsSize; i++)
		for (j = 0; j < *roomsColSize; j++) {
			if (rooms[i][j] == 0) {
				updateDist(room, roomsSize, *roomsColSize, i, j, 0);
			}
		}
}
