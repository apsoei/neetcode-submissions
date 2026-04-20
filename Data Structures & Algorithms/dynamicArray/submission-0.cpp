class DynamicArray 
{
public:
    int* arr;
    int len = 0;
    int cap;
    DynamicArray(int capacity) 
    {
        cap = capacity;
        arr = new int[capacity];
    }

    int get(int i) 
    {
        return arr[i];
    }

    void set(int i, int n) 
    {
        arr[i] = n;
    }

    void pushback(int n) 
    {
        if (len == cap)
        {
            // call resize and then pushback
            resize();
        }
        
        // pushback
        arr[len++] = n;
    }

    int popback() 
    {
        return arr[--len];
    }

    void resize() 
    {
        // double the cap
        int* temp = arr;
        arr = new int[cap * 2];
        for (int i = 0; i < len; ++i)
        {
            arr[i] = temp[i];
        }
        delete[] temp;
        cap *= 2;
    }

    int getSize() 
    {
        return len;
    }

    int getCapacity() 
    {
        return cap;
    }
};
