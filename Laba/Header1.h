#pragma once
#include "Header.h"

template <class DataT> class Node {
    template <class T>
    friend class Queue;
    DataT Data;
    Node<DataT> *Next, *Pred;
    Node();
    ~Node();
    Node* Init(DataT DataItem);
    void Print();
    Node* Insert(int Number, DataT DataItem);
    Node* Delete(int Number);   
};

template <class DataT>
Node<DataT>::Node() {
    Data = NULL;
    Next = NULL;
    Pred = NULL;
}

template <class DataT>
Node<DataT>::~Node() {
    if (Pred != NULL) {
        delete Pred;
    }
    if (Next != NULL) {
        delete Next;
    }
}


template <class DataT>
Node<DataT>* Node<DataT>::Init(DataT DataItem) {
    Data = DataItem;

}

template <class DataT>
void Node<DataT>::Print() {
    cout << this->Data << "\t";
    if (this->Next != NULL)
        this->Next->Print();
    else
        cout << "\n";
}


template<class DataT>
Node<DataT>* Node<DataT>::Insert(int Number, DataT DataItem) {
    Node<DataT>* NewItem = new Node<DataT>;
    Node<DataT>* Current = this;
    NewItem‚Û
    for (int i = 1; i < Number && Current->Next != NULL; i++)
        Current = Current->Next;
    if (Number == 0) {
        NewItem->Next = this;
        Head->Pred = NewItem;
        Head = NewItem;
    }
    else {
        if (Current->Next != NULL) Current->Next->Pred = NewItem;
        NewItem->Next = Current->Next;
        Current->Next = NewItem;
        NewItem->Pred = Current;
        Current = NewItem;
    }
    return Head;
}


template<class DataT>
Node<DataT>* Node<DataT>::Delete(int Number) {
    Node* ptr;
    Node* Current = Head;
    for (int i = 1; i < Number && Current != NULL; i++)
        Current = Current->Next;
    if (Current != NULL) {
        if (Current->Pred == NULL) {
            Head = Head->Next;
            delete(Current);
            if (Head != 0) Head->Pred = NULL;
            Current = Head;
        }
        else {
            if (Current->Next == NULL) {
                Current->Pred->Next = NULL;
                delete(Current);
                Current = Head;
            }
            else {
                ptr = Current->Next;
                Current->Pred->Next = Current->Next;
                Current->Next->Pred = Current->Pred;
                delete(Current);
                Current = ptr;
            }
        }
    }
    return Head;
}

template<class DataT>
inline Queue<DataT>::Queue()
{
    Begin = NULL;
    End = NULL;
}

//template<class DataT>
//void Queue<DataT>::Make_Queue(int n, DataT Data[]) {
//    Make_Node(n, &(this->Begin), NULL, Data);
//    
//}

template<class DataT>
bool Queue<DataT>::Empty_Node(Node<DataT>* Head) {
    if (Head != NULL) return false;
    else return true;
}

template<class DataT>
void Queue<DataT>::Print_Queue() {
    Print(this->Begin);
    Print(this->End);
}

template<class DataT>
void Queue<DataT>::Add_Item_Queue(DataT NewElem) {
    if (this->Begin = NULL) {
        this->Begin = Begin->Init()
    }
    else
        this->End = Insert(this->End, 0, NewElem)->Next;
    Node* ptr;
    ptr = this->Begin;
    while (ptr->Next != NULL)
        ptr = ptr->Next;
    this->End = ptr;
}

template<class DataT>
int Queue<DataT>::Extract_Item_Queue() {
    int NewElem = NULL;
    if (this->Begin != NULL) {
        NewElem = this->Begin->Data;
        this->Begin = Delete(this->Begin, 0);
    }
    return NewElem;
}

template<class DataT>
bool Queue<DataT>::Empty_Queue() {
    return Empty_Node(this->Begin);
}

template<class DataT>
void Queue<DataT>::Clear_Queue() {
    return Delete_Node(this->Begin);
}

template<class DataT>
int Queue<DataT>::Find_Max_Negative_Element() {
    int tmp;
    int max = Extract_Item_Queue(this);
    while (this->Begin->Data != 0) {
        tmp = Extract_Item_Queue(this);
        if (max < tmp)
        {
            max = tmp;
        }
    }
    return max;
}
template <class DataT> class Queue {
    Node<DataT>* Begin, * End;
public:
    Queue();
    void Make_Queue(int n, DataT Data[]);
    bool Empty_Node(Node<DataT>* Head);
    void Print_Queue();
    void Add_Item_Queue(DataT NewElem);
    int Extract_Item_Queue();
    bool Empty_Queue();
    void Clear_Queue();
    int Find_Max_Negative_Element();
};