#include<iostream>
using namespace std;
int maxbit(int data[],int n)//求数据的最大位数
{  
    int count; 
    int max=1;
    int* temp;
    temp=new int[n];
    for(int i=0;i<n;i++)
        temp[i]=data[i];
    for(int i=0;i<n;i++)
    {
      count=1;
        while(temp[i]/10>0)
        {
              count++;
              temp[i]/=10;
        }
        if(count>max)
           max=count;
    }
    delete[] temp;
    return max;               
}
void radixsort(int data[],int n)//基数排序
{ 
     int* temp;
     temp=new int[n];
     int k;
     int count[10];
     int radix=1;
     int max=maxbit(data,n);
     for(int i=radix;i<=max;i++)
     {
         for(int j=0;j<10;j++)
             count[j]=0;
         for(int j=0;j<n;j++)
         {
             k=(data[j]/radix)%10;
             count[k]++;
         }
         for(int j=1;j<10;j++)     //这一步重要
             count[j]+=count[j-1];
         for(int j=n-1;j>=0;j--)   //从后往前进行
         {
             k=(data[j]/radix)%10;
             count[k]--;
             temp[count[k]]=data[j];
         }
         for(int j=0;j<n;j++)
         {
             data[j]=temp[j];
             cout<<data[j]<<"    ";
         }
         cout<<endl;
         radix*=10;
     }
     delete[] temp;
}
int main()
{
    int nums[]={34,25,76,234,62,17};
    radixsort(nums,6);
    cout<<"最终排序结果："; 
    for (int i=0;i<6;i++)
        cout<<nums[i]<<"    ";
    cout<<endl;
    system("pause");
    return 0;
}
