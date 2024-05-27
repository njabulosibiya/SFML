#include "../headers/tilemap.h"

bool TileMap::load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height) {
	// load the tileset texture
    // returns false if texture is not found, map doesn't load
	if(!m_tileset.loadFromFile(tileset)) return false;

    // resize the vertex array to fit the level size
    m_vertices.setPrimitiveType(sf::Triangles);

    /* there are 16 * 8 total textures to be used (128).
     * Each texture uses 2 triangles (2 * 3 sides = 6), therefore there are a 
     * total of 6 vertices for each texture. The total number of vertices we need
     * is (16 * 8) * (2 *3) ~ 128 * 6 = 768.
     *
     * Therefore we resize the array of vertices(number of vertices/resizing array)
     * Currently only the number of vertices is known and neither position nor color/texture s
     */
    m_vertices.resize(width * height * 6);

    // populate the vertex array, with two triangles per tile
    // 2 equal triangles make 1 square
    /* How will we populate our tiles ? left to right ? top to bottom ?
    * In this case we populate our tiles top-to-bottom dtarting from the left.
    * for each value of the width, we populate the entire height.
    * */    
    for (unsigned int i(0); i < width; ++i) {
        for (unsigned int j(0); j < height; ++j) {
            // get the current tile number
            /* Since we are populating from top to bottom in a left-to-right form
            * we need to know which tile we are on. Which number? the 10th tile? the 12?
            * for instance, if we wanna know what number the bottom-left tile is we use 
            * the following equation. Since everything is indexed, the first column would be
            * 0th column and the 1st row be the oth row. so the bottom left would be 
            * (0 + 7) * 16 ~ 7 * 16 = 112th tile
            */
            int tileNumber = tiles[i + j * width];

            // find its position in the tileset texture
            // stores the remainder for division of odd numbers
            int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
            /* The tile number divided by the width of the tileset image which is divided by
            * tile size example the 16th tile: 16 /(256/32) ~ 16/8 = 2; the 32nd tile
            * 32/(256/32) ~ 32/8 = 4.
            */
            int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

            // get a pointer to the triangles' vertices of the current tile
            sf::Vertex* triangles = &m_vertices[(i + j * width) * 6];

            // define the 6 corners of the two triangles
            triangles[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
            triangles[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            triangles[2].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);
            triangles[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);
            triangles[4].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            triangles[5].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);

            // define the 6 matching texture coordinates
            triangles[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            triangles[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            triangles[2].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
            triangles[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
            triangles[4].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            triangles[5].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
        }
    }
    
    return true;
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // apply the transform
    states.transform *= getTransform();

    // apply the tileset texture
    states.texture = &m_tileset;

    // draw the vertex array
    target.draw(m_vertices, states);
}