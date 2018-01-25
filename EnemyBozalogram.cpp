#include "EnemyBozalogram.h"
#include "Image.h"
#include "Drawer.h"
#include "define.h"

//‚“‡

const Vector MOVE_SPEED( -1, 0 );
const double RANGE_UP = 200;
const double RANGE_DOWN = 600;
const double ACCEL = 0.3;
const double MAX_SPEED = 5;

EnemyBozalogram::EnemyBozalogram( const Vector& pos ) :
Enemy( pos, 32 , 30 ),
_flag( false ) {
	DrawerPtr drawer = Drawer::getTask( );
	_image = drawer->createImage( "enemy/enemy_medium.png" );
	setVec( MOVE_SPEED );
}


EnemyBozalogram::~EnemyBozalogram( ) {

}

void EnemyBozalogram::act( ) {
	Vector vec = getVec( );
	double a = ACCEL;
	if ( getPos( ).y > RANGE_DOWN ) {
		_flag = true;
	}
	if ( getPos( ).y < RANGE_UP ) {
		_flag = false;
	}

	if ( _flag ) {
		a *= -1;
	}
	if ( vec.y > MAX_SPEED ) {
		vec.y = MAX_SPEED;
	}
	if ( vec.y < -MAX_SPEED ) {
		vec.y = -MAX_SPEED;
	}
	vec.y += a;
	setVec( vec );
}

void EnemyBozalogram::draw( int camera_x ) const{
	_image->setRect( NORMAL_GRAPH_SIZE * 0, NORMAL_GRAPH_SIZE * 12, NORMAL_GRAPH_SIZE, NORMAL_GRAPH_SIZE );
	_image->setPos( ( int )getPos( ).x - camera_x, ( int )getPos( ).y );
	_image->draw( );
}
