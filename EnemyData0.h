#pragma once
#include "EnemyData.h"
#include <array>
class EnemyData0 : public EnemyData {
public:
	EnemyData0( );
	virtual ~EnemyData0( );
public:
	std::array< char, MAP_WIDTH_NUM * MAP_HEIGHT_NUM + 1 > getEnemyData( int pattern );
private:
	std::array< std::array< char, MAP_WIDTH_NUM * MAP_HEIGHT_NUM + 1 >, MAX_PATTERN > _data;
};

