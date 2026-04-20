class MinHeap 
{
public:
    vector<int> heap = {0};
    MinHeap() {}

    void push(int val) 
    {
        heap.push_back(val);
        // percolate up
        percolateUp(heap.size() - 1);
    }

    void percolateUp(int i)
    {
        while (i > 1 && heap[i] < heap[i / 2])
        {
            int temp = heap[i / 2];
            heap[i / 2] = heap[i];
            heap[i] = temp;
            i /= 2;
        }
    }

    void percolateDown(int i)
    {
        int n = heap.size();
        while (i * 2 < n)
        {
            int leftChild = i * 2;
            int rightChild = i * 2 + 1;
            if (rightChild < n && heap[rightChild] < heap[i] && heap[rightChild] < heap[i * 2])
            {
                int temp = heap[rightChild];
                heap[rightChild] = heap[i];
                heap[i] = temp;
                i = rightChild;
            }
            else if (heap[leftChild] < heap[i])
            {
                int temp = heap[leftChild];
                heap[leftChild] = heap[i];
                heap[i] = temp;
                i = leftChild;
            }
            else
            {
                break;
            }
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
        // percolate down
        percolateDown(1);

        return res;
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
        if (arr.empty())
        {
            heap.push_back(0);
            return;
        } 
        heap.push_back(arr[0]);

        int n = heap.size() - 1;
        int i = n / 2;

        while (i >= 1)
        {
            percolateDown(i);
            i--;
        }
    }
};
