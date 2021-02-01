#include <iostream>
#include <cstring>
#include <string>
using namespace std;
 
int main()
{
	int num;
	int sum;
	int part;
    scanf("%d", &num);
	for (int i = 1; i < num; i++) {
		sum = i;
		part = i;
		while (part) {
			sum += part % 10;
			part /= 10;
		}
		if (num == sum) {
			printf("%d", i);
			return 0;
		}
	}
	printf("0");
	return 0;
}