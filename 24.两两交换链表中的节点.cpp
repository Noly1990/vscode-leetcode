/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 *
 * https://leetcode-cn.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (59.04%)
 * Total Accepted:    19.3K
 * Total Submissions: 32.7K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 
 * 
 * 示例:
 * 
 * 给定 1->2->3->4, 你应该返回 2->1->4->3.
 * 
 * 
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// #include <iostream>

// using namespace std;

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

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
        return newHead;
    }
};
