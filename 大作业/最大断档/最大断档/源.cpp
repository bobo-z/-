#include<iostream>
using namespace std;
struct Bucket {
	int used;
	int min_num;
	int max_num;
	Bucket():used(false),min_num(0x7fffffff),max_num(0){}
};
int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	int max = 0, min = 0x7fffffff;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}

	int bucket_size = (max - min) / (n - 1);
	int bucket_num = (max - min) / bucket_size + 1;
	Bucket* buckets = new Bucket[bucket_num]();

	for (int i = 0; i < n; i++)
	{
		int bucket_id = (arr[i] - min) / bucket_size;//计算arr[i]数值对应的桶号
		buckets[bucket_id].used = true;
		buckets[bucket_id].max_num = buckets[bucket_id].max_num > arr[i] ? buckets[bucket_id].max_num : arr[i];
		buckets[bucket_id].min_num = buckets[bucket_id].min_num < arr[i] ? buckets[bucket_id].min_num : arr[i];
	}
	int prev_max = min;
	int max_gap = 0;
	for (int i = 0; i < bucket_num; i++)
	{
		if (!buckets[i].used)
			continue;
		max_gap = max_gap > (buckets[i].min_num-prev_max) ? max_gap : (buckets[i].min_num - prev_max);
		prev_max = buckets[i].max_num;
	}
	cout << max_gap;
	system("pause");
	return 0;
}