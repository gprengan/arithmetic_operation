#include<stdio.h>
#include<stdlib.h>

int main(void){

    static int a[100],b[100],ans[101],k[400][400],l[400][400],i,j,carry,n,incr;
    static int tempc,temp[100],a_count,b_count;

    char c;

    c=0;
    printf("Enter the first number:");

    //input for a

    for(i=0;c != '\n';i++){
        scanf("%1c",&c);
        temp[i] = c-48;
        a_count++;
    }
    temp[a_count-1]=0;
    a_count=a_count-1;

    for(i=0,j=a_count-1;i<a_count;i++,j--){
        a[j]=temp[i];
    }

    c=0;
    printf("Enter the second number:");

    //re init the temp to zero
    for(i=0;i<100;i++){
        temp[i]=0;
    }
    //input for b

    for(i=0;c != '\n';i++){
        scanf("%1c",&c);
        temp[i] = c-48;
        b_count++;
    }
    temp[b_count-1]=0;
    b_count=b_count-1;

    for(i=0,j=b_count-1;i<b_count;i++,j--){
        b[j]=temp[i];
    }

    n = (a_count>b_count) ? a_count:b_count;
    //printf("%d\n",n);

    //check for illegal input

    for(i=0;i<n;i++){
        if(a[i]>9 || b[i]>9 || a[i]<0 || b[i]<0){
            printf("symbols are not allowed\n");
            exit(0);
        }
    }

    //printf("\n");
    carry=0;
    for(i=0;i<n;i++){

        for(j=0;j<=n;j++){

            tempc=a[i]*b[j]+carry;
            carry=tempc/10;
            k[i][j]=tempc%10;
            //printf("%d ",k[i][j]);
        }
        //printf("\n");
    }
    //printf("\n");
    incr=0;
    for(i=0;i<n;i++){

        for(j=0;j<=n;j++){

            l[i][j+incr]=k[i][j];
        }
        incr++;
    }

    //print the l
    /*for(i=0;i<n;i++){

        for(j=2*n-1;j>=0;j--){
            printf("%d ",l[i][j]);
        }
        printf("\n");
    }

    */
    carry=0;
    tempc=0;
    //printf("\n");
    for(i=0;i<2*n;i++){
        for(j=0;j<n;j++){
            tempc=tempc+l[j][i];
        }
        tempc=tempc+carry;
        ans[i]=tempc%10;
        carry=tempc/10;
        tempc=0;
        //printf("%d %d\n",carry,ans[i]);
    }

    printf("\nAnswer:");
    for(i=2*n-1;i>=0;i--){
        printf("%d",ans[i]);
    }
    printf("\n");
    return 0;
}
