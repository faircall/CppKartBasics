#pragma once
#include <cmath>


using namespace std;

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

    Vec2 operator / (float s) 
    {
	// todo: handle division by zero
	s = 1.0f / s; // (note-cooper) : multiplication is faster than division so we take an inverse here
	return Vec2(this->x * s, this->y * s);
    }
    
    Vec2& operator *= (const float s)
    {
	this->x *= s;
	this->y *= s;
	return (*this);
    }

    Vec2& operator /= (float s)
    {
	s = 1.0f / s;
	this->x *= s;
	this->y *= s;
	return (*this);
    }

    Vec2& operator += (const Vec2& v)
    {
	this->x += v.x;
	this->y += v.y;
	return (*this);
    }

    Vec2& operator -= (const Vec2& v)
    {
	this->x -= v.x;
	this->y -= v.y;
	return (*this);
    }

    float Mag()
    {
	return sqrt(x*x + y*y);
    }

    Vec2 Normalize()
    {
	return Vec2(x, y) / this->Mag();
    }

    void Print()
    {
	cout << "vector value is " << this->x << "," << this->y << endl;
    }
};

inline Vec2 operator + (const Vec2& u, const Vec2& v)
{
    return Vec2(u.x + v.x, u.y + v.y);
}

inline Vec2 operator - (const Vec2& u, const Vec2& v)
{
    return Vec2(u.x - v.x, u.y - v.y);
}

inline float degToRad(float deg)
{
    return (deg * M_PI / 180.0f); 
}
