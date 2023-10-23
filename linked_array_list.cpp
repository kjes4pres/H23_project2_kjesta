#include <iostream>
#include <vector>
#include <memory>

#include "array_list.cpp"

    /**
     * @brief 
     * 
     */
struct ArrayListNode
{
    std::unique_ptr<ArrayList> value;
    ArrayListNode* prev;
    ArrayListNode* next;

    ArrayListNode(std::vector<int> values, ArrayListNode *prev, ArrayListNode *next)
    {
        value = std::make_unique<ArrayList>(values);
        this->prev = prev;
        this->next = next;
    }
};

class LinkedArrayList
{
    private:

     ArrayListNode *head;
     ArrayListNode *tail;
     int _size;

     public:

     LinkedArrayList() 
    {
        head = nullptr;
        tail = nullptr;
        _size = 0;
    }

    ~LinkedArrayList()
    {
        ArrayListNode *current = head;
        ArrayListNode *next = nullptr;
        // Move node until we are at the last element
        while (current != nullptr)
        {
            next = current->next;
            delete current;
            current = next;
        }
    }

    /**
     * @brief Append a list of values to the end of the linked array list, implemented as an arraylistnode.
     *
     * @param values List of values
     */
    void append(std::vector<int> values)
    {
        ArrayListNode *newNode = new ArrayListNode(values, tail, nullptr);
        if (_size == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        _size++;
    }
    
    /**
     * @brief Print the linked array list
     */
    void print()
    {
        std::cout << "[";
        ArrayListNode *current = head;
        
            while (current != nullptr)
            {
            current->value->print();
            current = current->next;
            if (current != nullptr)
            {
                std::cout << ", ";
            }
            }
        std::cout << "]\n";
    }


    /**
     * @brief Get a reference to the ArrayList at a given index.
     *
     * @param index The index
     * @return A reference to a std::unique_ptr<ArrayList>
     */
    std::unique_ptr<ArrayList> &operator[](int index)
    {
        if ((index < 0) || (index >= _size))
        {
            throw std::range_error("Index is out of bounds");
        }

        int current_index = 0;
        ArrayListNode *current = head;
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


};

int main()
{
    std::cout << "Making an ArrayListNode \n";
    ArrayListNode node({1, 2, 3}, nullptr, nullptr);
    std::cout << "Printing the values of the ArrayListNode. \n";
    node.value->print();
    std::cout << "Creating an empty LinkedArrayList \n";
    LinkedArrayList lal{}; 
    std::cout << "Appending a list to the empty LinkedArrayList \n";
    lal.append({1, 2}); 
    std::cout << "Appending another list. \n";  
    lal.append({4, 5, 6});
    std::cout << "Printing the enitre LinkedArrayList \n";
    lal.print();       
    std::cout << "Append the number 42 to the first ArrayList \n";    
    lal[0]->append(42);
    std::cout << "Print the entire list again. \n"; 
    lal.print();
    std::cout << "Success!";

    return 0;
};