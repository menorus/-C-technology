#define _USE_MATH_DEFINES
#include <math.h>
#include "math3d.h"
#include <string.h>
using namespace math3d;

math3d::mat4::mat4(float m11, float m12, float m13,
	float m21, float m22, float m23,
	float m31, float m32, float m33,
	float dx, float dy, float dz) {
	reset();
	_matrix[0][0] = m11; _matrix[0][1] = m12; _matrix[0][2] = m13; _matrix[0][3] = 0;
	_matrix[1][0] = m21; _matrix[1][1] = m22; _matrix[1][2] = m23; _matrix[1][3] = 0;
	_matrix[2][0] = m31; _matrix[2][1] = m32; _matrix[2][2] = m33; _matrix[2][3] = 0;
	_matrix[3][0] = dx; _matrix[3][1] = dy; _matrix[3][2] = dz; _matrix[3][3] = 1;
}
mat4& math3d::mat4::operator = (const mat4& right) {
	memcpy(_matrix, right._matrix, sizeof(float) * 16);
	return *this;
}
mat4 math3d::mat4::operator * (const mat4& right) {
	mat4 a;
	for (int i = 0; i < _rank; i++) {
		for (int j = 0; j < _rank; j++) {
			a._matrix[i][j] = 0;
			for (int n = 0; n < _rank; n++) {
				a._matrix[i][j] += _matrix[i][n] * right._matrix[n][j];
			}
		}
	}
	return a;
}
void mat4::reset() {
	for (int i = 0; i < _rank; i++) {
		for (int j = 0; j < _rank; j++) {
			if (i == j) _matrix[i][j] = 1;
			else _matrix[i][j] = 0;
		}
	}
}
mat4& math3d::mat4::rotateX(float angle) {
	float r=angle*M_PI/180;
	
	float cs = cos(r);
	float sn = sin(r);
	mat4 b(1, 0, 0, 0,
		cs, -sn, 0, 0,
		sn, cs, 0, 0);
	*this = *this * b;
	return *this;
}
mat4& math3d::mat4::rotateY(float angle) {
	float r = angle * M_PI / 180;

	float cs = cos(r);
	float sn = sin(r);
	mat4 b(cs, 0, -sn, 
		0,1, 0, 
		sn, 0, cs);
	*this = *this * b;
	return *this;
}
mat4& math3d::mat4::rotateZ(float angle) {
	float r = angle * M_PI / 180;

	float cs = cos(r);
	float sn = sin(r);
	mat4 b(cs, -sn, 0,sn, cs, 0,
		 0, 0,1,
		 0, 0, 0);
	*this = *this * b;
	return *this;
}

mat4& math3d::mat4::translate(float x, float y, float z) {
	mat4 sdvg(1, 0, 0, x, 0, 1, 0, y, 0, 0, 1, z);
	*this = *this * sdvg;
	return *this;
}
mat4& math3d::mat4::scale(float x, float y, float z) {
	mat4 mah(x, 0, 0,
		0, y, 0, 
		0, 0, z);
	*this = *this * mah;
	return *this;
}
mat4& math3d::mat4::perspective(float center) {
	mat4 per(1,0,0,-1/center, 0,1,0,0,0,0,1,0);
	*this = *this * per;
	return *this;
}
math3d::vec4::vec4(float x, float y, float z)
{
	_vector[0] = x;
	_vector[1] = y;
	_vector[2] = z;
	_vector[3] = 1;
}

vec4& math3d::vec4::operator=(const vec4& right)
{
	memcpy(_vector, right._vector, sizeof(float) * 4);
	return *this;
}

vec4 math3d::vec4::operator *(const mat4& right)
{
	vec4 v;

	for (int i = 0; i < _size; i++)
	{
		for (int n = 0; n < _size; n++)
		{
			v._vector[i] += _vector[n] * right._matrix[n][i];
		}
	}

	return v;
}
