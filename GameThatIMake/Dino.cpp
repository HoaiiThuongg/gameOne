#include "Dino.h"
#include "InputHandle.h"
#include "ChangeCharacterState.h"

std::string jump = "none";
int ground = 425;
int maxJump = 250;
bool ban = false;
int jumpNhay = 8;

Dino::Dino(const LoaderParams* pParams,int scale,int frame) :
	SDLGameObject(pParams,scale),frames(frame)
{}

void Dino::Jump()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		if (m_position.getY() == ground)
		{
			jump = "jump";
			DinoSound.PlayJumpSound();
		}
	}
}

void Dino::draw()
{
	SDLGameObject::draw();
}

void Dino::dead() 
{
	m_velocity.setY(-2);
	m_velocity.setX(0);
	currentRow = 2;
	currentFrame = 0;
	SDLGameObject::update();
}

void Dino::update()
{
	m_velocity.setX(0);
	m_velocity.setY(0);
	Jump();
	currentFrame = (SDL_GetTicks() / 200) % frames;
	if (jump == "jump")
	{
		m_velocity.setY(-jumpNhay);
		if (m_position.getY() < maxJump) jump = "down";
	}

	else if (jump == "down")
	{
		m_velocity.setY(jumpNhay);
		if (m_position.getY() > ground)
		{
			jump = "none";
			m_velocity.setY(0);
		}
	}

	if (jump == "none")
	{
		m_position.setY(ground );

	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		m_velocity.setX(4);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		m_velocity.setX(-4);
	}
	SDLGameObject::update();
}

void Dino::clean()
{
	DinoSound.Clean();
	SDLGameObject::clean();
}
