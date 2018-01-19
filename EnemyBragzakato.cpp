#include "EnemyBragzakato.h"
#include "Image.h"
#include "Drawer.h"
#include "define.h"
#include "Player.h"

//山蔭
const double BRAGZAKATO_VEC = 2;
const double ATTACK_RANGE = 100;

EnemyBragzakato::EnemyBragzakato( const Vector& pos, PlayerPtr player ) :
Enemy( pos, 32, 500 ),
_attack( false ),
_count( 0 ) {
	_player = player;
	DrawerPtr drawer = Drawer::getTask( );
	_image = drawer->createImage( "enemy/enemy_small1.png" );
}

   
EnemyBragzakato::~EnemyBragzakato( ) {

}

void EnemyBragzakato::act( ) {
	Vector target_pos = _player->getPos( );
	Vector pos = getPos( );
	Vector dir = ( target_pos - pos ).normalize( );
	Vector vec = dir * BRAGZAKATO_VEC;

	setVec( vec );
	if ( ( target_pos - pos ).getLength( ) < ATTACK_RANGE ) {
		_attack = true;
		//炸裂するよ
	}
	if ( _attack ) {
		_count++;
		setVec( Vector( ) );
		DrawerPtr drawer = Drawer::getTask( );
		if ( _count % 120 == 0 ) {
			drawer->drawString( 0, 0, "どおおおおおおおん" );//デバッグメッセージ
		}
	}


	draw( );
}

void EnemyBragzakato::draw( ) {
	Vector pos = getPos( );
	_image->setRect( SMALL_GRAPH_SIZE * 0, SMALL_GRAPH_SIZE * 3, SMALL_GRAPH_SIZE, SMALL_GRAPH_SIZE );
	_image->setPos( pos.x, pos.y );
	_image->draw( );
}