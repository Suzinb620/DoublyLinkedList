#pragma once
#include <functional>

template<typename T>
class List
{
public:
    struct Node
    {
        T data;
        Node* next;
        Node* prev;
    };
    
    class ConstIterator
    {
        friend class List;

    protected:
        Node* p;
        List* l;

    public:
        ConstIterator(Node* p, List* l) : p(p), l(l) {}

        ConstIterator& operator ++();
        ConstIterator operator ++(int);
        ConstIterator& operator --();
        ConstIterator operator --(int);
        bool operator != (const ConstIterator& it) { return p != it.p; }
        bool operator == (const ConstIterator& it) { return p == it.p; }
        const T& operator *() { return p->data; }
        const T& operator ->() { return p->data; }
    };

    class Iterator : public ConstIterator
    {
    public:
        Iterator(Node* p, List* l) : ConstIterator(p, l) {}

        Iterator& operator ++();
        Iterator operator ++(int);
        Iterator& operator --();
        Iterator operator --(int);
        T& operator *() { return this->p->data; }
        T& operator ->() { return this->p->data; }
    };

private:
    Node* head;
    Node* tail;

public:
    List() : head(nullptr), tail(nullptr) {}
    List(const size_t& size, const std::function<T(const size_t i)>& function);
    List(const std::initializer_list<T>& il);
    List(const List& list_to_copy);
    List(List&& list_to_move);
    ~List();

    void push_back(const T& element);
    void pop_back();
    void push_front(const T& element);
    void pop_front();
    void insert(Iterator it, const T& element);
    void erase(Iterator it);
    void clear();
    bool empty() { return size() == 0 ? true : false; }
    Iterator find(const T& element);
    size_t size();
    ConstIterator begin() const { return ConstIterator(head, this); }
    ConstIterator end() const { return !empty() ? ConstIterator(tail->next, this) : begin(); }
    Iterator begin() { return Iterator(head, this); }
    Iterator end() { return !empty() ? Iterator(tail->next, this) : begin(); }

    List& operator =(const List& rhs);
    List& operator =(List&& rhs);
};


/////DEFINICJE/////


//ConstIterator operator preinkrementacji
template<typename T>
typename List<T>::ConstIterator& List<T>::ConstIterator::operator ++()
{
    if (p != nullptr)
        p = p->next;
    return *this;
}

//ConstIterator operator postinkrementacji
template<typename T>
typename List<T>::ConstIterator List<T>::ConstIterator::operator ++(int)
{
    ConstIterator it = *this;
    ++* this;
    return it;
}

//ConstIterator operator predekrementacji
template<typename T>
typename List<T>::ConstIterator& List<T>::ConstIterator::operator --()
{
    if (p == nullptr)
        p = l->tail;
    else if (p->prev != nullptr)
        p = p->prev;
    return *this;
}

//ConstIterator operator postdekrementacji
template<typename T>
typename List<T>::ConstIterator List<T>::ConstIterator::operator --(int)
{
    ConstIterator it = *this;
    --* this;
    return it;
}

//Iterator operator preinkrementacji
template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator ++()
{
    if (this->p != nullptr)
        this->p = this->p->next;
    return *this;
}

//Iterator operator postinkrementacji
template<typename T>
typename List<T>::Iterator List<T>::Iterator::operator ++(int)
{
    Iterator it = *this;
    ++* this;
    return it;
}

//Iterator operator predekrementacji
template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator --()
{
    if (this->p == nullptr)
        this->p = this->l->tail;
    else if (this->p->prev != nullptr)
        this->p = this->p->prev;
    return *this;
}

//Iterator operator postdekrementacji
template<typename T>
typename List<T>::Iterator List<T>::Iterator::operator --(int)
{
    Iterator it = *this;
    --* this;
    return it;
}

//konstruktor funkcyjny
template<typename T>
List<T>::List(const size_t& size, const std::function<T(const size_t i)>& function)
{
    for (size_t i = 0; i < size; i++)
        push_back(function(i));
}

//konstruktor initializer_list
template<typename T>
List<T>::List(const std::initializer_list<T>& il)
{
    for (const auto& arg : il)
        push_back(arg);
}

//konstruktor kopiujacy
template<typename T>
List<T>::List(const List& list_to_copy)
{
    clear();
    Node* temp = list_to_copy.head;
    while (temp != nullptr)
    {
        push_back(temp->data);
        temp = temp->next;
    }
}

//konstruktor przenoszacy
template<typename T>
List<T>::List(List&& list_to_move) : head(list_to_move.head), tail(list_to_move.tail)
{
    list_to_move.head = nullptr;
    list_to_move.tail = nullptr;
}

//destruktor
template<typename T>
List<T>::~List()
{
    while (head != nullptr)
    {
        Node* to_delete = head;
        head = head->next;
        delete to_delete;
    }
}

//push_back()
template<typename T>
void List<T>::push_back(const T& element)
{
    Node* temp = new Node();
    temp->data = element;
    temp->next = nullptr;
    temp->prev = nullptr;

    if (head == nullptr)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
}

//pop_back()
template<typename T>
void List<T>::pop_back()
{
    if (tail != head)
    {
        Node* temp = new Node();
        temp = tail;
        tail = temp->prev;
        tail->next = nullptr;
        delete temp;
    }
    else
        head = nullptr;
}

//push_front()
template<typename T>
void List<T>::push_front(const T& element)
{
    if (!empty())
    {
        Node* temp = new Node();
        temp->data = element;
        temp->prev = nullptr;
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    else
        push_back(element);
}

//pop_front()
template<typename T>
void List<T>::pop_front()
{
    if (head != tail)
    {
        Node* to_delete = head;
        head->next->prev = nullptr;
        head = head->next;
        delete to_delete;
    }
    else
        head = nullptr;
}

//insert()
template<typename T>
void List<T>::insert(Iterator it, const T& element)
{
    if (it != end() && it != begin() && it != --end())
    {
        Node* temp = new Node();
        temp->data = element;
        temp->prev = it.p->prev;
        temp->next = it.p;
        it.p->prev->next = temp;
        it.p->next->prev = temp;
        it.p = temp;
    }
    else if (it == --end() && !empty())
    {
        push_back(it.p->data);
        it.p->data = element;
    }
    else if (it == begin() && !empty())
        push_front(element);
    else if (it == end() || empty())
        push_back(element);
}

//erase()
template<typename T>
void List<T>::erase(Iterator it)
{
    if (it != --end() && it != begin() && it != end())
    {
        it.p->prev->next = it.p->next;
        it.p->next->prev = it.p->prev;
        delete it.p;
    }
    else if (it == begin() && !empty())
        pop_front();
    else if (it == --end())
        pop_back();
}

//clear()
template<typename T>
void List<T>::clear()
{
    if (size() == 1)
    {
        head = nullptr;
        tail = nullptr;
    }
    else if (size() > 1)
    {
        Node* temp = head->next;
        while (temp != nullptr)
        {
            Node* to_delete = temp;
            temp = temp->next;
            delete to_delete;
        }
        head = nullptr;
        tail = nullptr;
    }
}

//find()
template<typename T>
typename List<T>::Iterator List<T>::find(const T& element)
{
    auto it = begin();
    while (it.p != nullptr && it.p->data != element)
        it++;
    return it;
}

//size()
template<typename T>
size_t List<T>::size()
{
    size_t size = 0;
    Node* temp = head;
    while (temp != nullptr)
    {
        size++;
        temp = temp->next;
    }
    return size;
}

//operator przypisania
template<typename T>
List<T>& List<T>::operator =(const List<T>& rhs)
{
    if (&rhs != this)
    {
        clear();
        Node* temp = rhs.head;
        while (temp != nullptr)
        {
            push_back(temp->data);
            temp = temp->next;
        }
    }
    return *this;
}

//operator przenoszacy
template<typename T>
List<T>& List<T>::operator =(List<T>&& rhs)
{
    if (&rhs != this)
    {
        clear();
        head = rhs.head;
        tail = rhs.tail;
        rhs.head = nullptr;
        rhs.tail = nullptr;
    }
    return *this;
}