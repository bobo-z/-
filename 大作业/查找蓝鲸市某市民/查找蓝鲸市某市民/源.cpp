#include<iostream>
#include<string>
using namespace std;
bool hashmap[1000001]{ 0 };
unsigned hash_func1(string str)//BKDRHash
{
	unsigned int hash = 0;
	for (size_t i = 0; i < str.size(); i++)
		hash = hash * 131 + str[i];
	return hash%1000000;
}
unsigned hash_func2(string str)//FNVHash
{
	if (str.size() == 0)
		return 0;
	unsigned int hash = 2166136261;
	for (size_t i = 0; i < str.size(); i++)
	{
		hash *= 16777619;
		hash ^= str[i];
	}
	return hash%1000000;
}
unsigned hash_func3(string str)//DJBHash
{
	if (str.size() == 0)
		return 0;
	unsigned hash = 5381;
	for (size_t i = 0; i < str.size(); i++)
		hash += (hash << 5) + str[i];
	return hash % 1000000;
}
int main()
{
	int n;
	cin >> n;
	string str;
	while (n--)
	{
		cin >> str;
		hashmap[hash_func1(str)] = 1;
		hashmap[hash_func2(str)] = 1;
		hashmap[hash_func3(str)] = 1;
	}
	cin >> str;
	if (hashmap[hash_func1(str)] && hashmap[hash_func2(str)] && hashmap[hash_func3(str)])
		cout << "true" << endl;
	else
		cout << "false" << endl;
	system("pause");
	return 0;
}