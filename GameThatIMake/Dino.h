#pragma once
#include "SDLGameObject.h"
#include "Sound.h"

class Dino : public SDLGameObject
{
public:
	Dino(const LoaderParams* pParams,int scale,int frame);
	virtual void draw();
	virtual void update();
	virtual void clean();
	void dead();
private:
	int frames;
	void Jump();
	Sound DinoSound;
};
