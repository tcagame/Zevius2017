#pragma once
#include "Enemy.h"
class EnemyGaruzakato : public Enemy {
public:
	EnemyGaruzakato( );
	virtual ~EnemyGaruzakato( );
private:
	void act( );
	void draw( );
};

