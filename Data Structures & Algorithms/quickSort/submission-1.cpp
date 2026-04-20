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
    vector<Pair> quickSort(vector<Pair>& pairs, int start, int end) {
        if (start >= end) {
            return pairs;
        }

        // partition
        int pivotVal = pairs[end].key;
        int i = start;
        int p = start;
        while (i < end) {
            if (pairs[i].key < pivotVal) {
                swap(pairs[i], pairs[p++]);
            }
            i++;
        }

        swap(pairs[p], pairs[end]);

        quickSort(pairs, start, p - 1);
        quickSort(pairs, p + 1, end);

        return pairs;
    }

    vector<Pair> quickSort(vector<Pair>& pairs) {
        return quickSort(pairs, 0, pairs.size() - 1);
    }
};
