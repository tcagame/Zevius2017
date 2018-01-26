#include "ScenePlay.h"
#include "Player.h"
#include "Military.h"
#include "Armoury.h"
#include "Drawer.h"
#include "Image.h"
#include "Game.h"
#include "smart_ptr.h"
#include "PlayerShot.h"
#include "Camera.h"
#include "define.h"

const int MAP_GRAPH_SIZE = 3000;

ScenePlay::ScenePlay( ) {
	_init = false;
	_camera = CameraPtr( new Camera( ) );
	_armoury = ArmouryPtr( new Armoury( ) );
	_player = PlayerPtr( new Player( _armoury, _camera ) );
	_military = MilitaryPtr( new Military( _player, _camera ) );
	DrawerPtr drawer = Drawer::getTask( );
	_image = drawer->createImage( "background/background.png" );
}


ScenePlay::~ScenePlay( ) {
}

Scene::NEXT_SCENE ScenePlay::update( ) {
	_camera->update( );
	_player->update( );
	_military->update( );
	_armoury->update( _military );
	if ( _player->isFinished( ) ) {
		_camera->initCamera( );
		return Scene::NEXT_RESULT;
	}
	return Scene::NEXT_CONTINUE;
}

void ScenePlay::draw( ) {
	int width = 0;
	int height = 0;
	_image->getImageSize( width, height );
	_image->setRect( 0, 0, width, height );
	int x1 = -( ( int )_camera->getCameraPos( ) ) % MAP_GRAPH_SIZE;
	int x2 = x1 + MAP_GRAPH_SIZE;
	int x3 = x2 + MAP_GRAPH_SIZE;
	_image->setPos( x1, 0, x2, SCREEN_HEIGHT );
	_image->draw( );//”wŒi
	_image->setPos( x2, 0, x3, SCREEN_HEIGHT );
	_image->draw( );//”wŒi
	_player->draw( _camera->getCameraPos( ) );
	_armoury->draw( _camera->getCameraPos( ) );
	_military->draw( );
}