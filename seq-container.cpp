#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <forward_list>
#include <string>

using namespace std;

// 顺序容器

void printVector(vector<int> &v)
{
  cout << "the vector print begin" << endl;
  for (auto iter = v.cbegin(); iter != v.cend(); iter++)
  {
    cout << (*iter) << endl;
  }
  cout << "the vector print end" << endl;
}

int main()
{
  // vector init

  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  /**
   * vector初始化的方式
   */
  vector<int> myVector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // 初始化为大括号内的数额
  vector<int> myVector2(myVector);  // 以另一个vector为拷贝初始化vector
  vector<int> myVector3{1,2,3,4,5,5,4,3,2,1};  // 初始化为大括号内的数额
  vector<int> myVector4(10);  // 初始化10个初始值的vector
  vector<int> myVector5(10,8); // 初始化10个值为8的vector
  vector<int> myVector6(myVector.begin(),myVector.begin()+4); // 传入迭代器
  
  cout << "vector size is %d" << myVector.size() << endl;
  cout << "vector max_size is %d"

  list<int> myList;
  deque<int> myDeque;
  forward_list<int> myForList;
  string myStr;

  

  return 0;
}
