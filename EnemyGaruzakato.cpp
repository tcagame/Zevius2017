#include "EnemyGaruzakato.h"
#include "Image.h"
#include "Drawer.h"
#include "define.h"
#include "Player.h"
#include "Time.h"

//ŠÔ‹{
const double GARUZA_VEC = 4;
const int TIMER = 240;


EnemyGaruzakato::EnemyGaruzakato( const Vector& pos, PlayerPtr player, ImagePtr small_1 ) :
Enemy( pos, SMALL_GRAPH_SIZE / 4, 30 ),
_time( TIMER ), 
_player( player ),
_image( small_1 ){
}


EnemyGaruzakato::~EnemyGaruzakato( ) {
}

void EnemyGaruzakato::act( ) {
	_time--;
	Vector target_pos = _player->getPos( );
	Vector pos = getPos( );
	Vector dir = ( target_pos - pos ).normalize( );
	Vector vec = dir * GARUZA_VEC;


	setVec( vec );
	if ( _time < 0 ) {
		//”š”­H
		setVec( Vector( ) );
	}
}

void EnemyGaruzakato::draw( int camera_x ) const{
	_image->setRect( SMALL_GRAPH_SIZE * 5, SMALL_GRAPH_SIZE * 3, SMALL_GRAPH_SIZE, SMALL_GRAPH_SIZE );
	_image->setPos( ( int )getPos( ).x - camera_x, ( int )getPos( ).y );
	_image->draw( );
}
