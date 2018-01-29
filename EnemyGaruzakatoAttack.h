#pragma once
#include "Enemy.h"
#include "smart_ptr.h"

PTR( Image );

class EnemyGaruzakatoAttack : public Enemy {
public:
	EnemyGaruzakatoAttack( const Vector& pos, const Vector& dir, ImagePtr image );
	virtual ~EnemyGaruzakatoAttack( );
private:
	void act( );
	void draw( int camera_x ) const;
private:
	Vector _pos;
	Vector _dir;
	ImagePtr _image;
	int _count;
};

