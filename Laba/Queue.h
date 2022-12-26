#include "Header.h"


template <class DataT> class Node
{
    template <class DataT>
    friend class Queue;
    DataT* data;
    Node *prev, *next;
    static Node* getnode(DataT &data);
};

template <class DataT>
Node<DataT>* Node<DataT>::getnode(DataT &data)
{
    Node* newNode = new Node<DataT>;
    newNode->data = &data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

template <class DataT> class Queue
{
    Node<DataT>* front;
    Node<DataT>* rear;
    int Size;
public:
    Queue()
    {
        front = rear = NULL;
        Size = 0;
    }
    ~Queue()
    {
        erase();
    }
    void insertFront(DataT &data);
    void insertNumber(DataT &data, int number);
    void insertRear(DataT &data);
    void deleteFront();
    void deleteNumber(int number);
    void deleteRear();
    DataT getFront();
    DataT getRear();
    DataT getNumber(int number);
    int size();
    bool isEmpty();
    void Print();
    void erase();
};

template <class DataT>
bool Queue<DataT>::isEmpty()
{
    return (front == NULL);
}

template <class DataT>
int Queue<DataT>::size()
{
    return Size;
}

template <class DataT>
void Queue<DataT>::insertFront(DataT &data)
{
    Node<DataT>* newNode = Node<DataT>::getnode(data);
    if (newNode == NULL)
        throw MyException("Overflow");
    else
    {
        if (front == NULL)
            rear = front = newNode;
        else
        {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }

        Size++;
    }
}

template<class DataT>
void Queue<DataT>::insertNumber(DataT &data, int number)
{
    Node<DataT>* newNode = Node<DataT>::getnode(data);
    if (newNode == NULL || number + 1 > size())
        throw MyException("Overflow");
    else if (number == 0) {
        insertFront(data);
    }
    else if (number == size()) {
        insertRear(data);
    }
    else {
        Node<DataT>* temp = front;
        for (int i = 0; i < number; i++)
        {
            temp = temp->next;
        }
        newNode->prev = temp->prev;
            temp->prev->next = newNode;
        newNode->next = temp;
        temp->prev = newNode;
        temp = newNode;
    }
    Size++;
}

template <class DataT>
void Queue<DataT>::insertRear(DataT &data)
{
    Node<DataT>* newNode = Node<DataT>::getnode(data);
    if (newNode == NULL)
        throw MyException("Overflow");
    else
    {
        if (rear == NULL)
            front = rear = newNode;
        else
        {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
        Size++;
    }
}

template <class DataT>
void Queue<DataT>::deleteFront()
{
    if (isEmpty())
        throw MyException("Underflow");
    else
    {
        Node<DataT>* temp = front;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        else
            front->prev = NULL;
        delete temp;
        Size--;
    }
}

template<class DataT>
void Queue<DataT>::deleteNumber(int number)
{
    if (isEmpty()) {
        throw MyException("Underflow");
    }
    else if (number == 0) {
        deleteFront();
    }
    else if (number == size() - 1) {
        deleteRear();
    }
    else {
        Node<DataT>* temp = front;
        for (int i = 0; i < number; i++)
        {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        Size--;
    }
}

template <class DataT>
void Queue<DataT>::deleteRear()
{
    if (isEmpty())
        throw MyException("Underflow");
    else
    {
        Node<DataT>* temp = rear;
        rear = rear->prev;

        if (rear == NULL)
            front = NULL;
        else
            rear->next = NULL;
        delete temp;

        Size--;
    }
}

template <class DataT>
DataT Queue<DataT>::getFront()
{
    if (isEmpty())
        return -1;
    return *(front->data);
}

template <class DataT>
DataT Queue<DataT>::getRear()
{
    if (isEmpty())
        return -1;
    return *(rear->data);
}

template <class DataT>
DataT Queue<DataT>::getNumber(int number)
{
    if (isEmpty())
        throw MyException("Underflow");
    else
    {
        Node<DataT>* temp = front;
        for (int i = 0; i < number; i++)
        {
            temp = temp->next;
        }
        return *(temp->data);
    }
}

void Queue<int>::Print()
{
    Node<int>* temp = front;
    while (temp != rear) {
        cout << *(temp->data) << " ";
        temp = temp->next;
    }
    cout << *(temp->data) << endl;
}

void Queue<float>::Print()
{
    Node<float>* temp = front;
    while (temp != rear) {
        cout << *(temp->data) << " ";
        temp = temp->next;
    }
    cout << *(temp->data) << endl;
}

void Queue<Matrix>::Print()
{
    try {
        Node<Matrix>* temp = front;
        while (temp != rear) {
            cout << *(temp->data) << " ";
            temp = temp->next;
        }
        cout << *(temp->data) << endl;
    }
    catch (MyException& e) {
        throw e;
    }
}

template <class DataT>
void Queue<DataT>::erase()
{
    rear = NULL;
    while (front != NULL)
    {
        Node<DataT>* temp = front;
        front = front->next;
        delete temp;
    }
    Size = 0;
}