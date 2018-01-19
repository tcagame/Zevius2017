#include "Map0.h"



Map0::Map0( ) {
	_map[ 0 ] = {
		"                                                                                                                                                      "
		"                                                                                                                                                      "
		"                                                                                                                                                      "
		"                                                                                                                                                      "
		"                                                                                                                                                      "
		"                                                                                                                                                      "
		"                                                                                                                                                      "
		"                                                                                                                                                      "
		"                                                                                                                                                      "
		"                                                                                                                                                      "
		"                                                                                                                                                      "
		"                                                                                                                                                      "
		"                                                                                                                                                      "
		"                                                                                                                                                      "
		"                                                                                                                                                      "
	};
}


Map0::~Map0( ) {

}

std::array< char, MAP_WIDTH * MAP_HEIGHT + 1 > Map0::getMap( int pattern ) {
	if ( pattern < 0 ) {
		pattern = 0;
	}
	if ( pattern >= MAX_PATTERN ) {
		pattern = MAX_PATTERN - 1;
	}
	return _map[ pattern ];
}
