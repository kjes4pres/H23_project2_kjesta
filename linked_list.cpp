#include <iostream>
#include <stdexcept>

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
};
