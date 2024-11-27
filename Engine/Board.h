#pragma once
#include "Location.h"
#include "Graphics.h"

class Board
{
public:
	Board(Graphics& gfx);
	void DrawCellAtLocation(const Location& location, Color c);
	void DrawBorder();
	bool IsInsideBorder(const Location& location) const;
	static constexpr int width = 25;
	static constexpr int height = 25;
private:
	static constexpr int cellSize = 20;

	Graphics& gfx;
	Color borderColor = Colors::MakeRGB(99, 33, 33);


};

