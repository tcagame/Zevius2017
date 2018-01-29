#pragma once
#include "mathmatics.h"
#include "smart_ptr.h"

PTR( Image );

class EnemyExplosion {
public:
	EnemyExplosion( Vector& pos, int size );
	virtual ~EnemyExplosion( );
public:
	bool isFinished( );
	void draw( int camera_x );
private:
	int _size;
	Vector _pos;
	int _count;
	ImagePtr _image;
};

