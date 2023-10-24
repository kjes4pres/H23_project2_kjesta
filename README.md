# H23_project2_kjesta
Project 2, IN1910
- Repo url: https://github.uio.no/IN1910/H23_project2_kjesta
- Author: Kjersti Stangeland (kjesta@uio.no)

## Comments and questions

## Compiling the programs
- All compiling programs has been checked on a IFI machine using ssh.

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
### compare_array_list_and_linked_list.cpp
- compiled using: "c++ -std=c++14 compare_array_list_and_linked_list.cpp -o compare"
- ran program using: "./compare"
### linked_array_list.cpp
- compiled using: "c++ -std=c++14 linked_array_list.cpp -o linked_array"
- ran program using: "./linked_array"

## Answers to task 3a) - Algorithm analysis
- #### Get element by index i:
    - In the ArrayList this is done using the: int get(int) method.The method has a constant runtime, and does not depend on the size of the list. It does not have to traverse a whole list to find the element. In Big-Oh notation this means that the algorithm has a constant relationship with runtime. O(1).

    - In the LinkedList, retrieving and element by index i is used with  int &operator[] (int index) method.
    -  This method has a linear relationship with runtime. Double the size of the list, you double the runtime for the algorithm to run. O(N). This is because the method is traversing the whole list, giving a runtime dependecy of the size of the list. O(N).

- #### Inserting at front of list
    - In the ArrayList, inserting at front of list is done using the method void insert(val, index). If given index 0, the method will insert the given value at the beginning of the list.
    It is an O(N) method/algorithm because it has to "copy" the existing list, and move each element one place to the right (down). It then depends both on the size of the list, but also which index it is given. Since the case here is index 0, it goes as O(N). If the index was in the middle of the list, the algorithm would take less time to run. 

    - In the LinkedList, inserting at front of list is done by using the method void push_front(int val). This is an O(1) algorithm, and does not depend on the length of the list. There are no loops traversing through the list, only executions being done once. 

- #### Insert at back of list
    - In ArrayList this is done by using the method void append(int n). The algorithm is O(1).

    - In LinkedList it is also done by the void append(int val) method. The algorithm is O(1). Neither of the classes traverse through the lists, they only have executions done at constant run time. 

- #### Insert into middle of list
    - In ArrayList this is done by the void insert(int val, int index) method. Inserting in middle of list means that the for-loop within the function is iterated n/2 times, possible to say it is an O(n/2) algortihm?

    - We also have a void insert(int val, int index) method in the LinkedList class. This one also has a for-loop dependent on the index, and if we want to insert in the middle of the list it gives us O(n/2).
 
- #### Remove element from front
    - ArrayList: the method void remove(int index) has to traverse the whole list, moving each element to the left. Hence, it is an O(N) algorithm.

    - LinkedList: to remove from the front we use the method void remove(int index). There is no looping through the list, and it is an O(1) algorithm. Constant runtime, not dependent of size.

- #### Remove element from back
    - ArrayList: either the method int pop() (but it retuns the removed value) og method void remove (int index). If we focus on the remove method, for removing an element at the back of the list it is an O(1) method/algorithm.

    - LinkedList: either pop or remove methods. Also here focusing on the remove method, it is still a O(1) algorithm.

- #### Remove element from middle
    - ArrayList, remove method. To remove an element from the middle of a list it has to traverse through the elements of the list larger than the index given, and move them to the left. You could say its an O(n/2) algorithm, because it depends on the lenght of the list but the runtime goes as half of it (only traversing half the list, by the conditions given in my for-loop). It depends on the number of elements being shifted to the left.

    - LinkedList, remove method. This method runs a for-loop up until the index where the element to be remove is. Meaning that also this method goes as an O(n/2) algorithm.

- #### Print
    - ArrayList: the print method iterates through the whole lists and prints each elements. It is an O(N) algorithm.

    - LinkedList: this print method also has to iterate the whole list (or nodes), and is also O(N).

## Answers to task 3b) - timing your implementation
- From the plots in arraylist_vs_linkedlist.png, by looking at them it seems that:
    - The acutal run time for the ArrayList and the get method, truly is constant O(1). The run time remains roughly the same, even when the list size increases.
    - The implementation of the insert method for ArrayList has a run time close to a linear relationship. Small deviations in the beginning. 
    - LinkedList and its get method acts as an O(N) algorithm when ran on my machine, as expected.
    - LinkedList and its insert method has the biggest deviation of them all in the plots. The run time measured on my computer actually decreases with increasing size of object, until it reaches a constant runtime when the size is 10^4.


