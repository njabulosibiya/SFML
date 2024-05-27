#ifndef VERTEXARRAYBASICS_H
#define VERTEXARRAYBASICS_H

#include <SFML/Graphics.hpp>

class VertexBasics {
public:
	// constructor
	VertexBasics();

	//simple vertex
	static sf::Vertex simpleVertex();
	// primitive
	static sf::VertexArray vertexArray();
	//textured vertex array
	static sf::VertexArray texturedVertex();
};

#endif // VERTEXARRAYBASICS_H