#pragma once
#include <array>
#include "define.h"

static const int MAP_WIDTH_NUM  = 150;
static const int MAP_HEIGHT_NUM = 15;
const int MAP_SIZE = 960 / MAP_HEIGHT_NUM;

class EnemyData {
public:
	EnemyData( );
	virtual ~EnemyData( );

public:
	virtual std::array< char, MAP_WIDTH_NUM * MAP_HEIGHT_NUM + 1 > getEnemyData( ) = 0;
};

