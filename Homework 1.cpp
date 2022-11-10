#include <iostream>
#include <fstream>

int main()
{
    setlocale(LC_ALL, "Russian");
    std::ifstream file("C:\\C++\\Homework 1\\in.txt"); // тут напишите свой путь к файлу.
    if (file.is_open()) {
        int size_N = 0, number_N = 0;
        file >> size_N;
        int* arr_N = new int[size_N];
        for (int i = 0; i < size_N; i++) {
            file >> arr_N[i];
        }

        int size_M = 0, number_M = 0;
        file >> size_M;
        int* arr_M = new int[size_M];
        for (int i = 0; i < size_M; i++) {
            file >> arr_M[i];
        }

        std::ofstream out("C:\\C++\\Homework 1\\out.txt", std::ios::app); // тут напишите свой путь к файлу.
        out << size_M; out << '\n';
        out << arr_M[size_M - 1]; out << ' ';
        for (int i = 0; i < (size_M-1); i++) {
            out << arr_M[i];
            out << ' ';
        }
        out << '\n';
        delete[] arr_M;

        out << size_N; out << '\n';
        for (int i = 1; i < size_N; i++) {
            out << arr_N[i];
            out << ' ';
        }
        out << arr_N[0]; out << '\n';
        delete[] arr_N;
    }
    else {
        std::cout << "Файл не открылся" << std::endl;
    }
}