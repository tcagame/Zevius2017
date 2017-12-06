#include "ScenePlay.h"
#include "Player.h"
#include "Drawer.h"
#include "Image.h"
#include "Game.h"
#include "smart_ptr.h"

const int MAP_SIZE = 3000;

ScenePlay::ScenePlay( ) {
	_player = PlayerPtr( new Player );
	DrawerPtr drawer = Drawer::getTask( );
	_image = drawer->createImage( "background/background.png" );
}


ScenePlay::~ScenePlay( ) {
}

Scene::NEXT_SCENE ScenePlay::update( ) {
	_player->update( );
	return Scene::NEXT_CONTINUE;
}

void ScenePlay::draw( ) {
	GamePtr game = Game::getTask( );
	int width = 0;
	int height = 0;
	_image->getImageSize( width, height );
	_image->setRect( 0, 0, width, height );
	int x1 = -game->getGameCount( ) % MAP_SIZE;
	int x2 = x1 + MAP_SIZE;
	int x3 = x2 + MAP_SIZE;
	_image->setPos( x1, 0, x2, 810 );
	//_image->draw( );//”wŒi
	_image->setPos( x2, 0, x3, 810 );
	//_image->draw( );//”wŒi
	_player->draw( );
}

void ScenePlay::addShot( PlayerShotPtr shot ) {
	_shots.push_back( shot );
}