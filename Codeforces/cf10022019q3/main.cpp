#include <iostream>
#include<vector>
using namespace std;
#define ll long long
ll arr[1000005];

vector<ll> primes;
void calculatePrimes(){
    arr[0] = 1,arr[1] = 1;
   for(ll i=2;i<1000005;++i){
        if(!arr[i]){
      for(ll j=i*i; j<1000005;j+=i){
        arr[j] = 1;
      }
    }
   }
   for(ll j=2;j<1000005;++j){
    if(!arr[j]){
        primes.push_back(j);
    }
   }
}
ll calculatePowerOfPrimes(ll b, ll a){
    ll ans = 0;
    ll div = a ;
    while(b%div==0){
        div *= a;
        ans++;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,b;
    cin>>n>>b;
    calculatePrimes();
    bool prime_flag = 0;
    ll ans = 999999999999999999;
     for(ll i=0; i<primes.size();++i){
        if(b%primes[i]==0){
            //cout<<primes[i]<<endl;
            ll divPower =  calculatePowerOfPrimes(b,primes[i]);
            ll power = primes[i];
            ll dividedNumber = n;
            ll tmpAns = 0;
            while(dividedNumber/power>0){
                tmpAns+=dividedNumber/power;
                dividedNumber = dividedNumber/power;

            }
            ans = min(ans, tmpAns/divPower);
            for(ll i=0;i<divPower; ++i){
               b = b/power;
            }
        }
     }
     if(b>1){
            ll divPower = 1;
            ll power = b;
            ll dividedNumber = n;
            ll tmpAns = 0;
            while(dividedNumber/power>0){
                tmpAns+=dividedNumber/power;
                dividedNumber = dividedNumber/power;

            }
            ans = min(ans, tmpAns/divPower);
     }

     cout<<ans<<endl;


    return 0;
}
