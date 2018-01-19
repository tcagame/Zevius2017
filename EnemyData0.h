#pragma once
#include "EnemyData.h"
#include <array>
class EnemyData0 : public EnemyData {
public:
	EnemyData0( );
	virtual ~EnemyData0( );
public:
	std::array< char, MAP_WIDTH_NUM * MAP_HEIGHT_NUM + 1 > getEnemyData( );
private:
	std::array< char, MAP_WIDTH_NUM * MAP_HEIGHT_NUM + 1 > _data;
};

