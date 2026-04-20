class Deque 
{
public:
    struct Doubly
    {
        Doubly* next = nullptr;
        Doubly* prev = nullptr;
        int val = 0;
        Doubly(int val) : val(val) {}
        Doubly(){}
    };

    Doubly* head;
    Doubly* tail;
    int size = 0;

    Deque() 
    {
        head = new Doubly();
        tail = new Doubly();
        head->next = tail;
        tail->prev = head;
    }

    bool isEmpty() 
    {
        return size == 0;
    }

    void append(int value) 
    {
        Doubly* prev = tail->prev;
        Doubly* node = new Doubly(value);
        prev->next = node;
        node->prev = prev;
        node->next = tail;
        tail->prev = node;
        size++;
    }

    void appendleft(int value) 
    {
        Doubly* right = head->next;
        Doubly* node = new Doubly(value);
        head->next = node;
        node->prev = head;
        node->next = right;
        right->prev = node;
        size++;
    }

    int pop() 
    {
        if (size == 0) return -1;

        Doubly* prev = tail->prev;
        int val = prev->val;
        Doubly* lastNode = prev->prev;
        lastNode->next = tail;
        tail->prev = lastNode;
        delete prev;
        size--;

        return val;
    }

    int popleft() 
    {
        if (size == 0) return -1;
        Doubly* deleting = head->next;
        Doubly* firstNode = deleting->next;
        int val = deleting->val;
        head->next = firstNode;
        firstNode->prev = head;
        delete deleting;
        size--;

        return val;
    }
};
