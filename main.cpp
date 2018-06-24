#include <iostream>
#include <stdexcept>

template<class T>
class list
{
public:
    using value_type = T;
    using size_type = std::size_t;
    using reference = T&;
    using const_reference = const T&;
    using pointer = T*;
    using const_pointer = const T*;
private:
    struct Node
    {
        T data;
        Node* next;
        Node* prev;
        Node(const_reference _data, Node* _next, Node* _prev) : data(_data), next(_next), prev(_prev) {}
    };

    size_type list_size = 0;
    Node* head;
    Node* tail;

public:

    using iterator = Node*;
    using reverse_iterator = T*;
    using const_iterator = const T*;
    using const_reverse_iterator = const T*;

    list() = default;
    //Element access
    reference front();
    reference back();
    const_reference front() const;
    const_reference back() const;

    //Iterators
    iterator begin() noexcept;
    iterator end() noexcept;

    const_iterator cbegin() const noexcept;
    const_iterator cend() const noexcept;

    reverse_iterator rbegin() noexcept;
    reverse_iterator rend() noexcept;

    //Capacity
    bool empty() const noexcept;
    size_type size() const noexcept;
    size_type max_size() const noexcept;

    //Modifiers
    void clear() noexcept;
    iterator insert(iterator pos, const_reference value);
    iterator erase(iterator pos);
    void push_back(const_reference value);
    void pop_back();
    void push_front(const_reference value);
    void pop_front();
    void swap(list& other);
};
//-------------------------------------------------------------
//Element access
template<class T>
typename list<T>::reference list<T>::front()
{
    if(head == nullptr)
        throw std::runtime_error("Head is nullptr");
    return head->data;
}

template<class T>
typename list<T>::reference list<T>::back()
{
    if(head == nullptr)
        throw std::runtime_error("Tail is nullptr");
    return tail->data;
}

//-------------------------------------------------------------
//Iterators
template<class T>
typename list<T>::iterator list<T>::begin() noexcept
{
    return head;
}

template<class T>
typename list<T>::iterator list<T>::end() noexcept
{
    return tail;
}

template<class T>
typename list<T>::const_iterator list<T>::cbegin() const noexcept
{
    return head;
}

template<class T>
typename list<T>::const_iterator list<T>::cend() const noexcept
{
    return tail;
}

template<class T>
typename list<T>::reverse_iterator list<T>::rbegin() noexcept
{
    return tail;
}

template<class T>
typename list<T>::reverse_iterator list<T>::rend() noexcept
{
    return head;
}

//-------------------------------------------------------------
//Capacity

template<class T>
bool list<T>::empty() const noexcept
{
    return head == nullptr;
}

template<class T>
typename list<T>::size_type list<T>::size() const noexcept
{
    return list_size;
}

template<class T>
typename list<T>::size_type list<T>::max_size() const noexcept
{
    return 18446744073709551615;
}

//-------------------------------------------------------------
//Modifiers

template<class T>
void list<T>::push_back(list<T>::const_reference value)
{

    if(head == nullptr)
        head = new Node(value, nullptr, tail);
    if(tail != nullptr)
        tail->next = new Node(value, nullptr, tail);
    tail = new Node(value, nullptr, tail);
    ++list_size;
}


int main()
{
    list<int> l;
    l.push_back(4);
    l.push_back(4);

    std::cout << l.size();
    return 0;
}
