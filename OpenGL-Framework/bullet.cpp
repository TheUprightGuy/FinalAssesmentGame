#include "bullet.h"

CBullet::CBullet(GLuint _program, glm::vec3 _placement, glm::vec3 _direction)
	: CObject::CObject(_program, "Resources/Rayman.jpg", MESH_SPHERE),
	m_direction(_direction)
{
	CObject::Scale(glm::vec3(0.5, 0.5, 0.5));
	CObject::Translate(_placement);
}

void CBullet::Process()
{
	CObject::Translate(CObject::GetPos() + m_direction);
}
