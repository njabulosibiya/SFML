#ifndef DRAWCIRCLE_H
#define DRAWCIRCLE_H

#include <SFML/Graphics.hpp>
#include <iostream>

class GettingStarted {
public:
	//constructor
	GettingStarted();

	bool operator==(const GettingStarted& other) const;
	/* ============= EVENT FUNCTIONS =============*/

	//window Resize sf::event
	static void windowResize(const sf::Event& event);
	//the KeyPressed sf::even
	static void keyPressed(const sf::Event& event);
	//event: mousewhel scrolling
	static void mouseWheelScrolled(const sf::Event& event);
	//for when buttons on the mouse are pressed
	static void mouseButtonPressed(const sf::Event& event);
	//for when mouse is moved inside window
	static void mouseMoved(const sf::Event& event);
	//for when the mouse enters and leaves the window
	static void mousePresence(const sf::Event* event);

	/* ============= INPUT FUNCTIONS =============*/
	//keyboard input
	static void keyboardKeyPressed(sf::CircleShape& character);
	//mouse input
	static void mouseInput(sf::CircleShape& character);


	/* ============= Sprite & TEXTURE FUNCTIONS =============*/
	//void textureFunction();
	static sf::Texture loadStoneWallTexture();

	static sf::Sprite mySprite(const sf::Texture& texture);
	static sf::CircleShape myCircle(const sf::Texture& texture, bool hasTexture, bool hasOutline);
	static sf::Texture loadCharacter();


	/* ============= FONT FUNCTIONS =============*/
	static sf::Font loadFont();
	static sf::Text myText(std::string displayText, const sf::Font& font);


	/* ============= THREADING FUNCTIONS =============*/
	static void renderingThread(sf::RenderWindow* window);
	
};
#endif // !DRAWCIRCLE_H

