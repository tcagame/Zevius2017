#include "EnemyGaruzakatoAttack.h"
#include "define.h"
#include "Image.h"
#include "Drawer.h"

const int ANIM_NUM = 4;

EnemyGaruzakatoAttack::EnemyGaruzakatoAttack( const Vector& pos, const Vector& dir ) :
Enemy( pos, SMALL_GRAPH_SIZE, 0, true ),
_pos( pos ),
_dir( dir ),
_count( 0 ) {
	DrawerPtr drawer = Drawer::getTask( );
	_image = drawer->createImage( "enemy/enemy_medium.png" );
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