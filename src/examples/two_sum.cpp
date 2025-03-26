/**
 * 牛客网算法题示例：两数之和
 * 题目描述：给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。
 * 作者：NowCode用户
 * 日期：2023-07-01
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * 两数之和问题求解
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map; // 值 -> 索引
    
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        
        // 查找是否存在互补的数
        if (map.find(complement) != map.end()) {
            return {map[complement], i};
        }
        
        // 将当前数及其索引存入哈希表
        map[nums[i]] = i;
    }
    
    // 未找到解
    return {};
}

int main() {
    // 优化输入输出速度
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // 读取输入
    int n, target;
    cin >> n >> target;
    
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    // 求解
    vector<int> result = twoSum(nums, target);
    
    // 输出结果
    if (result.empty()) {
        cout << "No solution found" << endl;
    } else {
        cout << result[0] << " " << result[1] << endl;
    }
    
    return 0;
}