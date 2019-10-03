
#include <math.h>
#include <stdlib.h>


#pragma once

#ifdef max
#undef max
#endif

#define check_valid( _v ) 0
#define assert( _exp ) ((void)0)

#define fastsqrt(x)			(sqrt)(x)

#define M_PI		3.14159265358979323846	// matches value in gcc v2 math.h

#define M_PI_F		((float)(M_PI))	// Shouldn't collide with anything.

// NJS: Inlined to prevent floats from being autopromoted to doubles, as with the old system.
#ifndef RAD2DEG
#define rad_2_deg( x  )  ( (float)(x) * (float)(180.f / M_PI_F) )
#endif

#ifndef DEG2RAD
#define deg_2_rad( x  )  ( (float)(x) * (float)(M_PI_F / 180.f) )
#endif

// MOVEMENT INFO
enum
{
	PITCH = 0,	// up / down
	YAW,		// left / right
	ROLL		// fall over
};

// decls for aligning data

#define DECL_ALIGN(x) __attribute__((aligned(x)))


#define ALIGN16 DECL_ALIGN(16)
#define VALVE_RAND_MAX 0x7fff
#define VectorExpand(v) (v).x, (v).y, (v).z

class vec3_t
{
public:
	float x, y, z;
	vec3_t(void);
	vec3_t(float X, float Y, float Z);
	void Init(float ix = 0.0f, float iy = 0.0f, float iz = 0.0f);
	bool IsValid() const;
	float operator[](int i) const;
	float& operator[](int i);
	inline void Zero();
	bool operator==(const vec3_t& v) const;
	bool operator!=(const vec3_t& v) const;
	inline vec3_t& operator+=(const vec3_t& v);
	inline vec3_t& operator-=(const vec3_t& v);
	inline vec3_t& operator*=(const vec3_t& v);
	inline vec3_t& operator*=(float s);
	inline vec3_t& operator/=(const vec3_t& v);
	inline vec3_t& operator/=(float s);
	inline vec3_t& operator+=(float fl);
	inline vec3_t& operator-=(float fl);
	inline float	Length() const;
	inline float LengthSqr(void) const
	{
		check_valid(*this);
		return (x * x + y * y + z * z);
	}
	bool IsZero(float tolerance = 0.01f) const
	{
		return (x > -tolerance && x < tolerance &&
			y > -tolerance && y < tolerance &&
			z > -tolerance && z < tolerance);
	}
	auto Dot(float* other) const -> float
	{
		return x * other[0] + y * other[1] + z * other[2];
	}
	vec3_t	Normalize();
	float	NormalizeInPlace();
	inline float	DistTo(const vec3_t& vOther) const;
	inline float	DistToSqr(const vec3_t& vOther) const;
	float	Dot(const vec3_t& vOther) const;
	float	Length2D(void) const;
	float	Length2DSqr(void) const;
	vec3_t& operator=(const vec3_t& vOther);
	vec3_t	operator-(void) const;
	vec3_t	operator+(const vec3_t& v) const;
	vec3_t	operator-(const vec3_t& v) const;
	vec3_t	operator*(const vec3_t& v) const;
	vec3_t	operator/(const vec3_t& v) const;
	vec3_t	operator*(float fl) const;
	vec3_t	operator/(float fl) const;
	// Base address...
	float* Base();
	float const* Base() const;
};

//===============================================
inline void vec3_t::Init(float ix, float iy, float iz)
{
	x = ix; y = iy; z = iz;
	check_valid(*this);
}
//===============================================
inline vec3_t::vec3_t(float X, float Y, float Z)
{
	x = X; y = Y; z = Z;
	check_valid(*this);
}
//===============================================
inline vec3_t::vec3_t(void) { }
//===============================================
inline void vec3_t::Zero()
{
	x = y = z = 0.0f;
}
//===============================================
inline void VectorClear(vec3_t& a)
{
	a.x = a.y = a.z = 0.0f;
}
//===============================================
inline vec3_t& vec3_t::operator=(const vec3_t& vOther)
{
	check_valid(vOther);
	x = vOther.x; y = vOther.y; z = vOther.z;
	return *this;
}
//===============================================
inline float& vec3_t::operator[](int i)
{
	assert((i >= 0) && (i < 3));
	return ((float*)this)[i];
}
//===============================================
inline float vec3_t::operator[](int i) const
{
	assert((i >= 0) && (i < 3));
	return ((float*)this)[i];
}
//===============================================
inline bool vec3_t::operator==(const vec3_t& src) const
{
	check_valid(src);
	check_valid(*this);
	return (src.x == x) && (src.y == y) && (src.z == z);
}
//===============================================
inline bool vec3_t::operator!=(const vec3_t& src) const
{
	check_valid(src);
	check_valid(*this);
	return (src.x != x) || (src.y != y) || (src.z != z);
}
//===============================================
inline void VectorCopy(const vec3_t& src, vec3_t& dst)
{
	check_valid(src);
	dst.x = src.x;
	dst.y = src.y;
	dst.z = src.z;
}
//===============================================
inline  vec3_t& vec3_t::operator+=(const vec3_t& v)
{
	check_valid(*this);
	check_valid(v);
	x += v.x; y += v.y; z += v.z;
	return *this;
}
//===============================================
inline  vec3_t& vec3_t::operator-=(const vec3_t& v)
{
	check_valid(*this);
	check_valid(v);
	x -= v.x; y -= v.y; z -= v.z;
	return *this;
}
//===============================================
inline  vec3_t& vec3_t::operator*=(float fl)
{
	x *= fl;
	y *= fl;
	z *= fl;
	check_valid(*this);
	return *this;
}
inline vec3_t vec3_t::operator-(void) const
{
	return vec3_t(-x, -y, -z);
}
//===============================================
inline  vec3_t& vec3_t::operator*=(const vec3_t& v)
{
	check_valid(v);
	x *= v.x;
	y *= v.y;
	z *= v.z;
	check_valid(*this);
	return *this;
}
//===============================================
inline vec3_t& vec3_t::operator+=(float fl)
{
	x += fl;
	y += fl;
	z += fl;
	check_valid(*this);
	return *this;
}
//===============================================
inline vec3_t& vec3_t::operator-=(float fl)
{
	x -= fl;
	y -= fl;
	z -= fl;
	check_valid(*this);
	return *this;
}
//===============================================
inline  vec3_t& vec3_t::operator/=(float fl)
{
	assert(fl != 0.0f);
	float oofl = 1.0f / fl;
	x *= oofl;
	y *= oofl;
	z *= oofl;
	check_valid(*this);
	return *this;
}
//===============================================
inline  vec3_t& vec3_t::operator/=(const vec3_t& v)
{
	check_valid(v);
	assert(v.x != 0.0f && v.y != 0.0f && v.z != 0.0f);
	x /= v.x;
	y /= v.y;
	z /= v.z;
	check_valid(*this);
	return *this;
}
//===============================================
inline float vec3_t::Length(void) const
{
	check_valid(*this);

	float root = 0.0f;

	float sqsr = x * x + y * y + z * z;

	root = sqrt(sqsr);

	return root;
}
//===============================================
inline float vec3_t::Length2D(void) const
{
	check_valid(*this);

	float root = 0.0f;

	float sqst = x * x + y * y;

	root = sqrt(sqst);

	return root;
}
//===============================================
inline float vec3_t::Length2DSqr(void) const
{
	return (x * x + y * y);
}
//===============================================
inline vec3_t CrossProduct(const vec3_t& a, const vec3_t& b)
{
	return vec3_t(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}
//===============================================
float vec3_t::DistTo(const vec3_t& vOther) const
{
	vec3_t delta;

	delta.x = x - vOther.x;
	delta.y = y - vOther.y;
	delta.z = z - vOther.z;

	return delta.Length();
}
float vec3_t::DistToSqr(const vec3_t& vOther) const
{
	vec3_t delta;

	delta.x = x - vOther.x;
	delta.y = y - vOther.y;
	delta.z = z - vOther.z;

	return delta.LengthSqr();
}
//===============================================
inline vec3_t vec3_t::Normalize()
{
	vec3_t vector;
	float length = this->Length();

	if (length != 0)
	{
		vector.x = x / length;
		vector.y = y / length;
		vector.z = z / length;
	}
	else
	{
		vector.x = vector.y = 0.0f; vector.z = 1.0f;
	}

	return vector;
}
//===============================================
inline float vec3_t::NormalizeInPlace()
{
	vec3_t& v = *this;

	float iradius = 1.f / (this->Length() + 1.192092896e-07F); //FLT_EPSILON

	v.x *= iradius;
	v.y *= iradius;
	v.z *= iradius;
}
//===============================================
inline float VectorNormalize(vec3_t& v)
{
	assert(v.IsValid());
	float l = v.Length();
	if (l != 0.0f)
	{
		v /= l;
	}
	else
	{
		// FIXME:
		// Just copying the existing implemenation; shouldn't res.z == 0?
		v.x = v.y = 0.0f; v.z = 1.0f;
	}
	return l;
}
//===============================================
inline float VectorNormalize(float* v)
{
	return VectorNormalize(*(reinterpret_cast<vec3_t*>(v)));
}
//===============================================
inline vec3_t vec3_t::operator+(const vec3_t& v) const
{
	vec3_t res;
	res.x = x + v.x;
	res.y = y + v.y;
	res.z = z + v.z;
	return res;
}

//===============================================
inline vec3_t vec3_t::operator-(const vec3_t& v) const
{
	vec3_t res;
	res.x = x - v.x;
	res.y = y - v.y;
	res.z = z - v.z;
	return res;
}
//===============================================
inline vec3_t vec3_t::operator*(float fl) const
{
	vec3_t res;
	res.x = x * fl;
	res.y = y * fl;
	res.z = z * fl;
	return res;
}
//===============================================
inline vec3_t vec3_t::operator*(const vec3_t& v) const
{
	vec3_t res;
	res.x = x * v.x;
	res.y = y * v.y;
	res.z = z * v.z;
	return res;
}
//===============================================
inline vec3_t vec3_t::operator/(float fl) const
{
	vec3_t res;
	res.x = x / fl;
	res.y = y / fl;
	res.z = z / fl;
	return res;
}
//===============================================
inline vec3_t vec3_t::operator/(const vec3_t& v) const
{
	vec3_t res;
	res.x = x / v.x;
	res.y = y / v.y;
	res.z = z / v.z;
	return res;
}
inline float vec3_t::Dot(const vec3_t& vOther) const
{
	const vec3_t& a = *this;

	return(a.x * vOther.x + a.y * vOther.y + a.z * vOther.z);
}

//-----------------------------------------------------------------------------
// length
//-----------------------------------------------------------------------------

inline float VectorLength(const vec3_t& v)
{
	check_valid(v);
	return (float)fastsqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

//VECTOR SUBTRAC
inline void VectorSubtract(const vec3_t& a, const vec3_t& b, vec3_t& c)
{
	check_valid(a);
	check_valid(b);
	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
}

//VECTORADD
inline void VectorAdd(const vec3_t& a, const vec3_t& b, vec3_t& c)
{
	check_valid(a);
	check_valid(b);
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
}

//-----------------------------------------------------------------------------
// Base address...
//-----------------------------------------------------------------------------
inline float* vec3_t::Base()
{
	return (float*)this;
}

inline float const* vec3_t::Base() const
{
	return (float const*)this;
}

inline void VectorMAInline(const float* start, float scale, const float* direction, float* dest)
{
	dest[0] = start[0] + direction[0] * scale;
	dest[1] = start[1] + direction[1] * scale;
	dest[2] = start[2] + direction[2] * scale;
}

inline void VectorMAInline(const vec3_t& start, float scale, const vec3_t& direction, vec3_t& dest)
{
	dest.x = start.x + direction.x * scale;
	dest.y = start.y + direction.y * scale;
	dest.z = start.z + direction.z * scale;
}

inline void VectorMA(const vec3_t& start, float scale, const vec3_t& direction, vec3_t& dest)
{
	VectorMAInline(start, scale, direction, dest);
}

inline void VectorMA(const float* start, float scale, const float* direction, float* dest)
{
	VectorMAInline(start, scale, direction, dest);
}

__declspec(align(16)) class vector_aligned : public vec3_t
{
public:
	inline vector_aligned(void) {};
	inline vector_aligned(float X, float Y, float Z)
	{
		Init(X, Y, Z);
	}

#ifdef VECTOR_NO_SLOW_OPERATIONS

private:
	// No copy constructors allowed if we're in optimal mode
	VectorAligned(const VectorAligned& vOther);
	VectorAligned(const Vector& vOther);

#else
public:
	explicit vector_aligned(const vec3_t& vOther)
	{
		Init(vOther.x, vOther.y, vOther.z);
	}

	vector_aligned& operator=(const vec3_t& vOther)
	{
		Init(vOther.x, vOther.y, vOther.z);
		return *this;
	}

#endif
	float w;	// this space is used anyway
};