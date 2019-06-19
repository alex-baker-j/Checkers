#include"pch.h"
#include"Board.h"

Board::Board(sf::RenderWindow &window, int height, int width, int tilesInRow, int tilesInCol) {
	boardH = height;
	boardW = width;
	tilesPerCol = tilesInCol;
	tilesPerRow = tilesInRow;
	tileCount = tilesPerCol * tilesPerRow;
	tileH = boardH / tilesPerCol;
	tileW = boardW / tilesPerRow;
	tileTypes = std::vector<tileType>(tileCount);
	tileShape = sf::RectangleShape(sf::Vector2f(tileW, tileH));
	for (int i = 0; i < tileCount; i++) {
		if (i % 2 - (i / tilesPerRow) % 2 == 0) {
			tileTypes[i] = white;
		}
		else {
			tileTypes[i] = black;
		}
	}
}

sf::Vector2f Board::getTilePos(int N) {
	float posx, posy;
	posx = (N % tilesPerRow) * tileW;
	posy = (N / tilesPerCol) * tileH;
	return sf::Vector2f(posx, posy);
}

void Board::drawBoard(sf::RenderWindow &window) {
	sf::Vector2f tilePos;
	for (int i = 0; i < tileCount; i++) {
		tilePos = getTilePos(i);
		tileShape.setPosition(tilePos);
		if (tileTypes[i] == white) {
			tileShape.setFillColor(sf::Color::White);
		}
		else {
			tileShape.setFillColor(sf::Color::Black);
		}
		window.draw(tileShape);
	}
}