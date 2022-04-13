#include <iostream>
#include <ctime>
using namespace std;

class Figure 
{
public:
	virtual int area()
	{
		return 0;
	}
	virtual void draw()
	{
		return;
	}

};
class Square : public Figure
{	
protected:
	int w;
public:

	Square()
	{
		w = rand() % 10;
	}
	Square(int w):w(w)
	{
	}
	int area()
	{
		return w * w;
	}
	void draw()
	{
		for (int i = 0; i < w; i++)
		{
			for (int j = 0; j < w; j++)
				cout << "#";
			cout << endl;
		}
	}
};

class Reactangle : public Square
{
private:
	int  h;
public:
	Reactangle()
	{
		h = rand() % 10;
	}
	Reactangle(int h, int w):Square(w), h(h)
	{			
	}
	int area()
	{
		return h * w;
	}
	void draw()
	{
		for (int i = 0; i < w; i++)
		{
			for (int j = 0; j < h; j++)
				cout << "#";
			cout << endl;
		}
	}

};