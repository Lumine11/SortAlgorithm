// Lab 3_SA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include"GenerateData.h" // header chứa Generate Data
#include"Timing.h" // header chứ các thuật toán sắp xếp _ đo thời gian
#include "CountingComparison.h"// header chứa các thuật toán sắp xếp - đo số lần so sánh
#include "cmd.h"
#include "Experiments.h"; // header chứ hàm Experiments để chạy ghi kết quả + vẽ biểu đồ

int main(int argc, char* argv[])
{
        // chạy và ghi kết quả vào
        //Experiments();
        
        if (argc == 5) {
            if (_stricmp(argv[1], "-a") == 0) { // khác nhau giữa 1 và 3 là InputSize và Filename
                ifstream fin(argv[3]);
                if (!fin)
                     command3(argv[2], argv[3], argv[4]);// Không tồn tại file => đây là size
                else{
                    fin.close();
                    command1(argv[2], argv[3], argv[4]);
                }
            }
            else
                command4(argv[2], argv[3], argv[4]);
        }
        else
            if (argc == 6) {
                if (_stricmp(argv[1], "-a") == 0)
                    command2(argv[2], argv[3], argv[4], argv[5]);
                else
                    command5(argv[2], argv[3], argv[4], argv[5]);
            }

    ///// test cmd
    //string Al1 = "quick-sort", InputSize = "300000", InputOrder = "-sorted", Outputpara = "-both";
    //// string Alg, string inputSize, string  inputOrder, string Outputpara
    //command1(Al1, "input_4.txt", Outputpara);

}