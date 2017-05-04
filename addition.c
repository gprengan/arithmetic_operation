#include<stdio.h>
#include<stdlib.h>

int main(void){

    static int a[100],b[100],carry,ans[101],n,tempc,i,temp[100],j,a_count,b_count;
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

    n=(a_count>b_count) ? a_count:b_count;
    //printf("%d\n",n);

    //check for illegal input

    for(i=0;i<n;i++){
        if(a[i]>9 || b[i]>9 || a[i]<0 || b[i]<0){
            printf("symbols are not allowed\n");
            exit(0);
        }
    }

    //calculation

    for(i=0;i<n+1;i++){

        tempc = a[i]+b[i]+carry;
        carry = tempc/10;
        ans[i] = tempc%10;

        //printf("%d %d\n",carry,ans[i]);
    }

    //Answer
    printf("\nAnswer:");
    for(i=n;i>=0;i--){

        printf("%d",ans[i]);
    }
    printf("\n");
    return 0;
}
