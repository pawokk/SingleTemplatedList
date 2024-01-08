#include "list.h"
int main()
{
    Deck <int> list1;
    list1.pushBack(2);
    list1.pushBack(3);
    Deck<int> list2(list1);
    list1.pushBack(4);
    std::cout << list2.toString();

}