#pragma once
#include <array>

const int MAP_WIDTH = 150;
static const int MAP_HEIGHT = 15;
static const int MAX_PATTERN = 3;

class Map {
public:
	Map( );
	virtual ~Map( );

public:
	virtual std::array< char, MAP_WIDTH * MAP_HEIGHT + 1 > getMap( int pattern ) = 0;
};

