#include "DieuTraState.h"
#include "DrawPic.h"
#include "Button.h"
#include "TextureManager.h"
#include "Vector2D.h"
#include "TTF.h"
#include "fstream"

const std::string DieuTraState::s_dieuTraID = "DIEUTRA";

int DieuTraState::s1Ok;
int DieuTraState::s2Ok;
int DieuTraState::s3Ok;
int DieuTraState::s4Ok;
int DieuTraState::state=0;

void DieuTraState::update()
{
	DTWrite.UpdateStatic();
	bgr->update();
	chuot->updateChuot(mouse->getX(), mouse->getY());
	if(state == 0)
	{
		for (int i = 0; i < m_dieuTra.size(); i++)
		{
			m_dieuTra[i]->update();
		}
		if (m_dieuTra.size() == 5)
		{
			if (s2Ok == MoNhungChuaMua)
			{
				m_dieuTra[1]->changeRow1();
			}
			if (s3Ok == MoNhungChuaMua)
			{
				m_dieuTra[2]->changeRow1();
			}
			if (s4Ok == MoNhungChuaMua)
			{
				m_dieuTra[3]->changeRow1();
			}
			//update mua ban
			if (s1Ok == DaMua)
			{
				m_dieuTra[0]->changeRow1();
			}
			if (s2Ok == DaMua)
			{
				m_dieuTra[1]->changeRow2();
			}

			if (s3Ok == DaMua)
			{
				m_dieuTra[2]->changeRow2();
			}

			if (s4Ok == DaMua)
			{
				m_dieuTra[3]->changeRow2();
			}
		}
	}
	else if (state == 1)
	{
		returnn->update();
	}
	else if (state == 2)
	{
		returnn->update();
	}
	else if (state == 3)
	{
		returnn->update();
	}
	else if (state == 4)
	{
		toBossState->update();
		returnn->update();
	}
}

void DieuTraState::render()
{
	bgr->draw();
	if(state == 0)
	{
		for (int i = 0; i < m_dieuTra.size(); i++)
		{
			m_dieuTra[i]->draw();
		}
	}
	else if (state == 1)
	{
		key1->draw();
		returnn->draw();
	}
	else if (state == 2)
	{
		key2->draw();
		returnn->draw();
	}
	else if (state == 3)
	{
		key3->draw();
		returnn->draw();
	}
	else if (state == 4)
	{
		key4->draw();
		toBossState->draw();
		returnn->draw();
	}
	for (int i = 0; i < m_hinhAnh.size(); i++)
	{
		m_hinhAnh[i]->draw();
	}
	DTWrite.WriteNumber(TTF::coin, 430, 53);
	DTWrite.WriteNumber(TTF::food, 640, 53);
	chuot->draw();
}

bool DieuTraState::onEnter()
{
	if (!TheTextureManager::Instance()->load("image/TaiLieu1.png",
		"tl1", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/TaiLieu2.png",
		"tl2", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/TaiLieu3.png",
		"tl3", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/TaiLieu4.png",
		"tl4", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if(!TheTextureManager::Instance()->load("image/DieuTra.jpg",
		"bgrDT", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/mouse.png",
		"mouse", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/Back.png",
		"Back", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/Key1.png",
		"key1", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/Key2.png",
		"key2", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/Key3.png",
		"key3", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/Key4.png",
		"key4", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/Xbutton.png",
		"x", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/BossState.png",
		"BS", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/CoinPlace.png",
		"cPlace", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("image/KeyPlace.png",
		"kPlace", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	GameObject* coinPlace = new DrawPic(new LoaderParams(400, 30, 64, 32, "cPlace"), 2, 1);
	GameObject* keyPlace = new DrawPic(new LoaderParams(600, 30, 64, 32, "kPlace"), 2, 1);

	m_hinhAnh.push_back(coinPlace);
	m_hinhAnh.push_back(keyPlace);

	key1 = new DrawPic(new LoaderParams(100, 110, 625, 441, "key1"), 1, 1);
	key2 = new DrawPic(new LoaderParams(100, 110, 625, 441, "key2"), 1, 1);
	key3 = new DrawPic(new LoaderParams(100, 110, 625, 441, "key3"), 1, 1);
	key4 = new DrawPic(new LoaderParams(100, 110, 625, 441, "key4"), 1, 1);

	toBossState= new Button(new LoaderParams(500, 400, 64, 32, "BS"), 2, m_toBossState);

	bgr = new DrawPic(new LoaderParams(0, 0, 800, 640, "bgrDT"), 1, 1);
	Button* tl1 = new Button(new LoaderParams(100, 200, 13, 20, "tl1"),5, TL1);
	Button* tl2 = new Button(new LoaderParams(300, 200, 14, 21, "tl2"),5, TL2);
	Button* tl3 = new Button(new LoaderParams(100, 400, 15, 23, "tl3"),5, TL3);
	Button* tl4 = new Button(new LoaderParams(300, 400, 17, 22, "tl4"),5, TL4);
	Button* backButton = new Button(new LoaderParams(600, 500, 39,33, "Back"), 2, Back);

	returnn = new Button(new LoaderParams(700, 100, 26,26, "x"), 2, Return);
	
	m_dieuTra.push_back(tl1);
	m_dieuTra.push_back(tl2);
	m_dieuTra.push_back(tl3);
	m_dieuTra.push_back(tl4);
	m_dieuTra.push_back(backButton);

	chuot = new DrawPic(new LoaderParams(mouse->getX(), mouse->getY(), 29, 29, "mouse"), 2, 1);

	std::ifstream file("font/dieuTra.txt");
	file >> s1Ok>> s2Ok >> s3Ok >> s4Ok;
	if (s1Ok == chuaMo) s1Ok = MoNhungChuaMua;
	file.close();

	return true;
}

bool DieuTraState::onExit()
{
	bgr->clean();
	for (int i = 0; i < m_dieuTra.size(); i++)
	{
		m_dieuTra[i]->clean();
	}

	std::ofstream file("font/dieuTra.txt");
	if (s1Ok == 3) s1Ok = 2;
	if (s2Ok == 3) s2Ok = 2;
	if (s3Ok == 3) s3Ok = 2;
	if (s4Ok == 3) s4Ok = 2;
	file <<s1Ok<<' '<< s2Ok << ' ' << s3Ok << ' ' << s4Ok;
	file.close();
	return true;
}

void DieuTraState::TL1()
{
	if (s1Ok == MoNhungChuaMua && TTF::food >= 10)
	{
		TTF::food -= 10;
		s1Ok = DaMua;
		s2Ok = MoNhungChuaMua;
	}
	else if(s1Ok == DaMua)
	{
		state = 1;
		//s2Ok = MoNhungChuaMua;
	}
}

void DieuTraState::TL2()
{
	if (s2Ok == MoNhungChuaMua && TTF::food >= 20)
	{
		TTF::food -= 20;
		s2Ok = DaMua;
		s3Ok = MoNhungChuaMua;
	}
	else if (s2Ok == DaMua)
	{
		state = 2;
		//s3Ok = MoNhungChuaMua;
	}
}

void DieuTraState::TL3()
{
	if (s3Ok == MoNhungChuaMua &&TTF::food >= 30)
	{
		TTF::food -= 30;
		s3Ok = DaMua;
		s4Ok = MoNhungChuaMua;
	}
	else if (s3Ok == DaMua)
	{
		state = 3;
		//s4Ok = MoNhungChuaMua;
	}
}

void DieuTraState::TL4()
{
	if (s4Ok == MoNhungChuaMua &&TTF::food >= 40)
	{
		TTF::food -= 40;
		s4Ok = DaMua;
	}
	else if (s4Ok == DaMua)
	{
		state = 4;
	}
}