#pragma once
#include "Character.h"
class Enemy : public Character {
public:
	Enemy( const Vector& pos, double radius, int score, bool attack );
	virtual ~Enemy( );
public:
	virtual void draw( int camera_x ) const = 0;
	bool isFinished( );
	bool isAttackCharacter( );
	virtual void erase( );
	virtual int getSize( ) const;
private:
	bool _erase;
	bool _attack;
};

