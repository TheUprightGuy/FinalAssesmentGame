#include "player.h"


CPlayer::CPlayer(GLuint _program)
	: CObject::CObject(_program, "Resources/Rayman.jpg", MESH_CUBE)
{

}
void CPlayer::init()
{

}

void CPlayer::process()
{

	glm::vec3 PlayerPos = GetPos();

	static float fAccel = 0.4f;

	static bool bTap = false;
	static int iCounter = 0;

	static bool bShoot = false;

	float rads = glm::radians(GetRot());
	if (CInput::GetInstance().GetCurrentState() == INPUT_RELEASE)
	{
		fAccel = 0.4f;
		bTap = false;
		bShoot = false;
	}

	//Moves the player according to its current rotation
	/*****************************************************************/
	if (CInput::GetInstance().GetKeyState('w') == INPUT_HOLD)
	{
		glm::vec3 forwardVec = glm::vec3(glm::cos(-rads), 0.0, glm::sin(-rads)); //I'm gonna be honest, I don't understand why this works, but it does, so I'm happy with it
		PlayerPos = PlayerPos + forwardVec;
	}

	if (CInput::GetInstance().GetKeyState('s') == INPUT_HOLD)
	{
		glm::vec3 backVec = glm::vec3(glm::cos(-rads), 0.0, glm::sin(-rads));
		PlayerPos = PlayerPos - backVec;
	}

	if (CInput::GetInstance().GetKeyState('a') == INPUT_HOLD)
	{
		glm::vec3 leftVec = glm::vec3(glm::cos(-glm::radians(GetRot() - 90)), 0.0, glm::sin(-glm::radians(GetRot() - 90)));
		PlayerPos = PlayerPos - leftVec;
	}

	if (CInput::GetInstance().GetKeyState('d') == INPUT_HOLD)
	{
		glm::vec3 rightVec = glm::vec3(glm::cos(-glm::radians(GetRot() + 90)), 0.0, glm::sin(-glm::radians(GetRot() + 90)));
		PlayerPos = PlayerPos - rightVec;
	}
	if (fAccel < 0.4f)
	{
		fAccel += 0.2f;
	}


	//Locks the mouse To the centre and hides it
	/*****************************************************************/
	//Debug so a key unlocks the mouse
	static bool bLockMouse = true;
	if (CInput::GetInstance().GetKeyState('`') == INPUT_HOLD && bTap == false)
	{
		bLockMouse = !bLockMouse;
		bTap = true;
	}
	if (bLockMouse)
	{
		//Deadzone size is 2
		if (CInput::GetInstance().GetMousePos().x < glutGet(GLUT_WINDOW_WIDTH) / 2 + 2)
		{
			Rotation(GetRot() + 7, glm::vec3(0.0f, 1.0f, 0.0f));
		}
		if (CInput::GetInstance().GetMousePos().x > glutGet(GLUT_WINDOW_WIDTH) / 2 - 2)
		{
			Rotation(GetRot() - 7, glm::vec3(0.0f, 1.0f, 0.0f));
		}

		glutWarpPointer(glutGet(GLUT_WINDOW_WIDTH) / 2, glutGet(GLUT_WINDOW_HEIGHT) / 2);
		glutSetCursor(GLUT_CURSOR_NONE);
	}
	else
	{
		glutSetCursor(GLUT_CURSOR_INHERIT);
	}

	

	/*****************************************************************/

	//Move player
	/*****************************************************************/
	Translate(PlayerPos);

	if (CInput::GetInstance().GetKeyState(' ') == INPUT_HOLD && bShoot == false)
	{
		Shoot();
		bShoot = true;
	}

	for (int i = 0; i < m_pBullets.size(); i++)
	{
		m_pBullets[i]->Process();
	}
}

void CPlayer::Render()
{
	for (int i = 0; i < m_pBullets.size(); i++)
	{
		m_pBullets[i]->Render();
	}
	CObject::Render();
}

void CPlayer::Shoot()
{
	glm::vec3 forwardVec = glm::vec3(glm::cos(-glm::radians(CObject::GetRot())), 0.0, glm::sin(-glm::radians(CObject::GetRot())));
	m_pBullets.push_back(new CBullet(m_program, CObject::GetPos(), forwardVec));
}
