#include "EnemyTorkan.h"
#include "Image.h"
#include "Drawer.h"
#include "define.h"

const Vector T_VEC( -3, 0 );
const Vector REMOVE_POS( 300, 0 );
const Vector REMOVE_VEC( 3, 3 );
const double HARF_POS = 400;

EnemyTorkan::EnemyTorkan( const Vector& pos ) :
Enemy( pos, 32, 500 ),
_remove( false ){
	DrawerPtr drawer = Drawer::getTask( );
	_image = drawer->createImage( "enemy/enemy.png" );
}


EnemyTorkan::~EnemyTorkan( ) {
}

void EnemyTorkan::act( ) {
	Vector pos = getPos( );
	Vector vec = T_VEC;
	if ( pos.x < REMOVE_POS.x && _remove == false ) {
		_remove = true;
	}
	if ( _remove == true ) {
		vec = REMOVE_VEC;
	}

	setVec( vec );

	draw( );
}

void EnemyTorkan::draw( ) {
	Vector pos = getPos( );
	_image->setRect( NORMAL_GRAPH_SIZE * 2, 0, NORMAL_GRAPH_SIZE, NORMAL_GRAPH_SIZE );
	_image->setPos( pos.x, pos.y );
	_image->draw( );
}