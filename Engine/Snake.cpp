#include "Snake.h"
#include "Game.h"
#include "Board.h"
#include "Graphics.h"
#include <assert.h>


Snake::Snake(Graphics& gfx, Board& board, const Location& location)
	:
	gfx(gfx),
	board(board),
	segments()
{
	segments[0].InitHead(location);
}

void Snake::Update()
{
	CheckForGameOver();
}

void Snake::Draw(Board& board) const
{
	for (int i = 0; i < activeSegments; i++) {
		Segment seg = segments[i];
		seg.Draw(board);
	}
	
	
}

void Snake::Move(const Location& dir)
{
	for (int i = activeSegments - 1; i > 0; i--) {
		Segment& seg = segments[i];
		seg.Follow(segments[i-1]);
	}
	segments[0].MoveBy(dir);
}

void Snake::Grow()
{
	if (activeSegments < maxSegments) {
		segments[activeSegments].InitBody();
		activeSegments++;
	}
	
}

Location& Snake::GetHeadLocation()
{
	return segments[0].GetLocation();
}

bool Snake::IsCollidingWithSelf(const Location& target)
{
	for (int i = 1; i < activeSegments; i++) {
		if (segments[i].GetLocation() == target) {
			return true;
		}
	}
	return false;
}

void Snake::CheckForGameOver()
{
	if (!board.IsInsideBorder(GetHeadLocation()) || IsCollidingWithSelf(GetHeadLocation())) {
		isDead = true;
	}

}

void Snake::Segment::InitHead(const Location& in_loc)
{
	loc = in_loc;
	c = Snake::headColor;
}

void Snake::Segment::InitBody()
{
	c = Snake::bodyColor;
}

void Snake::Segment::MoveBy(const Location& dir)
{
	assert(abs(dir.x) + abs(dir.y) == 1);
	loc.Add(dir);
}

void Snake::Segment::Follow(const Segment& seg)
{
	loc = seg.loc;
}

void Snake::Segment::Draw(Board& board) const
{
	board.DrawCellAtLocation(loc, c);
}

Location& Snake::Segment::GetLocation()
{
	return loc;
}
