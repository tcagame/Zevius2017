#include "Player.h"
#include "PlayerShot.h"
#include "Drawer.h"
#include "Image.h"
#include "Device.h"
#include "Keyboard.h"
#include "define.h"
#include "ScenePlay.h"
#include "Armoury.h"

//プレイヤーの初期位置
const double START_X = 50;
const double START_Y = 400;
const Vector START_POS( START_X, START_Y );
//プレイヤーの移動速度
const double MOVE_SPEED = 3.5;
//プレイヤーの移動制限
const int MAX_MOVE_X = 1412;
const int MAX_MOVE_Y = 780;

const int RADIUS = 32;

Player::Player( ) :
Character( START_POS, RADIUS ){
	_armoury = ArmouryPtr( new Armoury( ) );
	DrawerPtr drawer = Drawer::getTask( );
	_image = drawer->createImage( "player/sol_valou.png" );
	int width = 0;
	int height = 0;
	_image->getImageSize( width, height );
	_image->setRect( 0, 0, width, height );
}


Player::~Player( ) {
}


void Player::act( ) {
	actOnMove( );
	actOnAttack( );
	_armoury->update( );
}

void Player::actOnMove( ) {
	DevicePtr device = Device::getTask( );
	KeyboardPtr keyboard = Keyboard::getTask( );
	Vector vec;
	//プレイヤーの移動
	if ( keyboard->isHoldKey( "ARROW_RIGHT" ) ) {
		vec.x += MOVE_SPEED;
	}
	if ( keyboard->isHoldKey( "ARROW_LEFT" ) ) {
		vec.x += -MOVE_SPEED;
	}
	if ( keyboard->isHoldKey( "ARROW_UP" ) ) {
		vec.y += -MOVE_SPEED;
	}
	if ( keyboard->isHoldKey( "ARROW_DOWN" ) ) {
		vec.y += MOVE_SPEED;
	}

	Vector pos = getPos( );
	//プレイヤーの移動範囲
	if ( pos.x + vec.x <= 0 ) {
		vec.x = 0 - pos.x;
	}
	if ( pos.x + vec.x >= MAX_MOVE_X ) {
		vec.x = MAX_MOVE_X - pos.x;
	}
	if ( pos.y + vec.y <= 0 ) {
		vec.y = 0 - pos.y;
	}
	if ( pos.y + vec.y >= MAX_MOVE_Y ) {
		vec.y = MAX_MOVE_Y - pos.y;
	}
	
	Drawer::getTask( )->drawString( 0, 100, "x:%lf y:%lf", pos.x, pos.y );
	setVec( vec );
}

void Player::actOnAttack( ) {
	KeyboardPtr keyboard = Keyboard::getTask( );
	if ( keyboard->isPushKey( "SPACE" ) ) {
		_armoury->addShot( PlayerShotPtr( new PlayerShot( getPos( ) ) ) );
	}
}

void Player::draw( ) {
	Vector pos = getPos( );
	_image->setPos( ( int )pos.x, ( int )pos.y, ( int )pos.x + CHARACTER_SIZE, ( int )pos.y + CHARACTER_SIZE );
	_image->draw( );
	_armoury->draw( );
}