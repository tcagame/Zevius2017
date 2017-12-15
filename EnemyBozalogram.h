#pragma once
#include "Enemy.h"
#include "smart_ptr.h"

PTR( Image );

class EnemyBozalogram : public Enemy {
public:
	EnemyBozalogram( const Vector& pos );
	virtual ~EnemyBozalogram( );
private:
	void act( );
	void draw( );
private:
	ImagePtr _image;
	bool _flag;
};

