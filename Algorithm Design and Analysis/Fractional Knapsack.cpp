#include <bits/stdc++.h>
using namespace std;

void FractionalKnapsack(int w[], int b[], int weight){
    int profit=0, i=0;
    cout<<"Items Weight: ";
    while(weight>=0){
        if(weight-w[i]>=0){
            profit=profit+b[i];
            cout<<i+1<<"("<<w[i]<<"), ";
            weight-=w[i];
        }
        else{
            profit=profit+((b[i]*weight)/w[i]);
            cout<<i+1<<"("<<weight<<") ";
            weight-=w[i];
        }
        i++;
    }
    cout<<"\nTotal Profit = "<<profit<<endl;
}

void Sort(int w[], int b[], int weight){
    for(int i=0; i<5; i++){
        for(int j=i+1; j<5; j++){
            if(w[i]*b[j]>w[j]*b[i]){
                int temp_w=w[j], temp_b=b[j];
                w[j]=w[i],   b[j]=b[i];
                w[i]=temp_w, b[i]=temp_b;
            }
        }
    }
    FractionalKnapsack(w, b, weight);
}

int main()
{
    int w[]={5, 10, 20, 30, 40}, b[]={40, 20, 100, 90, 200};
    Sort(w,b,50);

    return 0;
}
