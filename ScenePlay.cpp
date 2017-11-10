#include "ScenePlay.h"



ScenePlay::ScenePlay( ) {
}


ScenePlay::~ScenePlay( ) {
}

void ScenePlay::update( ) {
	_player->update( );
}

void ScenePlay::draw( ) {
	_player->draw( );
}