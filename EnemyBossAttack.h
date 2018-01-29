#pragma once
#include "Enemy.h"
#include "smart_ptr.h"

PTR( Image );

class EnemyBossAttack : public Enemy {
public:
	EnemyBossAttack( const Vector& pos, const Vector& dir, ImagePtr image );
	virtual ~EnemyBossAttack( );
private:
	void act( );
	void draw( int camera_x ) const;
private:
	Vector _pos;
	Vector _dir;
	ImagePtr _image;
	int _count;
};

