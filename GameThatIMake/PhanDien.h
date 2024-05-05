#pragma once
#include "SDLGameObject.h"
#include "Sound.h"

class PhanDien :public SDLGameObject
{
public:
	PhanDien(const LoaderParams* pParams, int scale,int frames,int speeds);
	virtual void draw();
	virtual void update();
	virtual void updateCatus();
	virtual void clean();
	void dead1();
	void updateSpecial(int y);
	void diRa();
	bool appear = true;
	bool switchh = false;

	void changeRow0() { currentRow = 0; }
	void changeRow1() { currentRow = 1; }

	static int updateSpeed;

private:
	Sound PDSound;
	int swX = -1;
	int swY = -1;
	int frames;
	int speed;

	int yDan;
};