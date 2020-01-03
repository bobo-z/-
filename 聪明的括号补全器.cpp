#include<iostream>
#include<string>
using namespace std;
class Stack
{
private:
	int size;
	int top;
	string a[1000000];
public:
	Stack() :size(1000000), top(-1) {}
	//~Stack() {delete []a;}
	bool is_empty()
	{
		if (top == -1)
			return true;
		return false;
	}
	int push(string x)
	{
		a[++top] = x;
		return 0;
	}
	int s_size()
	{
		return top + 1;
	}
	string pop()
	{
		if (is_empty())
			return "-1";
		return a[top--];
	}
	string get_top()
	{
		if (is_empty())
			return "-1";
		return a[top];
	}
};
int minAddToMakeValid(string S) {
	Stack st;
	for (size_t i = 0; i < S.size(); i++)
	{
		if (S[i] == '(')
			st.push("(");
		else
		{
			if (!st.is_empty()&&st.get_top() == "(")
				st.pop();
			else
				st.push(")");
		}
	}
	return st.s_size();
}
int main()
{
	string s;
	cin >> s;
	cout << minAddToMakeValid(s);
	system("pause");
	return 0;
}