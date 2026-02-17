//The following example has been found at https://www.geeksforgeeks.org/dsa/how-do-dynamic-arrays-work/

#include <iostream>
using namespace std;

class DynamicArray {
private:
    // Pointer to store array created
    // using new keyword
    int* array = NULL;
    // Size of array
    int size;

    // Container size
    int capacity;

public:
    // Default constructor with size 1
    DynamicArray()
    {
        capacity = 1;
        size = 0;
        array = new int[capacity];
    }

    // Taking size from the user
    
    
    DynamicArray(int capacity)
    {
        this->capacity = capacity;
        array = new int[capacity];
        size = 0;
    }

    // Returns the size of Array
    // i.e Total elements stored currently
    int getSize() { return size; }

    // Returns the size of container
    int getCapacity() { return capacity; }

    // Inserting element after last stored index
    void push_back(int value)
    {
        // check is array having size to store element or
        // not
        if (size == capacity) {

            // if not then grow the array by double
            growArray();
        }

        // insert element
        array[size] = value;
        // increment the size or last_index+1
        size++;
    }

    // Deleting element at last stored index
    void pop_back()
    {
        // Replace the last index by 0
        array[size - 1] = 0;

        // Decrement the array size
        size--;

        // Reduce if the container half element of its
        // capacity
        if (size == (capacity / 2)) {
            shrinkArray();
        }
    }

    // Increase the array size by double of current capacity
    void growArray()
    {

        // Creating new array of double size
        int* temp = new int[capacity * 2];

        capacity = capacity * 2;
        // copy element of old array in newly created array
        for (int i = 0; i < size; i++) {
            temp[i] = array[i];
        }

        // Delete old array
        delete[] array;

        // Assign newly created temp array to original array
        array = temp;
    }

    // Reduce the size of array by half
    void shrinkArray()
    {

        // Creating new array of half size
        capacity = size;
        int* temp = new int[capacity];

        // copy element of old array in newly created array
        for (int i = 0; i < size; i++) {
            temp[i] = array[i];
        }

        // Delete old array
        delete[] array;

        // Assign newly created temp array to original array
        array = temp;
    }

    // Searching element in the given array
    int search(int key)
    {
        for (int i = 0; i < size; i++) {
            if (array[i] == key) {
                // If element found return its index
                return i;
            }
        }

        // Return -1 if element not found;
        return -1;
    }

    // Insert element at given index
    void insertAt(int index, int value)
    {
        // check is array having size to store element or
        // not
        if (size == capacity) {

            // if not then grow the array by double
            growArray();
        }

        for (int i = size - 1; i >= index; i--) {
            array[i + 1] = array[i];
        }

        array[index] = value;
        size++;
    }

    // Delete element at given index
    void deleteAt(int index)
    {
        for (int i = index; i < size; i++) {
            array[i] = array[i + 1];
        }

        // Replace the last index by 0
        array[size - 1] = 0;

        // Decrement the array size
        size--;

        // Reduce if the container half element of its
        // capacity
        if (size == (capacity / 2)) {
            shrinkArray();
        }
    }

    // To Print Array
    void printArrayDetails()
    {
        cout << "Elements of array : ";
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
        cout << "No of elements in array : " << size
             << ", Capacity of array :" << capacity << endl;
    }

    bool isEmpty()
    {
        if (size == 0) {
            return true;
        }
        else {
            return false;
        }
    }
};

int main()
{
    DynamicArray da;

    da.push_back(1);
    da.push_back(2);
    da.push_back(3);
    da.push_back(4);
    da.push_back(5);
    da.push_back(6);
    da.push_back(7);
    da.push_back(8);
    da.push_back(9);
    da.push_back(10);
    da.push_back(11);

    da.printArrayDetails();

    da.shrinkArray();
    cout << "\nCapacity of array  after shrinking : "
         << da.getCapacity() << endl;

    cout << "\nAfter inserting at index 3 " << endl;
    da.insertAt(3, 50);
    da.printArrayDetails();

    cout << "\nAfter delete last element ";
    da.pop_back();
    da.printArrayDetails();

    cout << "\nAfter deleting at index 3 ";
    da.deleteAt(3);
    da.printArrayDetails();

    cout << "\nSearching 5 in array ";
    int index = da.search(5);
    if (index != -1) {
        cout << "Element found at index : " << index << endl;
    }
    else {
        cout << "Element not found " << endl;
    }
    return 0;
}