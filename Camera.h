#pragma once
class Camera {
public:
	Camera( );
	virtual ~Camera( );
public:
	void update( );
	void initCamera( );
	double getCameraPos( );
private:
	double _camera_pos;
};

