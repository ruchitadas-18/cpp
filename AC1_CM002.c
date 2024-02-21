#include <stdio.h>
#include <math.h>

int seriesTwe(int o){
    int d =0;
    if(o==11)
        d+=6;
    else if(o==12)
        d+=8;
    else if(o==30)
        d+=8;
    else if(o==40)
        d+=8;
    else if(o==50)
        d+=8;
    else if(o==60)
        d+=7;
    else if(o==70)
        d+=9;
    else if(o==80)
        d+=8;
    else 
        d+=9;
    return d;
}
int seriesUnit(int o){
    int d =0;
    if(o==1)
        d+=3;
    else if(o==2)
        d+=3;
    else if(o==3)
        d=4;
    else if(o==4)
        d+=4;
    else if(o==5)
        d+=5;
    else if(o==6)
        d+=3;
    else if(o==7)
        d+=5;
    else if(o==8)
        d+=5;
    else 
        d+=4;
    return d;
}
int seriesTens(int o){
    int d =0;
    if(o==10)
        d+=3;
    else if(o==20)
        d+=6;
    else if(o==30)
        d+=6;
    else if(o==40)
        d+=6;
    else if(o==50)
        d+=5;
    else if(o==60)
        d+=5;
    else if(o==70)
        d+=7;
    else if(o==80)
        d+=6;
    else 
        d+=5;
    return d;
}
void convertWord(int D[],int a){
    int count =0;
    int C[a];
    int i=0;
    while(D[i]%10>0 || i<a){
        int f=D[i]%100;
        if(f>10 && f<20){
            int g = D[i];
            C[i]+=seriesTwe(g);
        }
        else{
            int o = D[i]%10;
            C[i]+=seriesUnit(o);
            C[i]+=seriesTens(f);
            int y = D[i]/100;
            if(y>0){
                C[i]+=seriesUnit(o);
            }
        }
    }
}

void swap(int a, int b) 
{ 
	int t = a; 
	a = b; 
	b = t; 
} 
int* sort(int D[], int N) 
{ 
	for (int j = 0; j < N - 1; j++) { 
		for (int i = 0; i < N - j - 1; i++) { 
			if (D[i] > D[i + 1]) { 
				swap(D[i],D[i+1]); 
			} 
		} 
	} 
    return D;
} 

int* dupilicate(int D[], int R[], int h){
    int prev = D[0];
    for(int i=0; i<h;i++){
        if(D[i]!=prev){
            R[i] = D[i];
        }
        prev = D[i];
    }
    return R;
}

int main(){
    int N;
    scanf("%d",&N);

    int B[N];
    for(int i=0; i<N; i++){
        scanf("%d",&B[i]);
    }

    int D[N-1];
    int j=0;
    for(int i=1; i<N; i++){
        D[j]=B[i]-B[i-1];
        printf("%d",B[i]);
        j++;
    }
    int count =0;
    int R[N];
    convertWord(D,N);
    int r = N-1;
    sort(D,N);
    dupilicate(D,R,N);
    for(int i=0; i<N; i++){
        printf("%d /n",R[i]);
    }
}