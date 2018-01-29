#pragma once
#include "Enemy.h"
#include "smart_ptr.h"

PTR( Image );
PTR( Camera );
PTR( Military );
PTR( EnemyBossAttack );

class EnemyBoss3 : public Enemy {
public:
	EnemyBoss3( const Vector& pos, ImagePtr boss, CameraPtr camera, MilitaryPtr military, ImagePtr attack_img );
	virtual ~EnemyBoss3( );
public:
	void act( );
	void draw( int camera_x ) const;
private:
	void erase( );
	int getSize( ) const;
private:
	int _hp;
	int _count;
	Vector _pos;
	ImagePtr _image;
	ImagePtr _attack_img;
	CameraPtr _camera;
	MilitaryPtr _military;
};
