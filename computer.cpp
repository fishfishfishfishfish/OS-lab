#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
class process
{
public:
	long long rtime;
	long long ptime;	
	process()
	{
		rtime = 0;
		ptime = 0;
	}
	bool operator<(const process &po)const
	{
		if(po.rtime == rtime) return ptime < po.ptime;
		else return  rtime < po.rtime;
	} 
}; 

int main()
{
	int n;
	while(cin >> n)
	{
		process* allProcess = new process[n+1];
		for(int i = 0; i < n; i++)
		{
			cin >> allProcess[i].rtime >> allProcess[i].ptime;
		}
		sort(allProcess, allProcess+n);
		priority_queue<long long, vector<long long>, greater<long long> > less_ptime;
		less_ptime.push(allProcess[0].ptime);
		long long cur_time = allProcess[0].rtime;
		int i = 1;
		long long res = 0;
		while(i < n)
		{
			if(less_ptime.top() <= allProcess[i].rtime-cur_time)
			{
				cur_time = cur_time+less_ptime.top();
				res += cur_time;
				less_ptime.pop();
				if(less_ptime.empty())
				{
					cur_time = allProcess[i].rtime;
					less_ptime.push(allProcess[i].ptime);
					i++;
				}
			}
			else if(less_ptime.top() > allProcess[i].rtime-cur_time)
			{
				long long tptime = less_ptime.top();
				less_ptime.pop();
				less_ptime.push(tptime-(allProcess[i].rtime-cur_time));
				less_ptime.push(allProcess[i].ptime);
				cur_time = allProcess[i].rtime;
				i++;
			}
		}
		while(!less_ptime.empty())
		{
			cur_time = cur_time+less_ptime.top();
			res += cur_time;
			less_ptime.pop();
		}
		cout << res << endl;
	}
}
