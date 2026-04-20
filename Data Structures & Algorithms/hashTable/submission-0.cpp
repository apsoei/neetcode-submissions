class Node
{
public:
    Node* next = nullptr;
    int key = 0;
    int val = 0;
    Node(int key, int val) : key(key), val(val) {}
    Node() {}
};

class HashTable 
{
public:
    int cap;
    vector<Node*> v;
    int size = 0;
    HashTable(int capacity) 
    {
        cap = capacity;
        v = vector<Node*>(cap, nullptr);
    }

    int hash(int k)
    {
        return k % cap;
    }

    void insert(int key, int value) 
    {
    
        int k = hash(key);
        Node* node = v[k];
        if (!node)
        {
            v[k] = new Node(key, value);
            size++;
        }
        else
        {
            Node* prev = nullptr;
            while (node && node->key != key)
            {
                prev = node;
                node = node->next;
            }
            if (!node)
            {
                // append the new node to the end of the linked list
                prev->next = new Node(key, value);
                size++;
            }
            else
            {
                // we have this key already, update the value
                node->val = value;
            }        
        }

    

        if (2 * size >= cap)
        {
            resize();
        }
    }

    int get(int key) 
    {
    
        int k = hash(key);
        Node* node = v[k];

        while (node && node->key != key)
        {
            node = node->next;
        }

        if (!node)
        {
            return -1;
        }
    
        return node->val;
    }

    bool remove(int key) 
    {
        int k = hash(key);
        Node* node = v[k];
        if (!node) return false;

        Node* prev = node;
        while (node && node->key != key)
        {
            prev = node;
            node = node->next;
        }

        if (!node)
        {
        
            return false;
        }

        prev->next = node->next;
        delete node;
        size--;
    
        return true;
    }

    int getSize() const 
    {
        return this->size;
    }

    int getCapacity() const 
    {
        return this->cap;
    }

    void resize() 
    {
        cap = 2 * cap;
    
        vector<Node*> old = v;
    

        v = vector<Node*>(cap, nullptr);
        for (int i = 0; i < old.size(); ++i)
        {
            v[i] = old[i];
        }
    
    }
};
