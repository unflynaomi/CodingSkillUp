#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int maxlen;    /* 记录最长重复子串长度 */
int maxindex;  /* 记录最长重复子串的起始位置 */
void outputLRS(char * arr);

char * suff[100];

int comlen(char * p, char * q)
{
    int len = 0;
    while(*p && *q && *p++ == *q++)
    {
        ++len;
    }
    return len;
}

int pstrcmp(const void * p, const void * q)
{
    return strcmp(*(char**)p, *(char**)q);
}

void LRS_suffix(char * arr, int size)
{
    int suff_index = maxlen = maxindex = 0;
    
    for(int i = 0; i < size; ++i) /* 初始化后缀数组 */
    {
        suff[i] = & arr[i];
    }
    qsort(suff, size, sizeof(char *), pstrcmp); /* 排序后缀 */
    for(int i = 0; i < size-1; ++i)  /* 寻找最长重复子串 */
    {
        int len = comlen(suff[i],suff[i+1]);
        if(len > maxlen)
        {
            maxlen = len;
            suff_index = i;
        }
    }
    outputLRS(suff[suff_index]);
}

void outputLRS(char * arr)
{
    if(maxlen == 0)
    {
        cout<<" "<<0<<endl;
        return;
    }
//    printf("The len of LRS is %d\n",maxlen);
    
    int i = maxindex;
    int j=maxlen;
    while(maxlen--)
    {
        printf("%c",arr[i++]);
    }
    printf(" %d",j);
}


int main()
{
    char str[100];

    cin>>str;
    LRS_suffix(str,strlen(str));
//    for (index=0;index<max;index++)
//    {
//        i++;
//        cout<<str[index+maxIndex];
//    }
//    cout<<" "<<i<<endl;
    return 0;
}
