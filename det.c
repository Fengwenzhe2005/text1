#include<iostream>
using namespace std;

const int N=15;
int n,a[N][N],col[N]; 

int det(int m,int l){
	if(m==1)
		for(int i=0;i<n;i++)
			if(!col[i]){
				return a[l][i];
			}
	
	int res=0,r=0,c=0;
	for(int i=0;i<n;i++){
		if(col[i]) continue ;
	    
		col[i]=1;
		int t=det(m-1,l+1);
		if((r+c)%2==0) res+=a[l][i]*t;
		else res-=a[l][i]*t;
		c++;
		col[i]=0;
	}	
	return res;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
			
	printf("%d\n",det(n,0));	
	return 0;	
}
