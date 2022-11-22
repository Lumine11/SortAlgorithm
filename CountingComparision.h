#pragma once
#pragma once
#include <iostream>
using namespace std;
#include <vector>

// Đếm số lần so sánh
															//Selection Sort
void COUNT_Selection_Sort(int a[], int n, long long int& c) {
	for (int i = 0; c++, i < n - 1; i++) {
		int min_index = i;
		for (int j = i + 1; c++, j < n; j++)
			if (c++, a[min_index] > a[j])
				min_index = j;

		swap(a[i], a[min_index]);
	}
}
//Insertion Sort, 
void COUNT_Insertion_Sort(int a[], int n, long long int& c)
{
	int i, key, j;
	for (i = 1; c++, i < n; i++)
	{
		key = a[i];
		j = i - 1;
		while ((c++, j >= 0) && (c++, a[j] > key))
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}
//Bubble Sort,	


void COUNT_Bubble_Sort(int a[], int n, long long int& c)
{
	for (int i = 0; c++, i < n - 1; i++)
	{
		for (int j = 0; c++, j < n - i - 1; j++)
		{
			if (c++, a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
			}
		}
	}
}

//															//Shaker Sort,
void COUNT_Shaker_Sort(int* a, int n, long long int& c)
{
	int Left = 0;
	int Right = n - 1;
	int k = 0;
	while (c++, Left < Right)
	{
		for (int i = Left; c++, i < Right; i++)
		{
			if (c++, a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				k = i;
			}
		}
		Right = k;
		for (int i = Right; c++, i > Left; i--)
		{
			if (c++, a[i] < a[i - 1])
			{
				swap(a[i], a[i - 1]);
				k = i;
			}
		}
		Left = k;
	}
}
//Shell Sort,
void COUNT_Shell_Sort(int a[], int n, long long int& c)
{
	for (int gap = n / 2; c++, gap > 0; gap /= 2)
	{
		for (int i = gap; c++, i < n; i += 1)
		{
			int temp = a[i];
			int j;
			for (j = i; (c++, j >= gap) && (c++, a[j - gap] > temp); j -= gap)
				a[j] = a[j - gap];

			a[j] = temp;
		}
	}
}
/// HEAPSORT
void CHeapify(int a[], int n, int i, long long int& c) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if ((c++, left < n) && (c++, a[left] > a[largest]))
		largest = left;

	if ((c++, right < n) && (c++, a[right] > a[largest]))
		largest = right;

	if (c++, largest != i) {
		swap(a[largest], a[i]);
		CHeapify(a, n, largest, c);
	}
}

void CCreateHeap(int a[], int n, long long int& c)
{
	for (int j = n / 2; c++, j >= 0; j--)
		CHeapify(a, n, j, c);
}

void CHeap_Sort(int a[], int n, long long int& c) {
	CCreateHeap(a, n, c);
	for (int i = n - 1; c++, i >= 0; i--) {
		swap(a[0], a[i]);
		CHeapify(a, i, 0, c);
	}
}

// Merge Sort,
void merge(int a[], int l, int m, int r, long long int& c)
{
	vector < int > a1(a + l, a + m + 1);
	vector<int> a2(a + m + 1, a + r + 1);
	int i = 0, j = 0;
	while ((c++, i < a1.size()) && (c++, j < a2.size()))
	{
		if (c++, a1[i] <= a2[j])
		{
			a[l++] = a1[i++];
		}
		else
		{
			a[l++] = a2[j++];
		}
	}
	while (c++, i < a1.size())
	{
		a[l++] = a1[i++];
	}
	while (c++, j < a2.size())
	{
		a[l++] = a2[j++];
	}
}
void COUNT_Merge_Sort(int a[], int l, int r, long long int& c)
{
	if (l >= r)
		return;
	int m = (l + r) / 2;
	COUNT_Merge_Sort(a, l, m, c);
	COUNT_Merge_Sort(a, m + 1, r, c);
	merge(a, l, m, r, c);
}
//														//Quick Sort,
int partition(int* a, int low, int high, long long int& c) {
	int pivot = a[high];     // Chọn pivot là phần tử cuối cùng
	int right = high - 1; // Chọn right
	int left = low;    // Chọn left
	while (true) {                         // Trong khi còn đúng (left < right)
		while ((c++, left <= right) && (c++, a[left] < pivot))
			left++;     // Tìm left thích hợp
		while ((c++, right >= left) && (c++, a[right] > pivot))
			right--;   // Tìm right thích hợp
		if (c++, left >= right)              // left >= right dừng
			break;
		swap(a[left], a[right]);     // Đổi chỗ
		left++;                     // Xét phần tử tiếp theo
		right--;
	}
	swap(a[left], a[high]);            // Đổi chỗ pivot về giữa mảng
	return left;                       // Trả về vị trí của pivot  
}

void COUNT_Quick_Sort(int* a, int low, int high, long long int& c) {
	if (c++, low < high)  //Mảng có nhiều hơn 0 phần tử
	{
		int pivot = partition(a, low, high, c);  // Chia đôi mảng
		COUNT_Quick_Sort(a, low, pivot - 1, c);           // Đệ quy bên trái
		COUNT_Quick_Sort(a, pivot + 1, high, c);         // Đệ quy bên phải
	}
}


//														//Counting Sort,
void getMinMax(int a[], int n, int& min, int& max, long long int& c) {
	min = a[0];
	max = a[0];
	for (int i = 1; c++, i < n; i++) {
		if (c++, min > a[i])
			min = a[i];
		if (c++, max < a[i])
			max = a[i];
	}
}


void COUNT_Counting_Sort(int a[], int n, long long int& c) {
	int min, max;
	getMinMax(a, n, min, max, c);
	int* count = new int[max - min + 1];

	for (int i = 0; c++, i < max - min + 1; i++)
		count[i] = 0; // khởi tạo các giá trị của mảng bằng 0
	for (int i = 0; c++, i < n; i++)
		count[a[i] - min]++; // lưu số lần xuất hiện vào mảng

	int k = 0;
	for (int i = 0; c++, i < max - min + 1; i++)
		while (c++, count[i] > 0) {
			a[k++] = i + min;
			count[i]--;
		}

	delete[] count;
}
//														//Radix Sort,
void COUNT_Radix_Sort(int* a, int n, long long int& c)
{
	int* b = new int[n];
	int m = a[0], exp = 1;

	for (int i = 0; c++, i < n; i++)
		if (c++, a[i] > m)
			m = a[i];

	while (c++, m / exp > 0)
	{
		int bucket[10] = { 0 };
		for (int i = 0; c++, i < n; i++)
			bucket[a[i] / exp % 10]++;
		for (int i = 1; c++, i < 10; i++)
			bucket[i] += bucket[i - 1];
		for (int i = n - 1; c++, i >= 0; i--)
		{
			int pos_output = --bucket[a[i] / exp % 10];
			b[pos_output] = a[i];
		}

		for (int i = 0; c++, i < n; i++)
			a[i] = b[i];
		exp *= 10;
	}
	delete[] b;
}
//															// Flash Sort.

void COUNT_Flash_Sort(int a[], int n, long long int& c) {
	int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);
	int* l = new int[m];
	for (int i = 0; c++, i < m; i++)
		l[i] = 0;
	for (int i = 1; c++, i < n; i++)
	{
		if (c++, a[i] < minVal)
			minVal = a[i];
		if (c++, a[i] > a[max])
			max = i;
	}
	if (c++, a[max] == minVal)
		return;
	double c1 = (double)(m - 1) / (a[max] - minVal);
	for (int i = 0; c++, i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++l[k];
	}
	for (int i = 1; c++, i < m; i++)
		l[i] += l[i - 1];
	swap(a[max], a[0]);
	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;
	while (c++, nmove < n - 1)
	{
		while (c++, j > l[k] - 1)
		{
			j++;
			k = int(c1 * (a[j] - minVal));
		}
		flash = a[j];
		if (c++, k < 0) break;
		while (c++, j != l[k])
		{
			k = int(c1 * (flash - minVal));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++nmove;
		}
	}
	delete[] l;
	COUNT_Insertion_Sort(a, n, c);
}

void COUNT_SortAl(int a[], int n, int type, long long int& c) {
	switch (type) {
	case 0:
		COUNT_Selection_Sort(a, n, c);
		break;
	case 1:
		COUNT_Insertion_Sort(a, n, c);
		break;
	case 2:
		COUNT_Bubble_Sort(a, n, c);
		break;
	case 3:
		COUNT_Shaker_Sort(a, n, c);
		break;
	case 4:
		COUNT_Shell_Sort(a, n, c);
		break;
	case 5:
		CHeap_Sort(a, n, c);
		break;
	case 6:
		int l, r;
		l = 0;
		r = n - 1;
		COUNT_Merge_Sort(a, l, r, c);
		break;
	case 7:
		int low, high;
		low = 0;
		high = n - 1;
		COUNT_Quick_Sort(a, low, high, c);
		break;
	case 8:
		COUNT_Counting_Sort(a, n, c);
		break;
	case 9:
		COUNT_Radix_Sort(a, n, c);
		break;
	case 10:
		COUNT_Flash_Sort(a, n, c);
		break;
	default:
		printf("Error: unknown data type!\n");
	}
}