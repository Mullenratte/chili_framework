#include "Location.h"
#include "Graphics.h"
#include "Board.h"

#pragma once
class Snake
{
private:
	class Segment {
	public:
		void InitHead(const Location& loc);
		void InitBody();
		void MoveBy(const Location& dir);
		void Follow(const Segment& seg);
		void Draw(Board& board) const;
		Location& GetLocation();

	private:
		Location loc;
		Color c;
	};

public:
	Snake(Graphics& gfx, Board& board, const Location& location);
	void Update();
	void Draw(Board& board) const;
	void Move(const Location& dir);
	void Grow();
	Location& GetHeadLocation();
	bool IsCollidingWithSelf(const Location& target);

private:
	static constexpr int maxSegments = 100;
	Segment segments[maxSegments];
	int activeSegments = 1;
	Graphics& gfx;
	Board& board;
	void CheckForGameOver();
	static constexpr Color headColor = Colors::Cyan;
	static constexpr Color bodyColor = Colors::White;
public:
	bool isDead = false;
};

