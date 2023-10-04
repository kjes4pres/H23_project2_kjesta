#include <cassert>
#include <iostream>

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

int main()
{
    test_empty_list_has_zero_length();
    return 0;
}