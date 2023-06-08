#include<stdio.h>
#include<stdlib.h>
int A[3][3];
int B[3][3];
int C[3][3];

void add(int a[3][3],int b[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            C[i][j]=a[i][j]+b[i][j];
        }
    }
    printf("Resultant matrix\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d\t",C[i][j]);
        }
        printf("\n");
    }
}
void subtract(int a[3][3],int b[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            C[i][j]=a[i][j]-b[i][j];
        }
    }
    printf("Resultant matrix\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d\t",C[i][j]);
        }
        printf("\n");
    }
}
void transpose(int a[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            C[i][j]=a[j][i];
        }
        printf("\n");
    }
    printf("Resultant matrix\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d\t",C[i][j]);
        }
        printf("\n");
    }
}
void multiply(int a[3][3],int b[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            C[i][j]=0;
            for(int k=0;k<3;k++){
                C[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    printf("Resultant matrix\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d\t",C[i][j]);
        }
        printf("\n");
    }
}

int main(){
    printf("enter the elements for matrix A\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&A[i][j]);
        }
    }
    printf("enter the elements for matrix B\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&B[i][j]);
        }
    }
    printf("matrix A\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d\t",A[i][j]);
        }
        printf("\n");
    }
    printf("matrix B\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d\t",B[i][j]);
        }
        printf("\n");
    }
    int ch;
    printf("1.add\n2.subtract\n3.transpose\n4.multiply\n5.exit\n");
    scanf("%d",&ch);
    while(ch!=5){
        switch(ch){
            case 1:
                add(A,B);
                break;
            case 2:
                subtract(A,B);
                break;
            case 3:
                printf("enter matrix to transpose(A->1/B->2)\n");
                int c1;
                scanf("%d",&c1);
                if(c1==1){
                    transpose(A);
                    break;
                }
                else{
                    transpose(B);
                    break;
                }
                break;
            case 4:
                multiply(A,B);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("wrong choice entered\n");
                break;
        }
        printf("1.add\n2.subtract\n3.transpose\n4.multiply\n5.exit\n");
        scanf("%d",&ch);
    }
}
