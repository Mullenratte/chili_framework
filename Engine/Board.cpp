#include "Board.h"
#include "Graphics.h"
#include <cassert>


Board::Board(Graphics& gfx)
	:
	gfx(gfx)
{
	
}

void Board::DrawCellAtLocation(const Location& location, Color c)
{
	assert(location.x >= 0);
	assert(location.x < width);
	assert(location.y >= 0);
	assert(location.y < height);
	gfx.DrawRectWH(location.x * cellSize, location.y * cellSize, cellSize, cellSize, c);
}

void Board::DrawBorder()
{
	gfx.DrawRect(0, 0, width * Board::cellSize, Board::cellSize, borderColor);
	gfx.DrawRect(0, 0, Board::cellSize, height * Board::cellSize, borderColor);
	gfx.DrawRect(0, height * Board::cellSize, width * Board::cellSize, width * Board::cellSize - Board::cellSize, borderColor);
	gfx.DrawRect(width * Board::cellSize - Board::cellSize, 0, width * Board::cellSize, height * Board::cellSize, borderColor);
}

bool Board::IsInsideBorder(const Location& location) const
{
	return location.x > 0 && location.x < width && location.y > 0 && location.y < height;
}
