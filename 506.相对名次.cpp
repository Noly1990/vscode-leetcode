/*
 * @lc app=leetcode.cn id=506 lang=cpp
 *
 * [506] 相对名次
 *
 * https://leetcode-cn.com/problems/relative-ranks/description/
 *
 * algorithms
 * Easy (47.57%)
 * Total Accepted:    2.1K
 * Total Submissions: 4.5K
 * Testcase Example:  '[5,4,3,2,1]'
 *
 * 给出 N 名运动员的成绩，找出他们的相对名次并授予前三名对应的奖牌。前三名运动员将会被分别授予 “金牌”，“银牌” 和“ 铜牌”（"Gold
 * Medal", "Silver Medal", "Bronze Medal"）。
 * 
 * (注：分数越高的选手，排名越靠前。)
 * 
 * 示例 1:
 * 
 * 
 * 输入: [5, 4, 3, 2, 1]
 * 输出: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
 * 解释: 前三名运动员的成绩为前三高的，因此将会分别被授予 “金牌”，“银牌”和“铜牌” ("Gold Medal", "Silver Medal"
 * and "Bronze Medal").
 * 余下的两名运动员，我们只需要通过他们的成绩计算将其相对名次即可。
 * 
 * 提示:
 * 
 * 
 * N 是一个正整数并且不会超过 10000。
 * 所有运动员的成绩都不相同。
 * 
 * 
 */

class Solution
{
  public:
    vector<string> findRelativeRanks(vector<int> &nums)
    {
  
        map<int, string> rankMap;

        string first = "Gold Medal";
        string second = "Silver Medal";
        string third = "Bronze Medal";

        sort(nums.begin(), nums.end());

        rankMap.insert({nums[0], first});
        rankMap.insert({nums[1], second});
        rankMap.insert({nums[2], third});

        for (auto iter = nums.begin() + 2; iter != nums.end(); iter++)
        {
            rankMap.insert({*iter, to_string(*iter)});
        }
        vector<string> out;
        for (auto it = nums.begin(); it != nums.end(); it++)
        {
            out.push_back(rankMap[*it]);
        }
        return out;
    }
};
