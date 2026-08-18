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
 ListNode* reverseList(ListNode* temp) {
        if(temp==nullptr ||temp->next==nullptr){
        return temp;
        }
        ListNode* newHead=reverseList(temp->next);
        ListNode*front=temp->next;
        front->next=temp;
        temp->next=nullptr;
        return newHead;
    }
    ListNode* getKthNode(ListNode*temp,int k){
       ListNode*me=temp;
       while(me!=nullptr){
        k--;
        if(k==0) break;
        me=me->next;
       }
       return me;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*temp=head;
        ListNode*prevlast=nullptr;
        while(temp!=nullptr){
            ListNode*kthnode=getKthNode(temp,k);
            if(kthnode==nullptr){
                if(prevlast)
                prevlast->next=temp;
                break;
            }
            ListNode*nextnode=kthnode->next;
            kthnode->next=nullptr;
            reverseList(temp);
            if(temp==head)
            {
                head=kthnode;
            }
            else{
                prevlast->next=kthnode;
            }
            prevlast=temp;
            temp=nextnode;
        }
        return head;
       
        
    }
};