#include <iostream>
#include "src/List.cpp"
#include "src/Node.cpp"
int main() {
    List<int> temp_list;
    auto lambda = [](int a){return std::to_string(a);};
    for (int i = 0; i < 10; i++) temp_list.push_back(i);
    std::cout << temp_list.to_string(lambda)<< '\n';
    List<int> subList;
    temp_list.sublist(0, 9, subList);
    std::cout << temp_list.to_string(lambda)<< '\n';
    std::cout << subList.to_string(lambda) << '\n';
}
