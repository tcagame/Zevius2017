#pragma once
#include "Enemy.h"
#include "smart_ptr.h"

PTR( Image );

class EnemyBoss : public Enemy {
public:
	EnemyBoss( const Vector& pos );
	virtual ~EnemyBoss( );
public:
	void act( );
	void draw( );
private:
	int _count;
	ImagePtr _image;
};

