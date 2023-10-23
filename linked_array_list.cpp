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

int main()
{
    ArrayListNode node({1, 2, 3}, nullptr, nullptr);
    node.value->print();
    return 0;
}