#include "Player.h"
#include "PlayerShot.h"
#include "Drawer.h"
#include "Image.h"
#include "Device.h"
#include "Keyboard.h"
#include "define.h"
#include "ScenePlay.h"

//�v���C���[�̏����ʒu
const double START_X = 50;
const double START_Y = 400;
//�v���C���[�̈ړ����x
const double MOVE_SPEED = 2.5;
//�v���C���[�̈ړ�����
const int MAX_MOVE_X = 1412;
const int MAX_MOVE_Y = 780;

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
	//�v���C���[�̈ړ�
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
	//�v���C���[�̈ړ��͈�
	if ( _pos.x <= 0 ) {
		_pos.x = 0;
	}
	if ( _pos.x >= MAX_MOVE_X ) {
		_pos.x = MAX_MOVE_X;
	}
	if ( _pos.y <= 0 ) {
		_pos.y = 0;
	}
	if ( _pos.y >= MAX_MOVE_Y ) {
		_pos.y = MAX_MOVE_Y;
	}
	//�v���C���[�U��
	if ( keyboard->isPushKey( "SPACE" ) ) {
		PlayerShotPtr shot = PlayerShotPtr( new PlayerShot( _pos ) );

	}
	//�f�o�b�O�p
	Drawer::getTask( )->drawString( 0, 100, "x:%lf y:%lf", _pos.x, _pos.y );
}

void Player::draw( ) {
	int width = 0;
	int height = 0;
	_image->getImageSize( width, height );
	_image->setRect( 0, 0, width, height );
	_image->setPos( _pos.x, _pos.y, _pos.x + CHARACTER_SIZE, _pos.y + CHARACTER_SIZE );
	_image->draw( );
	//_shot->draw( );
}