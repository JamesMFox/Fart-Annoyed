#include "Ball.h"

Ball::Ball(const Vec2& pos, const Vec2& vel)
	:
	pos(pos),
	vel(vel)
{}

void Ball::ReboundX()
{
	vel.x *= -1;
}

void Ball::ReboundY()
{
	vel.y *= -1;
}

RectF Ball::GetRect() const
{
	return RectF::FromCenter(pos, radius, radius);
}

void Ball::DrawBall(Graphics& gfx) const
{
	SpriteCodex::DrawBall(pos, gfx);
}

bool Ball::doWallCollision(RectF & walls)
{
	bool collided = false;
	const RectF rect = GetRect();
	if (rect.left < walls.left)
	{
		pos.x += walls.left - rect.left;
		ReboundX();
		collided = true;
	}
	else if (rect.right > walls.right)
		{
		pos.x -= walls.right - rect.right;
			ReboundX();
			collided = true;
		}

	if (rect.top < walls.top)
	{
		pos.y += walls.top - rect.top;
		ReboundY();
		collided = true;
	}
	else if (rect.bottom > walls.bottom)
	{
		pos.y -= rect.bottom - walls.bottom;
		ReboundY();
		collided = true;
	}
	return collided;
}

void Ball::Update(const float dt)
{
	pos += vel*dt;
}
