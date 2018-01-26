#pragma once
#include "Enemy.h"
#include "smart_ptr.h"

PTR( Image );

class EnemyToroid : public Enemy {
public:
	EnemyToroid( const Vector& pos, ImagePtr small_2 );
	virtual ~EnemyToroid( );
private:
	void act( );
	void draw( int camera_x ) const;
private:
	ImagePtr _image;
	int _count;
};

