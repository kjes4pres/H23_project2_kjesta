#include <iostream>
#include <stdexcept>
#include <vector>

struct Node
{
    // The value at the node
    int value;
    // Pointer to the next node
    Node *next = nullptr;
    // Pointer to the previous node
    Node *prev = nullptr;
};

class LinkedList
{
  private:
    // Pointer to the first element in the list
    Node *head = nullptr;

    // Pointer to the last element in the list
    Node *tail = nullptr;

    // Size of the list
    int _size = 0;

    /**
     * @brief Check wheter the given index if out of
     * bound and throw a range error if it is
     *
     * @param index The index to be checked
     */
    void check_index_out_of_bounds(int index)
    {
        if ((index < 0) || (index >= length()))
            throw std::range_error("Index out of bounds");
    }

  public:
    // Default constructor
    LinkedList()
    {
    }

    // Overloaded constructor
    LinkedList(std::vector<int> values)
    {
        for (int v : values)
        {
            append(v);
        }
    }

    // Destructor
    ~LinkedList()
    {
        Node *current = head;
        Node *next = nullptr;
        // Move node until we are at the last element
        while (current != nullptr)
        {
            next = current->next;
            delete current;
            current = next;
        }
    }

    /**
     * @brief Print values in the list
     *
     */
    void print()
    {
        std::cout << "[";
        if (head != nullptr)
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                std::cout << current->value;
                std::cout << ", ";
                current = current->next;
            }
            std::cout << current->value;
        }
        std::cout << "]\n";
    }

    /**
     * @brief Return the length of the list
     *
     * @return int The length
     */
    int length()
    {
        return _size;
    }

    /**
     * @brief Add element to the beginning of the list
     *
     * @param val The value to be added
     */
    void push_front(int val)
    {
        // Making a new Node for the value we want to insert at front of list
        Node *newNode = new Node{val, head, nullptr};

        if (_size == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else {
            head->prev = newNode;
            head = newNode;
        }
        _size++;
    }

    /**
     * @brief Add element to the end of the list
     *
     * @param val The value to be added
     */
    void append(int val)
    {
     Node *newNode = new Node{val, nullptr, tail};
     if (_size == 0)
     {
        head = newNode;
        tail = newNode;
     }
     else {
        tail->next = newNode;
        tail = newNode;
     }
        _size++;
    }


/**
     * @brief Overloads the square bracket operator to access elements by index
     *
     * @param index The index to be accessed
     */
    int &operator[](int index)
    {
        if (index > _size || index < 0)
        {
            throw std::out_of_range("Index " + std::to_string(index) + " is out of range.");
        }
        
        int current_index = 0;
        Node *current = head;
        while (current != nullptr)
        {
            if (current_index == index)
            {
                return current->value;
            }
            current = current->next;
            current_index++;
        }
        throw std::out_of_range("Index " + std::to_string(index) + " is out of range.");
    }

/**
     * @brief Insert element into list at given index
     *
     * @param val The value to be inserted
     * @param index The index where value will be inserted.
     */
    void insert(int val, int index)
    {
        if (index > _size || index < 0)
        {
            throw std::out_of_range("Index " + std::to_string(index) + " is out of range.");
        }

        Node *newNode = new Node{val, nullptr, nullptr};

     if (index == 0)
     {
        push_front(val);
     }
     else if (index == _size)
     {
        append(val);
     }
     else
     {
        Node *current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        // Now current is pointing to the index  we want to insert at.
        newNode->next = current;
        newNode->prev = current->prev;

        current->prev->next = newNode;
        current->prev = newNode;
        _size++;
     }
    }

/**
     * @brief Removes element at given index
     *
     * @param index The index where value will be removed
     */
    void remove(int index)
    {
     if (index > _size || index < 0)
        {
            throw std::out_of_range("Index " + std::to_string(index) + " is out of range.");
        }  

    if (index == 0)
    {
            Node *temporary = head;
            head = head->next;
            head->prev = nullptr;
            delete temporary;
    }

    else if (index == _size - 1)
    {
        Node *temporary = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temporary;
    }

    else
        {
            Node *current = head;
            for (int i = 0; i < index; i++)
            {
            current = current->next;
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current; 
        }
    _size--;
    }

/**
     * @brief Removes element at given index and returns it.
     *
     * @param index The index where value will be removed
     * @return int Value of element that was removed
     */
    int pop(int index)
    {
        if (index > _size || index < 0)
        {
            throw std::out_of_range("Index " + std::to_string(index) + " is out of range.");
        }  

        Node *current = head;
            for (int i = 0; i < index; i++)
            {
            current = current->next;
            }
            int value = current->value;
            remove(index);
            return value;
    }

    /**
     * @brief Removes the last element of a list and returns the value
     * @return The element removed
     */
    int pop() 
    {
            int value = tail->value;
            remove(_size - 1);
            return value;
    }
};
