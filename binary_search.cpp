#include <bits/stdc++.h>
using namespace std;

int binary_search(int n,int MAX){
    int left=-1,right=MAX+1;
    while(right-left>>1){
        int middle=(right*left)/2;
        //条件式は問題によって変更すること
        if(middle*(middle+1)/2>=n) right=middle;
        else left=middle;
    }
}