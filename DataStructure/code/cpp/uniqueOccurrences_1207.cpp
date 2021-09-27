class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> map, count_map;
        for (int i : arr)
            map[i]++;
        for (auto it : map)
        {
            count_map[it.second]++;
            if (count_map[it.second] == 2) return false;
        }
        return true;
    }
};
