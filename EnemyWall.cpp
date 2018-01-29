#include "EnemyWall.h"
#include "Drawer.h"
#include "Image.h"
#include "define.h"

const int ANIM_NUM = 7;
const Vector MOVE_SPEED( -1.5, 0 );
const int HP = 90;

EnemyWall::EnemyWall( const Vector& pos, ImagePtr medium ) :
Enemy( pos, NORMAL_GRAPH_SIZE / 4, 0, false ),
_count( 0 ),
_image( medium ),
_hp( HP ) {

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

void EnemyWall::erase( ) {
	_hp--;
	if ( _hp < 0 ) {
		Enemy::erase( );
	}
}