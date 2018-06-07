#include "SceneManager.h"

CSceneManager* CSceneManager::s_pSceneManager = nullptr;

CSceneManager::CSceneManager()
{
}


CSceneManager::~CSceneManager()
{
}

CSceneManager& CSceneManager::GetInstance()
{
	if (s_pSceneManager == nullptr)
	{
		s_pSceneManager = new CSceneManager();
	}

	return(*s_pSceneManager);
}

void CSceneManager::DestroyInstance()
{
	delete s_pSceneManager;
	s_pSceneManager = nullptr;
}

void CSceneManager::Init(GLuint& _program)
{
	m_program = _program;
	m_pCamera = new CCamera();
	myLight = new CLight(m_program);

	myButton = new CButton(m_program);
	myButton->Scale(glm::vec3(0.5f, 0.2f, 0.0f));
	myButton->Translate(glm::vec3(0.0, 0.0, 0.0));

	CGame::GetInstance().init(_program);
}

void CSceneManager::Render()
{
	CGame::GetInstance().Render();
	myLight->Render();
	//myButton->Render();
	//myCubeMap->render();
}

void CSceneManager::Process()
{
	CGame::GetInstance().Process();
	//static bool menuSelection = false;
	//float fMouseCalcX = ((m_pInput->GetMousePos().x / glutGet(GLUT_WINDOW_WIDTH)) * 2) - 1.0f; //This was done under heavy sleep deprivation. I have already confessed my sins
	//float fMouseCalcY = -(((m_pInput->GetMousePos().y / glutGet(GLUT_WINDOW_HEIGHT)) * 2) - 1.0f);

	//if (myButton->CheckCollision(glm::vec2(fMouseCalcX, fMouseCalcY) ) )
	//{
	//	menuSelection = true;
	//}
	//else
	//{
	//	menuSelection = false;
	//}

	//if (menuSelection)
	//{
	//	std::cout << "true" << std::endl;
	//}
}