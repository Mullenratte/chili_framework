#include "Brick.h"




Brick::Brick(const RectF& rect_in, Color c)
	:	
	rect(rect_in),
	color(c)
{
}

void Brick::Draw(Graphics& graphics) const
{
	graphics.DrawRect(rect, color);
}
