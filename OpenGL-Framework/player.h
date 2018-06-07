#pragma once
#ifndef __PLAYER_H__
#define  __PLAYER_H__

#include "utils.h"
#include "object.h"
#include "bullet.h"
#include "input.h"
class CPlayer : public CObject
{
public:
	CPlayer(GLuint _program);
	~CPlayer();

	void init();
	void process();
	void Render();
	void Shoot();

private:
	std::vector<CBullet*> m_pBullets;
};

#endif