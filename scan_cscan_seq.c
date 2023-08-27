#include<stdio.h>
#include<stdlib.h>
int head,a[20],range,n;

void scan(){
int i,dir,headmov=0,mov,cnt=0;
    printf("Entr 1-right/up 0-down/left");
    scanf("%d",&dir);
    printf("%d \t",head);
    if(dir==1){
    for(i=0;i<n;i++){
        if(a[i]<head)
        cnt++;
        else if(i==cnt){
            headmov+=abs(a[i]-head);
            printf("%d \t",a[i]);
        }
        else{
            headmov+=abs(a[i]-a[i-1]);
            printf("%d \t",a[i]);
        }
    }
    printf("%d \t",range);
    headmov+=abs(range-a[i-1]);
    printf("%d \t",a[cnt-1]);
    headmov+=abs(range-a[cnt-1]);
    for(i=cnt-1;i>0;i--){
    headmov+=abs(a[i]-a[i-1]);
    printf("%d \t",a[i-1]);
    }
    }
    
    else{
        for(i=0;i<n;i++){
            if(a[i]<head)
            cnt++;
            else
            break;
        }
        headmov+=abs(head-a[cnt-1]);
        printf("%d \t",a[cnt-1]);
        for(i=cnt-1;i>0;i--){
            printf("%d \t",a[i-1]);
            headmov+=abs(a[i]-a[i-1]);
        }
        printf("0 \t");
        headmov+=abs(a[0]-0);
        printf("%d \t",a[cnt]);
        headmov+=abs(0-a[cnt]);
        for(i=cnt+1;i<n;i++){
            headmov+=abs(a[i]-a[i-1]);
            printf("%d \t",a[i]);
        }
        
    }
    printf(" \n Total head movement scan= %d",headmov);
}
void cscan(){
    int i,dir,headmov=0,mov,cnt=0;
    printf("Entr 1-right/up 0-down/left");
    scanf("%d",&dir);
    printf("%d \t",head);
    
    if(dir==1){
        for(i=0;i<n;i++){
            if(a[i]<head){
                cnt++;
            }
            else if(i==cnt){
                headmov+=abs(head-a[i]);
                printf("%d \t",a[i]);
            }
            else{
                headmov+=abs(a[i]-a[i-1]);
                 printf("%d \t",a[i]);
            }
        }
        printf("%d \t",range);
        headmov+=abs(range-a[i-1]);
        printf("0 \t");
        printf("%d \t",a[0]);
        headmov+=abs(a[0]-0);
        for(i=1;i<cnt;i++){
        printf("%d \t",a[i]); 
        headmov+=abs(a[i]-a[i-1]);
        }
    }
    
    else{
        for(i=0;i<n;i++){
            if(a[i]<head)
            cnt++;
            else
            break;
        }
        printf("%d \t",a[cnt-1]);
        headmov+=abs(head-a[cnt-1]);
        for(i=cnt-1;i>0;i--){
            headmov+=abs(a[i]-a[i-1]);
            printf("%d \t",a[i-1]);
        }
        printf("0 \t");
        headmov+=abs(a[i+1]-0);
        printf("%d \t",range);
        headmov+=abs(a[n-1]-range);
        for(i=n-1;i>cnt;i--){
            headmov+=abs(a[i]-a[i-1]);
            printf("%d \t",a[i-1]);
        }
        
    }
    printf(" \n Total head movement cscan= %d",headmov);
}















void main()
{
int i,j,temp;
printf("Enter the total range of cylinders:");
scanf("%d",&range);
printf("\nEnter the number of cylinders:");
scanf("%d",&n);
printf("\nEnter the cylinder numbers:");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("\nEnter the header:");
scanf("%d",&head);
for(i=0;i<n-1;i++)
{
for(j=0;j<n-i-1;j++)
{
if(a[j]>a[j+1])
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
}
cscan();
// cscan();
}
