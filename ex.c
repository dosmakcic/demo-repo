#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*typedef struct Tocka{
    int x;
   struct Tocka *sljedeci;
} tocka;

 
tocka *prvi=NULL; */

void gen_arr( float V[], int n, float dg, float gg );

int sekv_pret( float V[], int n, float x );

void sort( float V[], int n );




int main() {
    int i,br, n=20;
    float x=5;
    float dg=0, gg=10;
    float V[n];
    time_t start, stop;
    
    srand(time(NULL));
    
    start=clock();
    gen_arr(V,n,dg,gg);
    stop=clock();
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ,",V[i]);
    }
    
    printf("Vrijeme potrebno za obavljanje funkcije je %ldms\n",stop-start);
    
    start=clock();
    br=sekv_pret(V,n,x);
    stop=clock();
    
     printf("Vrijeme potrebno za obavljanje funkcije je %ldms\n",stop-start);
     
     start=clock();
     sort(V,n);
     stop=clock();

   printf("\n Vrijeme potrebno za obavljanje funkcije je %ldms\n",stop-start);

return 0;
}

void gen_arr( float V[], int n, float dg, float gg ){
    for (int i=0;i<n;i++){
        V[i]=((float)rand()/(float)(RAND_MAX/gg)+dg);
    }
}

int sekv_pret( float V[], int n, float x ){
    for(int i=0;i<n-1;i++){
        if(V[i]==x){
            return i;
        }
        
    }
    return -1;
}


void sort( float V[], int n ){
    float temp=0;
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            if(V[i]>V[j]){
                temp=V[i];
                V[i]=V[j];
                V[j]=temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
       printf("%.2f ,",V[i]);
    }
    
}