# include <iostream>
# include <algorithm>

using namespace std;

int main(){
    

    int t, l, a, b;
    cin>>t;
    while(t--){
        
        cin>>l>>a>>b;
        // cout<<l<<" "<<a<<" "<<b<<endl;
        int k = l;
        

    
        int ans  =0;
        while(k--){

            int tmp = (a + (k)*b) % l;
            ans = max(ans,tmp);
        }

        cout<<ans<<endl;

    }


}

