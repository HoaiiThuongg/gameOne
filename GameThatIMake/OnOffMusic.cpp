#include "OnOffMusic.h"
#include "DrawPic.h"
#include "Button.h"
#include "TextureManager.h"
#include "Sound.h"

const std::string OnOffMusic::s_OOMID = "onOffMusic";
Sound OnOffMusic::OOS;
Button* OnOffMusic::off;

void OnOffMusic::update()
{
	for (int i = 0; i < button.size(); i++)
	{
		button[i]->update();
	}
}

void OnOffMusic::render()
{
	bgr->draw();
	for (int i = 0; i < button.size(); i++)
	{
		button[i]->draw();
	}
}
bool OnOffMusic::onEnter()
{
	if (!TheTextureManager::Instance()->load("image/bgrMenu.png",
		"OOSBgr", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/Back.png",
		"Back", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/off.png",
		"off", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/metMoiSound.png",
		"met", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	bgr = new DrawPic(new LoaderParams(0, 0, 800, 640, "OOSBgr"), 1, 1);

	off = new Button(new LoaderParams(100, 100, 48, 38, "off"), 2, Off);
	Button* truMua = new Button(new LoaderParams(200, 100, 50, 23, "met"), 2, toTruMua);
	Button* metMoi = new Button(new LoaderParams(200, 300, 50, 23, "met"), 2, toMetMoi);
	Button* queToi = new Button(new LoaderParams(400, 100, 50, 23, "met"), 2, toQueToi);
	Button* bumChac = new Button(new LoaderParams(400, 300, 50, 23, "met"), 2, toBumChac);
	Button* back = new Button(new LoaderParams(500, 500, 39, 33, "Back"), 2, Back);

	button.push_back(off);
	button.push_back(truMua);
	button.push_back(metMoi);
	button.push_back(queToi);
	button.push_back(bumChac);
	button.push_back(back);

	return true;
}

bool OnOffMusic::onExit()
{
	bgr->clean();
	off->clean();
	for (int i = 0; i < button.size(); i++)
	{
		button[i]->clean();
	}
	return true;
}

void OnOffMusic::Off()
{
	if(off->returnRow() == 0)
	{
		Sound::onMusic = false;
		OOS.pause();
		off->changeRow1();
	}
	else if (off->returnRow() == 1)
	{
		Sound::onMusic = true;
		OOS.resume();
		off->changeRow0();
	}
}

void OnOffMusic::toTruMua()
{
	Sound::pathMusic = "sound/truMua.mp3";
	OOS.PlayMenuSound();
}

void OnOffMusic::toMetMoi()
{
	Sound::pathMusic = "sound/metMoi.mp3";
	OOS.PlayMenuSound();
}

void OnOffMusic::toQueToi()
{
	Sound::pathMusic = "sound/queToiRemix.mp3";
	OOS.PlayMenuSound();
}

void OnOffMusic::toBumChac()
{
	Sound::pathMusic = "sound/boleroBungChac.mp3";
	OOS.PlayMenuSound();
}

void OnOffMusic::Back()
{
	TheGame::Instance()->getStateMachine()->popState();
}