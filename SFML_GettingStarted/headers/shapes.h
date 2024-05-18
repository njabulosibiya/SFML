#ifndef SHAPES_H
#define SHAPES_H

#include <SFML/Graphics.hpp>

class Shapes {
public:
	//constructor
	Shapes();

	static sf::RectangleShape myRectangle();
	// create a polgon
	static sf::CircleShape myPolygon(unsigned short sides);
	//create convex shape
	static sf::ConvexShape convexShape();

};
#endif // SHAPES_H