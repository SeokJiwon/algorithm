#include <stdio.h>
#include<iostream>
#include <list>

using namespace std;

int main()
{
    int num;
    scanf("%d", &num);
    list<int> lt;
    list<int>::iterator iter;
    for(int i=0;i<num;i++){
        int tmp;
        scanf("%d", &tmp);
        lt.push_back(tmp);
    }
    lt.sort();
    for(iter = lt.begin(); iter!= lt.end(); iter++){
        cout << *iter << endl;
    }    
}