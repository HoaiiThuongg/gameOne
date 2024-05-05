#pragma once
#include "GameState.h"
#include "TTF.h"
#include "Button.h"
#include "DrawPic.h"
#include "Sound.h"

class GameObject;

class OnOffMusic : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_OOMID; }
	static Sound OOS;

private:
	static void Off();
	static void toTruMua();
	static void toMetMoi();
	static void toBumChac();
	static void toQueToi();
	static void Back();

	static Button* off;

	std::vector<Button*> button;

	DrawPic* bgr;
	
	static const std::string s_OOMID;
};