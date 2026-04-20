class MinHeap 
{
public:
    vector<int> heap = {0};
    MinHeap() {}

    void push(int val) 
    {
        heap.push_back(val);

        // percolate up
        int i = heap.size() - 1;
        percolateUp(i);
    }

    void percolateUp(int i)
    {
        while (i > 1 && heap[i / 2] > heap[i])
        {
            // swap
            int temp = heap[i / 2];
            heap[i / 2] = heap[i];
            heap[i] = temp;
            i /= 2;
        }
    }

    int pop() 
    {
        if (heap.size() == 1)
        {
            return -1;
        }

        int res = heap[1];
        heap[1] = heap.back();
        heap.pop_back();

        percolateDown(1);

        return res;
    }

    void percolateDown(int i)
    {
        int n = heap.size();
        while (2 * i < n)
        {
            int leftChild = 2 * i;
            int rightChild = 2 * i + 1;
            if (rightChild < n && heap[rightChild] < heap[leftChild] && heap[rightChild] < heap[i])
            {
                // swap
                int temp = heap[i];
                heap[i] = heap[rightChild];
                heap[rightChild] = temp;
                i = rightChild;
            }
            else if (heap[leftChild] < heap[i])
            {
                // swap
                int temp = heap[i];
                heap[i] = heap[leftChild];
                heap[leftChild] = temp;
                i = leftChild;
            }
            else
            {
                break;
            }
        }
    }

    int top() 
    {
        if (heap.size() == 1)
        {
            return -1;
        }

        return heap[1];
    }

    void heapify(const vector<int>& arr) 
    {
        heap = arr;
        heap.push_back(heap[0]);

        // int i = (heap.size() - 1) / 2;
        int i = heap.size() - 1;

        while (i >= 1)
        {
            // percolateDown(i);
            percolateUp(i);
            i--;
        }
    }
};
