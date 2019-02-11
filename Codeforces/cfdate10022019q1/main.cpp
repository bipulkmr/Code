#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int x,y,z;
    int a,b,c;
    cin>>x>>y>>z;
    cin>>a>>b>>c;
    int flag = 1;
    if(x>a){
        flag=0;
    }
    if(y>(a+b-x)){
        flag=0;
    }
    if(z>(a+b+c-x-y)){
        flag=0;
    }

    string ans = flag?"YES":"NO";
    cout<<ans<<endl;
    return 0;
}
