#include <bits/stdc++.h>
#define llt long long int           // llt being used for long long int

using namespace std;

vector<llt> Digits(llt num){                
    vector<llt> digits;

    while(num){
        digits.push_back(num%10);
        num /= 10;
    }

    return digits;
}

llt dp[163][20];

llt Sum_to_N(llt sum, llt ind, llt tight, vector<llt> &digits){
    // Base case
    if(ind == -1) return sum;

    // If the value already exists in the dp
    if(dp[sum][ind] != -1 && tight == 0) return dp[sum][ind];

    // Max integer to be iterated to, based on the value of tight
    llt val = 0, new_tight, k;
    if(tight) k = digits[ind];
    else k = 9;

    // Iterating for all possible digits, and recursing them
    for(int i=0; i<=k; i++){
        if(i == digits[ind]) new_tight = tight;
        else new_tight = 0;

        val += Sum_to_N(sum+i, ind-1, new_tight, digits);
    }

    // If tight is 1, then the val is not to be stored
    if(!tight) dp[sum][ind] = val;

    return val;
}

void Main(){

    llt a, b;
    cin >> a >> b;

    vector<llt> Digits_a = Digits(a-1), Digits_b = Digits(b);
    memset(dp, -1, sizeof(dp));

    // Taking the difference and giving output
    cout << Sum_to_N(0, Digits_b.size()-1, 1, Digits_b) 
            - Sum_to_N(0, Digits_a.size()-1, 1, Digits_a) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t; while(t--) Main();
    return 0;
}