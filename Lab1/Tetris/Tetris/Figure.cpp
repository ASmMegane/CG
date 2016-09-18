#include "Figure.h"
#include <algorithm>


CFigure::CFigure(Forms const & forms)
	: m_forms(forms)
{
	MakeCurrentForm();
	CalculateSize();
}

CFigure::~CFigure()
{
}

void CFigure::SetTypeMove(TypeMove::Direction const & type)
{
	m_type = type;
}

TypeMove::Direction CFigure::GetTypeMove() const
{
	return m_type;
}

void CFigure::Rotate()
{
	m_forms.push_back(m_currentForm);
	MakeCurrentForm();
	CalculateSize();
}

void CFigure::SetPosition(glm::vec2 const & pos)
{
	m_pos = pos;
}

glm::vec2 CFigure::GetPosition() const
{
	return m_pos;
}

glm::vec2 CFigure::GetSize() const
{
	return glm::vec2(m_width, m_height);
}

void CFigure::CalculateSize()
{
	m_height = m_currentForm.size();
	for (auto const & line : m_currentForm)
	{
		m_width = std::max(m_width, line.size());
	}
}

void CFigure::MakeCurrentForm()
{
	m_currentForm = m_forms.front();
	m_forms.erase(m_forms.begin(), ++m_forms.begin());
}