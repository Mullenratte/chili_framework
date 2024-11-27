/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include <random>
#include <iostream>

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	rng(rd()),
	xDistrib(1, 18),
	yDistrib(1, 18),
	board(gfx),
	snake(gfx, board, {4, 4})
{
	appleLoc = { xDistrib(rng), yDistrib(rng) };
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (snake.isDead) {
		isGameOver = true;
	}
	if (!isGameOver) {
		if (wnd.kbd.KeyIsPressed('D') && !xLocked) {
			moveDir = { 1, 0 };
			xLocked = true;
			yLocked = false;
		}
		if (wnd.kbd.KeyIsPressed('A') && !xLocked) {
			moveDir = { -1, 0 };
			xLocked = true;
			yLocked = false;
		}
		if (wnd.kbd.KeyIsPressed('S') && !yLocked) {
			moveDir = { 0, 1 };
			xLocked = false;
			yLocked = true;
		}
		if (wnd.kbd.KeyIsPressed('W') && !yLocked) {
			moveDir = { 0, -1 };
			xLocked = false;
			yLocked = true;
		}

		snakeMoveCounter++;
		if (snakeMoveCounter >= snakeMoveFrame) {
			snakeMoveCounter = 0;
			if (snake.GetHeadLocation() == appleLoc) {
				snake.Grow();
				RandomizeAppleLocation();
			}
			snake.Move(moveDir);
		}

		
		

		snake.Update();
	}
	else {
		// Draw Game Over Screen
		for (int y = 0; y <= currentGameOverPixel.y; y++) {
			for (int x = 0; x <= currentGameOverPixel.x; x++) {
				board.DrawCellAtLocation({ x, y }, Colors::Red);
			}
		}

		drawGameOverCounter++;
		if (drawGameOverCounter >= drawGameOverFrame) {
			drawGameOverCounter = 0;
			if (currentGameOverPixel.x < board.width - 1|| currentGameOverPixel.y < board.height - 1) {
				if (currentGameOverPixel.x < board.width - 1) {
					currentGameOverPixel.x += 1;
				}
				else {
					currentGameOverPixel.y += 1;
				}
			}
		}
	}

}



void Game::ComposeFrame()
{
	if (!isGameOver) {
		board.DrawBorder();

		board.DrawCellAtLocation(appleLoc, Colors::Red);

		snake.Draw(board);

		
	}

}

void Game::RandomizeAppleLocation()
{
	appleLoc = { xDistrib(rng), yDistrib(rng) };
}
