#include "EnemyExplosion.h"
#include "Image.h"
#include "Drawer.h"
#include "define.h"

const int ANIM_NUM = 9;

EnemyExplosion::EnemyExplosion( Vector& pos, int size ) :
_size( size ),
_pos( pos ),
_count( 0 ) {
	DrawerPtr drawer = Drawer::getTask( );
	_image = drawer->createImage( "enemy/enemy_medium.png" );
}


EnemyExplosion::~EnemyExplosion( ) {

}

bool EnemyExplosion::isFinished( ) {
	return _count >= ANIM_NUM;
}

void EnemyExplosion::draw( int camera_x ) {
	_image->setRect( NORMAL_GRAPH_SIZE * _count, NORMAL_GRAPH_SIZE * 3, NORMAL_GRAPH_SIZE, NORMAL_GRAPH_SIZE );
	int sx = ( int )_pos.x - camera_x;
	int sy = ( int )_pos.y;
	_image->setPos( sx, sy, sx + _size, sy + _size );
	_image->draw( );
	_count++;
}
