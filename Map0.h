#pragma once
#include "Map.h"
#include <array>
class Map0 : public Map {
public:
	Map0( );
	virtual ~Map0( );
public:
	std::array< char, MAP_WIDTH * MAP_HEIGHT + 1 > getMap( int pattern );
private:
	std::array< std::array< char, MAP_WIDTH * MAP_HEIGHT + 1 >, MAX_PATTERN > _map;
};

