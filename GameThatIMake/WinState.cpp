#include "WinState.h"
#include "TextureManager.h"

const std::string WinState::s_winState = "winState";

void WinState::update()
{

}

void WinState::render()
{
	bgr.draw();
}

bool WinState::onEnter()
{
	if (!TheTextureManager::Instance()->load("image/WinState.png",
		"bgrWS", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	bgr.load(800, 640, "image/WinState.png", "bgrWS");

	return true;
}

bool WinState::onExit()
{
	bgr.clean();
	return true;
}