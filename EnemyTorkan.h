#pragma once
#include "Enemy.h"
class EnemyTorkan : public Enemy {
public:
	EnemyTorkan( const Vector& pos );
	virtual ~EnemyTorkan( );
private:
	void act( );
};

