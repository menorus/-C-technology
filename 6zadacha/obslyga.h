#pragma once


// obslyga

class obslyga : public CStatic
{
	DECLARE_DYNAMIC(obslyga)

public:
	obslyga();
	virtual ~obslyga();

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
	float func(float x);
	void peredacha(float w1, float w2, float phasa);
	float w1;
	float w2;
	float phasa;
};


