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
}

void EnemyWall::draw( int camera_x ) const{
	_image->setRect( NORMAL_GRAPH_SIZE * ( _count % ANIM_NUM ), NORMAL_GRAPH_SIZE * 2, NORMAL_GRAPH_SIZE, NORMAL_GRAPH_SIZE );
	_image->setPos( ( int )getPos( ).x - camera_x, ( int )getPos( ).y );
	_image->draw( );
}