#include<stdio.h>
#include<stdlib.h>

int main(void){

    static int check,i,j,div[100],dsr[100],n_div,n_dsr,l,ans_f[100],ans_f_n,k_count,zero_test=0;
    static int n_cmp,n_b,n,q_count,n_o,o[100][100],carry,temp,b[100],k,ans_w[100],ans_n,z;
    char ch;

    ch = 0;
    check=0;

    printf("Enter the dividend:");

    //input for div

    for(i=1;ch != '\n';i++){
        scanf("%1c",&ch);
        div[i] = ch-48;
        n_div++;
    }
    div[n_div]=0;
    n_div--;

    ch = 0;
    printf("Enter the divisor:");

    //input for dsr
    for(i=1;ch != '\n';i++){
        scanf("%1c",&ch);
        dsr[i] = ch-48;
        n_dsr++;
    }
    dsr[n_dsr]=0;
    n_dsr--;

    n_cmp = (n_div>n_dsr) ? n_div:n_dsr;
    n_cmp++;
    //check for illegal input

    for(i=1;i<=n_dsr;i++){
        if(dsr[i] == 0){
            zero_test++;
        }
    }
    if(zero_test == n_dsr){
        printf("division by zero not allowed\n");
        exit(0);
    }
    for(i=0;i<n_cmp;i++){
        if(div[i]>9 || dsr[i]>9 || div[i]<0 || dsr[i]<0){
            printf("symbols are not allowed\n");
            exit(0);
        }
    }

    n_b = n_dsr;
    n = n_b;
    q_count=0;
    n_o=0;

    z = n_dsr-n_div;

    if(n_dsr>n_div){
        for(i=0;i<=n_dsr;i++){
        o[n_o][i+z]=div[i];
        }
    }else{
        for(i=0;i<=n_dsr;i++){
        o[n_o][i]=div[i];
        }
    }


    //division operation starts
    for(l=n;l<=n_div+10;l++){
        for(i=0;i<=9;i++){
            n_b = n;
            carry=0;
            for(j=n_dsr;j>=0;j--){
                temp= i * dsr[j] + carry;
                b[n_b] = temp % 10;
                carry = temp / 10;
                n_b--;
            }
            for(k=k_count;k<=n;k++){
                if(o[n_o][k]==b[k]){
                    continue;
                }
                if(o[n_o][k]>b[k]){
                    break;
                }
                if(o[n_o][k]<b[k]){
                    check=1;
                    break;
                }
            }
            if(check == 1){
                break;
            }
            q_count++;
        }
        if(i==0){
            i=0;
        }
        else{
            i--;
        }
        carry=0;
        n_b = n;
        for(j=n_dsr;j>=0;j--){
            temp = i*dsr[j]+carry;
            carry = temp / 10;
            b[n_b] = temp % 10;
            n_b--;
        }
        q_count--;
        //printf("\n%d\n",q_count);
        if(n_div>=n){
            ans_w[ans_n]=q_count;
            ans_n++;
        }
        if(n_div<n){
            ans_f[ans_f_n]=q_count;
            ans_f_n++;
        }
        //subtraction
        //printf("\nn=%d\nn_o=%d",n,n_o);
        for(j=n;j>=k_count;j--){
            if(o[n_o][j]>=b[j]){
                o[n_o+1][j]=o[n_o][j]-b[j];
            }else{
                o[n_o+1][j]=o[n_o][j]+10-b[j];
                o[n_o][j-1]=o[n_o][j-1]-1;
            }
        }
        n++;
        n_o++;
        k_count++;
        check=0;
        q_count=0;

        if(n_div>=n){
            o[n_o][n] = div[n];
        }else{
            o[n_o][n] = 0;
        }

        /*
        //print b
        printf("\nb\n");
        for(m=k_count-1;m<=n-1;m++){
            printf("%d ",b[m]);
        }
        //print o[1][n]
        printf("\nO\n");
        for(m=k_count-1;m<=n-1;m++){
            printf("%d ",o[n_o][m]);
        }
        */
        //reset b
        for(i=0;i<100;i++){
            b[i]=0;
        }
    }
    //print ans_w
    if(n_dsr>n_div){
        ans_n=1;
    }
    printf("Ans:");
    for(i=0;i<ans_n;i++){
        printf("%d",ans_w[i]);
    }
    //print decimal char
    printf(".");
    //print ans_f
    for(i=0;i<ans_f_n;i++){
        printf("%d",ans_f[i]);
    }
    printf("\n");
}