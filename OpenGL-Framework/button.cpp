#include "button.h"
#include <iostream>

CButton::CButton(GLuint _program, std::string _ButtonTexture)
	:CObject::CObject(_program, _ButtonTexture, MESH_2D_SPRITE)
{
	m_program = _program;
	CObject::SetUI(true);
}



void CButton::Render()
{
	CObject::Render();
}

bool CButton::CheckCollision()
{
	glm::vec3 objPos = GetPos();
	glm::vec3 objScale = GetScale();

	float fMouseCalcX = ((CInput::GetInstance().GetMousePos().x / glutGet(GLUT_WINDOW_WIDTH)) * 2) - 1.0f; //This was done under heavy sleep deprivation. I have already confessed my sins
	float fMouseCalcY = -(((CInput::GetInstance().GetMousePos().y / glutGet(GLUT_WINDOW_HEIGHT)) * 2) - 1.0f);

	glm::vec2 mouseCoords = glm::vec2(fMouseCalcX, fMouseCalcY);
	//std::cout << mouseCoords.x << " , " << mouseCoords.y << " || " << objPos.x << " , " << objPos.y << std::endl;
	if ((mouseCoords.x > (objPos.x - objScale.x)) && (mouseCoords.x < (objPos.x + objScale.x)) &&
		(mouseCoords.y >(objPos.y - objScale.y)) && (mouseCoords.y < (objPos.y + objScale.y) ) )
	{
		return true;
	}
	else
	{
		return false;
	}
}
