#include <iostream>
#include <stdexcept>
#include <vector>

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

  public:
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
     * @param value The value to be appended
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
     * @param value The value to be appended, index The index
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
};