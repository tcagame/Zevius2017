#pragma once
#include "Enemy.h"
#include "smart_ptr.h"

PTR( Image );
PTR( Player );

class EnemyBragzakato : public Enemy {
public:
	EnemyBragzakato( const Vector& pos, PlayerPtr player );
	virtual ~EnemyBragzakato( );
private:
	void act( );
	void draw( int camera_x ) const;
private:
	ImagePtr _image;
	Vector _pos;
	PlayerPtr _player;
	bool _attack;
	int _count;
};

