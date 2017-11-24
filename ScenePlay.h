#pragma once
#include "smart_ptr.h"
#include "Scene.h"
#include "Player.h"
#include <list>

PTR( Player );
PTR( PlayerShot );
PTR( Image );

class ScenePlay : public Scene {
public:
	ScenePlay( );
	virtual ~ScenePlay( );
public:
	void addShot( PlayerShotPtr shot );
private:
	NEXT_SCENE update( );
	void draw( );
private:
	PlayerPtr _player;
	ImagePtr _image;
	std::list< PlayerShotPtr > _shots;
};

