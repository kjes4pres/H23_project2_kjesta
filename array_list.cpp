#include <iostream>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <algorithm>

class ArrayList
{
  private:
    // Array containing the acutaul data in the list
    int *_data;
    // Capacity of the array
    int _capacity = 1;
    // Size of the array
    int _size = 0;
    
    int _growth_factor = 2;

    /**
     * @brief Resizes current list by the growth factor.
     */
    void resize()
    {
        _capacity *= _growth_factor;
        int *newData = new int[_capacity];

        for (int i = 0; i < _size ; i++)
        {
            newData[i] = _data[i];
        }

        delete[] _data;

        _data = newData;
    }

    /**
     * @brief Replaces the underlying storage array with the smallest capacity that will fit all elements. 
     * Shrinking the array, minimizing storage use.
     */
    void shrink_to_fit()
    {
        int min_capacity = 1;
        while (min_capacity < _size)
        {
            min_capacity *= 2;
        }
    
        _capacity = min_capacity;

        int *newData = new int[_capacity];
        for (int i = 0; i < _size; i++)
        {
            newData[i] = _data[i];
        }

        delete[] _data;

        _data = newData;
    }

        public :
        // Default constructor
        ArrayList()
    {
        _data = new int[_capacity];
    }

    // Overloaded constructor
    ArrayList(std::vector<int> values)
    {
        if (_capacity < values.size())
        {
            _capacity = values.size();
        }
        _data = new int[_capacity];
        for (int value : values)
        {
            append(value);
        }
    }

        // Destructor
        ~ArrayList()
    {
        delete[] _data;
    }

    // Length of array
    int length()
    {
        return _size;
    }

    /**
     * @brief Get value at a given index.
     * Throws a range error in index if out of bounds
     *
     * @param index The index
     * @return int The value at that index
     */
    int get(int index)
    {
        if ((index < 0) || (index >= _size))
        {
            throw std::range_error("Index is out of bounds");
        }
        return _data[index];
    }

    /**
     * @brief Prints the array
     *
     */
    void print()
    {
        std::cout << "ArrayList([";
        for (int i = 0; i < _size - 1; i++)
        {
            std::cout << _data[i] << ", ";
        }
        std::cout << _data[_size - 1] << "])\n";
    }

    /**
     * @brief Get a reference to the value at a given index.
     * Throws a range error in index if out of bounds
     *
     * @param index The index
     * @return int The value at that index
     */
    int &operator[](int index)
    {
        if ((index < 0) || (index >= _size))
        {
            throw std::range_error("Index is out of bounds");
        }
        return _data[index];
    }

    /**
     * @brief Append value to end of list.
     * Resizes list if the current list is full.
     *
     * @param n The value to be appended
     */
    void append(int n)
    {
        if (_size >= _capacity)
        {
            resize();
        }
        _data[_size] = n;
        _size++;
    }

    /**
     * @brief Inserts a value at the give index of a list.
     * The element previously stored at that index, and all entries to the right of it (with higher indices), 
     * is moved one index up to make room for the new value.
     *
     * @param val The value to be appended
     * @param index The index
     */
    void insert(int val, int index)
    {
        if (index < 0 || index > _size)
        {
            throw std::range_error("Index out of bounds.");
        }

        if (_size >= _capacity)
        {
            resize();
        }

        for (int i = _size; i > index; --i)
        {
            _data[i] = _data[i - 1];
        }

        _data[index] = val;
        _size++;
    }

    /**
     * @brief Removes element from given index of list. 
     * Remaining elements are moved down the array to close the gap.
     * The size of the array list is shrunk to lessen storage use.
     *
     * @param index The index
     */
    void remove(int index)
    {
        if (index > _size)
        {
            throw std::range_error("Index out of bounds.");
        }

        _data[index] = 0;

        for (int i = index; i < _size - 1; ++i)
        {
            _data[i] = _data[i + 1];
        }
        
        _size--;
    
        if (_size < _capacity / 4) 
        {
            shrink_to_fit();
        }
    }

    /**
     * @brief Removes element from given index of list and returns it.
     *
     * @param index The index
     * @return value The removed element
     */
    int pop(int index)
    {
        if (index < 0 || index > _size)
        {
            throw std::range_error("Index out of bounds.");
        }

        int popped = _data[index];
        remove(index);

        if (_size < _capacity / 4)
        {
            shrink_to_fit();
        }
        return popped;
    }

    /**
     * @brief Removes last element of array list and returns it.
     * @return value The removed element
     */
    int pop()
    {
        int popped = _data[_size - 1];
        remove(_size - 1);

        if (_size < _capacity / 4)
        {
            shrink_to_fit();
        }
        return popped;
    }

    /**
     * @brief Returns the capacity of an array list.
     *
     * @return value The capacity of the array list.
     */
    int capacity()
    {
        return _capacity;
    }

    /**
     * @brief Returns the index of the smallest element of array list.
     */
    int argmin()
    {
        int index_min = 0;
        for (int i = 1; i < _size; i++)
        {
            if (_data[i] < _data[index_min])
            {
                index_min = i;
            }
        }
        return index_min;
    }

    /**
     * @brief Returns the index of the largest element of array list.
     */
    int argmax()
    {
        int index_max = 0;
        for (int i = 1; i < _size; i++)
        {
            if (_data[i] > _data[index_max])
            {
                index_max = i;
            }
        }
        return index_max;
    }

    /**
     * @brief Returns the smallest element of array list.
     */
    int min()
    {
        auto min_element = std::min_element(_data, _data + _size);
        return *min_element;
    }

    /**
     * @brief Returns the largest element of array list.
     */
    int max()
    {
        auto max_element = std::max_element(_data, _data + _size);
        return *max_element;
    }

    /**
     * @brief Returns the number of times a given value occurs in an array.
     * @param val The value to be counted
     */
    int count(int val)
    {
        int counter = 0;
        for (int i = 0; i < _size; i++)
        {
            if (_data[i] == val)
            {
                counter += 1;
            }
        }
        return counter;
    }
};