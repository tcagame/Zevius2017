#pragma once
#include <array>
#include "define.h"

static const int MAP_WIDTH_NUM  = 150;
static const int MAP_HEIGHT_NUM = 23;
const int MAP_SIZE = ( NORMAL_GRAPH_SIZE * MAP_HEIGHT_NUM ) / MAP_HEIGHT_NUM;

class EnemyData {
public:
	EnemyData( );
	virtual ~EnemyData( );

public:
	virtual std::array< char, MAP_WIDTH_NUM * MAP_HEIGHT_NUM + 1 > getEnemyData( ) = 0;
};

