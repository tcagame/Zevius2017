#include "Game.h"
#include "Application.h"
#include "Scene.h"
#include "SceneTitle.h"
#include "ScenePlay.h"
#include "SceneResult.h"
#include "Drawer.h"


GamePtr Game::getTask( ) {
	return std::dynamic_pointer_cast<Game>( Application::getInstance( )->getTask( getTag( ) ) );
}

Game::Game( ) :
_next( Scene::NEXT_TITLE ),
_count( 0 ) {
}


Game::~Game( ) {
}

void Game::initialize( ) {
	changeScene( );
}

void Game::update( ) {
	_count++;

	Drawer::getTask( )->flip( );
	_scene->draw( );
	_next = _scene->update( );
	changeScene( );
}

void Game::changeScene( ) {
	if ( _next == Scene::NEXT_CONTINUE ) {
		return;
	}
	switch( _next ) {
	case Scene::NEXT_TITLE:
		_scene = ScenePtr( new SceneTitle( ) );
		break;
	case Scene::NEXT_PLAY:
		_scene = ScenePtr( new ScenePlay( ) );
		break;
	case Scene::NEXT_RESULT:
		_scene = ScenePtr( new SceneResult( ) );
		break;
	}
}

int Game::getGameCount( ) {
	return _count;
}
