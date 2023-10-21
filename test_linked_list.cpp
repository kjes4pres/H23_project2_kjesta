#include <cassert>
#include <iostream>
#include <string>

#include "linked_list.cpp"

/**
 * @brief Test that an empty list has lenght zero.
 *
 */
void test_empty_list_has_zero_length()
{
    LinkedList ll{};
    std::cout << "Test that empty list has length zero";
    assert(ll.length() == 0);
    std::cout << " - Success!\n";
}


/**
 * @brief Test an element can be added to the start of a list
 *
 */
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

/**
 * @brief Test an element can be appended to the end of a list
 *
 */
void test_append()
{
    LinkedList ll{};
    ll.append(1);
    ll.append(2);
    assert(ll.length() == 2);
    std::cout << "Testing to see that the length of list is 2 after appending two elements. \n";
    std::cout << "Success! \n";
}


/**
 * @brief Testing that you can read and update a value in a list using square bracket operator.
 *
 */
void test_index_operator()
{
    LinkedList ll{};
    ll.append(43);
    ll.append(56);
    ll.append(9);

    std::cout << "Testing that you can read a list using the index operator. \n";
    assert(ll[0] == 43);
    assert(ll[1] == 56);
    assert(ll[2] == 9);

    std::cout << "Testing that you can write to a list using the index operator. \n";
    ll[0] = 5;
    assert(ll[0] == 5);
    std::cout << "Success! \n";
}

/**
 * @brief Testing that you can insert an element at the beginning, middle and end of a list.
 *
 */
void test_insert()
{
    LinkedList ll{};
    ll.append(0);
    ll.append(1);
    assert(ll.length() == 2);
    std::cout << "Test insertion of value at start of list. \n";
    ll.insert(42, 0);
    assert(ll.length() == 3);
    assert(ll[0] == 42);
    assert(ll[1] == 0);
    assert(ll[2] == 1);
    std::cout << "Test insertion of value at middle of list. \n";
    ll.insert(43, 1);
    assert(ll.length() == 4);
    assert(ll[0] == 42);
    assert(ll[1] == 43);
    assert(ll[2] == 0);
    assert(ll[3] == 1);
    std::cout << "Test insertion of value at end of list. \n";
    ll.insert(44, 4); 
    assert(ll.length() == 5);
    assert(ll[0] == 42);
    assert(ll[1] == 43);
    assert(ll[2] == 0);
    assert(ll[3] == 1);
    assert(ll[4] == 44);
    std::cout << "Success! \n";
}

/**
 * @brief Testing that you can instantiate a linked list by giving it a vector.
 *
 */
void test_vector_constructor()
{
    std::vector<int> values = {2, 3, 5, 7, 11};
    LinkedList ll{values};

    std::cout << "Testing that a list object has been constructed. \n";
    assert(ll.length() == values.size());
    for (int i = 0; i < values.size(); ++i)
    {
        assert(ll[i] == values[i]);
    }
    std::cout << "Success! \n";
}

/**
 * @brief Testing that you can remove an element from list at given index.
 *
 */
void test_remove()
{
    LinkedList ll{{1, 2, 3, 4, 5}};
    std::cout << "Test removal of value at start of list. \n";
    assert(ll.length() == 5);
    ll.remove(0);
    assert(ll.length() == 4);
    assert(ll[0] == 2);
    assert(ll[1] == 3);
    assert(ll[2] == 4);
    assert(ll[3] == 5);
    std::cout << "Test removal of value at middle of list. \n";
    ll.remove(2);
    assert(ll.length() == 3);
    assert(ll[0] == 2);
    assert(ll[1] == 3);
    assert(ll[2] == 5);
    std::cout << "Test removal of value at end of list. \n";
    ll.remove(2);
    assert(ll.length() == 2);
    assert(ll[0] == 2);
    assert(ll[1] == 3);
    std::cout << "Success! \n";
}

/**
 * @brief Testing pop method where you remove an element at given index and return the value.
 *
 */
void test_pop_at_index()
{
    LinkedList ll{{1, 2, 3, 4}};
    assert(ll.length() == 4);
    std::cout << "Testing that the pop method returns removed element. \n";
    int result = ll.pop(2);
    assert(ll.length() == 3);
    assert(result == 3);
    std::cout << "Success! \n";
}

/**
 * @brief Test that you can pop the last element of a list
 *
 */
void test_pop()
{
    LinkedList ll{{1, 2, 3, 4, 5}};
    assert(ll.length() == 5);
    std::cout << "Testing that the pop method removes last element, and returns it. \n";
    int result = ll.pop();
    assert(ll.length() == 4);
    assert(result == 5);
    std::cout << "Success! \n";
}


int main()
{
    test_empty_list_has_zero_length();
    test_push_front();
    test_append();
    test_index_operator();
    test_insert();
    test_vector_constructor();
    test_remove();
    test_pop_at_index();
    test_pop();
    std::cout << "All test passed, you're doing amazing sweetie! \n";
    return 0;
}