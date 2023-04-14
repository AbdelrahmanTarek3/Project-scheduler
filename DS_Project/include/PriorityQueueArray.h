#pragma once
#pragma once
template <typename T>
class PriorityQueueArray {
private:
    T* items; 
    int* priorities; 
    int count; 
    int capacity; 

public:
    // Constructor and Destructor
    PriorityQueueArray(int capacity);
    PriorityQueueArray();
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

template <typename T>
PriorityQueueArray<T>::PriorityQueueArray()
{

}

// Destructor
template <typename T>
PriorityQueueArray<T>::~PriorityQueueArray()
{
    delete[] items;
    delete[] priorities;
}

  
    bool isEmpty() const
    {
        return count == 0;
    }

 
    bool isFull() const
    {
        return count == capacity;
    }


    bool enqueue(const T& newEntry, int priority)
    {
        if (isFull()) 
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

 
    bool dequeue(T& FrontEntry)
    {
        if (isEmpty()) 
        {
            return false;
        }

        // Retrieve the item with the highest priority
        FrontEntry = items[count - 1];
        count--;

        return true;
    }

    // Retrieve the item with the highest priority from the priority queue without removing it
    bool peek(T& FrontEntry) const
    {
        if (isEmpty()) // If the queue is empty, cannot peek
        {
            return false;
        }

        // Retrieve the item with the highest priority
        FrontEntry = items[count - 1];
        return true;
    }

};

