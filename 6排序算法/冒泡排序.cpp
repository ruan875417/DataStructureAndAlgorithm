
#include<iostream>
using namespace std;
////////////////////////////////////////////////////////////////////
int main(){
    int nums[6]={5,9,10,6,1,3};//Ҫ��������
    int n=6;
    int temp;
    for(int i=0;i<n;i++)/*��������*/
    {
       for(int j=n-1;j>i;j--)//��С��ð��ǰ�� 
       {
           if(nums[j]<nums[j-1]) /*�ж�ǰһ������Ԫ���Ƿ�Ⱥ�һ���󣬴����򽻻�*/
           {
                temp=nums[j];
                nums[j]=nums[j-1];
                nums[j-1]=temp;
           }
       }
       for(int k=0;k<6;++k)
       {
           printf("%d��", nums[k]);
       }
       printf("\n");
    }
    printf("������������"); 
    for(int i=0;i<n;i++)
    {
        printf("%d,",nums[i]);
    }    
    printf("\n\n");

   
    int nums2[6]={5,9,10,6,1,3};//Ҫ��������
    for(int i=0;i<n;i++)/*��������*/
    {
       for(int j=0;j<n-i;j++)//����ð������ 
       { 
          if(nums2[j]>nums2[j+1]) /*�ж�ǰһ������Ԫ���Ƿ�Ⱥ�һ���󣬴����򽻻�*/
          {
            temp=nums2[j];
            nums2[j]=nums2[j+1];
            nums2[j+1]=temp;
          }
       }
       for(int k=0;k<6;++k)
       {
           printf("%d��", nums2[k]);
       }
       printf("\n");
    }
    printf("������������"); 
    for(int i=0;i<n;i++)
    {
        printf("%d,",nums2[i]);
    }     
    getchar();   
    return 0;
}
