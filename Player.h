#pragma once

#include "Character.h"
#include "smart_ptr.h"
#include "mathmatics.h"

PTR( Image );

class Player : public Character {
public:
	Player( );
	virtual ~Player( );
public:
	void draw( );
private:
	void act( );
private:
	ImagePtr _image;
	Vector _pos;
};

