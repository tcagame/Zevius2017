#include "ScenePlay.h"
#include "Player.h"


ScenePlay::ScenePlay( ) {
	_player = PlayerPtr( new Player( ) );
}


ScenePlay::~ScenePlay( ) {
}

Scene::NEXT_SCENE ScenePlay::update( ) {
	_player->update( );
	return Scene::NEXT_CONTINUE;
}

void ScenePlay::draw( ) {
	_player->draw( );
}