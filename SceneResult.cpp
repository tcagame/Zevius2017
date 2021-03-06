#include "SceneResult.h"
#include "Keyboard.h"
#include "Drawer.h"
#include "Image.h"
#include "define.h"

const int DRAW_BG_WIDTH  = 640;
const int DRAW_BG_HEIGHT = 300;
const int ADJUST_Y       = 110;

SceneResult::SceneResult( ) {
	DrawerPtr drawer = Drawer::getTask( );
	_image = drawer->createImage( "title/result.png" );
	_push = drawer->createImage( "title/push.png" );
}


SceneResult::~SceneResult( ) {

}

Scene::NEXT_SCENE SceneResult::update( ) {
	KeyboardPtr keyboard = Keyboard::getTask( );
	if ( keyboard->isPushKey( "ENTER" ) ) {
		return Scene::NEXT_TITLE;
	}

	return Scene::NEXT_CONTINUE;
}

void SceneResult::draw( ) {
	int width = 0;
	int height = 0;
	int wide = 0;
	int heigh = 0;
	_image->getImageSize( width, height );
	_image->setRect( 0, 0, width, height );
	_push->getImageSize( wide, heigh );
	_push->setRect( 0, 0, wide, heigh );
	int x1 = SCREEN_WIDTH / 2 - DRAW_BG_WIDTH / 2;
	int x2 = x1 + DRAW_BG_WIDTH;
	int y1 = SCREEN_HEIGHT / 2 - DRAW_BG_HEIGHT / 2 - ADJUST_Y;
	int y2 = y1 + DRAW_BG_HEIGHT;
	_image->setPos( x1, y1, x2, y2 );
	_image->draw( );

	int X1 = SCREEN_WIDTH / 2 - DRAW_BG_WIDTH / 2;
	int X2 = x1 + DRAW_BG_WIDTH;
	int Y1 = SCREEN_HEIGHT / 2 - DRAW_BG_HEIGHT / 2 + 300;
	int Y2 = y1 + DRAW_BG_HEIGHT + 300;
	_push->setPos( X1, Y1, X2, Y2 );
	_push->draw( );
}
