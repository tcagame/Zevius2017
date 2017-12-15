#pragma once
#include "Enemy.h"
class EnemyToroid : public Enemy {
public:
	EnemyToroid( );
	virtual ~EnemyToroid( );
private:
	void act( );
	void draw( );
};

