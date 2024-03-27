template <typename T>
class Stack {
    T *data;
    int stackSize = 0;
    int capacity = 5;
    
public:
    Stack() {
        data = new T[capacity];
    }
    
    void push(T element) {
        if (stackSize == capacity) {
            T *newData = new T[capacity*2];
            for (int i = 0; i < capacity; i++) {
                newData[i] = data[i];
            }
            capacity *= 2;
            data = newData;
        }
        data[stackSize] = element;
        stackSize++;
    }
    
    bool isEmpty() {
        return stackSize == 0;
    }
    
    T pop() {
        if (isEmpty()) {
            return 0;
        }
        
        T element = data[stackSize-1];
        stackSize--;
        return element;
    }
    
    T top() {
        T element = data[stackSize-1];
        return element;
    }

    int size() {
        return stackSize;
    }
  
};