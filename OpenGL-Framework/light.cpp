#include "light.h"

CLight::CLight(GLuint& _program)
{
	m_program = _program;
	m_lightColor = glm::vec3(1.0f, 1.0f, 1.0f);
	m_lightPos = glm::vec3(5.0f, 50.0f, 0.0f);
	m_ambientColor = glm::vec3(1.0f, 1.0f, 1.0f);

	m_ambientStrength = 0.01f;
	m_lightSpecStr = 0.5f;
	m_shininess = 30.0f;
}

void CLight::Render()
{
	glUniform3fv(glGetUniformLocation(m_program, "lightColor"), 1, glm::value_ptr(m_lightColor));
	glUniform3fv(glGetUniformLocation(m_program, "lightPos"), 1, glm::value_ptr(m_lightPos));
	glUniform3fv(glGetUniformLocation(m_program, "camPos"), 1, glm::value_ptr(CCameraManager::GetInstance().GetCam()->GetCamPos() ) );
	glUniform3fv(glGetUniformLocation(m_program, "ambientColor"), 1, glm::value_ptr(m_ambientColor));
	
	glUniform1f(glGetUniformLocation(m_program, "ambientStr"), m_ambientStrength);
	glUniform1f(glGetUniformLocation(m_program, "lightSpecStr"), m_lightSpecStr);
	glUniform1f(glGetUniformLocation(m_program, "shininess"), m_shininess);
}
