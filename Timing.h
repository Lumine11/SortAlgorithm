#pragma once
#pragma once
// Đo thời gian chạy
#include <iostream>
using namespace std;
#include <vector>

//														Selection sort
void Selection_Sort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int min_index = i;
		for (int j = i + 1; j < n; j++)
			if (a[min_index] > a[j])
				min_index = j;

		swap(a[i], a[min_index]);
	}
}
//Insertion Sort, 
void Insertion_Sort(int* a, int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}
//Bubble Sort,

void Bubble_Sort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
			}
		}
	}
}
//Shaker Sort,
void Shaker_Sort(int* a, int n)
{
	int Left = 0;
	int Right = n - 1;
	int k = 0;
	while (Left < Right)
	{
		for (int i = Left; i < Right; i++)
		{
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				k = i;
			}
		}
		Right = k;
		for (int i = Right; i > Left; i--)
		{
			if (a[i] < a[i - 1])
			{
				swap(a[i], a[i - 1]);
				k = i;
			}
		}
		Left = k;
	}
}
//														//Shell Sort,
void Shell_Sort(int* a, int n)
{
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i += 1)
		{
			int temp = a[i];
			int j;
			for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
				a[j] = a[j - gap];

			a[j] = temp;
		}
	}
}
// HEAPSORT
void Heapify(int a[], int n, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && a[left] > a[largest])
		largest = left;

	if (right<n && a[right] > a[largest])
		largest = right;

	if (largest != i) {
		swap(a[largest], a[i]);
		Heapify(a, n, largest);
	}
}

void CreateHeap(int a[], int n)
{
	for (int j = n / 2; j >= 0; j--)
		Heapify(a, n, j);
}

void Heap_Sort(int a[], int n) {
	CreateHeap(a, n);
	for (int i = n - 1; i >= 0; i--) {
		swap(a[0], a[i]);
		Heapify(a, i, 0);
	}
}
//
//														// Merge Sort,
void merge(int a[], int l, int m, int r)
{
	vector < int > a1(a + l, a + m + 1);
	vector<int> a2(a + m + 1, a + r + 1);
	int i = 0, j = 0;
	while (i < a1.size() && j < a2.size())
	{
		if (a1[i] <= a2[j])
		{
			a[l++] = a1[i++];
		}
		else
		{
			a[l++] = a2[j++];
		}
	}
	while (i < a1.size())
		a[l++] = a1[i++];
	while (j < a2.size())
		a[l++] = a2[j++];
}
void Merge_Sort(int a[], int l, int r)
{
	if (l >= r)
		return;
	int m = (l + r) / 2;
	Merge_Sort(a, l, m);
	Merge_Sort(a, m + 1, r);
	merge(a, l, m, r);
}
//														//Quick Sort,
int partition(int* a, int low, int high) {
	int pivot = a[high];     // Chọn pivot là phần tử cuối cùng
	int right = high - 1; // Chọn right
	int left = low;    // Chọn left
	while (true) {                         // Trong khi còn đúng (left < right)
		while (left <= right && a[left] < pivot)
			left++;     // Tìm left thích hợp
		while (right >= left && a[right] > pivot)
			right--;   // Tìm right thích hợp
		if (left >= right)              // left >= right dừng
			break;
		swap(a[left], a[right]);     // Đổi chỗ
		left++;                     // Xét phần tử tiếp theo
		right--;
	}
	swap(a[left], a[high]);            // Đổi chỗ pivot về giữa mảng
	return left;                       // Trả về vị trí của pivot  
}

void Quick_Sort(int* a, int low, int high) {
	if (low < high)  //Mảng có nhiều hơn 0 phần tử
	{
		int pivot = partition(a, low, high);  // Chia đôi mảng
		Quick_Sort(a, low, pivot - 1);           // Đệ quy bên trái
		Quick_Sort(a, pivot + 1, high);         // Đệ quy bên phải
	}
}

//														//Counting Sort,
void getMinMax(int a[], int n, int& min, int& max) {
	min = a[0];
	max = a[0];
	for (int i = 1; i < n; i++) {
		if (min > a[i])
			min = a[i];
		if (max < a[i])
			max = a[i];
	}
}


void Counting_Sort(int a[], int n) {
	int min, max;
	getMinMax(a, n, min, max);
	int* count = new int[max - min + 1];

	for (int i = 0; i < max - min + 1; i++)
		count[i] = 0; // khởi tạo các giá trị của mảng bằng 0
	for (int i = 0; i < n; i++)
		count[a[i] - min]++; // lưu số lần xuất hiện vào mảng

	int k = 0;
	for (int i = 0; i < max - min + 1; i++)
		while (count[i] > 0) {
			a[k++] = i + min;
			count[i]--;
		}

	delete[] count;
}
//														//Radix Sort,
void Radix_Sort(int* a, int n)
{
	int* b = new int[n];
	int m = a[0], exp = 1;

	for (int i = 0; i < n; i++)
		if (a[i] > m)
			m = a[i];

	while (m / exp > 0)
	{
		int bucket[10] = { 0 };
		for (int i = 0; i < n; i++)
			bucket[a[i] / exp % 10]++;
		for (int i = 1; i < 10; i++)
			bucket[i] += bucket[i - 1];
		for (int i = n - 1; i >= 0; i--)
		{
			int pos_output = --bucket[a[i] / exp % 10];
			b[pos_output] = a[i];
		}

		for (int i = 0; i < n; i++)
			a[i] = b[i];
		exp *= 10;
	}
	delete[] b;
}
//														// Flash Sort.

void Flash_Sort(int a[], int n) {
	int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);
	int* l = new int[m];
	for (int i = 0; i < m; i++)
		l[i] = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i] < minVal)
			minVal = a[i];
		if (a[i] > a[max])
			max = i;
	}
	if (a[max] == minVal)
		return;
	double c1 = (double)(m - 1) / (a[max] - minVal);
	for (int i = 0; i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++l[k];
	}
	for (int i = 1; i < m; i++)
		l[i] += l[i - 1];
	swap(a[max], a[0]);
	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;
	while (nmove < n - 1)
	{
		while (j > l[k] - 1)
		{
			j++;
			k = int(c1 * (a[j] - minVal));
		}
		flash = a[j];
		if (k < 0) break;
		while (j != l[k])
		{
			k = int(c1 * (flash - minVal));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++nmove;
		}
	}
	delete[] l;
	Insertion_Sort(a, n);
}

void SortAl(int a[], int n, int type) {
	switch (type) {
	case 0:
		Selection_Sort(a, n);
		break;
	case 1:
		Insertion_Sort(a, n);
		break;
	case 2:
		Bubble_Sort(a, n);
		break;
	case 3:
		Shaker_Sort(a, n);
		break;
	case 4:
		Shell_Sort(a, n);
		break;
	case 5:
		Heap_Sort(a, n);
		break;
	case 6:
		int l, r;
		l = 0;
		r = n - 1;
		Merge_Sort(a, l, r);
		break;
	case 7:
		int low, high;
		low = 0;
		high = n - 1;
		Quick_Sort(a, low, high);
		break;
	case 8:
		Counting_Sort(a, n);
		break;
	case 9:
		Radix_Sort(a, n);
		break;
	case 10:
		Flash_Sort(a, n);
		break;
	default:
		printf("Error: unknown data type!\n");
	}
}