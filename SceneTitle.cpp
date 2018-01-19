#include "SceneTitle.h"
#include "Keyboard.h"
#include "Drawer.h"
#include "Image.h"
#include "define.h"


SceneTitle::SceneTitle( ) {
	DrawerPtr drawer = Drawer::getTask( );
	_image = drawer->createImage( "title/title.png" );
}


SceneTitle::~SceneTitle( ) {
}

SceneTitle::NEXT_SCENE SceneTitle::update( ) {
	KeyboardPtr keyboard = Keyboard::getTask( );
	if ( keyboard->isPushKey( "ENTER" ) ) {
		return Scene::NEXT_PLAY;
	}

	return Scene::NEXT_CONTINUE;
}

void SceneTitle::draw( ) {
	int width = 0;
	int height = 0;
	_image->getImageSize( width, height );
	_image->setRect( 0, 0, width, height );
	_image->setPos( 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT );
	_image->draw( );
}