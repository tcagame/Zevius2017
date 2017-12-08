#pragma once
#include "Enemy.h"
#include "smart_ptr.h"

PTR( Image );

class EnemyTorkan : public Enemy {
public:
	EnemyTorkan( const Vector& pos );
	virtual ~EnemyTorkan( );
private:
	void act( );
	void draw( );
private:
	ImagePtr _image;
};

