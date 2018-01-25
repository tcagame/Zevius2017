#pragma once

#include "Character.h"
#include "smart_ptr.h"
#include "mathmatics.h"

PTR( Image );
PTR( Armoury );

class Player : public Character {
public:
	Player( ArmouryPtr armoury );
	virtual ~Player( );
public:
	void draw( int camera_x ) const;
	void setFinished( bool finish );
	bool isFinished( );
private:
	void act( );
	void actOnMove( );
	void actOnAttack( );
private:
	ImagePtr _image;
	ArmouryPtr _armoury;
	Vector _pos;
	bool _game_over;
};

