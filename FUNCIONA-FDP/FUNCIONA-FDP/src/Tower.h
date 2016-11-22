#pragma once
#include "ofMain.h"
#include "Enemy.h"

class Tower : public Enemy
{
public:
	Tower();

	void Reset();
	//void Update();
	void Draw();

	float SetSize();

	~Tower();

private:
	ofImage image;
};

