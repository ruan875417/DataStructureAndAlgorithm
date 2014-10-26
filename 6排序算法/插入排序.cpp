#include<iostream>
using namespace std;
////////////////////////////////////////////////////////////////////
int main(){
    int key,j;//key记录当前要插入元素 
    int nums[6]={5,9,10,6,1,3};//要排序数组
    //第一个元素默认有序，所以i从1开始，既拿第二个元素开始插入 
    for(int i=1;i<6;i++)
    {
        key=nums[i];
        j=i-1;
        while(j>=0&&nums[j]>key)
        {
           nums[j+1]=nums[j];//向后移动元素
           j--;
        }
        nums[j+1]=key;//将待插入元素插入到所查找好的位置
        for(int k=0;k<6;++k)
        {
            printf("%d，", nums[k]);
        }
        printf("\n");
    } 
    printf("最终排序结果："); 
    for(int i=0;i<6;i++)
    {
        printf("%d,",nums[i]);
    }    
    getchar();   
    return 0;
}
