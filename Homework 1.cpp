#include <iostream>
#include <fstream>

int main()
{
    setlocale(LC_ALL, "Russian");
    std::ifstream file("C:\\C++\\Homework 1\\in.txt"); // тут напишите свой путь к файлу.
    if (file.is_open()) {
        while (file.peek() != EOF) {
            int size = 0, number = 0;
            file >> size;
            int* arr = new int[size];
            for (int i = (size - 1); i > -1; i--) {
                file >> arr[i];
            }
            std::ofstream out("C:\\C++\\Homework 1\\out.txt", std::ios::app); // тут напишите свой путь к файлу.
            out << size; out << '\n';
            for (int i = 0; i < size; i++) {
                out << arr[i];
                out << ' ';
            }
            out << '\n';
            delete[] arr;
        }
    }
    else {
        std::cout << "Файл не открылся" << std::endl;
    }
}