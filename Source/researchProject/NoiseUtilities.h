#pragma once

// System:
#include <random>

// Engine:
#include "CoreMinimal.h"


// Potentially useful macros:
#define PI 3.1415926535f
#define EULERS 2.71828f


// Using the random number generator from CS500. I found its quite robust.
namespace RNG
{
	static std::random_device device;
	static std::mt19937_64 RNGen(device());
	static std::uniform_real_distribution<> myrandom(0.0, 1.0);
	// Call myrandom(RNGen) to get a uniformly distributed random number in [0,1].

	static float randFloat() {
		return static_cast<float>(myrandom(RNGen));
	}
	static double randDouble() {
		return myrandom(RNGen);
	}
};

static float LerpF(const float& a, const float& b, const float& w)
{
	return (a - b) * w + a;
}
static float LerpFClamped(const float& a, const float& b, const float& w)
{
	if (w < 0.0f) return a;
	if (w > 1.0f) return b;
	return (a - b) * w + a;
}

class PerlinNoiseGenerator2D
{
	//private:
		//std::random_device internalRandomizer;

public:
	PerlinNoiseGenerator2D(const float& _seed) : seed{ _seed } {};
	PerlinNoiseGenerator2D() : seed{ RNG::randFloat() } {};
	~PerlinNoiseGenerator2D() {}

	float seed;

	// Get the gradiant vector at an integer coordinate.
	FVector2D GradiantVector(const int& offsetX, const int& offsetY) const
	{
		// TODO: Replace this with something better...
		constexpr int STEP_X = 3278237597329879238;
		constexpr int STEP_Y = 1902841095719686912;

		int x = STEP_X * offsetX;
		int y = STEP_Y * offsetY;

		if (x & 2 == 0) x *= -1;
		if (y & 2 == 0) y *= -1;

		FVector2D result(static_cast<float>(x), static_cast<float>(y));
		result.Normalize();
		return result;
	}

	float Evaluate(const FVector2D& position) const
	{
		const float x = position.X, y = position.Y;
		const float floorxf = std::floorf(x);
		const float flooryf = std::floorf(y);
		const float ceilxf = std::ceilf(x);
		const float ceilyf = std::ceilf(y);
		const int floorx = (int)floorxf;
		const int floory = (int)flooryf;
		const int ceilx = (int)ceilxf;
		const int ceily = (int)ceilyf;

		// Generate the gradiant vectors.
		const FVector2D gradiant1 = GradiantVector(floorx, floory); // Bottom left
		const FVector2D gradiant2 = GradiantVector(ceilx, floory);	// Bottom right
		const FVector2D gradiant3 = GradiantVector(ceilx, ceily);	// Top right
		const FVector2D gradiant4 = GradiantVector(floorx, ceily);	// Top left

		// Offset vectors.
		const FVector2D offset1 = FVector2D(floorxf, flooryf) - position;
		const FVector2D offset2 = FVector2D(ceilxf, flooryf) - position;
		const FVector2D offset3 = FVector2D(ceilxf, ceilyf) - position;
		const FVector2D offset4 = FVector2D(floorxf, ceilyf) - position;

		// Dot products.
		const float dot1 = FVector2D::DotProduct(offset1, gradiant1); // bottom left
		const float dot2 = FVector2D::DotProduct(offset2, gradiant2); // bottom right
		const float dot3 = FVector2D::DotProduct(offset3, gradiant3); // top right
		const float dot4 = FVector2D::DotProduct(offset4, gradiant4); // top left

		const float lerp1 = LerpF(dot1, dot2, offset1.X);
		const float lerp2 = LerpF(dot4, dot3, offset1.X);
		const float lerp3 = LerpF(lerp1, lerp2, offset1.Y);

		return lerp3;
	}
	float Evaluate(const float& x, const float& y) const
	{
		Evaluate(FVector2D(x, y));
	}




};
