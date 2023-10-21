#include <cassert>
#include <iostream>
#include <string>

#include "linked_list.cpp"

/**
 * @brief
 *
 */
void test_empty_list_has_zero_length()
{
    LinkedList ll{};
    std::cout << "Test that empty list has length zero";
    assert(ll.length() == 0);
    std::cout << " - Success!\n";
}

void test_push_front()
{
    LinkedList ll{};
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    std::cout << "Test that push_front method adds elements to start of list. \n";
    std::cout << "Wanted to implement: [1, 2, 3]\n" << "results: \n";
    ll.print();
    std::cout << "Success! \n";

}

int main()
{
    test_empty_list_has_zero_length();
    test_push_front();
    return 0;
}