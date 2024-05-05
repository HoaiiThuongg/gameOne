#include "GameState.h"
#include "Boss.h"
#include "Dino.h"
#include "PhanDien.h"
#include "Background.h"
#include "DrawPic.h"
#include <unordered_map>

class GameObject;

class BossState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_bossID; }
private:
	bool checkVa(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);
	std::vector<PhanDien*> m_con;
	bool de = false;
	Boss* boss;
	Dino* me;

	Background bgr;
	Background mauChua;
	Background mauMe;

	DrawPic* CamChuong;
	static const std::string s_bossID;

	std::string trthaiboss;

	std::vector<DrawPic*> XanhPiuPiu;

	std::vector<std::string> chuong;

	std::unordered_map<DrawPic*, bool> Chuong;
	std::vector<DrawPic*> ChucNang;
};