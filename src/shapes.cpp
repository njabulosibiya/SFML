#include "../headers/shapes.h"

Shapes::Shapes() {

}

sf::RectangleShape Shapes::myRectangle() {
	// define a 120x50 rectangle
	sf::RectangleShape rectangle(sf::Vector2f(150.f, 50.f));

	// change the size to 100x100
	rectangle.setSize(sf::Vector2f(50.f, 50.f));

	// add color
	rectangle.setFillColor(sf::Color::Black);

	return rectangle;
}


sf::CircleShape Shapes::myPolygon(unsigned short sides) {
	sf::CircleShape polymorph(10.f, sides);

	polymorph.setFillColor(sf::Color::Green);

	return polymorph;
}


sf::ConvexShape Shapes::convexShape() {
	sf::ConvexShape shape;

	// resize it to have 5 points
	shape.setPointCount(5);

	// define the points
	shape.setPoint(0, sf::Vector2f(0.f, 0.f));
	shape.setPoint(1, sf::Vector2f(150.f, 10.f));
	shape.setPoint(2, sf::Vector2f(120.f, 90.f));
	shape.setPoint(3, sf::Vector2f(30.f, 100.f));
	shape.setPoint(4, sf::Vector2f(0.f, 50.f));

	return shape;
}