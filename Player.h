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
	void draw( );
private:
	void act( );
	void actOnMove( );
	void actOnAttack( );
private:
	ImagePtr _image;
	ArmouryPtr _armoury;
	Vector _pos;
};

