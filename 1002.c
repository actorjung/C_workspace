#include<stdio.h>
#include<math.h>
int terlet(int x1,int y1,int r1, int x2,int y2,int r2);

int main(){
    int a,b,c,d,e,f;
    int t; //테스트케이스
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
        terlet(a,b,c,d,e,f);
    }

    return 0;
}

int terlet(int x1,int y1,int r1, int x2,int y2,int r2){
    int result,distance,subtract;
    distance = sqrt(pow(x2-x1,2) + pow(y2-y1,2)); //거리구하는공식
    subtract = r1 > r2 ? r1-r2 : r2-r1; //거리의차
    if(x1==x2 && y1==y2 && r1==r2) //교점이 무한대일때 
        result = -1;
    else if(distance == subtract || distance == (r1 + r2)) //교점이 1개일때
        result = 1;
    else if(subtract < distance && distance < (r1 + r2)) //교점이 2개일때 
        result = 2;
    else 
        result = 0;
    printf("%d",result);
    return 0;
}

