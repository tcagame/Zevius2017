#pragma once
#include "Enemy.h"
#include "smart_ptr.h"

PTR( Image );

class EnemyBozalogram : public Enemy {
public:
	EnemyBozalogram( const Vector& pos, ImagePtr medium );
	virtual ~EnemyBozalogram( );
private:
	void act( );
	void draw( int camera_x ) const;
private:
	ImagePtr _image;
	bool _flag;
};

