#pragma once
#include "Enemy.h"
#include "smart_ptr.h"

PTR( Image );
PTR( Camera );

class EnemyTorkan : public Enemy {
public:
	EnemyTorkan( const Vector& pos, ImagePtr small_2, CameraPtr camera );
	virtual ~EnemyTorkan( );
private:
	void act( );
	void draw( int camera_x ) const;
private:
	ImagePtr _image;
	CameraPtr _camera;
	Vector _pos;
	bool _remove;
};

