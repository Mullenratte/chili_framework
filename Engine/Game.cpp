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
	xDistrib(50, 750),
	yDistrib(50, 550)
{

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
	if (wnd.kbd.KeyIsPressed('D')) {
	}
	if (wnd.kbd.KeyIsPressed('A')) {
	}
	if (wnd.kbd.KeyIsPressed('S')) {
	}
	if (wnd.kbd.KeyIsPressed('W')) {
	}

	if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
	}
	if (wnd.kbd.KeyIsPressed(VK_UP)) {
		
	}
	if (wnd.kbd.KeyIsPressed('F'))
	{
		// DEBUG HERE
	}
}

void Game::ComposeFrame()
{
	board.DrawBorder(gfx);
	board.DrawRectAtPosition(gfx, {150, 150});
}
