#pragma once
#include "Enemy.h"
#include "smart_ptr.h"

PTR( Image );

class EnemyTorkan : public Enemy {
public:
	EnemyTorkan( const Vector& pos, ImagePtr small_2 );
	virtual ~EnemyTorkan( );
private:
	void act( );
	void draw( int camera_x ) const;
private:
	ImagePtr _image;
	Vector _pos;
	bool _remove;
};

