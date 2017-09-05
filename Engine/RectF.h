#pragma once

#include "Vec2.h"

class RectF
{
public:
	RectF() = default;
	RectF(float left_in, float top_in, float right_in, float bottom_in);
	RectF(Vec2& topleft, Vec2& bottomright)
	{
		RectF(topleft.x, topleft.y, bottomright.x, bottomright.y);
	};
	RectF(Vec2& topleft, float width, float height)
	{
		RectF(Vec2(topleft.x, topleft.y), Vec2(topleft.x + width, topleft.y + height));
	};
	bool IsOverlappingWith(const RectF& other) const;

public:
	float top;
	float bottom;
	float left;
	float right;
};