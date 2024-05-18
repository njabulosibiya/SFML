#ifndef MYENTITY_H
#define MYENTITY_H

#include <SFML/Graphics.hpp>

class MyEntity : public sf::Drawable, public sf::Transformable {
public:

	// add functions to play with the entity's geometry / colors / texturing...

private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::Texture m_texture;
	sf::VertexArray m_vertices;
};

#endif // !MYENTITY_H
