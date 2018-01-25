#include "EnemyBoss.h"
#include "Drawer.h"
#include "Image.h"
#include "define.h"

const int BOSS_GRAPH_SIZE = 96;
const int ANIM_NUM = 7;

EnemyBoss::EnemyBoss( const Vector& pos ) :
Enemy( pos, 32, 5000 ) {
	DrawerPtr drawer = Drawer::getTask( );
	_image = drawer->createImage( "enemy/enemy_boss.png" );
}


EnemyBoss::~EnemyBoss( ) {
}

void EnemyBoss::act( ) {
	_count++;
}

void EnemyBoss::draw( int camera_x ) const{
	_image->setRect( BOSS_GRAPH_SIZE * ( _count % ANIM_NUM ), 0, BOSS_GRAPH_SIZE, BOSS_GRAPH_SIZE );
	_image->setPos( getPos( ).x, getPos( ).y );
	_image->draw( );
}
