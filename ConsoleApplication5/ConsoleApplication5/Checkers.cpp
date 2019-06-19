

#include "pch.h"
#include<SFML/Graphics.hpp>
#include "Board.h"
#include <iostream>

int main()
{
	const int windowW = 800;
	const int windowH = 800;
	const int tilesPerRow = 8;
	const int tilesPerCol = 8;


	sf::RenderWindow window(sf::VideoMode(windowW, windowH), "Checkers");

	Board gameBoard(window, windowW, windowH, tilesPerRow, tilesPerCol);
	

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		
		gameBoard.drawBoard(window);
		window.display();
	}
}
