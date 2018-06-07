#include "camera.h"

CCamera::CCamera()
{
	m_CamPos = glm::vec3(0.0f, 0.0f, 0.0f);
	m_TargetPos = glm::vec3(0.0f, 0.0f, 0.0f);
	m_View = glm::lookAt(
		glm::vec3(0.0f, 0.0f, 1.8f),
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f));

	GLfloat fWidth = (GLfloat)glutGet(GLUT_WINDOW_WIDTH);
	GLfloat fHeight = (GLfloat)glutGet(GLUT_WINDOW_HEIGHT);
	m_Proj = glm::perspective(45.0f, fWidth / fHeight, 0.1f, 10000.0f);
}

CCamera::~CCamera()
{
}

glm::mat4 CCamera::GetView()
{
	m_View = glm::lookAt(
		m_CamPos,
		m_TargetPos,
		glm::vec3(0.0f, 1.0f, 0.0f));

	return(m_View);
}
