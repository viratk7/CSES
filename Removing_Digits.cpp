// Removing Digits
// CSES ID: 1637
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    unordered_map<int,int> memo;

    function<int(int)> dp=[&](int num){
        if(num==0){
            return 0;
        }
        if(memo.count(num)){
            return memo[num];
        }
        //iterate over digits
        int temp=num;
        int curr_ans=INT_MAX;
        while(temp>0){
            int digit=temp%10;
            temp=temp/10;
            if (digit!=0){
                curr_ans=min(curr_ans,1+dp(num-digit));
            }
        }
        memo[num]=curr_ans;
        return memo[num];
    };

    cout<<dp(n)<<endl;

    return 0;
}
