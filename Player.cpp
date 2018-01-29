#include "Player.h"
#include "PlayerShot.h"
#include "Drawer.h"
#include "Image.h"
#include "Device.h"
#include "Keyboard.h"
#include "define.h"
#include "ScenePlay.h"
#include "Armoury.h"
#include "Camera.h"
#include "Sound.h"

//プレイヤーの初期位置
const double START_X = 50;
const double START_Y = 400;
const Vector START_POS( START_X, START_Y );
//プレイヤーの移動速度
const double MOVE_SPEED = 3.5;

//プレイヤーアニメーション
const int ANIM_NUM = 6;

PTR( Sound );

Player::Player( ArmouryPtr armoury, CameraPtr camera ) :
Character( START_POS, NORMAL_GRAPH_SIZE / 2 ),
_armoury( armoury ),
_camera( camera ),
_game_over( false ) {
	DrawerPtr drawer = Drawer::getTask( );
	SoundPtr sound = Sound::getTask( );
	sound->loadSE( "sound/xev_se_ZapperShoot.wav" );
	_image = drawer->createImage( "player/sol_valou.png" );
	int width = 0;
	int height = 0;
	_image->getImageSize( width, height );
	_image->setRect( 0, 0, width, height );
}


Player::~Player( ) {
}


void Player::act( ) {
	_count++;
	actOnMove( );
	actOnAttack( );
	actOnDead( );
}

void Player::actOnMove( ) {
	DevicePtr device = Device::getTask( );
	KeyboardPtr keyboard = Keyboard::getTask( );
	Vector vec = Vector( 1, 0 );
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
	int left = _camera->getCameraPos( );
	int right = _camera->getCameraPos( ) + SCREEN_WIDTH - NORMAL_GRAPH_SIZE;
	if ( pos.x + vec.x <= left ) {
		vec.x = left - pos.x;
	}

	if ( pos.x + vec.x >= right ) {
		vec.x = right - pos.x;
	}

	if ( pos.y + vec.y <= 0 ) {
		vec.y = 0 - pos.y;
	}
	if ( pos.y + vec.y >= SCREEN_HEIGHT - NORMAL_GRAPH_SIZE ) {
		vec.y = SCREEN_HEIGHT - NORMAL_GRAPH_SIZE - pos.y;
	}
	
	Drawer::getTask( )->drawString( 0, 100, "x:%lf y:%lf", pos.x, pos.y );
	setVec( vec );
}

void Player::actOnAttack( ) {
	KeyboardPtr keyboard = Keyboard::getTask( );
	if ( keyboard->isPushKey( "Z" ) ) {
		SoundPtr sound = Sound::getTask( );
		sound->playSE( "sound/xev_se_ZapperShoot.wav" );
		_armoury->addShot( PlayerShotPtr( new PlayerShot( Vector( getPos( ).x, getPos( ).y + SMALL_GRAPH_SIZE / 2 ) ) ) );
	}
}


void Player::actOnDead( ) {
		_image->setRect( 0, NORMAL_GRAPH_SIZE * ( _count % ANIM_NUM ) , NORMAL_GRAPH_SIZE, NORMAL_GRAPH_SIZE/*スタートX、スタートY、大きさX、大きさY*/);
}

void Player::draw( int camera_x ) const {
	Vector pos = getPos( );
	_image->setRect( 0, 0, SMALL_GRAPH_SIZE * 1, SMALL_GRAPH_SIZE * 1 );
	int sx1 = ( int )pos.x - camera_x;
	int sy1 = ( int )pos.y;
	int sx2 = sx1 + CHARACTER_SIZE;
	int sy2 = sy1 + CHARACTER_SIZE;
	_image->setPos( sx1, sy1, sx2, sy2 );
	_image->draw( );
	_armoury->draw( camera_x );
}

void Player::setFinished( bool finish ) {
	_game_over = finish;
}

bool Player::isFinished( ) {
	return _game_over;
}
