#pragma once

#include"GenerateData.h" // header chứa Generate Data
#include"Timing.h" // header chứ các thuật toán sắp xếp _ đo thời gian
#include "CountingComparison.h"// header chứa các thuật toán sắp xếp - đo số lần so sánh
#include <iomanip>
#include <string>


string sort_names[] = {
	"selection-sort", "insertion-sort","bubble-sort",
	"shaker-sort",  "shell-sort",
	"heap-sort", "merge-sort", "quick-sort", "couting-sort", "radix-sort", "flash-sort"
};
string Order[4] = { "-rand","-sorted","-rev","-nsorted" };
// : Run a sorting algorithm on the given input data + Write down the sorted array to the "output.txt" file
void command1(string Alg, string fileName, string Output) {
	cout << "ALGORITHM MODE" << endl;
	cout << "Algorithm: " << Alg << endl;
	ifstream fin(fileName);
	if (!fin) {
		cout << "Cannot open InputFile " << endl;
		return;
	}
	cout << "Input file: " << fileName << endl;
	int n = 0; // size of input file

	string buff; getline(fin, buff); // lưu dòng đầu để kiểm tra file có chứa "\xEF\xBB\xBF" làm đọc file bị lỗi không?
	char IdentifierUTF8[] = "\xEF\xBB\xBF";
	const char* firstline = buff.c_str(); // chuyển trừ string qua const char* để dùng strstr
	if (strstr(firstline, IdentifierUTF8) != nullptr) { // IdentifierUTF8 có xuất hiên trong dòng đầu của file => khác nullptr
		char* number =(char*) (firstline + 3*sizeof(char)); // bỏ qua 4 kí tự đầu (tính từ 0)
		n = atoi(number);
	}
	else
		n = stoi(buff);

	cout << "Input size: " << n << endl;
	int* a = new int[n];
	cout << "---------------------------------\n";
	for (int i = 0; i < n; i++)
		fin >> a[i];

	int x1 = 0;// stand for type of Sort
	for (x1 = 0; x1 < 11; x1++)
		if (sort_names[x1] == Alg)
			break;
	clock_t start, end;
	long long int com1 = 0;


	if (Output == "-time") {
		start = clock();
		SortAl(a, n, x1);
		end = clock();
		double time = (double)(end - start) / CLOCKS_PER_SEC * 1000;
		cout << "Running time (if required): " << fixed << time << endl;
		cout << "Comparisons(if required): NOT REQUIRED" << endl;

	}
	else if (Output == "-comp") {
		COUNT_SortAl(a, n, x1, com1);
		cout << "Running time (if required): NOT REQUIRED" << endl;
		cout << "Comparisons(if required): " << com1 << endl;

	}
	else if (Output == "-both") {
		int* b = new int[n];
		for (int i = 0; i < n; i++)
			b[i] = a[i];
		clock_t start, end;
		start = clock();
		SortAl(a, n, x1);
		end = clock();
		double time = (double)(end - start) / CLOCKS_PER_SEC * 1000;

		long long int com1 = 0;
		COUNT_SortAl(b, n, x1, com1);

		cout << "Running time (if required): " << fixed << time << endl;
		cout << "Comparisons(if required): " << com1 << endl;

		delete[] b;
	}
	else
		cout << "Wrong output parameters!";

	ofstream fout("output.txt");
	fout << n << endl;
	for (int i = 0; i < n - 1; i++)
		fout << a[i] << " ";
	fout << a[n - 1]; // để không dư dấu cách cuối file

	delete[] a;

}

// Run a sorting algorithm on the data generated automatically with specified size and order
// Write down the sorted array to the "output.txt" file.
// Write down the generated input to the "input.txt" file
void command2(string Alg, string inputSize, string  inputOrder, string Outputpara) {
	cout << "ALGORITHM MODE" << endl;
	cout << "Algorithm: " << Alg << endl;

	int x1 = 0;// stand for type of Sort
	for (x1 = 0; x1 < 11; x1++)
		if (sort_names[x1] == Alg)
			break;

	int n = stoi(inputSize);
	cout << "Input size: " << n << endl;

	int _order = 0;// input order;
	for (_order = 0; _order < 4; _order++)
		if (Order[_order] == inputOrder)
			break;
	cout << "Input order: " << inputOrder << endl;
	cout << "---------------------------------\n";
	int* a = new int[n];
	GenerateData(a, n, _order);

	//Write down the generated input to the "input.txt" file
	ofstream fout("input.txt");
	if (!fout) {
		cout << "cannot open input.txt in cmd2 ";
		return;
	}
	fout << n << endl;
	for (int i = 0; i < n - 1; i++)
		fout << a[i] << " ";
	fout << a[n - 1]; // để không dư dấu cách cuối file
	fout.close();


	clock_t start, end;
	long long int com1 = 0;

	if (Outputpara == "-time") {
		start = clock();
		SortAl(a, n, x1);
		end = clock();
		double time = (double)(end - start) / CLOCKS_PER_SEC * 1000;
		cout << "Running time (if required): " << fixed << time << endl;
		cout << "Comparisons(if required): NOT REQUIRED" << endl;

	}
	else if (Outputpara == "-comp") {
		COUNT_SortAl(a, n, x1, com1);
		cout << "Running time (if required): NOT REQUIRED" << endl;
		cout << "Comparisons(if required): " << com1 << endl;

	}
	else if (Outputpara == "-both") {
		int* b = new int[n];
		for (int i = 0; i < n; i++)
			b[i] = a[i];
		start = clock();
		SortAl(a, n, x1);
		end = clock();
		double time = (double)(end - start) / CLOCKS_PER_SEC * 1000;

		long long int com1 = 0;
		COUNT_SortAl(b, n, x1, com1);

		cout << "Running time (if required): " << fixed << time << endl;
		cout << "Comparisons(if required): " << com1 << endl;

		delete[] b;
	}
	else
		cout << "Wrong output parameters!";

	// write output
	ofstream fout_out("output.txt");
	fout_out << n << endl;
	for (int i = 0; i < n - 1; i++)
		fout_out << a[i] << " ";
	fout_out << a[n - 1]; // để không dư dấu cách cuối file
	fout_out.close();
}
void command3(string Alg, string inputSize, string Outputpara) {
	cout << "ALGORITHM MODE" << endl;
	cout << "Algorithm: " << Alg << endl;
	int x1 = 0;// stand for type of Sort
	for (x1 = 0; x1 < 11; x1++)
		if (sort_names[x1] == Alg)
			break;

	int n = stoi(inputSize);
	cout << "Input size: " << n << endl << endl;

	string Order[4] = { "Randomize","Reversed","Sorted","Nearly Sorted" };
	int realNo[4] = { 0,2,1,3 }; // chỉ số tương ứng dí switch case trong hàm Generate Data
	string InputFile[4] = { "input_1.txt", "input_4.txt", "input_3.txt", "input_2.txt" }; // mảng lưu tên fileInput ứng với thứ tự từng kiểu dữ liệu trong Order


	for (int i = 0; i < 4; i++) {

		int* a = new int[n];
		GenerateData(a, n, realNo[i]); // truyền vào số thứ tự ứng với kiểu dữ liệu

		/////////// write input 
		string filename = InputFile[i];
		ofstream fout(filename); // lấy tên file ứng với kiểu dữ liệu "Random", "Reverse" ,....
		if (!fout) {
			cout << "cannot open input_x.txt in cmd3 ";
			return;
		}
		if (filename == "input_4.txt")
			fout << "\xEF\xBB\xBF"; //  This is the UTF-8 byte order mark - identify the file as UTF-8.
		fout << n << endl; // ghi n
		for (int i = 0; i < n - 1; i++) // ghi từng phần tử trong mảng
			fout << a[i] << " ";
		fout << a[n - 1]; // để không dư dấu cách cuối file
		fout.close();

		cout << "Input order: " << Order[i] << endl;
		cout << "------------------------------\n";
		clock_t start, end;
		long long int com1 = 0;

		if (Outputpara == "-time") {
			start = clock();
			SortAl(a, n, x1);
			end = clock();
			double time = (double)(end - start) / CLOCKS_PER_SEC * 1000;
			cout << "Running time (if required): " << fixed << time << endl;
			cout << "Comparisons(if required): NOT REQUIRED" << endl;

		}
		else if (Outputpara == "-comp") {
			COUNT_SortAl(a, n, x1, com1);
			cout << "Running time (if required): NOT REQUIRED" << endl;
			cout << "Comparisons(if required): " << com1 << endl;

		}
		else if (Outputpara == "-both") {
			int* b = new int[n];
			for (int i = 0; i < n; i++)
				b[i] = a[i];
			start = clock();
			SortAl(a, n, x1);
			end = clock();
			double time = (double)(end - start) / CLOCKS_PER_SEC * 1000;

			long long int com1 = 0;
			COUNT_SortAl(b, n, x1, com1);

			cout << "Running time (if required): " << fixed << time << endl;
			cout << "Comparisons(if required): " << com1 << endl;

			delete[] b;
		}
		cout << endl << endl;
		delete[] a;
	}
}
void command4(string Al1, string Al2, string InputFile)
{
	ifstream fin(InputFile);
	if (!fin)
	{
		cout << "Can not read file" << endl;
		return;
	}
	int n; 


	string buff; getline(fin, buff); // lưu dòng đầu để kiểm tra file có chứa "\xEF\xBB\xBF" làm đọc file bị lỗi không?
	char IdentifierUTF8[] = "\xEF\xBB\xBF";
	const char* firstline = buff.c_str(); // chuyển trừ string qua const char* để dùng strstr
	if (strstr(firstline, IdentifierUTF8) != nullptr) { // IdentifierUTF8 có xuất hiên trong dòng đầu của file => khác nullptr
		char* number = (char*)(firstline + 3 * sizeof(char)); // bỏ qua 4 kí tự đầu (tính từ 0)
		n = atoi(number);
	}
	else
		n = stoi(buff);


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
	for (x1 = 0; x1 < 11; x1++)
		if (sort_names[x1] == Al1)
			break;
	for (x2 = 0; x2 < 11; x2++)
		if (sort_names[x2] == Al2)
			break;
	clock_t start1, end1, start2, end2;
	double time1 = 0, time2 = 0;
	start1 = clock();
	SortAl(a, n, x1);
	end1 = clock();
	start2 = clock();
	SortAl(b, n, x2);
	end2 = clock();
	time1 = (double)(end1 - start1) / CLOCKS_PER_SEC * 1000;
	time2 = (double)(end2 - start2) / CLOCKS_PER_SEC * 1000;
	cout << "Runtime: " << fixed << time1 << " | " << fixed << time2 << endl;

	// Comparison
	long long int com1 = 0;
	COUNT_SortAl(c, n, x1, com1);
	long long int com2 = 0;
	COUNT_SortAl(d, n, x2, com2);
	cout << "Comparisons: " << com1 << " | " << com2 << endl;
}

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
	for (x1 = 0; x1 < 11; x1++)
		if (sort_names[x1] == Al1)
			break;
	for (x2 = 0; x2 < 11; x2++)
		if (sort_names[x2] == Al2)
			break;

	string InputFileName = "input.txt";
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

	// đo thời gian chạy
	start1 = clock();
	SortAl(a, n, x1);
	end1 = clock();

	start2 = clock();
	SortAl(b, n, x2);
	end2 = clock();

	// in ra màn hình 
	time1 = (double)(end1 - start1) / CLOCKS_PER_SEC * 1000;
	time2 = (double)(end2 - start2) / CLOCKS_PER_SEC * 1000;
	cout << "Runtime: " << fixed << time1 << " | " << fixed << time2 << endl;

	// Comparison
	long long int com1 = 0;
	COUNT_SortAl(c, n, x1, com1);

	long long int com2 = 0;
	COUNT_SortAl(d, n, x2, com2);

	// in kq ra màn hình
	cout << "Comparisons: " << com1 << " | " << com2 << endl;
}
