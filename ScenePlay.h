#pragma once
#include "smart_ptr.h"
#include "Scene.h"
#include "Player.h"
#include <list>

PTR( Player );
PTR( Military );
PTR( Image );
PTR( Enemy );
PTR( Armoury );

class ScenePlay : public Scene {
public:
	ScenePlay( );
	virtual ~ScenePlay( );
private:
	NEXT_SCENE update( );
	void draw( );
private:
	bool _init;
	PlayerPtr _player;
	MilitaryPtr _military;
	ArmouryPtr _armoury;
	ImagePtr _image;
	std::list< EnemyPtr > _enemies;
};

