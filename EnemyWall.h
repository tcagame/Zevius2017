#pragma once
#include "Enemy.h"
#include "smart_ptr.h"

PTR( Image );

class EnemyWall : public Enemy {
public:
	EnemyWall( const Vector& pos );
	virtual ~EnemyWall( );
private:
	void act( );
	void draw( );
private:
	ImagePtr _image;
	double _count;
};

