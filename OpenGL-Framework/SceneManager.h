#pragma once
#ifndef __SCENEMANAGER_H__
#define __SCENEMANAGER_H__

#include <vector>
#include <map>
#include <string.h>

#include "utils.h"
#include "input.h"
#include "camera.h"
#include "TextLabel.h"
//#include "object.h"
#include "button.h"
#include "light.h"
#include "CubeMap.h"

#include "AudioManager.h"

#include "game.h"

class CSceneManager
{
public:
	~CSceneManager();

	static CSceneManager& GetInstance();
	static void DestroyInstance();

	//Initalize any scenes in here
	void Init(GLuint& _program);

	void Render();
	void Process();


protected:
	static CSceneManager* s_pSceneManager;

private:
	CSceneManager();
	CSceneManager(const CSceneManager& _kr) = delete;
	CSceneManager& operator= (const CSceneManager& _kr) = delete;

	//Variables
	GLuint m_program;

	//A map to hold the scenes

	//Global Camera
	CCamera* m_pCamera;

	CObject* mySprite;
	CButton* myButton;
	CLight* myLight;
	CCubeMap* myCubeMap;
};

#endif // !__SCENEMANAGER_H__

