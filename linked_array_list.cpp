#include <iostream>
#include <vector>
#include <memory>

#include "array_list.cpp"

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
    LinkedArrayList()
    {
    }

    ~LinkedArrayList()
    {
    }

    void append(std::vector<int>)
    {
    }

    void append(std::vector<int>)
    {
    }

    std::unique_ptr<ArrayList> &operator[](int)
    {
    }


};

int main()
{
    ArrayListNode node({1, 2, 3}, nullptr, nullptr);
    node.value->print();
    // LinkedArrayList lal{}; // Create an empty LinkedArrayList
    // lal.append({1, 2});    // Append first list
    // lal.append({4, 5, 6}); // Append a second list
    // lal.print();           // Print the entire LinkedArrayList
    // lal[0]->append(42);    // Append the number 42 to the first ArrayList
    // lal.print();           // Print the entire LinkedArrayList again

    return 0;
}