#include<stdio.h>
#include<conio.h>
int head,a[20],range,n;
void sstf()
{
int c=0,i,j,headm=0,k,t,temp,b[20];
for(i=0;i<n;i++)
{
    b[i]=a[i];
}
b[n]=head;
for(i=0;i<n;i++)
{
for(j=0;j<n-i;j++)
{
if(b[j]>b[j+1])
{
temp=b[j];
b[j]=b[j+1];
b[j+1]=temp;
}
}
}
for(i=0;i<n;i++)
{
if(b[i]==head)
break;
else
c++;
}
j=c;
k=c;
t=j;
for(i=0;i<n;i++)
{
if((b[k+1]-b[t])<(b[t]-b[j-1]) && j>0)
{
headm+=(b[k+1]-b[t]);
k++;
t=k;
}
else if(j==0)
{
headm+=(b[k+1]-b[t]);
k++;
t=k;
}
else
{
headm+=(b[t]-b[j-1]);
j--;
t=j;
}
}
printf("SSTF-Total head movement=%d\n",headm);
}
void look()
{
int headm=0,i,dir,temp,cnt=0;
printf("Enter the direction, upward/right=1, downward/left=-1:\n");
scanf("%d",&dir);
if(dir==1)
{
for(i=0;i<n;i++)
{
if(a[i]<head)
{
cnt++;
continue;
}
else if(i==cnt)
headm=headm+(a[i]-head);
else
headm=headm+(a[i]-a[i-1]);
}
headm+=a[n-1]-a[cnt-1];
for(i=cnt-1;i>0;i--)
{
headm+=(a[i]-a[i-1]);
}
}
else
{
for(i=0;i<n;i++)
{
if(a[i]>head)
break;
else
cnt++;
}
headm+=(head-a[cnt-1]);
for(i=cnt-1;i>0;i--)
{
headm+=(a[i]-a[i-1]);
}
headm+=(a[cnt]-a[0]);
for(i=cnt;i<n-1;i++)
{
headm+=(a[i+1]-a[i]);
}
}
printf("LOOK-Total head movement=%d\n",headm);

}
void clook()
{
int headm=0,i,dir,temp,cnt=0;
printf("Enter the direction, upward/right=1, downward/left=-1:\n");
scanf("%d",&dir);
if(dir==1)
{
for(i=0;i<n;i++)
{
if(a[i]<head)
{
cnt++;
continue;
}
else if(i==cnt)
headm=headm+(a[i]-head);
else
headm=headm+(a[i]-a[i-1]);
}
for(i=cnt-1;i>0;i--)
{
headm+=(a[i]-a[i-1]);
}
}
else
{
for(i=0;i<n;i++)
{
if(a[i]>head)
break;
else
cnt++;
}
headm+=(head-a[cnt-1]);
for(i=cnt-1;i>0;i--)
{
headm+=(a[i]-a[i-1]);
}
for(i=cnt;i<n-1;i++)
{
headm+=(a[i+1]-a[i]);
}

}
printf("CLOOK-Total head movement=%d\n",headm);
}
void main()
{
int i,j,temp;
printf("Enter the total range of cylinders:");
scanf("%d",&range);
printf("\nEnter the number of cylinders:");
scanf("%d",&n);
printf("\nEnter the header:");
scanf("%d",&head);
printf("\nEnter the cylinder numbers:");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
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
sstf();
look();
clook();
}
