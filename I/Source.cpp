//In the arithmetic expression, the number 1, addition, multiplication and parenthesis operations are allowed. 
//What is the smallest number of units you need to use to get a given natural number n?

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map<int, int> table;

int min_units(int x)
{
	if (x <= 5)
		return x;
	if (x <= 7)
		return x - 1;
	map<int, int>::iterator val = table.find(x);
	if (val != table.end())
		return val->second;
	int f;
	for (int i = sqrt(x); i > 1; i--)
		if (x % i == 0)
		{
			f = min(min_units(i) + min_units(x / i), min_units(x - 1) + 1);
			table.insert({ x, f });
			return f;
		}
	f = min_units(x - 1) + 1;
	table.insert({ x, f });
	return f;
}

int main()
{
	int x;
	cin >> x;
	cout << min_units(x);
	return 0;
}