#include<iostream>
#include<cmath>
#include<string>

using namespace std;


class table
{
public:
				void input();
				void columncheck(const int& in, const int& position);
				void rollcheck(const int &in, const int& positioin);
				void blockcheck(const int& in,const int& x,const int& y);
				bool check();
				void clear();
private:
				int column[9] = {0};
				int roll[9] = {0};
				int block[3][3] = {0};
};

int main()
{
				table sudoku;
				/*fstream fin;
				fstream fout;
				fin.open("input.txt", ios::in);
				fout.open("output.txt", ios::out);*/
				while (!cin.eof())
				{
								sudoku.input();
				}

}

void table::input()
{
				int temp=0;
				char c;
				for (int i = 0; i < 9; i++)
				{
								for (int j = 0; j < 9;j++ )
								{
												if (cin.eof())
																return;
												cin >> temp;
												if (j != 8)
																cin >> c;
												columncheck(temp,i);
												rollcheck(temp, j);
												blockcheck(temp, i / 3, j / 3);
												temp = 0;
								}
				}
				if (check())
								cout << "True" << endl;
				else
								cout << "False" << endl;
				clear();
}
void table::columncheck(const int& in,const int &position) 
{
				column[position] += (int)pow(2, in - 1);
				return;
}
void table::rollcheck(const int& in, const int& positioin)
{
				roll[positioin] += pow(2, in - 1);
				return;
}
void table::blockcheck(const int& in, const int& x, const int& y)
{
				block[y][x] += pow(2, in - 1);
				return ;
}
bool table::check()
{
				int i;
				for (i = 0; i < 9; i++)
				{
								//cout << column[i] << "\t" << roll[i] << "\t" << block[i / 3][i % 3] << endl;
								if (column[i] != 511 || roll[i] != 511 || block[i / 3][i % 3] != 511)
												break;
				}
				if (i == 9)
								return 1;
				else 
								return 0;
}

void table::clear()
{
				for (int i = 0; i < 9; i++)
				{
								column[i] = 0;
								roll[i] = 0;
								block[i / 3][i % 3] = 0;
				}
}