// obslyga.cpp: файл реализации
//
//#define _USE_MATH_DEFINES

#include "pch.h"
#include "6zadacha.h"
#include "obslyga.h"
#include <gdiplus.h>
#include <cmath>
using namespace Gdiplus;
// obslyga

IMPLEMENT_DYNAMIC(obslyga, CStatic)

ULONG_PTR token;

obslyga::obslyga()
{
	GdiplusStartupInput inp;
	Status s;
	s = GdiplusStartup(&token, &inp, NULL);
	if(s!=Ok){}
}

obslyga::~obslyga()
{
	GdiplusShutdown(token);
}


BEGIN_MESSAGE_MAP(obslyga, CStatic)
END_MESSAGE_MAP()

// Обработчики сообщений obslyga

void obslyga::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	float shir = lpDrawItemStruct->rcItem.right - lpDrawItemStruct->rcItem.left + 1;
	float vis = lpDrawItemStruct->rcItem.bottom - lpDrawItemStruct->rcItem.top + 1;
	Graphics Gren(lpDrawItemStruct->hDC);
	Bitmap opa(shir, vis, &Gren);
	Graphics Gr(&opa);
	Gr.Clear(Color::Blue);
	Matrix tamtam;
	//peredacha(w1, w2, phasa);
	int otr = 500;
	//float w1=10, w2=3;
	float otn = 4 * M_PI / (w1 - w2);
	
	float ksh = (shir-60) / otn;
	float Kv = (vis-60) / 4;
	tamtam.Translate(30, 30);
	tamtam.Scale(ksh, -Kv);
	tamtam.Translate(0, -2);
	Gr.SetSmoothingMode(SmoothingModeAntiAlias);
	Gr.SetTransform(&tamtam);
	Pen t(Color::Yellow, 0.005);
	Pen k(Color::DarkGray, 0.005);
	FontFamily text(L"Arial");
	Gdiplus::Font font(&text, 10, FontStyleRegular, UnitPixel);
	SolidBrush col(Color::Black);
	float shag = otn / otr;
	for (int i = 0; i < otr; i++) {
		float x1 = i * shag;
		float x2 = x1 + shag;
		float y1 = func( x1);
		float y2 = func( x2);
		Gr.DrawLine(&t, x1, y1, x2, y2);
	}
	int del = 16;
	//int del2 = 10;
	float xex = otn / del;
	float yey = 4.f / del;
	for (int i = 0; i <= del; i++) {
		float xx = i * xex;
		Gr.DrawLine(&k, xx, -2.f, xx, 2.f);
		Gr.ResetTransform();
		PointF p(xx, -2.1);
		tamtam.TransformPoints(&p);
		CString ex;
		ex.Format(L"%.2f", xx);
		Gr.DrawString(ex.GetBuffer(), -1, &font, p, &col);
		Gr.SetTransform(&tamtam);
	}
	for (int i = 0; i <= del; i++) {
		float yy = i * yey-2;
		Gr.DrawLine(&k, 0.f, yy, otn, yy);
		Gr.ResetTransform();
		PointF l(-0.03 * otn, yy);
		tamtam.TransformPoints(&l);
		CString ey;
		ey.Format(L"%.2f", yy);
		Gr.DrawString(ey.GetBuffer(), -1, &font, l, &col);
		Gr.SetTransform(&tamtam);

	}
	Gren.DrawImage(&opa, 0, 0);
	// TODO:  Добавьте исходный код для отображения указанного элемента
}


void obslyga::peredacha(float w1, float w2, float phasa)
{
	this->w1=w1;
	this->w2= w2;
	this->phasa= phasa;
	Invalidate(FALSE);
	//y = cos(w1 * x + phasa) + cos(w2 * x);
	// TODO: Добавьте сюда код реализации.
	
}
float obslyga::func(float x) {
	//peredacha(w1, w2, phasa);
	float y = cos(w1 * x + phasa) + cos(w2 * x);
	return y;

}
