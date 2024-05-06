#pragma once
#include "GameState.h"
#include "TTF.h"
#include "DrawPic.h"

class GameObject;

class EnterName : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_enterNameID; }

	static std::string name;
private:
	DrawPic* bgr;
	static const std::string s_enterNameID;
	Uint32 frameStart, frameTime;
	TTF_Font* font;
};