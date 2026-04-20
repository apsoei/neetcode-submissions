// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<Pair> mergeSort(vector<Pair>& pairs, int left, int right) {
        if (left >= right) return pairs;

        int mid = (left + right) / 2;
        mergeSort(pairs, left, mid);
        mergeSort(pairs, mid + 1, right);

        merge(pairs, left, mid, right);

        return pairs;
    }

    void merge(vector<Pair>& pairs, int left, int mid, int right) {
        vector<Pair> temp;
        int i = left, j = mid + 1;
        while (i <= mid && j <= right) {
            if (pairs[i].key <= pairs[j].key) {
                temp.push_back(pairs[i]);
                i++;
            } else {
                temp.push_back(pairs[j]);
                j++;
            }
        }

        while (i <= mid) {
            temp.push_back(pairs[i]);
            i++;
        }
        while (j <= right) {
            temp.push_back(pairs[j]);
            j++;
        }

        for (int k = 0; k < temp.size(); ++k) {
            pairs[left + k] = temp[k];
        }
    }
    
    vector<Pair> mergeSort(vector<Pair>& pairs) {
        return mergeSort(pairs, 0, pairs.size() - 1);
    }
};
