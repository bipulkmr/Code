#include <iostream>

using namespace std;


int getEvenOrOdd(int x, int y){
    if(x%2==0 && y%2==0){
        return 0;
    }
    if(x%2==0 && y%2!=0){
        return 0;
    }
      if(x%2!=0 && y%2==0){
        return 0;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int b,k;
    cin>>b>>k;
    int arr[k];
    for(int i=0; i<k;++i){
        cin>>arr[i];
    }
    //
    int parity = 0;
    parity += getEvenOrOdd(arr[k-1],1);
    for(int i=0; i<k-1; ++i){
        parity += getEvenOrOdd(arr[i], b);
        parity = parity %2;
    }

    string a = !parity?"even":"odd";
    cout<<a<<endl;

    return 0;
}
