#include "EnemyGaruzakato.h"
#include "Image.h"
#include "Drawer.h"
#include "define.h"
#include "Player.h"
#include "Time.h"

//ŠÔ‹{
const double GARUZA_VEC = 1;
const int TIMER = 500;


EnemyGaruzakato::EnemyGaruzakato( const Vector& pos, PlayerPtr player ) :
Enemy( pos, 32 , 30 ),
_time( TIMER ){
	DrawerPtr drawer = Drawer::getTask( );
	_image = drawer->createImage( "enemy/enemy_small1.png" );
	_player = player;
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
}

void EnemyGaruzakato::draw( int camera_x ) const{
	_image->setRect( SMALL_GRAPH_SIZE * 5, SMALL_GRAPH_SIZE * 3, SMALL_GRAPH_SIZE, SMALL_GRAPH_SIZE );
	_image->setPos( ( int )getPos( ).x - camera_x, ( int )getPos( ).y );
	_image->draw( );
}
