#include<iostream>
#include<string>
using namespace std;

bool is_letter(char c)
{
	return c >= 'a'&&c <= 'z' || c >= 'A'&&c <= 'Z';
}
string simplifyPath(string path) {
	string res[1000];
	int num = -1;
	for (int i = 0; i < path.size(); i++)
	{
		if (path[i] == '.'&&path[i + 1] == '.')
		{
			if (num != -1)
				num--;
			i++;
		}
		else if (is_letter(path[i])||path[i]=='.')
		{
			string s;
			s = path[i++];
			while (i < path.size() && path[i] != '/')
				s = s + path[i++];
			i--;
			if(s!=".")
				res[++num] = s;
		} 
	}
	//for(int i=0;i<=num;i++)
	  //  cout<<"/"<<res[i];
	string result;
	if (num == -1)
		result = "/";
	for (int i = 0; i <= num; i++)
		result = result+"/" + res[i];
	return result;
}

int main()
{
	string s;
	cin >> s;
	cout<<simplifyPath(s);
	return 0;
}