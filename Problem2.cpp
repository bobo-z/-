#include<iostream>
using namespace std;

unsigned long long find(int *a, int start, int end)
{
	unsigned long long max = 0;
	unsigned long long t = 0;
	while (start < end)
	{
		t = (unsigned long long)(end - start)*(a[start] < a[end] ? a[start] : a[end]);
		max = max > t ? max : t;
		if (a[start] < a[end])
			start++;
		else
			end--;
	}
	return max;
}
int main()
{
	int n;
	unsigned long long max = 0;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << find(a, 0, n - 1) << endl;
	//system("pause");
	return 0;
}