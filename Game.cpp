#include "Game.h"
#include "Application.h"
#include "Scene.h"
#include "ScenePlay.h"
#include "Drawer.h"


GamePtr Game::getTask( ) {
	return std::dynamic_pointer_cast<Game>( Application::getInstance( )->getTask( getTag( ) ) );
}

Game::Game( ) :
_next( Scene::NEXT_PLAY ){
}


Game::~Game( ) {
}

void Game::initialize( ) {
	changeScene( );
}

void Game::update( ) {
	Drawer::getTask( )->flip( );
	_scene->update( );
	_scene->draw( );
	changeScene( );
}

void Game::changeScene( ) {
	if ( _next == Scene::NEXT_CONTINUE ) {
		return;
	}
	switch( _next ) {
	case Scene::NEXT_PLAY:
		_scene = ScenePtr( new ScenePlay( ) );
	}
}
