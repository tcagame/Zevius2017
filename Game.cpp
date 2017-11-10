#include "Game.h"
#include "Application.h"


GamePtr Game::getTask( ) {
	return std::dynamic_pointer_cast<Game>( Application::getInstance( )->getTask( getTag( ) ) );
}

Game::Game( ) {
}


Game::~Game( ) {
}

void Game::update( ) {
	_scene_play->update( );
	_scene_play->draw( );
}

//void Game::run( ) {
//	_scene_play->update( );
//	_scene_play->draw( );
//}
