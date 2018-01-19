#pragma once
#include <array>
#include "define.h"

static const int MAP_WIDTH_NUM  = 400;
static const int MAP_HEIGHT_NUM = 15;
static const int MAX_PATTERN = 3;
const int MAP_SIZE = 1280 / MAP_HEIGHT_NUM;

class EnemyData {
public:
	EnemyData( );
	virtual ~EnemyData( );

public:
	virtual std::array< char, MAP_WIDTH_NUM * MAP_HEIGHT_NUM + 1 > getEnemyData( int pattern ) = 0;
};

