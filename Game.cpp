#include "Game.h"
#include "Application.h"
#include "Scene.h"
#include "SceneTitle.h"
#include "ScenePlay.h"
#include "SceneResult.h"
#include "Drawer.h"
#include "Sound.h"

PTR( Sound );

GamePtr Game::getTask( ) {
	return std::dynamic_pointer_cast<Game>( Application::getInstance( )->getTask( getTag( ) ) );
}

Game::Game( ) :
_next( Scene::NEXT_TITLE ) {
}


Game::~Game( ) {
}

void Game::initialize( ) {
	changeScene( );
}

void Game::update( ) {
	Drawer::getTask( )->flip( );
	_scene->draw( );
	_next = _scene->update( );
	changeScene( );
}

void Game::changeScene( ) {
	SoundPtr sound = Sound::getTask( );
	if ( _next == Scene::NEXT_CONTINUE ) {
		return;
	}
	switch( _next ) {
	case Scene::NEXT_TITLE:
		_scene = ScenePtr( new SceneTitle( ) );
		sound->playBGM( "sound/xev_music_GameStart.wav" );
		break;
	case Scene::NEXT_PLAY:
		_scene = ScenePtr( new ScenePlay( ) );
		sound->playBGM( "sound/xev_music_BGM_loop.wav" );
		break;
	case Scene::NEXT_RESULT:
		_scene = ScenePtr( new SceneResult( ) );
		sound->playBGM( "sound/xev_music_NameEntry_01.wav" );
		break;
	}
}