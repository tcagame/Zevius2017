#pragma once
#include "Enemy.h"
#include "smart_ptr.h"

PTR( Image );
PTR( Player );

class EnemyGaruzakato : public Enemy {
public:
	EnemyGaruzakato( const Vector& pos, PlayerPtr player );
	virtual ~EnemyGaruzakato( );
private:
	void act( );
	void draw( );
private:
	ImagePtr _image;
	PlayerPtr _player;
	int _time;
};

