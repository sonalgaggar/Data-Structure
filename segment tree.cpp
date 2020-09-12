// To find minimum range query in segment tree

#include<bits/stdc++.h>
using namespace std;

void buildtree(int *a,int *tree,int start,int end,int index)//to build a segment tree
{
    if(start>end)
        return;
    if(start==end){
        tree[index]=a[start];
        return;
    }
    int mid=(start+end)/2;
    buildtree(a,tree,start,mid,2*index);
    buildtree(a,tree,mid+1,end,2*index+1);
    int left=tree[2*index];
    int right=tree[2*index+1];
    
    tree[index]=min(left,right);
}

int query(int *tree,int index,int start,int end,int qs,int qe)  // to find minimum value of a range
{
    if(qs>end || qe<start)       //no overlap
        return INT_MAX;
    
    if(start>=qs && end<=qe)      //complete overlap;
        return tree[index];
    
    int mid=(start+end)/2;       //partial overlap
    int left=query(tree,2*index,start,mid,qs,qe);
    int right=query(tree,2*index+1,mid+1,end,qs,qe);
    return min(left,right);
}

void updatequery(int *tree,int index,int i,int value,int start,int end)  // to change value of any element ,then find minimum over a range
{
    if(i<start || i>end)   // index not found
        return;
    if(start==end){        // location of that index 
        tree[index]=value;
        return;
    }
    int mid=(start+end)/2;
    updatequery(tree,2*index,i,value,start,mid);
    updatequery(tree,2*index+1,i,value,mid+1,end);
    tree[index]=min(tree[2*index],tree[2*index+1]);
    return;
    
}

int main()
{
    int a[]={-1,0,3,6};
    int n=sizeof(a)/sizeof(a[0]);
    int* tree=new int[4*n];
    buildtree(a,tree,0,n-1,1);
    cout<<"range minimum query from 1 to "<<n<<" is: "<<tree[1]<<endl;
    cout<<"starting and ending point of query is: ";
    int x,y,i,value;
    cin>>x>>y;
    cout<<endl;
    cout<<"range minimum query from "<<x<<" to "<<y <<"is "<<query(tree,1,0,n-1,x,y)<<endl;
    cout<<"enter index and value to be updated: ";
    cin>>i>>value;
    cout<<endl;
    updatequery(tree,1,i,value,0,n-1);
        cout<<"range minimum query from 1 to "<<n<<" is: "<<tree[1];
    
    return 0;
}