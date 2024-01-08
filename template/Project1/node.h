#pragma once
template <typename T>
struct Node {
    Node (T data, Node* next=nullptr);
    T data; 
    Node* next;
};
template <typename T>
Node <T>::Node(T data, Node* next):
    data(data), next(next)
    {

    }




