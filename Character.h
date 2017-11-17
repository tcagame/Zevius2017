#pragma once
class Character {
public:
	Character( );
	virtual ~Character( );
public:
	virtual void act( ) = 0;
};

