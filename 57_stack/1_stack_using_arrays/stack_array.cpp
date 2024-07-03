template <typename T>
class Stack {
    T *data;
    int size;
    int capacity;
    
public:
    Stack() {
        capacity = 5;
        data = new T[capacity];
        size = 0;
    }
    
    void push(T element) {
        if (size == capacity) {
            T *newData = new T[capacity*2];
            for (int i = 0; i < capacity; i++) {
                newData[i] = data[i];
            }
            capacity *= 2;
            data = newData;
        }
        data[size] = element;
        size++;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    T pop() {
        if (isEmpty()) {
            return 0;
        }
        
        T element = data[size-1];
        size--;
        return element;
    }
    
    T top() {
        T element = data[size-1];
        return element;
    }

    int getSize() {
        return size;
    }
  
};