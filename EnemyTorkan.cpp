#include "EnemyTorkan.h"
#include "Image.h"
#include "Drawer.h"
#include "define.h"

const Vector ATTACK_POS( 50, 0 );
const Vector T_VEC( -3, 0 );

EnemyTorkan::EnemyTorkan( const Vector& pos ) :
Enemy( pos, 32, 500 ) {
	DrawerPtr drawer = Drawer::getTask( );
	_image = drawer->createImage( "enemy/enemy.png" );
}


EnemyTorkan::~EnemyTorkan( ) {
}

void EnemyTorkan::act( ) {
	Vector vec;
	vec += T_VEC;
	setVec( T_VEC );

	draw( );
}

void EnemyTorkan::draw( ) {
	Vector pos = getPos( );
	_image->setRect( NORMAL_GRAPH_SIZE * 2, 0, NORMAL_GRAPH_SIZE, NORMAL_GRAPH_SIZE );
	_image->setPos( pos.x, pos.y );
	_image->draw( );
}