class Solution {
public:
    // 自己定义一个仿函数
    class cmp {
        public:
          bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
              return lhs.second > rhs.second; // second是元素的频率，因为堆是完全二叉树，右边大于左边，表示最小堆
          }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;

        // 统计频率
        unordered_map<int, int> _map;
        for (int i = 0; i < nums.size(); i++)
            _map[nums[i]]++;

        // 对频率排序, 创建最小堆，维护长度为k的最小堆
        // 堆默认是用容器vector存储, 第一个参数是元素类型
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> _que;

        for (auto pair : _map)
        {
            _que.push(pair);
            if (_que.size() > k)
                _que.pop();
        }

        // 遍历返回元素
        for (int i = 0; i < k; i++)
        {
            res.push_back(_que.top().first);
            _que.pop();
        }
        return res;
    }
};
