#include "../headers/vertexArrayBasics.h"

VertexBasics::VertexBasics() {

}

sf::Vertex VertexBasics::simpleVertex() {
	//create vertex
	sf::Vertex* vertex = new sf::Vertex;

	//set its position
	vertex->position = sf::Vector2f(10.f, 50.f);

	// set its color
	vertex->color = sf::Color::Red;

	// set its texture coord
	vertex->texCoords = sf::Vector2f(100.f, 100.f);

	//clears stored values
	delete vertex;

	// ... or, using the correct constructor:
	sf::Vertex vertex2(sf::Vector2f(10.f, 50.f), sf::Color::Red, sf::Vector2f(100.f, 100.f));

	return vertex2;
}

sf::VertexArray VertexBasics::vertexArray() {
	// create an array of 3 vertices that define a triangle primitive
	sf::VertexArray triangle(sf::Triangles, 3);

	// define the position of the triangle's points
	triangle[0].position = sf::Vector2f(10.f, 10.f);
	triangle[1].position = sf::Vector2f(100.f, 10.f);
	triangle[2].position = sf::Vector2f(100.f, 100.f);

	// define the color of the triangle's points
	triangle[0].color = sf::Color::Red;
	triangle[1].color = sf::Color::Blue;
	triangle[2].color = sf::Color::Green;

	// no texture coordinates here, we'll see that later

	return triangle;
}

sf::VertexArray VertexBasics::texturedVertex() {
	// ALWAYS, ALWAYS, ALWAYS include the the primitive type and point count else 
	// you'll get a breakpoint error
	sf::VertexArray triangleStrip(sf::TrianglesStrip, 4);

	// define it as a rectangle, located at (10, 10) and with size 100x100
	// These are 2 conjoined triangles making a rectangle
	triangleStrip[0].position = sf::Vector2f(10.f, 10.f);
	triangleStrip[1].position = sf::Vector2f(10.f, 110.f);
	triangleStrip[2].position = sf::Vector2f(110.f, 10.f);
	triangleStrip[3].position = sf::Vector2f(110.f, 110.f);

	// define its texture area to be a 25x50 rectangle starting at (0, 0)
	// this means that when you pass a texture, of the whole texture provided, only 
	// the part of the texture listed in these co-ordinates will be used, in a word
	// the texture will be cropped at these points
	triangleStrip[0].texCoords = sf::Vector2f(0.f, 0.f);
	triangleStrip[1].texCoords = sf::Vector2f(0.f, 100.f);
	triangleStrip[2].texCoords = sf::Vector2f(100.f, 0.f);
	triangleStrip[3].texCoords = sf::Vector2f(100.f, 100.f);

	return triangleStrip;
}









