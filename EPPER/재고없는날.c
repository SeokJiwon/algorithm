#include <stdio.h>

int solution(int n, int m){
//이 아래 필요한 변수 및 필요한 코드를 작성하세요
	int answer=0;
	int cnt=0;
	while(n>0){
		cnt++;
		n-=1;
		if(cnt==m){
			n+=1;
			cnt=0;
		}
		answer++;
	}
	
	return answer;
}

int main() {
   int m;
   int n;
   int answer;
   scanf("%d %d", &n, &m);
   answer = solution(n, m);
   printf("%d", answer);
	
   return 0;
}