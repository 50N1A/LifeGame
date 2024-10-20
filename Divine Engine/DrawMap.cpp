#include <iostream>

void ClearConsole() {
	system("cls");
}

void DrawMap(char** map, bool** mapbool, int Width, int Height)
{
	for (int i = 0; i < Width; i++) {
		for (int j = 0; j < Height; j++) {
			std::cout << map[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	
}

void UpdateMap(char** map,bool**mapbool, int Width, int Height) {
	int counter = 0;
	for (int i = 0; i < Width; i++) {
		for (int j = 0; j < Height; j++) {
			counter = 0;
			if (i - 1 >= 0 && j - 1 >= 0 && map[i - 1][j - 1] == '#')counter++;
			if (i - 1 >= 0 && map[i - 1][j] == '#')counter++;
			if (i - 1 >= 0 && j + 1 < Height && map[i - 1][j + 1] == '#')counter++;
			if (j - 1 >= 0 && map[i][j - 1] == '#')counter++;
			if (j + 1 < Height && map[i][j + 1] == '#')counter++;
			if (i + 1 < Width && j - 1 >= 0 && map[i + 1][j - 1] == '#')counter++;
			if (i + 1 < Width && map[i + 1][j] == '#')counter++;
			if (i + 1 < Width && j + 1 < Height && map[i + 1][j + 1] == '#')counter++;
			if (counter == 3 && map[i][j] == ' ') {
				mapbool[i][j] = true;
				continue;
			}
			if ((counter == 2 || counter == 3) && map[i][j] == '#') mapbool[i][j] = true;
		}
		
	}
	for (int i = 0; i < Width; i++) {
		for (int j = 0; j < Height; j++) {
			if (mapbool[i][j] == true) map[i][j] = '#';
			else map[i][j] = ' ';
		}
	}
	for (int i = 0; i < Width; i++) {
		for (int j = 0; j < Height; j++) {
			mapbool[i][j] = false;
		}
	}
}