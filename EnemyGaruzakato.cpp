#include "EnemyGaruzakato.h"
#include "Image.h"
#include "Drawer.h"
#include "define.h"
#include "Player.h"
#include "Time.h"

//�ԋ{
const double GARUZA_VEC = 3;
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
	draw( );
}

void EnemyGaruzakato::draw( ) {
	_image->setRect( 16 * 5, 16*5, 16, 16 );
	_image->setPos( getPos( ).x, getPos( ).y );
	_image->draw( );
}