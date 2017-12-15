#include "EnemyTorkan.h"
#include "Image.h"
#include "Drawer.h"
#include "define.h"

<<<<<<< HEAD
=======
//¼“c
>>>>>>> 140162dff9c233e704eb4d16208df39573d33589

const Vector T_VEC( -3, 0 );
const Vector REMOVE_POS( 300, 0 );
const Vector REMOVE_VEC( 3, 3 );
const double HALF_POS = 600;



int Getrandom(int min, int max)
{
	return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));

}


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
<<<<<<< HEAD
	if ( pos.y < HALF_POS ) {
		vec.y *= -1;
	}
=======
>>>>>>> 140162dff9c233e704eb4d16208df39573d33589

	setVec( vec );

	draw( );
}

void EnemyTorkan::draw( ) {
	_image->setRect( NORMAL_GRAPH_SIZE * 2, 0, NORMAL_GRAPH_SIZE, NORMAL_GRAPH_SIZE );
	_image->setPos( getPos( ).x, getPos( ).y );
	_image->draw( );
}