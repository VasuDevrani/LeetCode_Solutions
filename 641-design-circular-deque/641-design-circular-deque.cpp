class MyCircularDeque {
    int *arr;
    int front, rear,size = 0;
public:
    MyCircularDeque(int k) {
        arr = new int[k];
        front = -1, rear = -1, size = k;
    }
    
    bool insertFront(int value) {
        if(isFull())
            return false;
        if(isEmpty()){
            front = rear = 0;
        }
        else if(front == 0 && rear != size-1)
        {
            front = size-1;
        }
        else{
            front--;
        }
        arr[front] = value;
        return true;
    }
    
    bool insertLast(int value) {
         if(isFull())
            return false;
        if(isEmpty()){
            front = rear = 0;
        }
        else if(rear == size-1 && front != 0)
        {
            rear = 0;
        }
        else{
            rear++;
        }
        arr[rear] = value;
        return true;
    }
    
    bool deleteFront() {
        if(front == -1)
            return false;
        arr[front] = -1;
        if(front == rear)
        {
            front = rear = -1;
        }
        else if(front == size-1)
            front = 0;
        else{
            front++;
        }
        return true;
    }
    
    bool deleteLast() {
         if(front == -1)
            return false;
        arr[rear] = -1;
        if(front == rear)
        {
            front = rear = -1;
        }
        else if(rear == 0)
            rear = size-1;
        else{
            rear--;
        }
        return true;
    }
    
    int getFront() {
        if(isEmpty())
            return -1;
        return arr[front];
    }
    
    int getRear() {
         if(isEmpty())
            return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        if(front == -1 && rear == -1)
            return true;
        return false;
    }
    
    bool isFull() {
        if(front == 0 && rear == size-1 || front != 0 && rear == (front-1)%(size-1))
            return true;
        return false;
    }
};