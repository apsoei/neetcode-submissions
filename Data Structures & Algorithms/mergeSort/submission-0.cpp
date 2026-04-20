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
    void mergeSort(vector<Pair>& pairs, int L, int R)
    {
        if (L >= R)
        {
            return;
        }
        int M = L + (R - L) / 2;
        mergeSort(pairs, L, M);
        mergeSort(pairs, M + 1, R);

        merge(pairs, L, M, R);
    }

    void merge(vector<Pair>& pairs, int L, int M, int R)
    {
        vector<Pair> temp;
        int i = L, j = M + 1;
        while (i <= M && j <= R)
        {
            if (pairs[i].key <= pairs[j].key)
            {
                temp.push_back(pairs[i]);
                i++;
            }
            else
            {
                temp.push_back(pairs[j]);
                j++;
            }
        }

        while (i <= M)
        {
            temp.push_back(pairs[i]);
            i++;
        }

        while (j <= R)
        {
            temp.push_back(pairs[j]);
            j++;
        }

        for (int k = 0; k < temp.size(); ++k)
        {
            pairs[k + L] = temp[k];
        }
    }

    vector<Pair> mergeSort(vector<Pair>& pairs) 
    {
        mergeSort(pairs, 0, pairs.size() - 1);

        return pairs;
    }
};
