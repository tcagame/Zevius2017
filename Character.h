#pragma once

#include "mathmatics.h"
#include "smart_ptr.h"

PTR( Character )

class Character {
public:
	Character( const Vector& pos, const double radius );
	virtual ~Character( );
public:
	void update( );
	virtual void draw( int camera_x ) const = 0;
public://getÅEisån
	double getRadius( ) const;
	Vector getPos( ) const;
	Vector getVec( ) const;
	bool isOverLapped( CharacterPtr target ) const;
protected:
	virtual void act( ) = 0;
	void setVec( const Vector& vec );
private:
	Vector _pos;
	Vector _vec;
	int _radius;
};

