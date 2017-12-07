#pragma once

#include "Character.h"
#include "smart_ptr.h"
#include "mathmatics.h"

PTR( Image );
PTR( ScenePlay )

class Player : public Character {
public:
	Player( );
	virtual ~Player( );
public:
	void init( ScenePlayPtr play );
	void draw( );
private:
	void act( );
private:
	ImagePtr _image;
	ScenePlayPtr _play;
	Vector _pos;
};

