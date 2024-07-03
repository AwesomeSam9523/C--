#include <iostream>

template <typename T>
class Queue {
    T *data;
    int size;
    int firstIndex;
    int nextIndex;
    int capacity;

public:
    Queue(int dataSize) {
        data = new T[dataSize];
        size = 0;
        firstIndex = -1;
        nextIndex = 0;
        capacity = dataSize;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    // Inserting an element
    void enqueue(T element) {
        if (size == capacity) {
            T *newData = new T[capacity*2];
            int j = 0;
            for (int i = firstIndex; i < capacity; i++, j++) {
                newData[j] = data[i];
            }
            for (int i = 0; i < firstIndex; i++, j++) {
                newData[j] = data[i];
            }

            delete [] data;
            data = newData;
            firstIndex = 0;
            nextIndex = capacity;
            capacity *= 2;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % 5;
        if (firstIndex == -1) {
            firstIndex = 0;
        }
        size++;
    }

    // Getting the first element
    T front() {
        if (size == 0) {
            std::cout << "Queue is empty!" << std::endl;
            return 0;
        }

        return data[firstIndex];
    }

    // Removing an element
    T dequeue() {
        if (size == 0) {
            std::cout << "Queue is empty!" << std::endl;
            return 0;
        }

        T element = data[firstIndex];
        firstIndex = (firstIndex + 1) % 5;
        size--;
        if (size == 0) {
            firstIndex = -1;
            nextIndex = 0;
        }

        return element;
    }
};
