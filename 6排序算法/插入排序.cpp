#include<iostream>
using namespace std;
////////////////////////////////////////////////////////////////////
int main(){
    int key,j;//key��¼��ǰҪ����Ԫ�� 
    int nums[6]={5,9,10,6,1,3};//Ҫ��������
    //��һ��Ԫ��Ĭ����������i��1��ʼ�����õڶ���Ԫ�ؿ�ʼ���� 
    for(int i=1;i<6;i++)
    {
        key=nums[i];
        j=i-1;
        while(j>=0&&nums[j]>key)
        {
           nums[j+1]=nums[j];//����ƶ�Ԫ��
           j--;
        }
        nums[j+1]=key;//��������Ԫ�ز��뵽�����Һõ�λ��
        for(int k=0;k<6;++k)
        {
            printf("%d��", nums[k]);
        }
        printf("\n");
    } 
    printf("������������"); 
    for(int i=0;i<6;i++)
    {
        printf("%d,",nums[i]);
    }    
    getchar();   
    return 0;
}
