#include "Player.h"
#include "Drawer.h"
#include "Image.h"
#include "Device.h"
#include "Keyboard.h"

//�v���C���[�̏����ʒu
const double START_X = 50;
const double START_Y = 400;
//�v���C���[�̈ړ����x
const double MOVE_SPEED = 2.5;

Player::Player( ) :
_pos( Vector( START_X, START_Y ) ) {
	DrawerPtr drawer = Drawer::getTask( );
	_image = drawer->createImage( "player/sol_valou.png" );
}


Player::~Player( ) {
}

void Player::update( ) {
	act( );
}

void Player::act( ) {
	DevicePtr device = Device::getTask( );
	KeyboardPtr keyboard = Keyboard::getTask( );
	if ( keyboard->isHoldKey( "ARROW_RIGHT" ) ) {
		_pos.x += MOVE_SPEED;
	}
	if ( keyboard->isHoldKey( "ARROW_LEFT" ) ) {
		_pos.x -= MOVE_SPEED;
	}
	if ( keyboard->isHoldKey( "ARROW_UP" ) ) {
		_pos.y -= MOVE_SPEED;
	}
	if ( keyboard->isHoldKey( "ARROW_DOWN" ) ) {
		_pos.y += MOVE_SPEED;
	}
	//�f�o�b�O�p
	Drawer::getTask( )->drawString( 0, 100, "x:%lf y:%lf", _pos.x, _pos.y );
}

void Player::draw( ) {
	_image->setPos( _pos.x, _pos.y );
	_image->draw( );
}