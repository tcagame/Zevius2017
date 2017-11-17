#pragma once
#include "smart_ptr.h"
#include "Scene.h"
#include "Player.h"

PTR( Player );

class ScenePlay : public Scene {
public:
	ScenePlay( );
	virtual ~ScenePlay( );
private:
	NEXT_SCENE update( );
	void draw( );
private:
	PlayerPtr _player;
};

