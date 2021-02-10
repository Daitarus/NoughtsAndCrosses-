#include <iostream>

using namespace std;
class AllClass
{
public:
	void outC(char x[])
	{
		int j = 0;
		for (int i = 0; i < 5; i++)
		{
			if ((i == 1) || (i == 3))
			{
				cout << "---+---+---" << endl;
			}
			else
			{
				cout << " " << x[j] << " | " << x[j + 1] << " | " << x[j + 2] << " " << endl;
				j = j + 3;
			}
		}
	}
	char win(char x[])
	{
		char o = 0; bool st = false;
		//standoff
		for (int i = 0; i < 9; i++)
		{
			if (x[i] == ' ')
			{
				st = true;
			}
		}
		if (st == false)
		{
			o = 3;
		}
		//line
		for (int i = 0; i < 3; i++)
		{
			if ((x[3 * i] == x[3 * i + 1]) && (x[3 * i] == x[3 * i + 2])&&(x[3 * i] != ' '))
			{
				if (x[3 * i] == 'x')
				{
					o = 1;
				}
				else
				{
					o = 2;
				}
			}
		}
		//column
		for (int i = 0; i < 3; i++)
		{
			if ((x[i] == x[i+3]) && (x[i] == x[i+6]) && (x[i] != ' '))
			{
				if (x[i] == 'x')
				{
					o = 1;
				}
				else
				{
					o = 2;
				}
			}
		}
		//sideways
		if ((x[0] == x[4]) && (x[0] == x[8]) && (x[0] != ' '))
		{
			if (x[0] == 'x')
			{
				o = 1;
			}
			else
			{
				o = 2;
			}
		}
		if ((x[2] == x[4]) && (x[2] == x[8]) && (x[6] != ' '))
		{
			if (x[2] == 'x')
			{
				o = 1;
			}
			else
			{
				o = 2;
			}
		}		
		return o;
	}
};

int main()
{
	AllClass allClass;
	char x[9];
	for (int i = 0; i < 9;i++)
	{
		x[i] = ' ';
	}
	char ch = 0; bool o2 = true, h = false;
	int c = -1;
	allClass.outC(x);
	while (ch==0)
	{		
		h = !h;
		o2 = true;
		//enter not x/o, but index(1-9)
		while (o2)
		{
			if (h)
			{
				cout << "Enter x" << endl;
			}
			else
			{
				cout << "Enter o" << endl;
			}
			cin >> c;
			if ((x[c - 1] == ' ') && (c > 0) && (c < 10))
			{
				o2 = false;
			}
			else
			{
				cout << "Entered incorrectly" << endl;
			}
		}
		system("cls");
		if (h)
		{
			x[c-1] = 'x';
		}
		else
		{
			x[c-1] = 'o';
		}
		allClass.outC(x);
		ch = allClass.win(x);
		if (ch == 1)
		{
			cout << "Win X" << endl;
		}
		else if (ch == 2)
		{
			cout << "Win O" << endl;
		}
		else if (ch == 3)
		{
			cout << "None Win" << endl;
		}
	}
	cout << "Game over" << endl;
}
