#include <iostream>
#include "src/List.cpp"
#include "src/Node.cpp"
int main() {
    List<int> temp_list;
    auto lambda = [](int a){return std::to_string(a);};
    auto comparator = [](int x, int y){return x > y;};
    temp_list.push_back(3);
    temp_list.push_back(4);
    temp_list.push_back(5);
    temp_list.push_back(6);
    temp_list.push_back(9);
    temp_list.push_back(10);
    temp_list.push_back(7);
    temp_list.push_back(2);
    temp_list.push_back(1);
    temp_list.push_back(8);
    temp_list.push_back(10);
    std::cout << temp_list.to_string(lambda)<< '\n';
    temp_list.sort(comparator);
    std::cout << temp_list.to_string(lambda)<< '\n';
    List<int> sublist;
    temp_list.sublist(1,5,sublist);
    std::cout << sublist.to_string(lambda)<< '\n';
    std::cout << sublist[2];
}
