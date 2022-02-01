#include<stdio.h>
#include<conio.h>
int step = 0;
void toh(int n,char source,char temp,char destination){
    if(n == 1){
        printf("\nMove disk %d from %c to %c",n,source,destination);
        step++;
    }
    else{
        toh(n-1,source,destination,temp);
        printf("\nMove disk %d from %C to %c",n,source,destination);
        step++;
        toh(n-1,destination,temp,source);
    }
}

void main(){
    int n;
    printf("Enter the no. of disks\n");
    scanf("%d",&n);
    printf("\nThe sequence of the steps are:\n");
    toh(n,'A','B','C');
    printf("steps made %d",step);
}