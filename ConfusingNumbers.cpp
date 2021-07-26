/*
Intuition: Iterate from 1 to N inclusive. See if all numbers are confusing or not.
We can check if the number is confusing by reversing it and getting the roatated digit for each digit.

This will give us Time Limit Exceeded.
Time Complexity: O(N)
Space Complexity: O(1)
//////////////////////////////////////////
To improve this we can use the confused digits and form all possible numbers using these confused digits.
Still the time complexity will be the same but it is accepted on LC.
Time Complexity: O(N)
Space Complexity: O(1)
//////////////////////////////////////////
*/

//Time Limited Exceeded Solution
class Solution {
public:
    map<int,int>map;
    int confusingNumberII(int n) {
        int result = 0;
        
        map.insert({0,0});
        map.insert({1,1});
        map.insert({6,9});
        map.insert({9,6});
        map.insert({8,8});
        
        for ( int i = 1; i <= n; i++){
            if ( isValid((long)i)) result++;
        }
        return result;
    }
    
    bool isValid(long num){
        long long resultNum = 0;
        long copyNum = num;
        while ( num > 0){
            int r = num % 10;
            if ( map.find(r) == map.end()) return false;
            long rotatedNum = map[r];
            resultNum = resultNum * 10 + rotatedNum;
            num = num / 10;
        }
        
        return resultNum != copyNum;
    
    
    }
};


//Exploring all nums
class Solution {
public:
    map<int,int>map;
    int result;
    int confusingNumberII(int n) {
        result = 0;
        
        map.insert({0,0});
        map.insert({1,1});
        map.insert({6,9});
        map.insert({9,6});
        map.insert({8,8});
        
        dfs(n, 0);
        return result;
    }
    
    void dfs(int N, long curr){
        
        if ( curr > N) return;
        if( isValid(curr)) result++;
        for ( auto KV: map){
            long newNum = curr * 10 + KV.first;
            if ( newNum != 0 ) dfs(N, newNum);
        
        }
    } 
       
    bool isValid(long num){
        long long resultNum = 0;
        long copyNum = num;
        while ( num > 0){
            int r = num % 10;
            if ( map.find(r) == map.end()) return false;
            long rotatedNum = map[r];
            resultNum = resultNum * 10 + rotatedNum;
            num = num / 10;
        }
        
        return resultNum != copyNum;
    
    
    }
};