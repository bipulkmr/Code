#include <iostream>

using namespace std;

int arr[100005];
int n,m,k;

int checkForMinimumValue(int val){
    int lengthCovered = 1;
    int cnt = 1;

   for(int i=1; i<n; ++i){
        if((lengthCovered+(arr[i]-arr[i-1]))<=val){
               lengthCovered+=arr[i]-arr[i-1];
           }
           else{
            cnt++;
            lengthCovered= 1;
           }

   }

   if(cnt<=k){
    return 1;
   }
   else{
    return 0;
   }

}

int getLength(int val){
    int ans = 0;
    int lengthCovered = 1;
    for(int i=1;i<n;++i){
        if(arr[i]-arr[i-1]+lengthCovered <=val){
            lengthCovered += arr[i]-arr[i-1];
            if(i==n-1){
                ans+=lengthCovered;
            }
        }
        else{
            ans += lengthCovered;
            lengthCovered = 1;
            if(i==n-1){
                ans+=1;
            }
        }
    }
    return ans;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n>>m>>k;
    for(int i=0; i<n;++i){
        cin>>arr[i];
    }
    int low = 0,high=m;

    while(low <= high){
        int mid = (low+high+1)/2;
       // cout<<checkForMinimumValue(mid)<<" "<<low<<high<<endl;

        if(checkForMinimumValue(mid)){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    cout<<getLength(low)<<endl;

    return 0;
}
