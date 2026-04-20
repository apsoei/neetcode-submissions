// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution 
{
public:
    void quickSort(vector<Pair>& pairs, int L, int R)
    {
        if (L >= R)
        {
            return;
        }

        int p = partition(pairs, L, R);
        quickSort(pairs, L, p - 1);
        quickSort(pairs, p + 1, R);
    }
    int partition(vector<Pair>& pairs, int L, int R)
    {
        int pivotKey = pairs[R].key;
        int p = L, i = L;
        while (i < R)
        {
            if (pairs[i].key < pivotKey)
            {
                swap(pairs[i], pairs[p]);
                p++;
            }
            i++;
        }

        swap(pairs[p], pairs[R]);

        return p;
    }

    vector<Pair> quickSort(vector<Pair>& pairs) 
    {
        quickSort(pairs, 0, pairs.size() - 1);

        return pairs;
    }
};
