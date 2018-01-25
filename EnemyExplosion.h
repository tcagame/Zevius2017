#pragma once
#include "mathmatics.h"
#include "smart_ptr.h"

PTR( Image );

class EnemyExplosion {
public:
	EnemyExplosion( Vector& pos );
	virtual ~EnemyExplosion( );
private:
	void drawExplosion( Vector& pos );
private:
	ImagePtr _image;
};

