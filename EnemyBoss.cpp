#include "EnemyBoss.h"
#include "Drawer.h"
#include "Image.h"
#include "define.h"

const int BOSS_GRAPH_SIZE = 96;
const int ANIM_NUM = 7;

EnemyBoss::EnemyBoss( const Vector& pos, ImagePtr boss ) :
Enemy( pos, 32, 5000 ),
_image( boss ) {
}


EnemyBoss::~EnemyBoss( ) {
}

void EnemyBoss::act( ) {
	_count++;
}

void EnemyBoss::draw( int camera_x ) const{
	_image->setRect( BOSS_GRAPH_SIZE * ( _count % ANIM_NUM ), 0, BOSS_GRAPH_SIZE, BOSS_GRAPH_SIZE );
	_image->setPos( getPos( ).x - camera_x, getPos( ).y );
	_image->draw( );
}
