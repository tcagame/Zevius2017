#pragma once
#include "smart_ptr.h"
#include "mathmatics.h"
#include "Character.h"

PTR( Image );

class Player : public Character {
public:
	Player( );
	virtual ~Player( );
public:
	void update( );
	void draw( );
private:
	void act( );
private:
	ImagePtr _image;
	Vector _pos;
};

