#include "Map.h"
#include "../Render/RenderWindow.h"

Map::Map() :
    m_width(32), m_height(16)
{
    m_level = 
    "################################"
    "#..............................#"
    "#..............................#"
    "#..............................#"
    "#..............................#"
    "#..............................#"
    "#..............................#"
    "#..............................#"
    "#..............................#"
    "#..............................#"
    "#..............................#"
    "#..............................#"
    "#..............................#"
    "#..............................#"
    "#..............................#"
    "################################";

    RenderWindow::Get().LoadTexture("atlas", "assets/reactor.png");
}

Map::~Map()
{
    RenderWindow::Get().DropTexture("atlas");
}

char Map::GetTile(int x, int y)
{
    if (x >= 0 && x <= m_width && y >= 0 && y <= m_height)
        return m_level[y * m_width + x];
    else
        return ' ';
}

void Map::SetTile(int x, int y, char c)
{
    if (x >= 0 && x <= m_width && y >= 0 && y <= m_height)
        m_level[y * m_width + x] = c;
}

void Map::DrawMap()
{
    for (int i = 0; i < m_height; i++)
    {
        for (int j = 0; j < m_width; j++)
        {
            char tileId = GetTile(j, i);

            switch (tileId)
            {
                case '.':
                    RenderWindow::Get().DrawRect(j * 32, i * 32, 32, 32, 0x242A3BFF);
                    break;

                case '#':
                    RenderWindow::Get().DrawFrame("atlas", j * 32, i * 32, 16, 16, 14, 2);
                    break;                 
            }
        }
    }
}

