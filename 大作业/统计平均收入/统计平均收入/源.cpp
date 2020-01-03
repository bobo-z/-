#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int find_low(int* a,int start, int end,int x)
{
	if (start == end)
		return start;
	if (start == end - 1)
	{
		if (x < a[start]) return -1;
		else if (x >= a[start] && x < a[end])
			return start;
		else
			return end;
	}
	int mid = (start + end) / 2;
	if (x < a[mid])
		return find_low(a, start, mid, x);
	else
		return find_low(a, mid, end, x);
}
int find_high(int* a, int start, int end, int x)
{
	if (start == end)
		return start;
	if (start == end - 1)
	{
		if (x <= a[start]) return start;
		else if (x > a[start] && x <= a[end])
			return end;
		else
			return -1;
	}
	int mid = (start + end) / 2;
	if (x <= a[mid])
		return find_high(a, start, mid, x);
	else
		return find_high(a, mid, end, x);
}
void merge(int *data, int start, int end, int *result)
{
	int left_length = (end - start + 1) / 2 + 1;
	int left_index = start;
	int right_index = start + left_length;
	int result_index = start;
	while (left_index < start + left_length && right_index < end + 1)  //store data into new array
	{
		if (data[left_index] <= data[right_index])
			result[result_index++] = data[left_index++];
		else
			result[result_index++] = data[right_index++];
	}
	while (left_index < start + left_length)
		result[result_index++] = data[left_index++];
	while (right_index < end + 1)
		result[result_index++] = data[right_index++];
}

void merge_sort(int *data, int start, int end, int *result)
{
	if (1 == end - start)   //last only two elements
	{
		if (data[start] > data[end])
		{
			int temp = data[start];
			data[start] = data[end];
			data[end] = temp;
		}
		return;
	}
	else if (end == start)
		return; //last one element then there is no need to sort;
	else {
		//continue to divide the interval
		merge_sort(data, start, (end - start + 1) / 2 + start, result);
		merge_sort(data, (end - start + 1) / 2 + start + 1, end, result);
		//start to merge sorted data
		merge(data, start, end, result);
		for (int i = start; i <= end; ++i)
		{
			data[i] = result[i];
		}
	}

}
int main()
{
	int n,m;
	scanf("%d%d", &n, &m);
	int *salary = new int[n];
	int *order_sal = new int[n];
	long long *sum = new long long[n+1];
	for (int i = 0; i < n; i++)
		scanf("%d", &salary[i]);
	merge_sort(salary, 0, n - 1, order_sal);
	for (int i = 0; i <= n; i++)
	{
		if (i == 0)
			sum[i] = 0;
		else
			sum[i] = (long long)(sum[i - 1] + (long long)order_sal[i - 1]);
	}
	while (m--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		bool flag = false;
		if (l > r)//r is bigger
		{
			int temp = r;
			r = l;
			l = temp;
		}
		if (r<order_sal[0] || l>order_sal[n - 1])
		{
			printf("0\n");
			continue;
		}
		l = find_high(order_sal, 0, n - 1, l);
		r = find_low(order_sal, 0, n - 1, r);
		if (l > r||l==-1||r==-1)
		{
			printf("0\n");
			continue;
		}
		long long result = (long long)(sum[r + 1] - sum[l]) / (r + 1 - l);
		printf("%llu\n", result);
	}
	return 0;
}
