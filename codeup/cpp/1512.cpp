#include<iostream>
int main(){int N,X,Y,i,j;std::cin>>N>>X>>Y;for(i=1;i<=N;i++){for(j=1;j<=N;j++)std::cout<<(X-i<0?i-X:X-i)+(Y-j<0?j-Y:Y-j)+1<<' ';std::cout<<'\n';}}