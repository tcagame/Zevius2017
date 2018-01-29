#include "SceneTitle.h"
#include "Keyboard.h"
#include "Drawer.h"
#include "Image.h"
#include "define.h"


const int DRAW_BG_WIDTH  = 640;
const int DRAW_BG_HEIGHT = 380;
const int ADJUST_Y       = 110;

SceneTitle::SceneTitle( ) {
	DrawerPtr drawer = Drawer::getTask( );
	_image = drawer->createImage( "title/Xevious_UI_title.png" );
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
	int x1 = SCREEN_WIDTH / 2 - DRAW_BG_WIDTH / 2;
	int x2 = x1 + DRAW_BG_WIDTH;
	int y1 = SCREEN_HEIGHT / 2 - DRAW_BG_HEIGHT / 2 - ADJUST_Y;
	int y2 = y1 + DRAW_BG_HEIGHT;
	_image->setPos( x1, y1, x2, y2 );
	_image->draw( );
}