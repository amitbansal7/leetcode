//My solution
//Runtime: 123 ms
class Solution {
public:

    vector<int> squares;
    int solve(int n,vector<int>&DP)
    {
        if(DP[n] != -1)
            return DP[n];

        int ans = INT_MAX;
        int sq = sqrt(n);

        for(int i=0;i<sq;i++)
            ans =  min(ans, solve(n-squares[i], DP));

        ans++;

        return DP[n] = ans;

    }

    int numSquares(int n) {
        int srt = sqrt(n);
        for(int i=1;i<=srt;i++)
            squares.push_back(i*i);

        vector<int>DP(n+1,-1);
        DP[0] = 0;
        DP[1] = 1;
        return solve(n, DP);
    }

};

//Optimal solution
//Runtime: 6 ms
class Solution {
public:

    int numSquares(int n) {

        if(n<=0)
            return 0;
        static vector<int> answers({0});

        while(answers.size() <= n)
        {
            int a = answers.size();

            int ans = INT_MAX;
            for(int i=1;i*i<=a;i++)
                ans = min(ans, answers[a-i*i]+1);

            answers.push_back(ans);

        }
        return answers[n];
    }

};
