#pragma once
#include "smart_ptr.h"
#include "mathmatics.h"

PTR( Image );
PTR( PlayerShot );

class PlayerShot {
public:
	PlayerShot( Vector pos );
	virtual ~PlayerShot( );
public:
	void update( );
	void draw( );
private:
	ImagePtr _image;
	Vector _pos;
};

