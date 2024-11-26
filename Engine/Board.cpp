#include "Board.h"
#include "Graphics.h"


void Board::DrawRectAtPosition(Graphics& gfx, Location location)
{
	gfx.DrawRectWH(location.x, location.y, Board::gridSize, Board::gridSize, Colors::White);
}

void Board::DrawBorder(Graphics& gfx)
{
	gfx.DrawRect(0, 0, gfx.ScreenWidth, Board::gridSize, borderColor);
	gfx.DrawRect(0, 0, Board::gridSize, gfx.ScreenHeight, borderColor);
	gfx.DrawRect(0, gfx.ScreenHeight, gfx.ScreenWidth, gfx.ScreenHeight - Board::gridSize, borderColor);
	gfx.DrawRect(gfx.ScreenWidth, 0, gfx.ScreenWidth - Board::gridSize, gfx.ScreenHeight, borderColor);
}
