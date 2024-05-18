#include "../headers/myentity.h"

void MyEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	// add functions to play with the entity's geometry / colors / texturing...
	states.transform *= getTransform(); // getTransform() is defined by sf::Transformable

    // apply the texture
    states.texture = &m_texture;

    // you may also override states.shader or states.blendMode if you want

    // draw the vertex array
    target.draw(m_vertices, states);
}