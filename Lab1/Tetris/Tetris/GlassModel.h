#pragma once
#include <vector>
#include <string>
#include <boost\noncopyable.hpp>
#include "Figure.h"
#include <memory>

class CGlassModel : private boost::noncopyable
{
public:
	CGlassModel();
	~CGlassModel();
	void ClearFullLine();
	void MoveFigure();
	void SetFigure(CFigure* figure);
	bool CanMoveFigure();
private:
	void FillField();
	void ProcessCollisions(glm::ivec2 & newPos, glm::ivec2 const & oldPos );
private:
	std::vector<std::vector<char>> m_field;
	std::vector<std::vector<char>> m_copyField;
	std::vector<char> m_emptyLine;
	CFigure* m_figure = nullptr;
};

