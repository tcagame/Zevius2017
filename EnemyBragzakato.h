#pragma once
#include "Enemy.h"
#include "smart_ptr.h"

PTR( Image );

class EnemyBragzakato : public Enemy {
public:
	EnemyBragzakato( const Vector& pos );
	virtual ~EnemyBragzakato( );
private:
	void act( );
	void draw( );
private:
	ImagePtr _image;
	Vector _pos;
};

