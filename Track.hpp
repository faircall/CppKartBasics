#pragma once
#include <SFML/Graphics.hpp>

class Track
{
    int m_across;
    int m_down;
    int *m_pTiles;
    int m_tileWidth;
    int m_tileHeight;
    
public:
    Track(int _across, int _down, int _tileWidth, int _tileHeight)
    {
	m_across = _across;
	m_down = _down;
	m_pTiles = new int[m_down*m_across];
	m_tileWidth = _tileWidth;
	m_tileHeight = _tileHeight;
	PopulateTiles();	
    }

    ~Track()
    {
	delete [] m_pTiles;
    }

    int GetTileAt(int i, int j)
    {
	return m_pTiles[i*m_across + j];
    }

    void PopulateTiles()
    {
	int totalTiles = m_across * m_down;
	for (int tile = 0; tile < totalTiles; tile++) {
	    m_pTiles[tile] = rand() % numColors;
	}
    }

    void Render(sf::RenderWindow& window)
    {
	
	for (int x = 0; x < m_across; x++) {
	    for (int y = 0; y < m_down; y++) {
		// forced to use sfml vector class here
		sf::Vector2f tileSize((float)m_tileWidth, (float)m_tileHeight);
		sf::RectangleShape tile(tileSize);
		tile.setPosition(x * m_tileWidth, y * m_tileHeight);
		switch (GetTileAt(x, y)) {
		case red:
		    tile.setFillColor(sf::Color(220, 10, 0, 255));
		    break;
		case green:
		    tile.setFillColor(sf::Color(0, 100, 0, 255));
		    break;
		case blue:
		    tile.setFillColor(sf::Color(0, 5, 150, 255));
		    break;
		    
		}
		window.draw(tile);
	    }
	}
    }

private:
    enum TrackColor {red, green, blue, numColors};    
        
};
