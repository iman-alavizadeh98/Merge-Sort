#include <iostream>
using namespace std;
void merge(float list[],int low,int mid,int high)
{
	
	int i,j,k;
	int n1 = mid - low +1;
	int n2 = high-mid;
	int * s;
	int * u;
	s = new int[n1];
	u = new int[n2];
	for(i=0;i<n1;i++)
	s[i]=list[low+i];
	for(j=0;j<n2;j++)
	u[j]=list[mid+1+j];
	i=0;
	j=0;
	k=low;
	while(i<n1 && j<n2)
	{
		if(s[i]<=u[j])
		{
			list[k]=s[i];
			i++;
		}
		else
		{
			list[k]=u[j];
			j++;
		}
		k++;
	}
	 while(i<n1)
	{
		list[k]=s[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		list[k]=u[j];
		j++;
		k++;
	}
	
}
void mergesort(float list[], int low,int high)
{
	int mid;
	if(low<high)
	{
		mid = (low + high)/2;
		mergesort(list,low,mid);
		mergesort(list,mid+1,high);
		merge(list,low,mid,high);
	}

}
void show(float list[],int n)
{
	for(int i=0;i<n;i++)
	{
	
	cout<<list[i]<<endl;
}
}
int main()
{
int n,l,r;
float x,y;
float * list;
cout<<"meghdar araye ra moshakhas konid\n";
cin>>n;
list =new float[n];
cout<<"adad araye ra vared konid\n";
for(int j=0;j<n;j++){
	cin>>x;
	list[j]=x;
}
l=0;
r=n-1;
mergesort(list,l,r);
show(list,n);
system("pause");
return 0;
}
