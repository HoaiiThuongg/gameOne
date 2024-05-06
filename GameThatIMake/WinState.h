#pragma once
#include "GameState.h"
#include "TTF.h"
#include "Background.h"

class GameObject;

class WinState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_winState; }

	static std::string name;
private:
	Background bgr;
	static const std::string s_winState;
};