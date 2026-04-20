class MinHeap 
{
public:
    vector<int> heap = {0};
    MinHeap() {}

    void push(int val) 
    {
        heap.push_back(val);
        percolateUp(heap.size() - 1);
    }

    int pop() 
    {
        if (heap.size() <= 1)
        {
            return -1;
        }

        int val = heap[1];
        heap[1] = heap.back();
        heap.pop_back();
        percolateDown(1);

        return val;
    }

    int top() 
    {
        if (heap.size() <= 1)
        {
            return -1;
        }

        return heap[1];
    }

    void percolateUp(int i)
    {
        while (i > 1)
        {
            int parentIndex = i / 2;
            if (heap[parentIndex] > heap[i])
            {
                // swap with parent
                int temp = heap[i];
                heap[i] = heap[parentIndex];
                heap[parentIndex] = temp;
                i = parentIndex;
            }
            else
            {
                break;
            }
        }
    }

    void percolateDown(int i)
    {
        int sz = heap.size();

        while (2 * i < sz)
        {
            int leftChildIndex = 2 * i;
            int rightChildIndex = 2 * i + 1;

            if (rightChildIndex < sz && heap[rightChildIndex] <= heap[leftChildIndex] && heap[rightChildIndex] < heap[i])
            {
                // swap with right child
                int temp = heap[i];
                heap[i] = heap[rightChildIndex];
                heap[rightChildIndex] = temp;
                i = rightChildIndex;
            }
            else if (heap[leftChildIndex] < heap[i])
            {
                // swap with left child
                int temp = heap[i];
                heap[i] = heap[leftChildIndex];
                heap[leftChildIndex] = temp;
                i = leftChildIndex;
            }
            else
            {
                break;
            }
        }
    }

    void heapify(const vector<int>& arr) 
    {
        heap.clear();
        heap.push_back(0);
        if (arr.empty()) return;
        heap = arr;
        heap.push_back(arr.front());
        int n = heap.size();
        for (int i = n - 1; i >= 1; --i)
        {
            percolateDown(i);
        }
    }
};
