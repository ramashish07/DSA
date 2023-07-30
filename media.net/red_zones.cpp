#include<bits/stdc++.h>
typedef double C;
typedef complex <C> P;
#define X real()
#define Y imag()
P a[205];
int n,k,x,y;
bool check(int r ){
    int c=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
             P g= a[j]-a[i];
             double d = abs(g);
             if(d>2*r) continue;
             P mid =(a[i]+a[j])*(1.0/2);
             double h =sqrt(r*1.0*r-d*d/4);
             P per = P(-g.Y,g.X)*(h/d);
             int c1=2,c2=2;
             for(int l =0;l<n;l++){
                 if(l==i || l==j) continue;
                 if(abs(a[l]-(mid-per))<=r) c1++;
                 if(abs(a[l]-(mid+per))<=r) c2++;
             }
             c= max({c,c1,c2});
        }
    }
    return c>=k;
}


int Solution::solve(vector<vector<int> > &A, int B) {
    n=A.size();
    k=B;
    for(int i=0;i<n;i++){
        a[i]={1.0*A[i][0],1.0*A[i][1]};
    }
    int low =1,high= 2000000000;
    int ans =-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(check(mid)){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return ans;
}
