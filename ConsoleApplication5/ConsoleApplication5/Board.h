#pragma once
#include<SFML/Graphics.hpp>
#include<vector>

enum tileType {
	black,
	white
};

class Board
{
public:
	Board(sf::RenderWindow &window, int height, int width, int tilesInRow, int tilesInCol);
	sf::RectangleShape tileShape;
	int boardH, boardW;
	int tileH, tileW;
	int tilesPerRow, tilesPerCol;
	int tileCount;
	void drawBoard(sf::RenderWindow &window);
	sf::Vector2f getTilePos(int N);
	
	std::vector<tileType> tileTypes;
};