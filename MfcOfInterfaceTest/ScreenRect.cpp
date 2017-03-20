#include "StdAfx.h"
#include "ScreenRect.h"


ScreenRect::ScreenRect(void)
{

}


ScreenRect::~ScreenRect(void)
{

}


void ScreenRect::ScreenInit(int m, int n, CRect screenRect, int line_offset, int type)
{
	vector<vector <CRect> > ivec(m ,vector<CRect>(n, new CRect(0,0,0,0)));    //m*n的二维vector，所有元素为0
	m_rectVector = ivec;

	switch(type){
		//0为有外边框
	case 0:
		{
			//小矩形总和
			int rect_sum_w = screenRect.Width()-line_offset*(m+1);
			int rect_sum_h = screenRect.Height()-line_offset*(n+1);

			//小矩形宽长
			int rect_w = rect_sum_w/m;
			int rect_h = rect_sum_h/n;

			//宽长余数
			int line_w = rect_sum_w%m;
			int line_h = rect_sum_h%n;

			int col = 0 ,row = 0;                //加到间隔中置1
			for(int i=0; i<m; i++)
			{
				if(col != line_h) col++;
				row = 1;
				for(int j=0; j<n; j++)
				{
					if(row != line_w) row++;
					m_rectVector[i][j] = new CRect(
						line_offset*(j+1)+j*rect_w +row,
						line_offset*(i+1)+i*rect_h + col,
						line_offset*(j+1)+(j+1)*rect_w +row,
						line_offset*(i+1)+(i+1)*rect_h + col);
				}
			}
		}
		break;
		//1为无外边框
	case 1:
		{
			//小矩形总和
			int rect_sum_w = screenRect.Width()-line_offset*(m-1);
			int rect_sum_h = screenRect.Height()-line_offset*(n-1);

			//小矩形宽长
			int rect_w = rect_sum_w/m;
			int rect_h = rect_sum_h/n;

			//宽长余数
			int line_w = rect_sum_w%m;
			int line_h = rect_sum_h%n;

			int line = 0 ,row = 0;                //加到间隔中置1
			for(int i=0; i<m; i++)
			{
				if(line != line_h) line++;
				row = 1;
				for(int j=0; j<n; j++)
				{
					if(row != line_w) row++;
					m_rectVector[i][j] = new CRect(
						line_offset*(j)+j*rect_w +row,
						line_offset*(i)+i*rect_h + line,
						line_offset*(j)+(j+1)*rect_w + row,
						line_offset*(i)+(i+1)*rect_h + line);
				}
			}
		}
		break;
		//2未无分割线
	case 2:
		{
			//小矩形总和
			int rect_sum_w = screenRect.Width();
			int rect_sum_h = screenRect.Height();

			//小矩形宽长
			int rect_w = rect_sum_w/m;
			int rect_h = rect_sum_h/n;

			//宽长余数
			int line_w = rect_sum_w%m;
			int line_h = rect_sum_h%n;

			int col = 0 ,row = 0;                //加到间隔中置1
			for(int i=0; i<m; i++)
			{
				for(int j=0; j<n; j++)
				{				
					m_rectVector[i][j] = new CRect(
						j*rect_w + row,
						i*rect_h + col,
						(j+1)*rect_w + 1 + row,
						(i+1)*rect_h + 1 + col);
					if(row != line_w) row++;
				}
				if(col != line_h) col++;
				row = 0;
			}
		}
		break;
	}
}

//获取指定矩形
CRect ScreenRect::GetCRect(int x, int y)
{	
	return m_rectVector[x][y];
}

//获取控件布局矩形
CRect ScreenRect::GetCRect(int x, int y, int x1, int y1)
{
	CRect rect(GetCRect(x, y).TopLeft(), GetCRect(x1, y1).BottomRight());
	return rect;
}