// 随机生成30道100以内的四则运算，可以出现真分数 
#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<time.h>
using namespace std;
#define random() (rand()%100) 
int main()
{
	int i, j, m, a, b, c, d;
	char k;
	srand((int)time(NULL));  //设置时间种子 ，使得程序每次运行的结果都不同 
	for (i = 0; i<30; i++)
	{
		a = random();
		b = random();
		c = random();
		d = random();
		j = random();
		m = random();
		j = j % 4;
		m = m % 2;
		if (m == 0)  //m=0时，生成整数四则运算 
		{
			if (j == 0) k = '+';
			else if (j == 1) k = '-';
			else if (j == 2) k = '*';
			else
			{
				for (;;)
				{
					if (b == 0) b = random();
					else break;
				}
				k = '/';
			}

			cout << setw(3) << a << setw(2) << k << setw(3) << b << setw(3) << "= " << endl;
		}
		else  //m=1时，生成真分数四则运算 
		{
			for (;;) //位于分母的c不能为0 
			{
				if (c <= a)
				{
					c = random();
				}
				else break;
			}
			for (;;)  //位于分母的d不能为0 
			{
				if (d <= b)
				{
					d = random();
				}
				else break;
			}
			if (j == 0) k = '+';
			else if (j == 1) k = '-';
			else if (j == 2) k = '*';
			else  //当b为0时，b/d为除数，所以b也不能为0 
			{
				for (;;)
				{
					if (b == 0)
					{
						b = random();
					}
					else if (b <= d)
					{
						d = random();
					}
					else break;
				}
				k = '/';
			}

			cout << setw(3) << a << "/" << c << setw(2) << k << setw(3) << b << "/" << d << setw(3) << "= " << endl;
		}

	}
	return 0;
}