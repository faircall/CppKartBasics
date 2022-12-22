#pragma once
#include <cmath>




struct Vec2
{
    float x, y;

    Vec2() = default;

    Vec2(float a, float b) // todo: could use member initialization syntax here
    {
	x = a;
	y = b;
    }

    float& operator [](int i)
    {
	// (note-cooper):this relies on the fact that x, y are layed out next to each other in memory
	// so we can access it with pointer/array indexing
	return ((&x)[i]);
    }

    const float& operator [](int i) const
    {
	return ((&x)[i]);
    }

    Vec2 operator * (const float s) 
    {
	// scalar multiplication
	return Vec2(this->x * s, this->y * s);
    }

    // (note-cooper) : overloading the * for vectors makes sense either as a dot product (or a bivector in geometric algebra). But NOT the Hadamard product!


    
    Vec2& operator *= (const float s)
    {
	this->x *= s;
	this->y *= s;
	return (*this);
    }

    Vec2& operator /= (float s)
    {
	// possibly raise an exception here instead
	// but not sure if that's desired in a math lib
	const float epsilon = 0.000000001f; // just an arbitrary value for now, should do testing for f.p instability
	if (fabsf(s) < epsilon) {
	    // maybe return a 'special' vector with unlikely values to check against
	    float unlikely = 1337.1337f;
	    this->x = unlikely;
	    this->x = -unlikely;
	    return (*this);
	}
	s = 1.0f / s;
	this->x *= s;
	this->y *= s;
	return (*this);
    }

    const Vec2 operator / (float s) 
    {
	// todo: handle division by zero

	return Vec2(*this) /= s;
    }

    Vec2& operator += (const Vec2& v)
    {
	this->x += v.x;
	this->y += v.y;
	return (*this);
    }

    const Vec2 operator + (const Vec2& v)
    {
	return Vec2(*this) += v;
    }

    Vec2& operator -= (const Vec2& v)
    {
	this->x -= v.x;
	this->y -= v.y;
	return (*this);
    }

    const Vec2 operator - (const Vec2& v)
    {
	return Vec2(*this) -= v;
    }

    const float Mag()
    {
	return sqrt(x*x + y*y);
    }

    const Vec2 Normalize()
    {
	return Vec2(x, y) / this->Mag();
    }

    const void Print()
    {
	std::cout << "vector value is " << this->x << "," << this->y << "\n";
    }
};

inline float degToRad(float deg)
{
    return (deg * M_PI / 180.0f); 
}
