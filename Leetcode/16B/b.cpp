#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int INF = 0x3f3f3f3f;

class Solution {
	int n;
	bool vis[20][20][2];
	LL d[20][20][2];
	vector<int> num;
	public:
		LL dfs(int t1,int t2,int t)
		{
			LL& ans = d[t1][t2][t];
			if(t1 >= t2 || vis[t1][t2][t]) return ans;
			vis[t1][t2][t] = 1;
			if(t&1)
			{
				ans = -INF;
				if(t1+1 <= n)
					ans = max(ans,dfs(t1+1,t2,t^1) + num[t1+1]);
				if(t2-1 > 0)
					ans = max(ans,dfs(t1,t2-1,t^1) + num[t2-1]);
			}
			else
			{
				ans = INF;
				if(t1+1 <= n)
					ans = min(ans,dfs(t1+1,t2,t^1) - num[t1+1]);
				if(t2-1 > 0)
					ans = min(ans,dfs(t1,t2-1,t^1) - num[t2-1]);
			}

			return ans;
		}
		bool PredictTheWinner(vector<int>& nums) {
			n = nums.size();
			num.push_back(0);
			for(int i=0;i<n;++i) num.push_back(nums[i]);
			memset(vis,0,sizeof vis);
			memset(d,0,sizeof d);
			return dfs(0,n+1,1) >= 0;
		}
};

int main()
{
	Solution s;
	vector<int> nums;

	nums.push_back(1);
	nums.push_back(5);
	nums.push_back(233);
	nums.push_back(7);

	puts(s.PredictTheWinner(nums)?"True":"False");
	return 0;
}
