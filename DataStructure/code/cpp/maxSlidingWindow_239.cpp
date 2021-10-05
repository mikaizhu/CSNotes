#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <queue>
#include <deque>



using namespace std;
/*
// 暴力解法
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1) return nums;
        vector<int> res;
        int _max;
        for (int i = 0; i <= nums.size() - k; i++)
        {
            _max = *max_element(nums.begin() + i, nums.begin() + i + k);
            res.push_back(_max);
        }
        return res;
    }
};
*/
class Solution {
private:
  class Mydeque {
  public:
      deque<int> _que;

      // 队列返回的就是结果
      int front() {
          return _que.front();
      }

      // 将要push的元素和队列右边(尾部)的元素比较，如果val大于尾部元素，则pop出尾部元素
      void push(int _val)
      {
          while (!_que.empty() && _val > _que.back()) // 不用等于
              _que.pop_back();
          _que.push_back(_val);
      }

      void pop(int _val) {
          if (!_que.empty() && _val == _que.front())
              _que.pop_front();
      }
  };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        Mydeque que;
        vector<int> res;
        // 先将第一个窗口的元素添加进去
        for (int i = 0; i < k; i++)
            que.push(nums[i]);
        res.push_back(que.front());
        // 因为每次只移动一步，所以再用个for循环即可
        for (int i = k; i < nums.size(); i++)
        {
            que.pop(nums[i-k]); // 将最左边的弹出
            que.push(nums[i]); // 添加元素进去
            res.push_back(que.front()); // 返回窗口最大值
        }
        return res;
    }
};

int main()
{
    vector<int> t = {1,3,-1,-3,5,3,6,7};
    Solution so;
    so.maxSlidingWindow(t, 3);
}
