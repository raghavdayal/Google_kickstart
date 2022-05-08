#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

float calc_area(int pos,int r, int A,int B,int beg){
    float area = 0.0;
    if(r==0){return area;}
    else if (pos==-1){
        float rad = r*A;
        area += (M_PI *rad*rad)+(calc_area(1,rad,A,B,0));
    }
    else{
        if(beg){
           area += (M_PI *r*r)+calc_area(-1,r,A,B,0); 
        }
        else{
        int rad = r/B;
        area += calc_area(-1,rad,A,B,0)+(M_PI *rad*rad);
        }
    }
    return area;
}
int main(){
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int R,A,B;
        float area = 0.0;
        cin>>R>>A>>B;
        area = calc_area(1,(float)R,A,B,1);
        cout<<"Case #"<<i+1<<": "<<fixed<<setprecision(6)<<area<<"\n";
    }
    return 0;
}