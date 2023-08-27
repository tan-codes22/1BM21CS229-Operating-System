#include<stdio.h>
#include<stdlib.h>
int head,a[20],range,n;
void fcfs(){
    int i;
    int mov,headm=0;
    printf("%d \t",head);
    for(i=0;i<n;i++){
    if(i==0)
    {
        headm+=abs(head-a[i]);
        printf("%d \t",a[i]);
    }
    else{
        headm+=abs(a[i]-a[i-1]);
         printf("%d \t",a[i]);
    }
    }
    printf(" \n Total head movement = %d",headm);
    
}

void look(){
    int i,dir,headmov=0,mov,cnt=0;
    printf("Entr 1-right/up 0-down/left");
    scanf("%d",&dir);
    if(dir==1){
        for(i=0;i<n;i++){
            if(a[i]<head){
                cnt++;continue;
            }
            else if(i==cnt){
            printf("%d \t %d \t",head,a[cnt]);
            headmov+=abs(head-a[cnt]);
            }
            else{
                printf("%d \t",a[i]);
                headmov+=abs(a[i]-a[i-1]);
            }
            
        }
        printf("%d \t",a[cnt-1]);
        headmov+=abs(a[i-1]-a[cnt-1]);
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
        printf("%d \t %d \t",head,a[cnt-1]);
        headmov+=abs(head-a[cnt-1]);
        for(i=cnt-1;i>0;i--){
        headmov+=abs(a[i]-a[i-1]);
        printf("%d \t %d \t",a[i-1],a[cnt]);
        }
        headmov+=abs(a[0]-a[cnt]);
        for(i=cnt+1;i<n;i++){
        printf("%d \t",a[i]);
        headmov+=abs(a[i]-a[i-1]);
        
        }
        
    }
    printf(" \n Total head movement look= %d",headmov);
    
}

void clook(){
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
            headmov+=abs(a[i]-head);
            printf("%d \t",a[i]);
            }
            else{
            headmov+=abs(a[i]-a[i-1]);  
            printf("%d \t",a[i]);
            }
        }
            printf("%d \t",a[0]);
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
        headmov+=abs(head-a[cnt-1]);
        printf("%d \t",a[cnt-1]);
        for(i=cnt-1;i>0;i--){
        headmov+=abs(a[i]-a[i-1]);
        printf("%d \t",a[i-1]);
        }
        printf("%d \t",a[n-1]);
        for(i=n-1;i>cnt;i--){
        printf("%d \t",a[i-1]);
        headmov+=abs(a[i]-a[i-1]);
        }
    }
   printf(" \n Total head movement clook= %d",headmov);
    
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
fcfs();
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
clook();
// cscan();
}
