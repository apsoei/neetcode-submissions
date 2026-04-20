class LinkedList 
{
private:
    struct Node
    {
        int val = 0;
        Node* next = nullptr;
        Node(int val) : val(val) {}
        Node() {}
    };

public:
    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;
    LinkedList() 
    {
        head = new Node();
        tail = new Node();
        head->next = tail;
    }

    int get(int index) 
    {
        if (index < 0 || index >= size)
        {
            return -1;
        }

        Node* node = head->next;

        while (index)
        {
            node = node->next;
            index--;
        }

        return node->val;
    }

    void insertHead(int val) 
    {
        Node* front = head->next;
        Node* adding = new Node(val);
        head->next = adding;
        adding->next = front;
        size++;

        if (size == 1)
        {
            front->next = tail;
        }
    }
    
    void insertTail(int val) 
    {
        Node* node = head;
        while (node->next != tail)
        {
            node = node->next;
        }

        Node* adding = new Node(val);
        node->next = adding;
        adding->next = tail;
        size++;
    }

    bool remove(int index) 
    {
        if (index < 0 || index >= size)
        {
            return false;
        }

        Node* node = head;

        while (index)
        {
            node = node->next;
            index--;
        }
        // node -> deleting -> temp
        Node* deletingNode = node->next;
        Node* temp = node->next->next;

        node->next = temp;
        delete deletingNode;
        size--;

        return true;
    }

    vector<int> getValues() 
    {
        Node* node = head->next;
        vector<int> res;
        while (node != tail)
        {
            res.push_back(node->val);
            node = node->next;
        }

        return res;
    }
};
