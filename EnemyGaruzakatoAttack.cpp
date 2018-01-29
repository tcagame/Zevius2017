#include "EnemyGaruzakatoAttack.h"
#include "define.h"
#include "Image.h"

const int ANIM_NUM = 4;

EnemyGaruzakatoAttack::EnemyGaruzakatoAttack( const Vector& pos, const Vector& dir, ImagePtr image ) :
Enemy( pos, SMALL_GRAPH_SIZE / 2, 0, true ),
_image( image ),
_pos( pos ),
_dir( dir ),
_count( 0 ) {
}


EnemyGaruzakatoAttack::~EnemyGaruzakatoAttack( ) {
}

void EnemyGaruzakatoAttack::act( ) {
	_count++;
	if ( _count > ANIM_NUM ) {
		_count = 0;
	}
	setVec( _dir );
}

void EnemyGaruzakatoAttack::draw( int camera_x ) const {
	_image->setRect( NORMAL_GRAPH_SIZE * _count, NORMAL_GRAPH_SIZE * 7, NORMAL_GRAPH_SIZE, NORMAL_GRAPH_SIZE );
	_image->setPos( getPos( ).x - camera_x, getPos( ).y );
	_image->draw( );
}