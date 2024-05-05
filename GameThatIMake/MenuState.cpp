#include "MenuState.h"
#include "DinoState.h"
#include <iostream>
#include "TextureManager.h"
#include "Button.h"
#include "GameObject.h"
#include "Sound.h"
#include "SpaceState.h"
#include "ChangeCharacterState.h"
#include "TTF.h"
#include "Dino.h"
#include "Spaceship.h"
#include "DrawPic.h"
#include "GameOverState.h"
#include "EnterName.h"
#include "HuongDan.h"
#include "DieuTraState.h"
#include "WinState.h"
#include "OnOffMusic.h"


const std::string MenuState::s_menuID = "MENU";
void MenuState::update()
{
	bgrMenu.update();
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
	phiHanhGia->update();
	dino->updateChuot(phiHanhGia->getPosition().getX() - 60,
		phiHanhGia->getPosition().getY() + 30);
}
void MenuState::render()
{
	bgrMenu.draw();
	avatar->drawFlip();
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}

	menuWrite.WriteNumber(TTF::coin, 430, 53);
	menuWrite.WriteNumber(TTF::food, 640, 53);
	std::ifstream playerName("font/playerName.txt");
	//docTen
	playerName >> EnterName::name;
	playerName.close();

	if (EnterName::name == "") 
	{
		menuWrite.Write(160, 12, "Enter your name");
	}
	else
	{
		menuWrite.Write(160, 42, EnterName::name);
		menuWrite.Write(150, 85, "Danh hieu: dep trai");
	}
	phiHanhGia->draw();
	dino->drawFlip();
}
bool MenuState::onEnter()
{
	menuSound.PlayMenuSound();
	if (ChangeCharacterState::pathPhgID == "")
	{
		ChangeCharacterState::pathPhgID = "image/PhiHanhGia1.png";
		ChangeCharacterState::pathAvaID = "image/avaPHG1.png";
		ChangeCharacterState::menuw = 22;
		ChangeCharacterState::menuh = 32;
		ChangeCharacterState::phgFrames = 4;
	}
	if (ChangeCharacterState::pathID == "")
	{
		ChangeCharacterState::pathID = "image/KhungLongFrames.png";
		ChangeCharacterState::width = 25;
		ChangeCharacterState::height = 25;
		ChangeCharacterState::frames = 9;
	}
	bgrMenu.load(2142,640,"image/bg.jpg", "bgr");
	if (!TheTextureManager::Instance()->load("image/MainPlay.png",
		"playSpace", TheGame::Instance()->getRenderer()))
	{
		std::cout << "fail to load in MenuState" << std::endl;
		return false;
	}
	if (!TheTextureManager::Instance()->load("image/DinoState.png",
		"playDino", TheGame::Instance()->getRenderer()))
	{
		return false;
		std::cout << "fail to load in MenuState" << std::endl;

	}
	if (!TheTextureManager::Instance()->load("image/Quit.png",
		"exitbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
		std::cout << "fail to load in MenuState" << std::endl;

	}
	if (!TheTextureManager::Instance()->load("image/Shop.png",
		"changeCharacter", TheGame::Instance()->getRenderer()))
	{
		return false;
		std::cout << "fail to load in MenuState" << std::endl;
	}

	if (!TheTextureManager::Instance()->load("image/DT.png",
		"DTButton", TheGame::Instance()->getRenderer()))
	{
		return false;
		std::cout << "fail to load in MenuState" << std::endl;
	}

	//phg
	if (!TheTextureManager::Instance()->load(ChangeCharacterState::pathPhgID,
		"phg", TheGame::Instance()->getRenderer()))
	{
		return false;
		std::cout << "fail to load in MenuState" << std::endl;

	}
	//kl
	if (!TheTextureManager::Instance()->load(ChangeCharacterState::pathID,
		"khungLong", TheGame::Instance()->getRenderer()))
	{
		std::cout << "fail to load phg3";
		return false;
		std::cout << "fail to load in MenuState" << std::endl;

	}
	//ava
	if (!TheTextureManager::Instance()->load(ChangeCharacterState::pathAvaID,
		"ava", TheGame::Instance()->getRenderer()))
	{
		std::cout << "fail to load in MenuState" << std::endl;
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/CoinPlace.png",
		"cPlace", TheGame::Instance()->getRenderer()))
	{
		std::cout << "fail to load phg3";
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/KeyPlace.png",
		"kPlace", TheGame::Instance()->getRenderer()))
	{
		std::cout << "fail to load phg3";
		return false;
	}
	if (!TheTextureManager::Instance()->load("image/NamePlace.png",
		"nPlace", TheGame::Instance()->getRenderer()))
	{
		std::cout << "fail to load phg3";
		return false;
	}
	if (!TheTextureManager::Instance()->load("image/HuongDanButton.png",
		"hdBtoon", TheGame::Instance()->getRenderer()))
	{
		std::cout << "fail to load phg3";
		return false;
	}
	if (!TheTextureManager::Instance()->load("image/music.png",
		"musicBtoon", TheGame::Instance()->getRenderer()))
	{
		std::cout << "fail to load phg3";
		return false;
	}

	GameObject* button1 = new Button(new LoaderParams(400, 200, 96,
		64, "playSpace"),2, s_menuToSpace);
	GameObject* button2 = new Button(new LoaderParams(600, 200, 53,
		32, "playDino"), 3, s_menuToDino);
	GameObject* button3 = new Button(new LoaderParams(400, 400, 96,
		49, "changeCharacter"), 2, s_menuToChangeCharacter);
	GameObject* button4 = new Button(new LoaderParams(600, 500, 64,
		32, "exitbutton"),2, s_exitFromMenu);
	GameObject* button5 = new Button(new LoaderParams(16, 300, 64,
		32, "hdBtoon"), 1, s_HuongDan);
	GameObject* button6 = new Button(new LoaderParams(16, 200, 33,
		29, "DTButton"), 2, s_DieuTra);
	GameObject* button7 = new Button(new LoaderParams(16, 400, 33,
		29, "musicBtoon"), 2, s_Music);

	avatar = new DrawPic(new LoaderParams(10, 30, 64, 64, "ava"), 2,1);
	phiHanhGia = new Spaceship(new LoaderParams(200, 400, 
		ChangeCharacterState::menuw, ChangeCharacterState::menuh, "phg"), 3,
		ChangeCharacterState::phgFrames,4);
	dino = new DrawPic(new LoaderParams(phiHanhGia->getPosition().getX() - 60,
		phiHanhGia->getPosition().getY()+30, ChangeCharacterState::width, 
		ChangeCharacterState::height,
		"khungLong"),2, ChangeCharacterState::frames);

	GameObject* coinPlace = new DrawPic(new LoaderParams(400, 30, 64, 32, "cPlace"), 2, 1);
	GameObject* keyPlace = new DrawPic(new LoaderParams(600, 30, 64, 32, "kPlace"), 2, 1);

	GameObject* namePlace = new Button(new LoaderParams(150, 40, 220,
		40, "nPlace"), 1, s_menuToEnterName);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	m_gameObjects.push_back(button3);
	m_gameObjects.push_back(button4);
	m_gameObjects.push_back(button5);
	m_gameObjects.push_back(button6);
	m_gameObjects.push_back(button7);
	m_gameObjects.push_back(namePlace);
	m_gameObjects.push_back(coinPlace);
	m_gameObjects.push_back(keyPlace);
	menuWrite.readFile();

	Spaceship::i = 0;
	std::cout << "entering MenuState\n";
	return true;
}
bool MenuState::onExit()
{
	bgrMenu.clean();
	avatar->clean();
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	std::cout << m_gameObjects.size() << std::endl;
;

	menuWrite.Clean();

	TheTextureManager::Instance()->clearFromTextureMap("playSpace");
	TheTextureManager::Instance()->clearFromTextureMap("playDino");
	TheTextureManager::Instance()->clearFromTextureMap("exitbutton");
	TheTextureManager::Instance()->clearFromTextureMap("changeCharacter");
	TheTextureManager::Instance()->clearFromTextureMap("phg");
	TheTextureManager::Instance()->clearFromTextureMap("khungLongCam");
	TheTextureManager::Instance()->clearFromTextureMap("ava");
	TheTextureManager::Instance()->clearFromTextureMap("kPlace");
	TheTextureManager::Instance()->clearFromTextureMap("cPlace");

	std::cout << "exiting MenuState\n";
	return true;
}

void MenuState::s_menuToSpace()
{
	TheGame::Instance()->getStateMachine()->changeState(new SpaceState());
}

void MenuState::s_menuToDino()
{
	TheGame::Instance()->getStateMachine()->changeState(new DinoState());
}

void MenuState::s_menuToChangeCharacter()
{
	TheGame::Instance()->getStateMachine()->changeState(new ChangeCharacterState());
}

void MenuState::s_menuToEnterName()
{
	TheGame::Instance()->getStateMachine()->changeState(new EnterName());
}

void MenuState::s_HuongDan()
{
	TheGame::Instance()->getStateMachine()->pushState(new HuongDan());
}

void MenuState::s_DieuTra()
{
	TheGame::Instance()->getStateMachine()->pushState(new DieuTraState());
}

void MenuState::s_Music()
{
	TheGame::Instance()->getStateMachine()->pushState(new OnOffMusic());
}



void MenuState::s_exitFromMenu()
{
	TheGame::Instance()->clean();
}