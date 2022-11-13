#include <iostream>
#include <fstream>

int main()
{
    setlocale(LC_ALL, "Russian");
    std::ifstream file("in.txt");
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
        file.close();

        std::ofstream out("out.txt", std::ios::app);
        if (out.is_open()) {
            out << size_M; out << '\n';
            out << arr_M[size_M - 1]; out << ' ';
            for (int i = 0; i < (size_M - 1); i++) {
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
            out.close();
        }
        else {
            std::cout << "Файл для записи не открылся" << std::endl;
        }
    }
    else {
        std::cout << "Файл не открылся" << std::endl;
    }
}