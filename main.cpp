#include <iostream>
#include <fstream>
#include <Windows.h>
#include "src/List.cpp"
#include "src/Node.cpp"
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    List<int> list;
    std::string inp, out;
    std::cout << "Введите путь к файлу для считывания: ";
    std::cin >> inp;
    std::cout << "Введите путь к файлу для записи: ";
    std::cin >> out;
    std::ifstream file_inp(inp);
    if (file_inp.is_open()){
        bool error = false;
        while (!file_inp.eof()){
            try{
                std::string buffer;
                file_inp >> buffer;
                int temp = std::stoi(buffer);
                list.push_back(temp);
            }
            catch (std::exception) {
                error = true;
                break;
            }
        }
        if (!error && !list.empty()){
            auto printer = [](int x){return std::to_string(x);};
            auto more = [](int left, int right){return left > right;};
            auto odd = [](int x){return x%2 == 0;};
            List<int> odder;
            std::cout << list.to_string(printer)<< '\n';
            list.sort(more);
            std::cout << list.to_string(printer) << '\n';
            list.check(odd, odder);
            std::cout << odder.to_string(printer) << '\n';
            int begin = -1;
            int end = -1;
            for (int i = 1; i < odder.size(); i++) {
                if (odder[i] - odder[i - 1] == 1) {
                    if (end == i - 1) end = i;
                    else {
                        begin = i - 1;
                        end = i;
                    }
                }
            }
            std::ofstream file_out(out);
            if (file_out.is_open()) {
                if (begin != -1) {
                    List<int> subList;
                    list.sublist(begin, end, subList);
                    list.add(0, subList);
                }
                file_out << '\n' << list.to_string(printer);
                if (begin == - 1){
                    file_out << '\n' << "Нет чётных чисел в последовательности.";
                }
            }
            else {
                std::cout << "Нет доступа к файлу.";
            }
        }
        else {
            std::cout << "Ошибка при чтении файла.";
        }
    }
    else std::cout << "Файл не был открыт.";
}
