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
#include <chrono>
#include "RectF.h"
#include "Brick.h"
#include "Ball.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	rng(rd()),
	audioParam(0.0f, 0.3f),
	ball(Vec2(450, 750), Vec2(600, 600), Colors::White),
	walls(0.0f, Graphics::ScreenWidth, 0.0f, Graphics::ScreenHeight),
	sound_bounce(L"Sounds\\bounce.wav")
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
	deltaTime = ft.Mark();


	ball.Update(deltaTime);
	if (ball.HandleWallCollision(walls)) {
		float randPitch = 0.85f + audioParam(rng);
		sound_bounce.Play(randPitch, 0.4f);
	}
}



void Game::ComposeFrame()
{
	Brick brick(RectF(20, 80, 20, 40), Colors::Cyan);
	brick.Draw(gfx);

	ball.Draw(gfx);
	
}
