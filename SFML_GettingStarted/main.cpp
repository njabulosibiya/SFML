#include <SFML/Graphics.hpp>
#include <iostream>

#include "headers/gettingStarted.h"
#include "headers/shapes.h"
#include "headers/vertexArrayBasics.h"
#include "headers/myentity.h"
#include "headers/tilemap.h"
#include "headers/particleSystem.h"

TileMap getMap() {

	// define the level with an array of tile indices
	const int level[] =
	{
		0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
		1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
		0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
		0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
		0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
		2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
		0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
	};

	TileMap map;

	if (!map.load("resources/tileset.png", sf::Vector2u(32, 32), level, 16, 8))
		std::cout << "Map not found";

	return map;
}

int main() {
	// Anti-aliasing
	// settings will store settings
	sf::ContextSettings settings;
	// set anti-aliasing level setting
	settings.antialiasingLevel = 8;

	//renders the window
	// pass settings to window
	sf::RenderWindow window(sf::VideoMode(512, 256), "Tile Map", sf::Style::Default, settings);
	//window position realatuve to desktop(x:y coordinates)
	window.setPosition(sf::Vector2i(10, 50));
	//change window size
	//window.setSize(sf::Vector2u(900, 900));
	//change title of window
	// window.setTitle("Aaaaaaaaaaaaaagggghhhhhhhhh");

	// deactivate its OpenGL context
	// window.setActive(false);

	//get size of the window
	// sf::Vector2u size(window.getSize());

	// launch the rendering thread
	//sf::Thread thread(&renderingThread, &window);
	//thread.launch();

	//check if window has focus
	bool focus = !window.hasFocus();

	sf::Font font(GettingStarted::loadFont());
	sf::Texture texture(GettingStarted::loadStoneWallTexture());

	sf::CircleShape myCircle(GettingStarted::myCircle(texture, 1, 0));
	sf::Sprite mySprite(GettingStarted::mySprite(texture));

	ParticleSystem particles(1000);

	sf::Clock clock;





	//run program as long as window is open
	while (window.isOpen()) {
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		
		while (window.pollEvent(event)) {
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed) window.close();
			
			GettingStarted::windowResize(event);
			GettingStarted::keyPressed(event);
			GettingStarted::mouseWheelScrolled(event);
			GettingStarted::mouseButtonPressed(event);
			GettingStarted::mouseMoved(event);
			GettingStarted::mousePresence(&event);
			GettingStarted::keyboardKeyPressed(myCircle);
			GettingStarted::mouseInput(myCircle);
		}

		// make the particle system emitter follow the mouse
		sf::Vector2i mouse = sf::Mouse::getPosition(window);
		particles.setEmitter(window.mapPixelToCoords(mouse));

		// update it
		sf::Time elapsed = clock.restart();
		particles.update(elapsed);

		window.clear(sf::Color::Black);
		//window.draw(mySprite);
		//window.draw(GettingStarted::myText("Hello SFML!", font));
		//window.draw(Shapes::myPolygon(3));
		//window.draw(VertexBasics::vertexArray());
		//window.draw(VertexBasics::texturedVertex(), &texture);
		window.draw(particles);
		window.draw(myCircle);
		window.display();
	}

	return 0;
}
