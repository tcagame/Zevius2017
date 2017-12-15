#pragma once
#include "Enemy.h"
class EnemyBragzakato : public Enemy {
public:
	EnemyBragzakato( );
	virtual ~EnemyBragzakato( );
private:
	void act( );
	void draw( );
};

