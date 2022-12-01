#include<iostream>
#include<graphics.h>
#include<conio.h>
using namespace std;

void Bresenham_Circle(int x0, int y0, int r)
{
	initgraph(800, 640);
	int flag = 2 - 2 * r;
	int x = 0, y = r;
	int Direction;
	while (y >= 0)
	{
		cout << "x=" << x << "£¬y=" << y << "£¬flag=" << flag << endl;
		putpixel(x + x0, y + y0, RED);
		putpixel(x + x0, y0 - y, RED);
		putpixel(-x + x0, y + y0, RED);
		putpixel(-x + x0, y0 - y, RED);
		if (flag < 0)
		{
			int flag1 = 2 * (flag + y) - 1;
			if (flag1 <= 0)
				Direction = 1;
			else Direction = 2;
		}
		else if (flag > 0)
		{
			int flag2 = 2 * (flag - x) - 1;
			if (flag2 <= 0)
				Direction = 2;
			else Direction = 3;
		}
		else if (flag == 0)
		{
			Direction = 2;
		}

		if (Direction == 1)
		{
			x++;
			flag += (2 * x + 1);
		}
		else if (Direction == 2)
		{
			x++;
			y--;
			flag += (2 * x - 2 * y + 2);
		}
		else if (Direction == 3)
		{
			y--;
			flag += (1 - 2 * y);
		}
	}
	_getch();
	closegraph();
}

int main(void)
{
	Bresenham_Circle(300, 300, 100);
	return 0;
}
