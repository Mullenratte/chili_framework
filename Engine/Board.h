#pragma once
#include "Location.h"
#include "Graphics.h"

class Board
{
private:
	static constexpr int gridSize = 25;
	Color borderColor = Colors::MakeRGB(99, 33, 33);

public:
	void DrawRectAtPosition(Graphics& gfx, Location location);
	void DrawBorder(Graphics& gfx);
};

