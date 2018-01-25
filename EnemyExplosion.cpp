#include "EnemyExplosion.h"
#include "Image.h"
#include "Drawer.h"
#include "define.h"

const int ANIM_NUM = 9;

EnemyExplosion::EnemyExplosion( Vector& pos ) {
	DrawerPtr drawer = Drawer::getTask( );
	_image = drawer->createImage( "enemy/enemy_medium.png" );
	drawExplosion( pos );
}


EnemyExplosion::~EnemyExplosion( ) {

}

void EnemyExplosion::drawExplosion( Vector& pos ) {
	for ( int i = 0; i < ANIM_NUM; i++ ) {
		_image->setRect( NORMAL_GRAPH_SIZE * i, NORMAL_GRAPH_SIZE * 3, NORMAL_GRAPH_SIZE, NORMAL_GRAPH_SIZE );
		_image->setPos( pos.x, pos.y );
		_image->draw( );
	}
}
