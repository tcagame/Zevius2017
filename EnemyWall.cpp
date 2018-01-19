#include "EnemyWall.h"
#include "Drawer.h"
#include "Image.h"
#include "define.h"

const int ANIM_NUM = 7;
const Vector MOVE_SPEED( -2, 0 );

EnemyWall::EnemyWall( const Vector& pos ) :
Enemy( pos, 32, 0 ),
_count( 0 ){
	DrawerPtr drawer = Drawer::getTask( );
	_image = drawer->createImage( "enemy/enemy_medium.png" );
}


EnemyWall::~EnemyWall( ) {
}


void EnemyWall::act( ) {
	_count++;
	setVec( MOVE_SPEED );
	draw( );
}

void EnemyWall::draw( ) {
	if ( _count > ANIM_NUM ) {//_count‚ªANIM_NUM‚ğ’´‚¦‚½‚çA_count1‚ğ0‚É‚·‚é
		_count = 0;
	}
	_image->setRect( NORMAL_GRAPH_SIZE * _count, NORMAL_GRAPH_SIZE * 2, NORMAL_GRAPH_SIZE, NORMAL_GRAPH_SIZE );
	_image->setPos( getPos( ).x, getPos( ).y );
	_image->draw( );
}