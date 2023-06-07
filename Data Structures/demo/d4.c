#include<stdio.h>
#include<string.h>
int main()
{
    int s[100];
    int i;
    scanf("%s",r);
    int sum=0;
    int n=strlen(r);
    printf("%d\n",n);
    for(i=0;i<n;i++){
        printf("%d ",i);
        printf("%c ",s[i]);
        int t=(int)s[i]-96; 
        sum=sum+t;
        printf("%d ",t);
    }
    
    // for(i=0;i<strlen(s);i++)
    // {
    //     printf("%d ",s[i]);
    // }
    return 0;
}