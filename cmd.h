#pragma once

#include"GenerateData.h" // header chứa Generate Data
#include"Timing.h" // header chứ các thuật toán sắp xếp _ đo thời gian
#include "CountingComparision.h"// header chứa các thuật toán sắp xếp - đo số lần so sánh

#include <string>


string sort_names[] = {
	"selection-sort", "insertion-sort","bubble-sort",
	"shaker-sort",  "shell-sort",
	"heap-sort", "merge-sort", "quick-sort", "couting-sort", "radix-sort", "flash-sort"
};

void command1();
void command2();
void command3();
void command4(string Al1, string Al2, string InputFile)
{
	ifstream fin(InputFile);
	if (!fin)
	{
		cout << "Cn not read file" << endl;
		return;
	}
	int n; fin >> n;
	int* a = new int[n], * b = new int[n], * c = new int[n], * d = new int[n];
	for (int i = 0; i < n; i++)
	{
		fin >> a[i]; b[i] = a[i]; c[i] = a[i]; d[i] = a[i];
	}
	cout << "COMPARE MODE" << endl;
	cout << "Algorithm: " << Al1 << " | " << Al2 << endl;
	cout << "Inputfile: " << InputFile << endl;
	cout << "InputSize: " << n << endl;
	int x1 = 0, x2 = 0;// stand for type of Sort
	for (int x1 = 0; x1 < 11; x1++)
		if (sort_names[x1] == Al1)
			break;
	for (int x2 = 0; x2 < 11; x2++)
		if (sort_names[x2] == Al1)
			break;
	clock_t start1, end1, start2, end2;
	double time1 = 0, time2 = 0;
	start1 = clock();
	SortAl(a, n, x1);
	end1 = clock();
	start2 = clock();
	SortAl(b, n, x2);
	end2 = clock();
	time1 = (double)end1 - (double)start1;
	time2 = (double)end1 - (double)start1;
	cout << "Runtime: " << time1 << " | " << time2 << endl;

	// Comparison
	long long com1 = 0, com2 = 0;
	COUNT_SortAl(c, n, x1, com1);
	COUNT_SortAl(d, n, x2, com2);
	cout << "Comparisons: " << com1 << " | " << com2 << endl;
}
string Order[4] = { "-rand","-sorted","-rev","-nsorted" };
string NameInputFile[] = { "input_1.txt","input_3.txt" ,"input_4.txt" ,"input_2.txt" };
void command5(string Al1, string Al2, string InputSize, string InputOrder)
{
	cout << "COMPARE MODE" << endl;
	cout << "Algorithm: " << Al1 << " | " << Al2 << endl;
	cout << "Input size: " << InputSize << endl;
	cout << "Input Order: " << InputOrder << endl;
	int _order = 0;// input order;
	for (_order = 0; _order < 4; _order++)
		if (Order[_order] == InputOrder)
			break;
	int x1 = 0, x2 = 0;// stand for type of Sort
	for (int x1 = 0; x1 < 11; x1++)
		if (sort_names[x1] == Al1)
			break;
	for (int x2 = 0; x2 < 11; x2++)
		if (sort_names[x2] == Al1)
			break;

	string InputFileName = NameInputFile[_order];
	ofstream fout(InputFileName);
	if (!fout)
	{
		cout << "Can not open input.txt" << endl;
		return;
	}
	int n = stoi(InputSize);
	fout << n << endl;
	int* a = new int[n], * b = new int[n], * c = new int[n], * d = new int[n];
	GenerateData(a, n, _order);
	for (int i = 0; i < n; i++)
	{
		fout << a[i] << " ";
		b[i] = a[i]; c[i] = a[i], d[i] = a[i];
	}

	clock_t start1, end1, start2, end2;
	double time1 = 0, time2 = 0;
	start1 = clock();
	SortAl(a, n, x1);
	end1 = clock();
	start2 = clock();
	SortAl(b, n, x2);
	end2 = clock();
	time1 = (double)end1 - (double)start1;
	time2 = (double)end1 - (double)start1;
	cout << "Runtime: " << time1 << " | " << time2 << endl;

	// Comparison
	long long int com1 = 0, com2 = 0;
	COUNT_SortAl(c, n, x1, com1);
	COUNT_SortAl(d, n, x2, com2);
	cout << "Comparisons: " << com1 << " | " << com2 << endl;
}
