#include <iostream>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
  ListNode *swapPairs(ListNode *head)
  {
    if (head == NULL || head->next == NULL)
      return head;

    ListNode *newHead = head->next;

    ListNode *single = head;

    ListNode *singleRight = head->next;

    ListNode *nextSingle;

    ListNode *beforeSingle;

    if (single->next->next == NULL)
    {
      singleRight->next = single;
      single->next = NULL;
      return newHead;
    }
    else
    {

      beforeSingle = single;

      nextSingle = single->next->next;
      single->next->next = single;
      single->next = nextSingle;
      single = nextSingle;
    }

    bool flag = true;

    while (flag)
    {
      if (single->next == NULL)
      {
        flag = false;
        return newHead;
      }
      else
      {
        singleRight = single->next;
        if (single->next->next == NULL)
        {
          // 执行完这一轮
          flag = false;

          beforeSingle->next = singleRight;
          singleRight->next = single;
          single->next = NULL;
          return newHead;
        }
        else
        {
          nextSingle = singleRight->next;
          beforeSingle->next = singleRight;
          singleRight->next = single;
          single->next = nextSingle;
          beforeSingle = single;
          single = nextSingle;
        }
      }
    }
  }
};

void printList(ListNode *head) {
  ListNode *recent = head;
  while(recent->next != NULL){
    /* code */
    cout << recent->val << endl;
    recent = recent->next;
  }
  cout << recent->val << endl;
}

int main()
{
  ListNode *node1 = new ListNode(1);
  ListNode *node2 = new ListNode(2);
  ListNode *node3 = new ListNode(3);
  ListNode *node4 = new ListNode(4);
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = NULL;
  printList(node1);
  Solution s;
  ListNode *newList = s.swapPairs(node1);

  printList(newList);
}