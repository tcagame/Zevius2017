#pragma once
#include "smart_ptr.h"

PTR( Image );

class Player {
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
};

