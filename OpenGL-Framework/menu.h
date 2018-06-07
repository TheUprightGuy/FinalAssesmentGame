#pragma once
#ifndef __MENU_H__

#include "utils.h"
#include "button.h"
#include <string.h>
#include <map>
class CMenu
{
public:
	CMenu(){}
	~CMenu()
	{
		m_pMenu.empty();
	}

	void AddButton(CButton* m_pButton, std::string _key) { m_pMenu[_key] = m_pButton; }

	std::string GetSelection()
	{
		std::map<std::string, CButton*>::const_iterator it; // declare an iterator
		it = m_pMenu.begin(); // assign it to the start of the vector
		while (it != m_pMenu.end()) // while it hasn't reach the end
		{
			if (it->second->CheckCollision())
			{
				return(it->first);
			}
			it++; // and iterate to the next element
		}
	}
	void Render()
	{
		std::map<std::string, CButton*>::const_iterator it; // declare an iterator
		it = m_pMenu.begin(); // assign it to the start of the vector
		while (it != m_pMenu.end()) // while it hasn't reach the end
		{
			it->second->Render();
			it++; // and iterate to the next element
		}
	}
private:
	std::map<std::string, CButton*> m_pMenu;
};
#endif