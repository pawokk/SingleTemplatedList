#include "list.h"
int main()
{
    list <int> list1;
    list1.pushBack(5);
    list1.pushBack(7);
    std::cout<<list1.tostring();
    list <std::string> list2;
    list2.pushBack("qw");
    list2.pushBack("wr");
    std::cout<<list2.tostring();
}