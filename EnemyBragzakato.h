#pragma once
#include "Enemy.h"
#include "smart_ptr.h"

PTR( Image );
PTR( Player );
PTR( Military );

class EnemyBragzakato : public Enemy {
public:
	EnemyBragzakato( const Vector& pos, PlayerPtr player, ImagePtr small_1, MilitaryPtr military, ImagePtr attack_img );
	virtual ~EnemyBragzakato( );
private:
	void act( );
	void draw( int camera_x ) const;
private:
	ImagePtr _image;
	ImagePtr _attack_img;
	Vector _pos;
	PlayerPtr _player;
	MilitaryPtr _military;
	bool _attack;
	int _count;
};

