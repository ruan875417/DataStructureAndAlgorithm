
#include<iostream>
using namespace std;
////////////////////////////////////////////////////////////////////
int main(){
    int nums[6]={5,9,10,6,1,3};//要排序数组
    int n=6;
    int temp;
    for(int i=0;i<n;i++)/*排序趟数*/
    {
       for(int j=n-1;j>i;j--)//最小的冒到前面 
       {
           if(nums[j]<nums[j-1]) /*判断前一个数据元素是否比后一个大，大于则交换*/
           {
                temp=nums[j];
                nums[j]=nums[j-1];
                nums[j-1]=temp;
           }
       }
       for(int k=0;k<6;++k)
       {
           printf("%d，", nums[k]);
       }
       printf("\n");
    }
    printf("最终排序结果："); 
    for(int i=0;i<n;i++)
    {
        printf("%d,",nums[i]);
    }    
    printf("\n\n");

   
    int nums2[6]={5,9,10,6,1,3};//要排序数组
    for(int i=0;i<n;i++)/*排序趟数*/
    {
       for(int j=0;j<n-i;j++)//最大的冒到后面 
       { 
          if(nums2[j]>nums2[j+1]) /*判断前一个数据元素是否比后一个大，大于则交换*/
          {
            temp=nums2[j];
            nums2[j]=nums2[j+1];
            nums2[j+1]=temp;
          }
       }
       for(int k=0;k<6;++k)
       {
           printf("%d，", nums2[k]);
       }
       printf("\n");
    }
    printf("最终排序结果："); 
    for(int i=0;i<n;i++)
    {
        printf("%d,",nums2[i]);
    }     
    getchar();   
    return 0;
}
