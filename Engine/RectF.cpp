#include "RectF.h"

RectF::RectF(float left_in, float top_in, float right_in, float bottom_in)
	:
	top(top_in),
	bottom(bottom_in),
	left(left_in),
	right(right_in)
{}
bool RectF::IsOverlappingWith(const RectF & other) const
{
	if (left <= other.right &&
		right >= other.left &&
		top >= other.bottom &&
		bottom <= other.top)
	{
		return true;
	}
	return false;
}