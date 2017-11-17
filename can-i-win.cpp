//Runtime: 183 ms
class Solution {
public:
	unordered_map<int, bool> Mp;
	vector<bool>used;
	int findkey(vector<bool>&used)
	{
		int num = 0;
		for (bool a : used)
		{
			num <<= 1;
			if (a) num |= 1;

		}
		return num;
	}

	bool solve(int dt)
	{
		if (dt <= 0)
			return 0;

		int key = findkey(used);

		auto it = Mp.find(key);
		if (it != Mp.end())
			return it->second;

		for (int i = 1; i < used.size(); i++)
		{
			if (!used[i])
			{
				used[i] = 1;

				if (!solve(dt - i))
				{
					Mp[key] = 1;
					used[i] = 0;
					return 1;
				}
				used[i] = 0;
			}
		}
		Mp[key] = 0;
		return 0;
	}

	bool canIWin(int maxChoosableInteger, int desiredTotal) {
		if (desiredTotal <= 0)
			return 1;
		int sum = (1 + maxChoosableInteger) * maxChoosableInteger / 2;
		if (sum < desiredTotal)
			return 0;

		for (int i = 0; i <= maxChoosableInteger; i++)
			used.push_back(0);

		return solve(desiredTotal);
	}
};
