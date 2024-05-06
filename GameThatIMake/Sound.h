#pragma once
#include "SDL_mixer.h"
#include <map>
#include <string>

class Sound
{
public:
	static std::string pathMusic ;
	static bool onMusic;
	void PlayJumpSound()
	{
		InitJumpSound();
		Mix_PlayChannel(-1, chunk, 0);
	}


	void PlayMenuSound()
	{
		if(onMusic)
		{
			InitMenuSound();
			Mix_PlayMusic(nenmusic, -1);
		}
	}

	void PlayMenuMusic()
	{
		if (onMusic)
		{
			Mix_PlayMusic(nenmusic, -1);
		}
	}

	void PlayDieSound()
	{
		InitDieSound();
		Mix_PlayMusic(music, -1);
	}

	void PlayCCSound()
	{
		InitCCSound();
		Mix_PlayMusic(music, -1);
	}

	void PlayGunSound()
	{
		InitGunSound();
		Mix_PlayChannel(-1, chunk, 0);
	}

	void PlayCoinSound()
	{
		InitCoinSound();
		Mix_PlayChannel(-1, chunk, 0);
	}

	void PlayOcSound()
	{
		InitOcSound();
		Mix_PlayChannel(-1, chunk, 0);
	}

	void PlayGOSSound()
	{
		InitGOSSound();
		Mix_PlayMusic(music, -1);
	}

	void PlayLenThienDangSound()
	{
		InitLenThienDangSound();
		Mix_PlayMusic(music, -1);
	}

	void Clean()
	{
		Mix_FreeChunk(chunk);
	}

	void Clear()
	{
		Mix_FreeMusic(music);
		Mix_CloseAudio();
	}

	void resume()
	{
		Mix_ResumeMusic();
	}

	void pause()
	{
		Mix_PauseMusic();
	}
	void changeMusic(std::string path)
	{
		pathMusic = path;
	}
	void turnOff()
	{
		onMusic = false;
	}
	void turnOn()
	{
		onMusic = true;
	}
private:
	Mix_Music* music;
	Mix_Music* nenmusic;
	Mix_Chunk* chunk;
	std::map<std::string, Mix_Music*> nhacNen;

	void InitJumpSound()
	{
		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
		chunk = Mix_LoadWAV("sound/JumpVideoGame.wav");
	}

	void InitMenuSound()
	{
		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
		nenmusic = Mix_LoadMUS(pathMusic.c_str());
	}

	void InitDieSound()
	{
		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
		music = Mix_LoadMUS("sound/WelcomeParadise.wav");
	}

	void InitGOSSound()
	{

		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
		music = Mix_LoadMUS("sound/thienDang.mp3");
	}

	void InitCCSound()
	{
		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
		music = Mix_LoadMUS("sound/adventure.mp3");
	}

	void InitGunSound()
	{
		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
		chunk = Mix_LoadWAV("sound/gun.mp3");
	}

	void InitCoinSound()
	{
		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
		chunk = Mix_LoadWAV("sound/coin.wav");
	}

	void InitOcSound()
	{
		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
		chunk = Mix_LoadWAV("sound/oc.mp3");
	}

	void InitLenThienDangSound()
	{
		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
		music = Mix_LoadMUS("sound/lenThienDang.mp3");
	}
	void InitMetMoiSound()
	{
		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
		music = Mix_LoadMUS("sound/metMoi.mp3");
	}

};