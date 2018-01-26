#include "Camera.h"

const double CAMERA_SPEED = 1;

Camera::Camera( ) :
_camera_pos( 0 ) {

}


Camera::~Camera( ) {

}

void Camera::update( ) {
	_camera_pos += CAMERA_SPEED;
}

void Camera::initCamera( ) {
	_camera_pos = 0;
}

double Camera::getCameraPos( ) {
	return _camera_pos;
}