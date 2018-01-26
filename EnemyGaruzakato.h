#pragma once
#include "Enemy.h"
#include "smart_ptr.h"

PTR( Image );
PTR( Player );
PTR( Military );
PTR( EnemyGaruzakatoAttack );

class EnemyGaruzakato : public Enemy {
public:
	EnemyGaruzakato( const Vector& pos, PlayerPtr player, ImagePtr small_1, MilitaryPtr military );
	virtual ~EnemyGaruzakato( );
private:
	void act( );
	void draw( int camera_x ) const;
private:
	ImagePtr _image;
	PlayerPtr _player;
	MilitaryPtr _military;
	int _time;
};

