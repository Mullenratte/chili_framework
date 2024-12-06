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

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	rng(rd()),
	audioParam(0.0f, 0.3f),
	paddle(Vec2(400, 720), 40.0f, 5.0f, Colors::White),
	ball(Vec2(450, 750), Vec2(100, 400), Colors::White),
	walls(0.0f, Graphics::ScreenWidth, 0.0f, Graphics::ScreenHeight),
	sound_bounce(L"Sounds\\bounce.wav"),
	sound_hitBrick(L"Sounds\\hitBrick.wav")
{
	for (int y = 0; y < brickRows; y++) {
		Color c = rowColors[y];
		int health = brickRows - y;
		for (int x = 0; x < brickCols; x++) {
			Vec2 test = Vec2(x * brickWidth, y * brickHeight);
			RectF test2 = RectF(brickStartPos + Vec2(x * brickWidth, y * brickHeight), brickWidth, brickHeight);
			bricks[y * brickCols + x] = Brick(RectF(
				brickStartPos + Vec2(x * brickWidth, y * brickHeight), brickWidth, brickHeight),
				health, 
				c);
		}
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
	deltaTime = ft.Mark();

	ball.Update(deltaTime);

	paddle.Update(wnd.kbd, deltaTime);
	paddle.HandleWallCollision(walls);



	// AUDIO & COLLISION
	float randPitch = 0.85f + audioParam(rng);
	if (paddle.HandleBallCollision(ball)) {
		sound_bounce.Play(randPitch + 0.6f, 0.15f);
	}

	for (Brick& brick : bricks) {
		if (brick.HandleBallCollision(ball)) {
			sound_hitBrick.Play(randPitch, 0.1f);
		}
	}


	if (ball.HandleWallCollision(walls)) {
		sound_bounce.Play(randPitch, 0.25f);
	}
}



void Game::ComposeFrame()
{
	paddle.Draw(gfx);
	for (Brick& brick : bricks) {
		brick.Draw(gfx);
	}

	ball.Draw(gfx);
	
}
