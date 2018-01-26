#include "EnemyTorkan.h"
#include "Image.h"
#include "Drawer.h"
#include "define.h"


//���c

const Vector T_VEC( -3, 0 );
const Vector REMOVE_POS( 300, 0 );
const Vector REMOVE_VEC( 3, 3 );
const double HALF_POS = 600;




int Getrandom(int min, int max)
{
	return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));

}


EnemyTorkan::EnemyTorkan( const Vector& pos, ImagePtr small_2 ) :
Enemy( pos, 32, 500 ),
_remove( false ),
_image( small_2 ){
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
	if ( pos.y < HALF_POS ) {
		vec.y *= -1;
	}

	setVec( vec );
}

void EnemyTorkan::draw( int camera_x ) const{
	_image->setRect( 16 * 0, 0, 16, 16 );
	_image->setPos( ( int )getPos( ).x - camera_x, ( int )getPos( ).y );
	_image->draw( );
}