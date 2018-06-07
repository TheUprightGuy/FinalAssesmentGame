#pragma once
#ifndef __BUTTON_H__

#include <string.h>

#include "utils.h"
#include "object.h"
#include "TextLabel.h"
#include "input.h"

//okay okay, I know your gonna read this eventually callan, but the textlabel positioning function is retarded. Hence why it's not being used here
class CButton : public CObject
{
public:
	CButton(GLuint _program, std::string _ButtonTexture = "Resources/defaultbutton.png");
	~CButton() {}

	void Render();
	bool CheckCollision();
private:
};

#endif // !__BUTTON_H__
