/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
   priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;

    ListNode *start = NULL , *ans; 

    for(int i=0;i<A.size();i++){
        pq.push({A[i]->val , i});
    }

    while(!pq.empty()){
        pair<int , int> tmp;
        tmp = pq.top();
        pq.pop();

        
        if(start == NULL){
            ans = A[tmp.second];
            start = ans;
        }   
        else{
            ans->next = A[tmp.second];
            ans = ans->next;
        }

        if(A[tmp.second]->next){

            A[tmp.second] = A[tmp.second]->next;
            pq.push({A[tmp.second]->val , tmp.second});
        }
    }

    return start;

}
//time complexity : O(K)+(NK-K)LogK
//space complexity : O(K)
