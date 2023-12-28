#include "list.h"
int main()
{
    Deck <int> list1;
    list1.pushBack(5);
    list1.pushBack(7);
    std::cout<<list1.tostring();
    Deck <std::string> list2;
    list2.pushBack("qw");
    list2.pushBack("wr");
    std::cout<<list2.tostring();
    std::cout<<list2.peekBack();
    std::cout<<list2.peekFront();
}