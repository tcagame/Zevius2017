#include "EnemyToroid.h"
#include "Image.h"
#include "define.h"
#include "Drawer.h"

const int ANIM_NUM = 7;

EnemyToroid::EnemyToroid( const Vector& pos, ImagePtr small_2 ) :
Enemy( pos, SMALL_GRAPH_SIZE / 2, 30 ),
_count( 0 ) {

}


EnemyToroid::~EnemyToroid( ) {

}

void EnemyToroid::act( ) {
	_count++;


	if( _count > ANIM_NUM ) {
		_count = 0;
	}
}

void EnemyToroid::draw( int camera_x ) const{
	_image->setRect( SMALL_GRAPH_SIZE * _count, SMALL_GRAPH_SIZE, SMALL_GRAPH_SIZE, SMALL_GRAPH_SIZE );
	_image->setPos( getPos( ).x - camera_x, getPos( ).y );
	_image->draw( );

}
