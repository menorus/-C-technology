#include "MyForm.h"
#include "Math.h"
#include <cmath>
#include "cmplx.h"
#include <iostream>
#include <vector>


#define _USE_MATH_DEFINES

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Project3::MyForm form;
	Application::Run(% form);
}

void msg(char* err)
{
	FILE* fp = fopen("report.msg", "at");
	fprintf(fp, "%s\n\n", err);
	fclose(fp);
}
//----------------------------------------------------------------
cmplx operator * (cmplx& x, cmplx& y)
{
	cmplx z;
	z.re = x.re * y.re - x.im * y.im;
	z.im = x.re * y.im + y.re * x.im;
	return z;
}

//----------------------------------------------------------------
cmplx operator / (cmplx& x, cmplx& y)
{
	cmplx z;
	double y2 = y.re * y.re + y.im * y.im;
	if (y2 < 10e-40)  return z;
	z.re = (x.re * y.re + x.im * y.im) / y2;
	z.im = (y.re * x.im - x.re * y.im) / y2;
	return z;
}

cmplx operator / (cmplx& x, double y)
{
	cmplx z;
	if (y < 10e-40)  return z;
	z.re = x.re / y;
	z.im = x.im / y;
	return z;
}

cmplx operator + (cmplx& x, cmplx& y)
{
	cmplx z;
	z.re = x.re + y.re;
	z.im = x.im + y.im;
	return z;
}

cmplx operator - (cmplx& x, cmplx& y)
{
	cmplx z;
	z.re = x.re - y.re;
	z.im = x.im - y.im;
	return z;
}

cmplx& cmplx::operator = (cmplx& c)
{
	re = c.re;
	im = c.im;
	return *this;
}

// комплексное сопряжение
cmplx conjg(cmplx c) { return cmplx(c.re, -c.im); }
cmplx conjg(double re, double im) { return cmplx(re, -im); }

// сложение комплексных матриц C = A + B
void ADD(long m, long n, cmplx** A, cmplx** B, cmplx** C)
{
	for (long i = 0; i < n; i++)
		for (long j = 0; j < m; j++)
			C[j][i] = A[j][i] + B[j][i];
}

// переносит содержимое матрицы A в B
void ASSIGN(long m, long n, cmplx** A, cmplx** B)
{
	for (long j = 0; j < m; j++)  for (long i = 0; j < n; i++)  B[j][i] + A[j][i];
}

// возвращает идентифицированную матрицу A[m][m]
int IDENT(long m, long n, cmplx** A)
{
	if (m != n)  return -1;

	for (long j = 0; j < m; j++)
		for (long i = 0; i < n; i++)
			if (i == j) A[j][i] = cmplx(1., 0.);  else A[j][i] = cmplx(0., 0.);
	return 0;
}

//-------------------------- Быстрое фурье преобразование   is=  -1 -prjamoe  +1 -obratnoe
//void fourea(long v_size, cmplx* F, double is)
//{
//	cmplx  temp, w, c;
//	long i, i1, j, j1, istep;
//	long m, mmax;
//	long n = v_size;
//	double fn, r1, theta;
//	fn = (double)n;
//	double r = PI * is;
//	j = 1;
//	for (i = 1; i <= n; i++)
//	{
//		i1 = i - 1;
//		if (i < j)
//		{
//			j1 = j - 1;
//			temp = F[j1];
//			F[j1] = F[i1];
//			F[i1] = temp;
//		}
//		m = n / 2;
//		while (j > m) { j -= m;	m = (m + 1) / 2; }
//		j += m;
//	}
//	mmax = 1;
//	while (mmax < n)
//	{
//		istep = 2 * mmax;
//		r1 = r / (double)mmax;
//		for (m = 1; m <= mmax; m++)
//		{
//			theta = r1 * (double)(m - 1);
//			w = cmplx(cos(theta), sin(theta));
//			for (i = m - 1; i < n; i += istep)
//			{
//				j = i + mmax;
//				c = F[j];
//				temp = w * c;
//				F[j] = F[i] - temp;
//				F[i] = F[i] + temp;
//			}
//		}
//		mmax = istep;
//	}
//	if (is > 0)  for (i = 0; i < n; i++) { F[i].re /= fn;  F[i].im /= fn; }
//	return;
//}


void Project3::MyForm::DefaultParams()
{
	A1 = 3;
	textBox_a1->Text = Convert::ToString(A1);
	A2 = 5;
	textBox_a2->Text = Convert::ToString(A2);
	A3 = 10;
	textBox_a3->Text = Convert::ToString(A3);
	F1 = 5;
	textBox_f1->Text = Convert::ToString(F1);
	F2 = 10;
	textBox_f2->Text = Convert::ToString(F2);
	F3 = 3;
	textBox_f3->Text = Convert::ToString(F3);
	Y1 = 0;
	textBox_y1->Text = Convert::ToString(Y1);
	Y2 = 3;
	textBox_y2->Text = Convert::ToString(Y2);
	Y3 = 0;
	textBox_y3->Text = Convert::ToString(Y3);
}

System::Void Project3::MyForm::start_butt_Click(System::Object^ sender, System::EventArgs^ e)
{

	String^ a1 = textBox_a1->Text;
	String^ a2 = textBox_a2->Text;
	String^ a3 = textBox_a3->Text;
	String^ f1 = textBox_f1->Text;
	String^ f2 = textBox_f2->Text;
	String^ f3 = textBox_f3->Text;
	String^ y1 = textBox_y1->Text;
	String^ y2 = textBox_y2->Text;
	String^ y3 = textBox_y3->Text;
	String^ fd = textBox_fd->Text;
	String^ n = textBox_n->Text;
	String^ fii = textBox1->Text;

	//String^ xx = textBox1->Text;
	//String^ yy = textBox2->Text;

	double A1 = Double::Parse(a1);
	double A2 = Double::Parse(a2);
	double A3 = Double::Parse(a3);
	double F1 = Double::Parse(f1);
	double F2 = Double::Parse(f2);
	double F3 = Double::Parse(f3);
	double Y1 = Double::Parse(y1);
	double Y2 = Double::Parse(y2);
	double Y3 = Double::Parse(y3);
	double Fd = Double::Parse(fd);
	double N = Double::Parse(n);
	double FI = Double::Parse(fii);

	double XX = N / Fd;
	double YY = A1 + A2 + A3 + 1;
	double YYY = 0 - YY;



	this->chart1->Series[0]->Points->Clear();
	this->chart2->Series[0]->Points->Clear();
	this->chart2->Series[1]->Points->Clear();
	this->chart3->Series[0]->Points->Clear();
	this->chart3->Series[1]->Points->Clear();

	this->chart1->ChartAreas[0]->AxisX->Maximum = XX;
	this->chart1->ChartAreas[0]->AxisY->Maximum = YY;
	this->chart1->ChartAreas[0]->AxisX->Minimum = 0;
	this->chart1->ChartAreas[0]->AxisY->Minimum = YYY;

	//this->chart2->ChartAreas[0]->AxisX->Maximum = XX;
	//this->chart2->ChartAreas[0]->AxisY->Maximum = YY;
	//this->chart2->ChartAreas[0]->AxisX->Minimum = 0;
	//this->chart2->ChartAreas[0]->AxisY->Minimum = -1;

	std::vector<double> clear; //вектор сигнала
	clear.resize(N);
	std::vector<double> noise; //вектор шума
	noise.resize(N);
	std::vector<double> no_noise; //вектор восстановленный
	clear.resize(N);
	
	double Es = 0; //энергии
	double En = 0;

	for (int i = 0; i < N; i++)
	{
		double t = (1 / Fd) * i;
		clear[i] = A1 * sin(2 * 3.14159265358979323846 * F1 * t + Y1) + A2 * sin(2 * 3.14159265358979323846 * F2 * t + Y2) + A3 * sin(2 * 3.14159265358979323846 * F3 * t + Y3);
		Es += std::abs(clear[i]) * std::abs(clear[i]);
		this->chart3->Series[0]->Points->AddXY(t, clear[i]); //исходный
	};

	double B = sqrt((FI * Es) / En);

	cmplx* F = new cmplx[N];
	cmplx* FS = new cmplx[N];
	for (int i = 0; i < N; i++) {
		F[i] = cmplx(clear[i], 0);
		FS[i] = F[i];
	}

	fourea(N, F, -1);
	for (int i = 0; i < N; i++) {
		double mod = sqrt((F[i].re * F[i].re) * (F[i].im * F[i].im));
		double fi = (i * Fd) / N;
		this->chart2->Series[0]->Points->AddXY(fi, mod); //спектр без шума
	}


	for (int i = 0; i < N; i++)
	{
		FS[i] = FS[i] + cmplx(Shym(B), 0); // Shym - шум (не работает)
		this->chart1->Series[0]->Points->AddXY(i, FS[i].re); //с шумом
	}

	fourea(N, FS, -1); 
	for (int i = 0; i < N; i++) {
		double mod = sqrt((FS[i].re * FS[i].re) * (FS[i].im * FS[i].im));
		double fi = (i * Fd) / N;
		this->chart2->Series[1]->Points->AddXY(fi, mod); //спектр c шумом
	}



	double porog = Es * FI; //порог

	double P = 0;//будет использоваться для отслеживания суммы абсолютных значений комплексных чисел
	int G = sizeof(F);

	for (int i = 0; i <= N / 2; i++) //перебирает первую половину - вектор комплексных чисел симметричен
	{
		if (P <= porog) { //Условие проверки порога
			P += 2 * sqrt((F[i].re * F[i].re) * (F[i].im * F[i].im));
		}                                //Таким образом, мы увеличиваем порог, пропуская компоненты сигнала, чьи амплитуды меньше порогового значения.
		else {
			F[i] = F[G - i - 1] = cmplx(0, 0); //Установка комплексных чисел на обоих концах вектора в нули
		}
	}

	//for (int i = 0; i < N; i++)
	//{
	//	clear[i] = sqrt(F[i].re * F[i].re + F[i].im * F[i].im);
	//}

	//Filtr(F, porog);
	//for (int i = 0; i < N; i++)
	//{
	//	S = sqrt(Data[i].real() * Data[i].real() + Data[i].imag() * Data[i].imag());
	//	this->chart3->Series[1]->Points->AddXY(i, S);
	//}

	fourea(N, F, -1);// Обработка данных после обратного БПФ
	for (int i = 0; i < N; i++)
	{
		t = double(i) / Fd;
		this->chart3->Series[1]->Points->AddXY(t, F[i].re); //восстановленныый
	}

}



