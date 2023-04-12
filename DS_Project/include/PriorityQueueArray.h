#pragma once
#pragma once
template <typename T>
class PriorityQueueArray {
private:
    T* items; // Array of items in the priority queue
    int* priorities; // Array of priorities of the items
    int count; // Current count of queue items
    int capacity; // Capacity of the queue array

public:
    // Constructor and Destructor
    PriorityQueueArray(int capacity);
    ~PriorityQueueArray();

    // Queue operations
    bool isEmpty() const;
    bool isFull() const;
    bool enqueue(const T& newEntry, int priority);
    bool dequeue(T& FrontEntry);
    bool peek(T& FrontEntry) const;
};

// Constructor
template <typename T>
PriorityQueueArray<T>::PriorityQueueArray(int capacity)
{
    this->capacity = capacity;
    items = new T[capacity];
    priorities = new int[capacity];
    count = 0;
}

// Destructor
template <typename T>
PriorityQueueArray<T>::~PriorityQueueArray()
{
    delete[] items;
    delete[] priorities;
}

// Check if the priority queue is empty
template <typename T>
bool PriorityQueueArray<T>::isEmpty() const
{
    return count == 0;
}

// Check if the priority queue is full
template <typename T>
bool PriorityQueueArray<T>::isFull() const
{
    return count == capacity;
}

// Add a new item to the priority queue based on its priority
template <typename T>
bool PriorityQueueArray<T>::enqueue(const T& newEntry, int priority)
{
    if (isFull()) // If the queue is full, cannot enqueue
    {
        return false;
    }

    // Add the new item and its priority to the end of the arrays
    items[count] = newEntry;
    priorities[count] = priority;
    count++;

    // Sort the arrays in descending order of priority
    for (int i = count - 1; i > 0; i--)
    {
        if (priorities[i] > priorities[i - 1])
        {
            // Swap the items and priorities
            T tempItem = items[i];
            int tempPriority = priorities[i];
            items[i] = items[i - 1];
            priorities[i] = priorities[i - 1];
            items[i - 1] = tempItem;
            priorities[i - 1] = tempPriority;
        }
        else
        {
            break;
        }
    }

    return true;
}

// Remove and retrieve the item with the highest priority from the priority queue
template <typename T>
bool PriorityQueueArray<T>::dequeue(T& FrontEntry)
{
    if (isEmpty()) // If the queue is empty, cannot dequeue
    {
        return false;
    }

    // Retrieve the item with the highest priority
    FrontEntry = items[count - 1];
    count--;

    return true;
}

// Retrieve the item with the highest priority from the priority queue without removing it
template <typename T>
bool PriorityQueueArray<T>::peek(T& FrontEntry) const
{
    if (isEmpty()) // If the queue is empty, cannot peek
    {
        return false;
    }

    // Retrieve the item with the highest priority
    FrontEntry = items[count - 1];
    return true;
}
