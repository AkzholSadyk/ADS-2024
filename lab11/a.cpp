#include<bits/stdc++.h>

using namespace std;

int main(){
	int a, b;cin >> a >> b;
	long long sum = 0;

	vector< pair < int , pair<int,int> > > ako;
	for (int i = 0; i < b; i++){
		int l, r, c;
		cin >> l >> r >> c;
		ako.push_back({c, {l, r}});
	}

	sort(ako.begin(),ako.end());
	int limit = 2;
	while(limit <= a){
		for(int i=0;i<ako.size();i++){
			int x = ako[i].second.first;  
            int y = ako[i].second.second;
            int  cost = ako[i].first;
			if(x < limit && limit <= y){
				sum += cost;
				limit++;
				break;
			}
		}
	}
	cout << sum;
	return 0;
}