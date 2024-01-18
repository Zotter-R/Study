#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//打印三座塔
void road(int rT1[],int rT2[],int rT3[],int sz)
{
    printf("T1:>");
    for(int i =0;i<=sz-1;i++)
    {
        printf("%d ",rT1[i]);
    }
    
    printf("\nT2:>");
    for(int i =0;i<=sz-1;i++)
    {
        printf("%d ",rT2[i]);
    }

    printf("\nT3:>");
    for(int i =0;i<=sz-1;i++)
    {
        printf("%d ",rT3[i]);
    }

    printf("\n\n");
}

//从m1移到m2，移动1项,总长sz
void move(int m1[],int m2[],int sz)
{
    int i=0;int j=0;
    if(m1[0]!=0)
    {
    //找到不是0的最高位
        for(i=0;;)
        {
            i++;
            if(i==sz) {break;}
            if(m1[i]==0) {break;}
        }
    //找到为0的最低位 
        for(j=0;;j++)
        {
            if(j==sz) {break;}
            if(m2[j]==0) {break;}
        }

        m2[j]=m1[i-1];
        m1[i-1]=0;
    }
    else 
        {printf("没东西移动");}
}

//总长sz项，每次作用i项
int Han(int hT1[],int hT2[],int hT3[],int i,int sz)
{
    static int count=0;
    count++;
    if(1 == i)
    {
        move(hT1,hT3,sz);
    }
    else
    {
        Han(hT1,hT3,hT2,i-1,sz);
        move(hT1,hT3,sz);
        Han(hT2,hT1,hT3,i-1,sz);
    }
    road(hT1,hT2,hT3,sz);
    return count;
}   

int main()
{
    int n=0;
    scanf("%d",&n);
    int *T1 = (int *)malloc(sizeof(int) * n);
    int *T2 = (int *)malloc(sizeof(int) * n);
    int *T3 = (int *)malloc(sizeof(int) * n);
    for(int i=1;i<=n;i++)
    {
        T1[n-i]=i;
        T2[n-i]=0;
        T3[n-i]=0;
    }
    int sz=sizeof(int) * n/sizeof(T1[0]);
    //被除数应该填这个，而不是sizeof(T1),
    //因为通过malloc分配空间的T1是指针，而不是数组本身
    system("cls");
    
    road(T1,T2,T3,sz);
    int cH=Han(T1,T2,T3,sz,sz);
    printf("%d\n",cH);

    free(T1);
    free(T2);
    free(T3);
    system("pause");
    return 0;
}
