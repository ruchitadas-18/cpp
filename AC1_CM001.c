#include <stdio.h>
#include <math.h>

int even_num(int d){
    return d*d*d;
}
int power(int a){
    int c = 1;
    int b = 2;
    while(b>0){
        c=c*a;
        b--;
    }
    return c;
}
int odd_num(int r){
    int b =0;
    while(r>0){
        int v = r%10;
        b += power(v);
        r=r/10;
    }
    return b;
}

int digit(int a){
    int prod = 1;
    int max = 0;
    int count =0;
    int b;
    int r = a;
    while(a>0){
        prod = prod*(a%10);
        if(max<a%10){
            max = a%10;
        }
        count++;
        a/=10;
    }
    if(prod==0){
        b=-1;
    }
    else{
        if(prod%2==0){
            b=even_num(max);
        }else{
            b=odd_num(r);
        }
    }
    return b;
}

int main(){
    int a;
    scanf("%d",&a);
    int y;
    y = digit(a);
    printf("%d",y);
    return 0;
}