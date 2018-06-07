#include "game.h"

CGame* CGame::s_pGame = nullptr;

CGame::CGame()
{

}

CGame& CGame::GetInstance()
{
	if (s_pGame == nullptr)
	{
		s_pGame = new CGame();
	}

	return(*s_pGame);
}

void CGame::DestroyInstance()
{
	delete s_pGame;
	s_pGame = nullptr;
}

void CGame::init(GLuint& _program)
{
	m_program = _program;

	//Places the environment
	/*****************************************************************/
	CObject* gameFloor = new CObject(_program, "Resources/ground.jpg", MESH_CUBE);
	gameFloor->Scale(glm::vec3(50.0f, 0.5f, 50.0f));
	m_vpEnviroment.push_back(gameFloor);

	CObject* gameWall = new CObject(_program, "Resources/wall.jpg", MESH_CUBE);
	gameWall->Scale(glm::vec3(50.0f, 1.0f, 1.0f));
	gameWall->Translate(glm::vec3(0.0f, 1.0f, 49.0f));
	m_vpEnviroment.push_back(gameWall);

	gameWall = new CObject(_program, "Resources/wall.jpg", MESH_CUBE);
	gameWall->Scale(glm::vec3(50.0f, 1.0f, 1.0f));
	gameWall->Translate(glm::vec3(0.0f, 1.0f, -49.0f));
	m_vpEnviroment.push_back(gameWall);

	gameWall = new CObject(_program, "Resources/wall.jpg", MESH_CUBE);
	gameWall->Scale(glm::vec3(1.0f, 1.0f, 50.0f));
	gameWall->Translate(glm::vec3(49.0f, 1.0f, 0.0f));
	m_vpEnviroment.push_back(gameWall);

	gameWall = new CObject(_program, "Resources/wall.jpg", MESH_CUBE);
	gameWall->Scale(glm::vec3(1.0f, 1.0f, 50.0f));
	gameWall->Translate(glm::vec3(-49.0f, 1.0f, 0.0f));
	m_vpEnviroment.push_back(gameWall);

	//CCameraManager::GetInstance().GetCam()->CamTranslate(glm::vec3(0.0f, 100.0f, 40.0f));
	//CCameraManager::GetInstance().GetCam()->CamTarget(glm::vec3(0.0f, 0.0f, 5.0f));

	//Initialises the player
	/*****************************************************************/
	m_Player = new CPlayer(_program);
	m_Player->Scale(glm::vec3(0.5f, 1.0f, 0.5f));
	m_Player->Translate(glm::vec3(0.0f, 2.5f, 0.0f));

	//I'm gonna make the cursor... DISSAPEAR
	/*****************************************************************/
	glutSetCursor(GLUT_CURSOR_NONE);
}

void CGame::Process()
{

	m_Player->process();

	//Camera Placement
	/*****************************************************************/
	glm::vec3 camVec = glm::vec3(glm::cos(-glm::radians(m_Player->GetRot())), -0.7, glm::sin(-glm::radians(m_Player->GetRot() ) ) );
	CCameraManager::GetInstance().GetCam()->CamTarget(m_Player->GetPos());
	CCameraManager::GetInstance().GetCam()->CamTranslate(m_Player->GetPos() + (-camVec * 8.0f));
}

void CGame::Render()
{
	for (int i = 0; i < m_vpEnviroment.size(); i++)
	{
		m_vpEnviroment[i]->Render();
	}
	m_Player->Render();
}

