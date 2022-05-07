class MyCircularQueue {
public:
    int *arr;
    int f;
    int r;
    int n;
    
    MyCircularQueue(int k) {
        arr=new int[k];
        n=k;
        f=-1;
        r=-1;
    }
    
    bool enQueue(int value) {
        if(isEmpty())
        {
            f=0;
            r=0;
        }
        else if(isFull()){
            cout<<"hello";
            return false;
        }
        else if(f!=0 && r==n-1)
        {
            r=0;
        }
        else
            r++;
        arr[r]=value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        else if(f==r)
        {
            f=-1;
            r=-1;
            return true;
        }
        else if(f==n-1)
            f=0;
        else f++;
        return true;
    }
    
    int Front() {
        if(f==-1)
            return -1;
        return arr[f];
    }
    
    int Rear() {
        if(r==-1)
            return -1;
        return arr[r];
    }
    
    bool isEmpty(){
        if(r==-1 && f==-1)
            return true;
        else 
            return false;
    }
    
    bool isFull() {
        if((f==0 && r==n-1) || r==f-1)
            return true;
        else
            return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */