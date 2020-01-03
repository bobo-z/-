#include<iostream>
#include<string>
using namespace std;
class Heap {
private:
	int* heap;
	int size;
	int type;//type 0:min	type 1:max
	void sift_up()
	{
		int index = size;
		int parent = (size - 1) / 2;

		int temp = heap[index];
		while (index > 0)
		{
			if (type == 0 && temp > heap[parent])
				break;
			else if (type == 1 && temp < heap[parent])
				break;
			else
				heap[index] = heap[parent];
			index = parent;
			parent = (parent - 1) / 2;
		}
		heap[index] = temp;
	}
	void sift_down()
	{
		int index = 0;
		int child = 1;

		int tmp = heap[index];
		while (child <= size - 1) {
			if (type == 0 && child + 1 <= size - 1 && heap[child] > heap[child + 1])
				++child;
			if (type == 1 && child + 1 <= size - 1 && heap[child] < heap[child + 1])
				++child;
			if (type == 0 && tmp < heap[child])
				break;
			if (type == 1 && tmp > heap[child])
				break;
			else
				heap[index] = heap[child];

			index = child;
			child = child * 2 + 1;
		}
		heap[index] = tmp;
	}
public:
	Heap(int x, int t)
	{
		heap = new int[x];
		type = t;
		size = 0;
	}
	Heap(Heap &h)
	{
		size = h.get_size();
		type = h.type;
		heap = new int[size];
		for (int i = 0; i < size; i++)
			heap[i] = h.heap[i];
	}
	~Heap()
	{
		delete []heap;
		heap = nullptr;
	}
	void insert(int x)
	{
		heap[size] = x;
		sift_up();
		size++;
	}
	void remove()
	{
		heap[0] = heap[size - 1];
		--size;
		sift_down();
	}
	int get_top()
	{
		return heap[0];
	}
	int get_size()
	{
		return size;
	}
};

int main()
{
	int n, k;
	cin >> n >> k;
	string str;
	Heap a1(n, 1);
	while (cin >> str)
	{
		if (str == "Check")
		{
			Heap temp(a1);
			int size = temp.get_size();
			for (int i = 0; i < k&&i<size; i++)
			{
				cout << temp.get_top() << " ";
				temp.remove();
			}
			cout << endl;
			temp.~Heap();
		}
		else
		{
			int t = stoi(str);
			a1.insert(t);
		}
	}
	system("pause");
	return 0;
}