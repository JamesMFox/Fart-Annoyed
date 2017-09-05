#pragma once

#include "SpriteCodex.h"
#include "RectF.h"
#include "Vec2.h"
#include "Graphics.h"
#include "FrameTimer.h"

class Ball
{
public:
	Ball() = default;
	Ball(const Vec2& pos, const Vec2& vel);
	void DrawBall(Graphics& gfx) const;
	bool doWallCollision(RectF& walls);
	void ReboundX();
	void ReboundY();
	RectF GetRect() const;
	void Update(const float ft);
private:
	static constexpr float radius = 7.0f;
	Vec2 pos;
	Vec2 vel;
};