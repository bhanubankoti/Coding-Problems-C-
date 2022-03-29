/*Problem Description

Given an array of integers A representing the length of ropes.

You need to connect these ropes into one rope. The cost of connecting two ropes is equal to the sum of their lengths.

Find and return the minimum cost to connect these ropes into one rope.


Problem Constraints

1 <= length of the array <= 100000
1 <= A[i] <= 1000



Input Format

The only argument given is the integer array A.

Output Format

Return an integer denoting the minimum cost to connect these ropes into one rope.

Example Input

Input 1:

 A = [1, 2, 3, 4, 5]
Input 2:

 A = [5, 17, 100, 11]


Example Output

Output 1:

 33
Output 2:

 182*/


int Solution::solve(vector<int> &A) {
    
    int cost = 0;
    priority_queue<int , vector<int> , greater<int>> pq;

    for(auto i : A){
        pq.push(i);
    }

    while(pq.size() != 1){
        int x , y;
        x = pq.top();
        pq.pop();

        y = pq.top();
        pq.pop();

        cost += x+y;

        pq.push(x+y);
    }

    return cost;


}
