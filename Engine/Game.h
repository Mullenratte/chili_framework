/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include <random>

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include <random>
#include "Brick.h"
#include "Ball.h"
#include "FrameTimer.h"
#include "Sound.h"
#include "Paddle.h"
#include "Keyboard.h"
#include "RectF.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();

private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	FrameTimer ft;

	std::random_device rd;
	std::mt19937 rng;
	std::uniform_real_distribution<float> audioParam;
	float deltaTime;

	Paddle paddle;
	Ball ball;
	RectF walls;

	Vec2 brickStartPos = { 150, 150 };
	static constexpr int brickRows = 4;
	static constexpr int brickCols = 8;
	static constexpr int totalBricks = brickRows * brickCols;
	static constexpr float brickWidth = 35;
	static constexpr float brickHeight = 20;
	Color rowColors[brickRows] = { Colors::Blue, Colors::Cyan, Colors::Gray, Colors::LightGray };
	Brick bricks[totalBricks];


	Sound sound_bounce;
	Sound sound_hitBrick;

	/********************************/
};