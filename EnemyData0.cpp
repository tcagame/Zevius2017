#include "EnemyData0.h"



EnemyData0::EnemyData0( ) {
	_data[ 0 ] = {
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


EnemyData0::~EnemyData0( ) {

}

std::array< char, MAP_WIDTH_NUM * MAP_HEIGHT_NUM + 1 > EnemyData0::getEnemyData( int pattern ) {
	if ( pattern < 0 ) {
		pattern = 0;
	}
	if ( pattern >= MAX_PATTERN ) {
		pattern = MAX_PATTERN - 1;
	}
	return _data[ pattern ];
}
