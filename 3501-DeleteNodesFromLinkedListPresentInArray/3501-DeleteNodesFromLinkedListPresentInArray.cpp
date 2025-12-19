// Last updated: 19/12/2025, 19:23:49
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int>mp;
        for(auto it:nums) mp[it]=1;
        while(head!=nullptr){
            int x = head->val;
            if(mp.find(x)!=mp.end()) head = head->next;
            else break;
        }
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* ans = head, *prev = head, *curr = head->next;
        while(curr!=nullptr){
            int x = curr->val;
            if(mp.find(x)!=mp.end()) prev->next = curr->next;
            else{
                prev = prev->next;
            }
            curr = curr->next;
        }
        return ans;
    }
};