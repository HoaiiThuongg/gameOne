#pragma once
#include "GameObject.h"
#include "SDLGameObject.h"
#include "Background.h"
#include "Dino.h"
#include "PhanDien.h"
#include "TTF.h"
#include "Octopus.h"
#include "Bullet.h"
#include "DrawPic.h"
#include "Button.h"
#include "DrawPic.h"

class GameObject;

class HuongDan : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_huongDanName; }
private:
	static const std::string s_huongDanName;
	Button* back;
	DrawPic* huongDan;
	static void Back();
	
};