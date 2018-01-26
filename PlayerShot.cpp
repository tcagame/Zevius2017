#include "PlayerShot.h"
#include "Drawer.h"
#include "Image.h"
#include "define.h"

const Vector SHOT_SPEED( 5, 0 );
const int ANIM_NUM = 1;

PlayerShot::PlayerShot( Vector pos ) :
Character( pos, 16 ),
_count( 0 ) {
	DrawerPtr drawer = Drawer::getTask( );
	_image = drawer->createImage( "player/shot.png" );
}


PlayerShot::~PlayerShot( ) {
}

void PlayerShot::act( ) {
	_count++;
	if ( _count > ANIM_NUM ) {
		_count = 0;
	}
 	Vector vec;
	vec += SHOT_SPEED;
	setVec( vec );
}

void PlayerShot::draw( int camera_x ) const {
	Vector pos = getPos( );
	_image->setRect( SMALL_GRAPH_SIZE * _count, SMALL_GRAPH_SIZE * 0, SMALL_GRAPH_SIZE, SMALL_GRAPH_SIZE );
	_image->setPos( pos.x - camera_x, pos.y );
	_image->draw( );
}
