#pragma once
#include <math.h>
#include <stdio.h>
#include <math.h>
#include <random>
#include <chrono>



#define PI 3.141592653589793

void msg(char* err);

class cmplx {
public:
	double re;
	double im;

	cmplx() { re = im = 0.; }
	cmplx(double x, double y) { re = x; im = y; }
	cmplx& operator = (cmplx&);
	friend cmplx operator * (cmplx& x, cmplx& y);
	friend cmplx operator / (cmplx& x, cmplx& y);
	friend cmplx operator / (cmplx& x, double y);
	friend cmplx operator + (cmplx& x, cmplx& y);
	friend cmplx operator - (cmplx& x, cmplx& y);
};

// ����������� ����������
cmplx conjg(cmplx c);
cmplx conjg(double re, double im);

// �������� ����������� ������ C = A + B
void ADD(long m, long n, cmplx** A, cmplx** B, cmplx** C);
// ��������� ���������� ������� A � B
void ASSIGN(long m, long n, cmplx** A, cmplx** B);

// ���������� ������������������ ������� A[m][m]
int IDENT(long m, long n, cmplx** A);


//========================================================

void fourea(long v_size, cmplx* F, double is)
{
	cmplx  temp, w, c;
	long i, i1, j, j1, istep;
	long m, mmax;
	long n = v_size;
	double fn, r1, theta;
	fn = (double)n;
	double r = PI * is;
	j = 1;
	for (i = 1; i <= n; i++)
	{
		i1 = i - 1;
		if (i < j)
		{
			j1 = j - 1;
			temp = F[j1];
			F[j1] = F[i1];
			F[i1] = temp;
		}
		m = n / 2;
		while (j > m) { j -= m;	m = (m + 1) / 2; }
		j += m;
	}
	mmax = 1;
	while (mmax < n)
	{
		istep = 2 * mmax;
		r1 = r / (double)mmax;
		for (m = 1; m <= mmax; m++)
		{
			theta = r1 * (double)(m - 1);
			w = cmplx(cos(theta), sin(theta));
			for (i = m - 1; i < n; i += istep)
			{
				j = i + mmax;
				c = F[j];
				temp = w * c;
				F[j] = F[i] - temp;
				F[i] = F[i] + temp;
			}
		}
		mmax = istep;
	}
	if (is > 0)  for (i = 0; i < n; i++) { F[i].re /= fn;  F[i].im /= fn; }
	return;
}



//void Fltr(cmplx & A, double porog) //��������� ���������� � ������� ����������� ����� A � �������������� ���������� ��������
//{
//	double ����� = 0;//����� �������������� ��� ������������ ����� ���������� �������� ����������� �����
//	int N = A.size();
//
//	for (int i = 0; i <= N / 2; i++) //���������� ������ �������� ��������� ������ ����������� ����� �����������, �� ������������� ������ ������ ��������.
//	{
//		if (����� <= porog) { //������� �������� ������
//			����� += 2 * std::abs(A[i]);
//		}                                //����� �������, �� ����������� �����, ��������� ���������� �������, ��� ��������� ������ ���������� ��������.
//		else {
//			A[i] = A[N - i - 1] = std::cmplx<double>(0, 0); //��������� ����������� ����� �� ����� ������ ������� � ����
//		}
//	}
//}
// 
// 
//���������� ��������� ��� 
double Shym(double k) {
	unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count(); //�������� ���������� ���������� �������� (seed) �� ������ �������� ������� � ������������. ��� �������� ������������ ��� ������������� ���������� ��������� �����.
	std::default_random_engine e(seed); // ������������� ���������� ��������� ����� (e) � �������������� ����������� seed
	std::normal_distribution <double> distN(-1, 1);//����� ������������ �����, �������������� �� ����������� ������ � ���������� �����������.
	return distN(e) * k; //��������� ���������� ����� �� ����������� �������������, ����������� �� �������� k. �������� k ������ ������������� ��������������� ��� ���������� ���������� ����.
}