#pragma once

#include "Character.h"
#include "smart_ptr.h"
#include "mathmatics.h"

PTR( Image );
PTR( Armoury );
PTR( Camera );

class Player : public Character {
public:
	Player( ArmouryPtr armoury, CameraPtr camera );
	virtual ~Player( );
public:
	void draw( int camera_x ) const;
	void setFinished( bool finish );
	bool isFinished( );
private:
	void act( );
	void actOnMove( );
	void actOnAttack( );
	void actOnDead( );
private:
	CameraPtr _camera;
	ImagePtr _image;
	ArmouryPtr _armoury;
	Vector _pos;
	bool _game_over;
	int _count;
};

