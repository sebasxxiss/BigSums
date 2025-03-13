#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <chrono>
using namespace std;

class BigNumber
{
private:
	vector<int> num;
	int static toNumber(char c)
	{
		return (int)c - 48;
	};
	template <typename U>
	vector<U> static reverseVector(vector<U> n)
	{
		vector<U> copy = n;
		int init = 0;
		int end = n.size() - 1;
		int temp;
		while (init < end)
		{
			copy[init] = n[end];
			copy[end] = n[init];
			init++;
			end--;
		}
		return copy;
	};
	vector<int> static compareFn(vector<int> v1, vector<int> v2)
	{
		int acc = 0;
		vector<int> newVector;
		if (v1.size() >= v2.size())
		{

			for (int i = 0; i <= v1.size(); i++)
			{
				if (i == v1.size() - 1 && i >= v2.size())
				{
					if ((v1[i] + acc) >= 10)
					{
						newVector.push_back((v1[i] + acc) % 10);
						newVector.push_back(1);
						break;
					}
					else
					{
						newVector.push_back((v1[i] + acc));
						acc = 0;
						continue;
					}
				}
				if (i == v1.size() - 1 && i == v2.size() - 1)
				{
					if ((v1[i] + v2[i] + acc) >= 10)
					{
						newVector.push_back((v1[i] + v2[i] + acc) % 10);
						newVector.push_back(1);
						break;
					}
					else
					{
						newVector.push_back((v1[i] + v2[i] + acc));
						acc = 0;
						continue;
					}
				}
				if (i >= v2.size() && acc == 1)
				{
					if ((v1[i] + acc) >= 10)
					{
						newVector.push_back((v1[i] + acc) % 10);
						acc = 1;
						continue;
					}
					else
					{
						newVector.push_back((v1[i] + acc));
						acc = 0;
						continue;
					}
				}
				if (acc == 0 && i >= v2.size())
				{
					break;
				}
				if ((v1[i] + v2[i] + acc) >= 10)
				{
					newVector.push_back((v1[i] + v2[i] + acc) % 10);
					acc = 1;
					continue;
				}
				else
				{
					newVector.push_back((v1[i] + v2[i] + acc));
					acc = 0;
					continue;
				}
			}
		}
		else
		{

			for (int i = 0; i <= v2.size(); i++)
			{
				if (i == v2.size() - 1 && i >= v1.size())
				{
					if ((v2[i] + acc) >= 10)
					{
						newVector.push_back((v2[i] + acc) % 10);
						newVector.push_back(1);
						break;
					}
					else
					{
						newVector.push_back((v2[i] + acc));
						acc = 0;
						continue;
					}
				}
				if (i == v2.size() - 1 && i == v1.size() - 1)
				{
					if ((v2[i] + v1[i] + acc) >= 10)
					{
						newVector.push_back((v2[i] + v1[i] + acc) % 10);
						newVector.push_back(1);
						break;
					}
					else
					{
						newVector.push_back((v2[i] + v1[i] + acc));
						acc = 0;
						continue;
					}
				}
				if (i >= v1.size() && acc == 1)
				{
					if ((v2[i] + acc) >= 10)
					{
						newVector.push_back((v2[i] + acc) % 10);
						acc = 1;
						continue;
					}
					else
					{
						newVector.push_back((v2[i] + acc));
						acc = 0;
						continue;
					}
				}
				if (acc == 0 && i >= v1.size())
				{
					break;
				}
				if ((v2[i] + v1[i] + acc) >= 10)
				{
					newVector.push_back((v2[i] + v1[i] + acc) % 10);
					acc = 1;
					continue;
				}
				else
				{
					newVector.push_back((v2[i] + v1[i] + acc));
					acc = 0;
					continue;
				}
			}
		}
		return BigNumber::reverseVector(newVector);
	}

public:
	BigNumber(string n)
	{
		num = toVector(n);
	}
	BigNumber(vector<int> v)
	{
		num = v;
	}
	vector<int> static toVector(string str)
	{
		vector<int> v;
		for (char c : str)
		{
			v.push_back(toNumber(c));
		}
		return v;
	}
	vector<int> getNum()
	{
		return num;
	}
	void setNum(vector<int> v)
	{
		num = v;
	}
	void showVector()
	{
		for (int n : num)
		{
			cout << n << endl;
		}
	}
	string vectorToString()
	{
		string str;
		for (int n : num)
		{
			str = str + to_string(n);
		}
		return str;
	}
	BigNumber static sum(BigNumber big1, BigNumber big2)
	{
		vector<int> newVector = compareFn(reverseVector(big1.getNum()), reverseVector(big2.getNum()));
		BigNumber newBG(newVector);
		return newBG;
	}
};

void fibonnacciAccurateValues(unsigned int n)
{
	unsigned long long primero = 0;
	unsigned long long segundo = 1;
	unsigned long long res = 0;
	BigNumber bg1("0");
	BigNumber bg2("0");
	BigNumber bgResult("0");
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			cout << i << ". " << primero << endl;
			continue;
		}
		if (i == 1)
		{
			cout << i << ". " << segundo << endl;
			continue;
		}
		if (i <= 91)
		{
			res = primero + segundo;
			cout << i << ". " << primero << " + " << segundo << " = " << res << endl;
			primero = segundo;
			segundo = res;
		}
		else if (i == 92)
		{

			bg1.setNum(BigNumber::toVector(to_string(primero)));
			bg2.setNum(BigNumber::toVector(to_string(segundo)));
			bgResult = BigNumber::sum(bg1, bg2);
			cout << i + 1 << ". " << bg1.vectorToString() << " + " << bg2.vectorToString() << " = " << bgResult.vectorToString() << endl;
			bg1.setNum(bg2.getNum());
			bg2.setNum(bgResult.getNum());
		}
		else
		{
			bgResult = BigNumber::sum(bg1, bg2);
			cout << i << ". " << bg1.vectorToString() << " + " << bg2.vectorToString() << " = " << bgResult.vectorToString() << endl;
			bg1.setNum(bg2.getNum());
			bg2.setNum(bgResult.getNum());
		}
	}
}
void fibonacci()
{
	unsigned long long primero = 0;
	unsigned long long segundo = 1;
	unsigned long long res = 0;
	for (int i = 0; i < 100; i++)
	{
		res = primero + segundo;
		// a partir de 93 los valores son erroneos
		cout << i + 1 << ". " << primero << " + " << segundo << " = " << res << endl;
		primero = segundo;
		segundo = res;
	}
}
int main()
{
	// fibonacci();
	auto start = chrono::high_resolution_clock::now();
	fibonnacciAccurateValues(100);
	auto finish = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(finish - start);

	cout << duration.count() << " miliseconds" << endl;
	return 0;
}