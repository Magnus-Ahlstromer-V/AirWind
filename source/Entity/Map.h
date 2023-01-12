#pragma once
#include <string>

class Map
{	
public:
    Map();
    ~Map();

    char GetTile(int x, int y);
    void SetTile(int x, int y, char c);

    void DrawMap();

private:
    int m_width;
    int m_height;
    std::string m_level;
};
