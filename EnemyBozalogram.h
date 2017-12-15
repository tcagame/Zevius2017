#pragma once
#include "Enemy.h"
class EnemyBozalogram : public Enemy {
public:
	EnemyBozalogram( );
	virtual ~EnemyBozalogram( );
private:
	void act( );
	void draw( );
};

