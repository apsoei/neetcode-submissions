class MinHeap {
public:
    vector<int> _heap;
    MinHeap() {
        _heap.push_back(0);
    }

    void push(int val) {
        _heap.push_back(val);

        // percolate up
        int i = _heap.size() - 1;

        while (i / 2 >= 1 && _heap[i / 2] > _heap[i]) {
            // swap
            swap(_heap[i / 2], _heap[i]);
            i /= 2;
        }
    }

    int pop() {
        if (_heap.size() <= 1) {
            return -1;
        }

        int val = _heap[1];
        _heap[1] = _heap.back();
        _heap.pop_back();

        // percolate down
        percolateDown(1);

        return val;

    }

    int top() {
        if (_heap.size() <= 1) {
            return -1;
        }

        return _heap[1];
    }

    void heapify(const vector<int>& arr) {
        if (arr.empty()) {
            _heap.clear();
            _heap.push_back(0);
            return;
        }
        // copy
        _heap = arr;
        // append 0th element to the back
        _heap.push_back(arr[0]);

        // percolate down
        int i = _heap.size() / 2;
        while (i) {
            percolateDown(i--);
        }
    }

    void percolateDown(int i) {
        while (2 * i < _heap.size()) {
            int leftChild = 2 * i;
            int rightChild = 2 * i + 1;
            if (rightChild < _heap.size() && 
                _heap[rightChild] < _heap[leftChild] &&
                _heap[i] > _heap[rightChild]) {
                swap(_heap[rightChild], _heap[i]);
                i = rightChild;
            } else if (_heap[i] > _heap[leftChild]) {
                swap(_heap[leftChild], _heap[i]);
                i = leftChild;
            } else {
                break;
            }
        }
    }
};
