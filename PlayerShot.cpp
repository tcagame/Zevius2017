#include "PlayerShot.h"
#include "Drawer.h"
#include "Image.h"
#include "define.h"

const Vector SHOT_SPEED( 5, 0 );

PlayerShot::PlayerShot( Vector pos ) :
Character( pos, 16 ) {
	DrawerPtr drawer = Drawer::getTask( );
	_image = drawer->createImage( "player/shot.png" );
}


PlayerShot::~PlayerShot( ) {
}

void PlayerShot::act( ) {
 	Vector vec;
	vec += SHOT_SPEED;
	setVec( vec );
}

void PlayerShot::draw( ) {
	Vector pos = getPos( );
	_image->setRect( 0,0,SMALL_GRAPH_SIZE * 1,SMALL_GRAPH_SIZE * 1/*切り取り始点X、切り取り始点Y、始点からどれくらいX、始点からどれくらいY*/ );
	_image->setPos( pos.x, pos.y );
	_image->draw( );
}
