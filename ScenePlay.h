#pragma once
#include "smart_ptr.h"
#include "Player.h"

PTR( Player );

class ScenePlay {
public:
	ScenePlay( );
	virtual ~ScenePlay( );
public:
	void update( );
	void draw( );
private:
	PlayerPtr _player;
};

