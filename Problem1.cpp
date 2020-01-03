#include<iostream>
using namespace std;
int main()
{
	int m = 0, n = 0;
	int *p_m = nullptr, *p_n = nullptr;
	int *result;
	while (cin >> m >> n)
	{
		p_m = new int[m];
		p_n = new int[n];
		result = new int[m + n];
		for (int i = 0; i < m; i++)
			cin >> p_m[i];
		for (int i = 0; i < n; i++)
			cin >> p_n[i];
		int i = 0, j = 0, k = 0;
		while (i < m&&j < n)
		{
			if (p_m[i] < p_n[j])
				result[k] = p_m[i++];
			else
				result[k] = p_n[j++];
			k++;
		}
		if (i >= m)
			for (; k < m + n; k++)
				result[k] = p_n[j++];
		else
			for (; k < m + n; k++)
				result[k] = p_m[i++];
		i = 0;
		for (; i < m + n-1; i++)
			cout << result[i] << " ";
		cout << result[i] << endl;
	}
	//system("pause");
	return 0;
}