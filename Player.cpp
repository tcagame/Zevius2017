#include "Player.h"
#include "Drawer.h"
#include "Image.h"

const int PLAYER_START_X = 20;
const int PLAYER_START_Y = 20;

Player::Player( ) {
	DrawerPtr drawer = Drawer::getTask( );
	_image = drawer->createImage( "player/sol_valou.png" );
}


Player::~Player( ) {
}

void Player::update( ) {
	act( );
}

void Player::act( ) {

}

void Player::draw( ) {
	_image->setPos( PLAYER_START_X, PLAYER_START_Y );
	_image->draw( );
}