#include <iostream>
#include "src/List.h"
int main() {
    List temp_list;
    for (int i = 0; i < 10; i++) temp_list.push_back(i);
    std::cout << temp_list.to_string()<< '\n';
    List subList;
    temp_list.sublist(0, 9, subList);
    std::cout << temp_list.to_string()<< '\n';
    std::cout << subList.to_string() << '\n';
}
