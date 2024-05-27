#ifndef TILEMAP_H
#define TILEMAP_H

#include <SFML/Graphics.hpp>

class TileMap : public sf::Drawable, public sf::Transformable {
public:
	/* returns true if map is loaded false if there was an issue loading map.
	* tileSet - path and file name of texture
	* The Texture we passed is 256 x 32, with each texture in it being 32 x 32. Therefore there are 8 textures.
	* each texture being 32 x 32. 
	* So tileSize is the dimensions of each texture in the file passed (32 x 32)
	* tiles - is the the level map/array/matrix
	* we then pass in the width and the hight - these are the dimensions of the map. it's 8 textures high
	* and 16 textures wide. The map is 16 x 8*/
	bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::VertexArray m_vertices;
	sf::Texture m_tileset;

};


#endif // !TILEMAP_H
