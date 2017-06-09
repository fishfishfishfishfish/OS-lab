#include<iostream>
#include<queue>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, m;
		cin >> n >> m;
		int Available[m];
		bool Finish[n];
		int Allocation[n][m];
		int Need[n][m];
		bool flag_finish,flag_need,flag_bankrupt;
		for(int i = 0; i < m; i++)
		{
			cin >> Available[i];
		}
		for(int i = 0; i < n; i++)
		{
			Finish[i] = 0;
			for(int j = 0; j < m; j++)
			{
				cin >> Allocation[i][j];
			}
		}
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				cin >> Need[i][j];
			}
		}
		queue<int> seq;
		while(1)
		{
			flag_finish = 1;
			flag_bankrupt = 1;
			for(int i = 0; i < n; i++)
			{
				if(!Finish[i])
				{
					flag_finish = 0;
					flag_need = 1;
					for(int j = 0; j < m; j++)
					{
						if(Need[i][j] > Available[j])
						{
							flag_need = 0;
							break;
						}
					}
					if(flag_need)
					{
						flag_bankrupt = 0;
						for(int j = 0; j < m; j++)
						{
							Available[j] += Allocation[i][j];
						}
						Finish[i] = 1;
						seq.push(i);
						break;
					}
				}
			}
			if(flag_finish)
			{
				cout << "Yes";
				while(!seq.empty())
				{
					cout << ' ' << seq.front();
					seq.pop();
				}
				cout << endl;
				break;
			}
			else if(flag_bankrupt)
			{
				cout << "No" << endl;
				break;
			}
		}
		
	} 
	return 0;
 } 
