#include "PlayerShot.h"
#include "Drawer.h"
#include "Image.h"



PlayerShot::PlayerShot( Vector pos ) :
_pos( pos ) {
	DrawerPtr drawer = Drawer::getTask( );
	_image = drawer->createImage( "player/shot.png" );
}


PlayerShot::~PlayerShot( ) {
}

void PlayerShot::update( ) {
 	_pos.x++;
}

void PlayerShot::draw( ) {
	_image->setPos( _pos.x, _pos.y );
	_image->draw( );
}
