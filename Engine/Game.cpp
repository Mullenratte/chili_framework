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
	player.x = Graphics::ScreenWidth / 2;
	player.y = Graphics::ScreenHeight / 2;
	player.moveSpeed = 3;
	std::uniform_int_distribution<int> vDistrib(-2, 2);
	
	for (Enemy& enemy : enemies)
	{
		int x = xDistrib(rng);
		int y = yDistrib(rng);
		int vX = vDistrib(rng);
		int vY = vDistrib(rng);
		enemy.Init(x, y, vX, vY);
	}
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
		player.x += player.moveSpeed;
	}
	if (wnd.kbd.KeyIsPressed('A')) {
		player.x -= player.moveSpeed;
	}
	if (wnd.kbd.KeyIsPressed('S')) {
		player.y += player.moveSpeed;
	}
	if (wnd.kbd.KeyIsPressed('W')) {
		player.y -= player.moveSpeed;
	}

	if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
		++rectx0;
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
		--rectx0;
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
		++recty0;
	}
	if (wnd.kbd.KeyIsPressed(VK_UP)) {
		--recty0;
	}
	if (wnd.kbd.KeyIsPressed('F'))
	{
		// DEBUG HERE
	}

	if (wnd.mouse.LeftIsPressed()) {
		rectx1 = wnd.mouse.GetPosX();
		recty1 = wnd.mouse.GetPosY();
	}

	player.Update(); 

	for (Enemy& enemy : enemies)
	{
		enemy.Update();
		enemy.ProcessHit(player.x, player.y, Player::width, Player::height);
	}
}

void Game::ComposeFrame()
{
	for (Enemy& enemy : enemies)
	{
		enemy.Draw(gfx);
	}

	gfx.DrawRect(rectx0, recty0, rectx1, recty1, Colors::Cyan);

	DrawPlayer(player.x, player.y, Player::width, Player::height);
}

void Game::DrawPlayer(int x, int y, int width, int height) {
	for (int j = y; j < y + height; j++) {
		for (int i = x; i < x + width; i++) {
			gfx.PutPixel(i, j, Colors::Green);
		}
	}
}
