#ifndef MAPFIRSTTRY_TILEMAP_H
#define MAPFIRSTTRY_TILEMAP_H

#include "SFML/Graphics.hpp"
#include <string>

class TileMap : public sf::Drawable, public sf::Transformable {
public:
    bool load(std::string tilename, sf::Vector2u tileSize, const int *tiles, unsigned int width, unsigned int height);

private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
};

#endif //MAPFIRSTTRY_TILEMAP_H
