#include "EnterName.h"
#include "TTF.h"
#include "Game.h"
#include "InputHandle.h"
#include "DrawPic.h"
#include "TextureManager.h"

const std::string EnterName::s_enterNameID = "EnterName";

const int FPS = 60;
const int DELAY_TIME = 9000.0f / FPS;
std::string EnterName::name = "";

void EnterName::update()
{
    bgr->update();
    if (name.length() <= 14)
    {
        std::string abc = "";
        if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_A)) {
            abc = "a";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_B)) {
            abc = "b";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_C)) {
            abc = "c";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_D)) {
            abc = "d";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_E)) {
            abc = "e";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_F)) {
            abc = "f";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_G)) {
            abc = "g";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_H)) {
            abc = "h";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_I)) {
            abc = "i";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_J)) {
            abc = "j";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_K)) {
            abc = "k";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_L)) {
            abc = "l";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_M)) {
            abc = "m";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_N)) {
            abc = "n";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_O)) {
            abc = "o";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_P)) {
            abc = "p";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_Q)) {
            abc = "q";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_R)) {
            abc = "r";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_S)) {
            abc = "s";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_T)) {
            abc = "t";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_U)) {
            abc = "u";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_V)) {
            abc = "v";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_W)) {
            abc = "w";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_X)) {
            abc = "x";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_Y)) {
            abc = "y";
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_Z)) {
            abc = "z";
        }

        if (abc != "")
        {
            frameTime = SDL_GetTicks() - frameStart;
            if (frameTime < DELAY_TIME)
            {
                return;
            }
            frameStart = SDL_GetTicks();
            name += abc;
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
        {
            frameTime = SDL_GetTicks() - frameStart;
            if (frameTime < DELAY_TIME)
            {
                return;
            }
            frameStart = SDL_GetTicks();
            name += ' ';
        }
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_BACKSPACE) && name.length() > 0)
    {
        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < DELAY_TIME)
        {
            return;
        }
        frameStart = SDL_GetTicks();
        name.pop_back();
    }
}
void EnterName::render()
{
    SDL_Color textColor = { 0, 0, 0 };
    SDL_SetRenderDrawColor(TheGame::Instance()->getRenderer(), 0, 0, 0, 255);
    SDL_RenderClear(TheGame::Instance()->getRenderer());
    bgr->draw();
    SDL_Surface* surface = TTF_RenderText_Solid(font, name.c_str(), textColor);

    if (surface == nullptr)
    {
        return ;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(TheGame::Instance()->getRenderer(), surface);
    SDL_Rect dstRect = { 250, 300, surface->w, surface->h };
    SDL_RenderCopy(TheGame::Instance()->getRenderer(), texture, NULL, &dstRect);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);

    SDL_RenderPresent(TheGame::Instance()->getRenderer());
}

bool EnterName::onEnter()
{
    if (!TheTextureManager::Instance()->load("image/yourName.png",
        "bgrEnter", TheGame::Instance()->getRenderer()))
    {
        std::cout << "fail to load phg3";
        return false;
    }
    bgr = new DrawPic(new LoaderParams(0, 0, 800, 640, "bgrEnter"), 1, 1);

    frameStart = 0.0f;
    font = TTF_OpenFont("Font/poxel.ttf", 24);
    if (font == nullptr)
    {
        return false;
    }
	return true;
}

bool EnterName::onExit()
{
    if (name == "") name = "";
    std::ofstream playerName("font/playerName.txt");
    playerName << name;
    playerName.close();
    bgr->clean();
    TTF_CloseFont(font);
    TTF_Quit();
	return true;
}