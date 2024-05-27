#include "headers/gettingStarted.h"

#include <SFML/Graphics.hpp>

GettingStarted::GettingStarted() {

}

void GettingStarted::windowResize(const sf::Event& event) {

	if (event.type == sf::Event::Resized) {
		std::cout << "new height: " << event.size.height << std::endl;
		std::cout << "new width: " << event.size.width << std::endl;
	}
}

void GettingStarted::keyPressed(const sf::Event& event) {
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.scancode == sf::Keyboard::Scan::Escape) {
			std::cout << "the escape key was pressed" << std::endl;
			std::cout << "scancode: " << event.key.scancode << std::endl;
			std::cout << "code: " << event.key.code << std::endl;
			std::cout << "control: " << event.key.control << std::endl;
			std::cout << "alt: " << event.key.alt << std::endl;
			std::cout << "shift: " << event.key.shift << std::endl;
			std::cout << "system: " << event.key.system << std::endl;
			std::cout << "description: " << sf::Keyboard::getDescription(event.key.scancode).toAnsiString() << std::endl;
			std::cout << "localize: " << sf::Keyboard::localize(event.key.scancode) << std::endl;
			std::cout << "delocalize: " << sf::Keyboard::delocalize(event.key.code) << std::endl;
		}
	}
}

void GettingStarted::mouseWheelScrolled(const sf::Event& event) {
	//if our mouse wheel is scrolled
	if (event.type == sf::Event::MouseWheelScrolled) {
		//if the event is that of the mousewheel moving up or down
		if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
			std::cout << "wheel type: vertical" << std::endl;
		}
		//if the event is that of the mousewheel in a horizontal direction
		else if (event.mouseWheelScroll.wheel == sf::Mouse::HorizontalWheel) {
			std::cout << "wheel type: horizontal" << std::endl;
		}
		else
			std::cout << "wheel type: unknown" << std::endl;

		std::cout << "wheel movement: " << event.mouseWheelScroll.delta << std::endl;
		//returns horizontal(x)location of mouse pointer in window
		std::cout << "mouse x: " << event.mouseWheelScroll.x << std::endl;
		//returns vertical(y) location of mouse pointer in window
		std::cout << "mouse y: " << event.mouseWheelScroll.y << std::endl;
	}
}

void GettingStarted::mouseButtonPressed(const sf::Event& event) {
	//if the type of event is a mouse button click
	if (event.type == sf::Event::MouseButtonPressed) {
		//if the button pressed is the right button
		if (event.mouseButton.button == sf::Mouse::Right) {
			std::cout << "right mouse button pressed\n";
			std::cout << "mouse x: " << event.mouseButton.x << std::endl;
			std::cout << "mouse y: " << event.mouseButton.y << std::endl;
		}
	}
}

void GettingStarted::mouseMoved(const sf::Event& event) {
	//if the event type is the moving of the mouse
	if (event.type == sf::Event::MouseMoved) {
		std::cout << "new mouse x: " << event.mouseMove.x << std::endl;
		std::cout << "new mouse y: " << event.mouseMove.y << std::endl;
	}
}

void GettingStarted::mousePresence(const sf::Event* event) {
	//if mouse enters window
	if (event->type == sf::Event::MouseEntered) {
		std::cout << "Welcome home mouse, welcome home\n";
	}
	//if mouse leaves window
	else if (event->type == sf::Event::MouseLeft) {
		std::cout << "Goodbye mousie\n";
	}
}

void GettingStarted::keyboardKeyPressed(sf::CircleShape& character) {
	//get & store character position
	sf::Vector2f characterPosition(character.getPosition());
	signed int speed(3);

	//if left key is pressed, we move our circle to the left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		//move character left
		character.move(-speed, 0.f);
		//debug
		std::cout << "character moved left, new position:\nX: " << characterPosition.x
			<< "\nY: " << characterPosition.y << std::endl;
	}
	//if right key is pressed, we move our circle to the right
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		character.move(speed, 0.f);

	// Moving Up
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		character.move(0.f, -speed);
	}
	//moving down
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		character.move(0.f, speed);
	}
}

void GettingStarted::mouseInput(sf::CircleShape& character) {
	//get & store character position
	sf::Vector2f characterPosition(character.getPosition());
	float characterX(characterPosition.x);
	float characterY(characterPosition.y);

	//if left mouse button is clicked, we move our character
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		character.move(-30.f, 0.f);
		//debug
		std::cout << "[Mouse clicked! ] character moved left, new position:\nX: " << characterX
			<< "\nY: " << characterY << std::endl;
	}
}

/*void GettingStarted::textureFunction(const sf::CircleShape& circle) {
	sf::RenderTexture renderTexture;

	if (!renderTexture.create(500, 500)) {
		//error
	}

	// drawing uses the same functions
	renderTexture.clear();
	renderTexture.draw(circle);//on sprite or any other drawable
	renderTexture.display();

	//get target texture (where the stuff has been drawn)
	//we get our texture
	const sf::Texture& texture(renderTexture.getTexture());

	//draw it to the window
	//our sprite has this texture on it
	sf::Sprite sprite(texture);
	//we draw this sprite in our window
	window.draw(sprite);
}*/

void GettingStarted::renderingThread(sf::RenderWindow* window) {
	// activate the window's context
	window->setActive(true);

	while (window->isOpen()) {
		// draw 

		// end current frame
		window->display();
	}

}

sf::Texture GettingStarted::loadStoneWallTexture() {
	sf::Texture texture;

	if (!texture.loadFromFile("resources/stonewall_grayscale.png")) {
		std::cerr << "404: Texture not found!" << std::endl;
	}
	texture.setSmooth(true);

	return texture;
}

sf::Texture GettingStarted::loadCharacter() {
	sf::Texture character;

	if (!character.loadFromFile("resources/OIF.jpg")) std::cerr << "404: Texture not found!";

	return character;
}

sf::Sprite GettingStarted::mySprite(const sf::Texture& texture) {
	// instantiate and initialize to have texture
	sf::Sprite sprite(texture);
	// green & half transparent
	sprite.setColor(sf::Color(0, 255, 0, 128));

	//set origin
	sprite.setOrigin(sf::Vector2f(51.f, 51.f));



	// set position
	sprite.setPosition(sf::Vector2f(50.f, 50.f));// absolute position
	sprite.move(sf::Vector2f(2.f, 5.f));// offset relative to the current angle


	// rotation
	sprite.setRotation(0.f); // absolute angle
	sprite.rotate(0.f);// offset relative to the current angle


	// scale
	sprite.setScale(sf::Vector2f(1.f, 1.f));
	sprite.scale(sf::Vector2f(1.f, 1.f)); // factor relative to the current scale


	return sprite;

}

sf::CircleShape GettingStarted::myCircle(const sf::Texture& texture, bool hasTexture, bool hasOutline) {
	//creates a circle with a radius of 100
	sf::CircleShape shape(10.f);

	(!hasTexture == 0) ? shape.setTexture(&texture, false) : shape.setFillColor(sf::Color::Green);
	if (!hasOutline == 0) {
		shape.setOutlineColor(sf::Color::Red);
		shape.setOutlineThickness(5.f);
	}

	return shape;
}

sf::Font GettingStarted::loadFont() {
	sf::Font font;

	if (!font.loadFromFile("resources/Inter-Regular.ttf")) {
		std::cerr << "404: Font not found!";
	}

	return font;
}

sf::Text GettingStarted::myText(std::string displayText, const sf::Font& font) {
	sf::Text text;

	// set font
	text.setFont(font);

	// the text you wanna display
	text.setString(displayText);

	// set the character size (font size)
	text.setCharacterSize(34);

	// set color of the text
	text.setFillColor(sf::Color(255, 0, 0)); // red

	// set the text style
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);

	return text;
}

bool GettingStarted::operator==(const GettingStarted& other) const
{
	return false;
}
