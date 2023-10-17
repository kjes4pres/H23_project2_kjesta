#include <cassert>
#include <iostream>

#include "array_list.cpp"

/**
 * @brief Test that an empty array list has length zero
 *
 */
void test_empty_array_has_length_zero()
{
    ArrayList a{};
    std::cout << "Test that empty array has length zero";
    assert(a.length() == 0);
    std::cout << " - Success!\n";
}

/**
 * @brief Test that an array with 2 appended elemets has length 2
 *
 */
void test_array_with_two_elements_appended_has_length_two()
{
    ArrayList b{};
    b.append(1);
    b.append(2);
    std::cout << "Test that the array has length 2, when 2 elements have been added.";
    assert(b.length() == 2);
    std::cout << " -  Success! \n";
}

/**
 * @brief Test that printing of array with 3 unique elements is correct.
 *
 */
void test_print()
{
    ArrayList c{};
    c.append(1);
    c.append(2);
    c.append(3);
    std::cout << "Testing the pretty printing \n";
    c.print();
    std::cout << "Success! \n";
}

/**
 * @brief Test that printing of array with 3 unique elements is correct.
 *
 */
void test_indexing_operator()
{
    ArrayList d{};
    d.append(3);
    d.append(2);

    std::cout << "Testing indexing operator. \n";
    assert(d[0] == 3);
    assert(d[1] == 2);

    std::cout << "Testing that you can write to the array. \n";
    d[0] = 6;
    assert(d[0] == 6);
    std::cout << "Success! \n";
}

/**
 * @brief Test that overloaded costructor costructs a list oject with initialized values.
 *
 */
void test_vector_constructor()
{
    std::vector<int> values = {2, 3, 5, 7, 11};
    ArrayList primes(values);

    std::cout << "Testing that a list object has been constructed. \n";
    assert(primes.length() == values.size());
    for (int i = 0; i < values.size(); ++i)
    {
        assert(primes[i] == values[i]);
    }
    std::cout << "Success! \n";
}

/**
 * @brief Test that insertion of value at a given index, moves elements at higher indexes to the right. 
 * This should also change the size of the array list by +1.
 */
void test_insert()
{
    ArrayList a{{0, 1}};
    std::cout << "Test insertion of value at start of array. \n";
    assert(a.length() == 2);
    a.insert(42, 0);
    assert(a.length() == 3);
    assert(a[0] == 42);
    assert(a[1] == 0);
    assert(a[2] == 1);
    std::cout << "Test insertion of value at middle of array. \n";
    a.insert(43, 1);
    assert(a.length() == 4);
    assert(a[0] == 42);
    assert(a[1] == 43);
    assert(a[2] == 0);
    assert(a[3] == 1);
    std::cout << "Test insertion of value at end of array. \n";
    a.insert(44, 4);
    assert(a.length() == 5);
    assert(a[0] == 42);
    assert(a[1] == 43);
    assert(a[2] == 0);
    assert(a[3] == 1);
    assert(a[4] == 44);
    std::cout << "Success! \n";
}

/**
 * @brief Test that removal of value at a given index, moves elements at higher indexes to the left.
 *This should also change the size of the array list by -1.
 */
void test_remove()
{
    ArrayList a{{1, 2, 3, 4, 5}};
    std::cout << "Test removal of value at start of array. \n";
    assert(a.length() == 5);
    a.remove(0);
    assert(a.length() == 4);
    assert(a[0] == 2);
    assert(a[1] == 3);
    assert(a[2] == 4);
    assert(a[3] == 5);
    std::cout << "Test removal of value at middle of array. \n";
    a.remove(2);
    assert(a.length() == 3);
    assert(a[0] == 2);
    assert(a[1] == 3);
    assert(a[2] == 5);
    std::cout << "Test removal of value at end of array. \n";
    a.remove(2);
    assert(a.length() == 2);
    assert(a[0] == 2);
    assert(a[1] == 3);
    std::cout << "Success! \n";
}

/**
 * @brief Tests that the pop method removes an element and returns the removed element.
 */

void test_pop_at_index()
{
    ArrayList a{{1, 2, 3, 4, 5}};
    assert(a.length() == 5);
    std::cout << "Testing that the pop method returns removed element. \n";
    int result = a.pop(3);
    assert(a.length() == 4);
    assert(result == 4);
    std::cout << "Success! \n";
}

/**
 * @brief Tests that the pop method removes the last element  of the array list,
 * and returns the removed element.
 */
void test_pop()
{
    ArrayList a{{1, 2, 3, 4, 5}};
    assert(a.length() == 5);
    std::cout << "Testing that the pop method removes last element, and returns it. \n";
    int result = a.pop();
    assert(a.length() == 4);
    assert(result == 5);
    std::cout << "Success! \n";
}

/**
 * @brief Tests that when removing elements from array list, the size shrinks.
 * Starting with appending a bunch of elements, and then pop them out.
 * Comparing capacity before and after.
 */
void test_shrink_to_fit()
{
    ArrayList a;
    for (int i = 0; i < 100; i++)
    {
        a.append(i);
    }
    int capacity_before = a.capacity();

    for (int i = 0; i < 90; i++)
    {
        a.pop();
    }
    int capacity_after = a.capacity();

    std::cout << "Testing that capacity has been reduced after removing elements. \n";
    assert(capacity_after < capacity_before);
    std::cout << "Success! \n";
}

int main()
{
    test_empty_array_has_length_zero();
    test_array_with_two_elements_appended_has_length_two();
    test_print();
    test_indexing_operator();
    test_vector_constructor();
    test_insert();
    test_remove();
    test_pop_at_index();
    test_pop();
    test_shrink_to_fit();
    std::cout << "All tests passed. \n";
}