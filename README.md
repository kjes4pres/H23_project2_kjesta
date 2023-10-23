# H23_project2_kjesta
Project 2, IN1910
- Repo url: https://github.uio.no/IN1910/H23_project2_kjesta
- Author: Kjersti Stangeland (kjesta@uio.no)

## Comments and questions

## Compiling the programs

### array_list.cpp
- did not compile.
### test_array_list.cpp
- compiled using: "c++ -std=c++14 test_array_list.cpp -o test_array_list"
- ran program using: "./test_array_list"
### linked_list.cpp
- did not compile.
### test_linked_list.cpp
- compiled using: "c++ -std=c++14 test_linked_list.cpp -o test_linked_list"
- ran program using: ".\test_linked_list"

## Answers to task 3a) - Algorithm analysis
- Get element by index i:
    - In the ArrayList this is done using the 
    
int get(int) method.

    int get(int index)
    {
        if ((index < 0) || (index >= _size))
        {
        throw std::range_error("Index is out of bounds");
    }
    return _data[index];
    }
    
    - Meaning that the method/algorithm does not depend on the lenght of the object. In Big-Oh notation this means that the algorithm has a constant relationship with runtime.

    - In the LinkedList, retrieving and element by index i is used with  int &operator[] (int index) method.

      int &operator[](int index)
      {
        if (index > _size || index < 0)
        {
            throw std::out_of_range("Index " + std::to_string(index) + " is out of range.");
        }
        
        int current_index = 0;
        Node *current = head;
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
   
- Which gives a linear relationship with runtime. Double the size of the list, you double the runtime for the algorithm to run.