#include "HuongDan.h"
#include "DrawPic.h"
#include "Button.h"
#include "TextureManager.h"

const std::string HuongDan::s_huongDanName = "HUONGDAN";


void HuongDan::update()
{
	huongDan->update();
	back->update();
}

void HuongDan::render()
{
	huongDan->draw();
	back->draw();
}
bool HuongDan::onEnter()
{
	if (!TheTextureManager::Instance()->load("image/bgr.png",
		"hdBgr", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/Back.png",
		"Back", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	huongDan = new DrawPic(new LoaderParams(0, 0, 800, 640, "hdBgr"), 1, 1);
	back = new Button(new LoaderParams(500, 500, 39, 33, "Back"),2, Back);
	return true;
}

bool HuongDan::onExit()
{
	huongDan->clean();
	back->clean();
	return true;
}

void HuongDan::Back()
{
	TheGame::Instance()->getStateMachine()->popState();
}