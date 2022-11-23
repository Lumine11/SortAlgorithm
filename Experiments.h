#pragma once

#include"GenerateData.h" // header chứa Generate Data
#include"Timing.h" // header chứ các thuật toán sắp xếp _ đo thời gian
#include "CountingComparision.h"// header chứa các thuật toán sắp xếp - đo số lần so sánh

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;


void Experiments() {
	int size[6] = { 10000, 30000, 50000, 100000, 300000, 500000 };
	vector <string> Name = { "SelectionSort", "Insertion_Sort", "Bubble_sort", "Shaker_Sort", "Shell_Sort", "Heap_Sort" , "Merge_Sort" , "Quick_Sort" , "Counting_Sort", "Radix_Sort", "Flash_Sort" };
	vector <string> Order = { "RandomData" , "SortedData", "ReverseData", "NearlySortedData" };
	clock_t start, end;   // Khai báo biến thời gian

	ofstream fout("Experiments_output.txt");

	for (int OrderNo = 0; OrderNo < 4; OrderNo++) {
		fout << "Data order:" << Order[OrderNo] << endl;
		cout << "Kind of order: " << Order[OrderNo] << endl;
		for (int id = 0; id < 6; id++) // size
		{
			int n = size[id];
			int* a = new int[n];
			GenerateData(a, size[id], OrderNo);
			fout << "Data size" << n << endl;
			cout << "   *size = " << n << endl;

			for (int sort = 0; sort < 11; sort++)
			{
				int* b = new int[n];
				int* c = new int[n];

				for (int i = 0; i < size[id]; i++)
					c[i] = b[i] = a[i];

				fout << "       Kind of sort: " << Name[sort] << endl;
				cout << "       Kind of sort: " << Name[sort] << endl;

				start = clock();
				SortAl(b, n, sort);
				end = clock();
				double time_use = (double)(end - start) / CLOCKS_PER_SEC * 1000;
				fout << "       " << time_use << endl;
				cout << fixed << "       " << time_use << endl;
				delete[] b;


				long long int count = 0;
				COUNT_SortAl(c, n, sort, count);
				fout << "       " << count << endl;
				cout << "       " << count << endl;
				delete[] c;
			}
			delete[] a;
		}
	}

	fout.close();
}