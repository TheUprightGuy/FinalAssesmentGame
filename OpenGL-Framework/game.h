#pragma once
#ifndef __GAME_H__
#define __GAME_H__

#include "input.h"
#include "utils.h"
#include "object.h"
#include "CameraManager.h";
#include "player.h"
#include "bullet.h"
class CGame
{
public:
	~CGame(){}

	static CGame& GetInstance();
	static void DestroyInstance();

	void init(GLuint& _program);
	
	void Process();
	void Render();

protected:
	static CGame* s_pGame;

private:
	CGame();
	CGame(const CGame& _kr) = delete;
	CGame& operator= (const CGame& _kr) = delete;

	GLuint m_program;

	CPlayer* m_Player;


	std::vector<CObject*> m_vpEnviroment;
};


#endif