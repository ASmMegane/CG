#pragma once
#include "Tetris.h"
#include "TetrisController.h"

class CGameSystem
{
public:
	CGameSystem();
	~CGameSystem();

	void Update(float deltaSeconds);
	bool OnKeyDown(const SDL_KeyboardEvent & event);
	bool OnKeyUp(const SDL_KeyboardEvent & event);
	void Draw() const;
private:
	CTetris m_tetris;
	std::unique_ptr<CTetrisController> m_control = nullptr;
};

