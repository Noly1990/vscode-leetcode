#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

template <typename T>
void printVector(T &v)
{
  for (auto iter = v.cbegin(); iter != v.cend(); iter++)
  {
    cout << (*iter) << endl;
  }
}

bool cmp(int a, int b)
{
  return a > b;
}

class Solution
{
public:
  vector<string> findRelativeRanks(vector<int> &nums)
  {

    vector<int> source(nums.begin(), nums.end());

    map<int, string> rankMap;

    source.assign(nums.begin(), nums.end());

    int len = nums.size();

    string first = "Gold Medal";
    string second = "Silver Medal";
    string third = "Bronze Medal";
    printVector(nums);

    sort(nums.begin(), nums.end(), cmp);

    rankMap.insert({nums[0], first});
    rankMap.insert({nums[1], second});
    rankMap.insert({nums[2], third});

    for (auto iter = nums.begin() + 2; iter != nums.end(); iter++)
    {
      rankMap.insert({*iter, to_string(*iter)});
    }
    vector<string> out;
    for (auto it = source.begin(); it != source.end(); it++)
    {
      out.push_back(rankMap[*it]);
    }
    return out;
  }
};

int main()
{
  Solution myS;
  vector<int> ranks = {11, 2, 13, 4, 5, 16, 7, 18, 9, 10};
  vector<string> out;
  out = myS.findRelativeRanks(ranks);
  cout << "out is ---> " << endl;
  printVector(out);
  return 0;
}
