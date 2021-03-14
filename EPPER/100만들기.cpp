#include <iostream>
using namespace std;
int main() {
	int num[9];
	int answer[7];
	int sum=0;
	for(int i=0;i<9;i++){
		cin >> num[i];
	}
	for(int i=0;i<9;i++){
		sum+=num[i];
	}

	for(int i=0;i<9;i++){
		for(int j=0;j<8;j++){
			if(i==j)
				continue;
			if(sum - num[i] - num[j] == 100){
				num[i]=0;
				num[j]=0;
			}					
		}
	}
	int cnt=0;
	for(int i=0;i<9;i++){
		if(num[i]!=0){
			answer[cnt]=num[i];
			cnt++;
		}
	}
	for(int i=0;i<7;i++){
		cout << answer[i] << " ";
	}
	return 0;
}