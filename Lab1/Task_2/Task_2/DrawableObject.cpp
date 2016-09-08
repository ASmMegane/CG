#include "stdafx.h"
#include "DrawableObject.h"


CDrawableObject::~CDrawableObject()
{
	DeleteList();
}

void CDrawableObject::Draw() const
{
	// ���� ���������� ������ ��� �� ��� ������, �� ��� ������ ������� ���
	if (!m_displayList)
	{
		// ���������� ����� ���������� ������ ��� ������
		m_displayList = glGenLists(1);
		glNewList(m_displayList, GL_COMPILE);
		// ��� ���������� ������ �������� redraw.
		Redraw();
		// ��������� ���������� ������
		glEndList();
	}

	// �������� ����� ��������� ���������� ������
	glCallList(m_displayList);
}

void CDrawableObject::DeleteList() 
{
	if (m_displayList)
	{
		glDeleteLists(m_displayList, 1);
		m_displayList = 0;
	}
}

