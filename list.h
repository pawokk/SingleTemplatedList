#pragma once
#include "node.h"
#include <iostream>
#include <string>
#include <sstream>
template <typename T>
class list {
    public:
        //Констуктор по умолчанию
        list ();
        //Констуктор с листом инициализации
        list (std::initializer_list <T> list);
        //Деструткор по умолчанию
        ~list();
        //Конструктор копирования
        list (const list & list2);
        //Конструткор перемещения
        list (list && list2);
        //Добавление эелементов в конец списка
        void pushBack (const T & data);
        //Проверка на пустоту
        bool isempty ();
        //Перевод массива в строчку
        std::string tostring();
        //Перегрузка оператора сравнения
        bool operator==(list & list2);
        //Перегрузка оператора копирования
        list & operator=(const list & list2);
        //Удаление первого элемента
        void pop();

    private:
        Node <T>* first;
        size_t size;
};
template <typename T>
list <T>::list():
    first(nullptr), size(0)
{

}
template <typename T>
list <T>::list (std::initializer_list <T> list):
    first (nullptr), size (0)
{

}
template <typename T>
list <T>::~list ()
{
    while (size != 0)
    {
        pop ();
    }
}
template <typename T>
list <T>::list (const list & list2)
{
    if (this->first==nullptr)
    {
        for (Node <T>* node=list2.first; node != nullptr; node=node->next)
        {
            this->pushBack(node->data);

        }
    }
}
template <typename T>
void list <T>::pushBack (const T & data)
{
    if (first==nullptr) 
    {
        first=new Node <T> (data);

    }
    else 
    {
        Node <T>* thisNode=first;
        while (thisNode->next!=nullptr)
        {
            thisNode=thisNode->next;
        }
        thisNode->next=new Node <T> (data);

    }
    size++;
}
template <typename T>
bool list <T>::isempty()
{
    return size==0;
}

template <typename T> 
std::string list<T>::tostring() 
{      
    std::stringstream buffer;      
    if (first != nullptr)     
    {        
        Node<T>* thisNode = first;          
        for (size_t i = 0; i < size; i++)         
        {             
            buffer << thisNode->data << " ";              
            thisNode = thisNode->next;         
        }     
    }       
    return buffer.str(); 
}
template <typename T>
bool list <T>::operator==(list & list2)
{
    return (this->tostring()==list2.tostring());

}
template <typename T>
list <T> & list <T>::operator=(const list & list2)
{
    if (this!=list2)
    {
        list <T> tempo (list2);
        std::swap(tempo.first, this->first);
        std::swap(tempo.size, this->size);
    }
    return*this;
}
template <typename T>
void list <T>::pop()
{
    Node <T>*tempo=first;
    first=first->next;
    size--;
    delete tempo;
}