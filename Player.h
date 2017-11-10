#pragma once
#include "smart_ptr.h"

PTR( Image );

class Player {
public:
	Player( );
	virtual ~Player( );
public:
	void update( );
private:
	void act( );
	void draw( );
private:
	ImagePtr _image;
};

