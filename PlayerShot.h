#pragma once
#include "smart_ptr.h"
#include "mathmatics.h"
#include "Character.h"

PTR( Image );
PTR( PlayerShot );

class PlayerShot : public Character {
public:
	PlayerShot( Vector pos );
	virtual ~PlayerShot( );
public:
	void draw( );
private:
	void act( );
private:
	ImagePtr _image;
	Vector _pos;
};

