#include<stdio.h>
#include<math.h>

void sort(int arr[], int n);
void swap(int *a, int *b);

int ones(int n){
    if(n==1){
        return 3;
    }
    else if(n==2){
        return 3;
    }
    else if(n==3){
        return 5;
    }
    else if(n==4){
        return 4;
    }
    else if(n==5){
        return 4;
    }
    else if(n==6){
        return 3;
    }
    else if(n==7){
        return 5;
    }
    else if(n==8){
        return 5;
    }
    else if(n==9){
        return 4;
    }
    else{
        return 3;
    }
}

int twos(int n){
    if(n==10){
        return 3;
    }
    else if(n==11){
        return 6;
    }
    else if(n==12){
        return 6;
    }
    else if(n==13){
        return 8;
    }
    else if(n==14){
        return 8;
    }
    else if(n==15){
        return 7;
    }
    else if(n==16){
        return 7;
    }
    else if(n==17){
        return 9;
    }
    else if(n==18){
        return 8;
    }
    else if(n==19){
        return 7;
    }
    else{
        return 6;
    }
}

int tens(int n){
    if(n==10){
        return 3;
    }
    else if(n==20){
        return 6;
    }
    else if(n==30){
        return 6;
    }
    else if(n==40){
        return 6;
    }
    else if(n==50){
        return 5;
    }
    else if(n==60){
        return 5;
    }
    else if(n==70){
        return 7;
    }
    else if(n==80){
        return 6;
    }
    else if(n==90){
        return 6;
    }
}

int countTwos(int n){
    if(n == 0) return 4;

    int cnt = 0;
    if(n <= 10){
        return ones(n);
    }
    else if(n>=11 && n<=20){
        return twos(n);
    }
    else if(n%10 == 0){
        return tens(n);
    }
    return tens((n/10) * 10) + ones(n%10); //45--- 4*10+5
}

int countThrees(int n){
    if(n == 100){
        return 10;
    }
    if(n%10 == 0){
        n/=10; //330
        return 10 + tens((n%10)*10);
    }
    else if(n < 109){
        return 10+ones(n%10);
    }
    else if(n>=111 && n<120){
        return 10 + twos(10+n%10);
    }
    else{
        int z = n%10;
        n/=10;
        int y = n%10;
        n/=10;
        int x = n;
        return ones(x)+countTwos(y*10 + z)+7;
    }
}

int main(){

    int n;
    printf("Enter size of the array: ");
    scanf("%d", &n);

    printf("Enter Array: ");    
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    int newarr[n-1];
    for(int i=1; i<n; i++){
        newarr[i-1] = arr[i] - arr[i-1];
        if(newarr[i-1] < 0){
            newarr[i-1] *= -1;
        }
    }
    // change array
    printf("\n");
    for(int i=0; i<n-1; i++){
        if(newarr[i] < 100){
            newarr[i] = countTwos(newarr[i]);
        }
        else newarr[i] = countThrees(newarr[i]);
        // printf("%d ", newarr[i]);
    }

    printf("\nSorted Array: ");
    sort(newarr, n-1);
    int prev = -1;
    for(int i=0; i<n-1; i++){
        if(newarr[i] != prev){
            printf("%d ", newarr[i]);
            prev = newarr[i];
        }
    }

    return 0;
}

void sort(int arr[], int n){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] < arr[j])swap(&arr[i], &arr[j]);
        }
    }
}
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}