#pragma once
#include<vector>

using namespace std;

class ScreenRect
{
public:
	ScreenRect(void);
	~ScreenRect(void);

	//m:x轴方向的矩形个数
	//n:y轴方向的矩形个数
	//rect:窗口矩形
	//line_offset:分割线宽度
	//type：0为有外边框，1为无外边框，2未无分割线
	void ScreenInit(int m, int n, CRect screenRect, int line_offset = 2, int type = 0);

	//获取指定矩形 (0~m-1, 0~n-1)
	CRect GetCRect(int x, int y);

	//获取控件布局矩形
	CRect GetCRect(int x, int y, int x1, int y1);
private:
	//小矩形二维数组 vector外为列
	vector< vector<CRect> > m_rectVector;
};

