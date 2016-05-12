#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;

int max(int x, int y){
    return x > y ? x : y;
}
int max(int x, int y, int z){
    return max( max(x,y), z);
}
int min(int x, int y){
    return x > y ? y : x;
}
int min(int x, int y, int z){
    return min( min(x,y), min(y,z));
}
int meio(int x, int y, int z){
    int a[] = {x, y, z};
    sort(a, a + 3);
    return a[1];
}

int main() {
    int ta,tb,tc,a,b,c,tx,ty,x,y,z;
    do{
        cin >> ta >> tb >> tc >> tx >> ty;
        if( ta == 0 && tb == 0)
            break;
        a = max(ta,tb,tc);
        b = meio(ta,tb,tc);
        c = min(ta,tb,tc);
        x = max(tx,ty);
        y = min(tx,ty);
        
        //cout << a << " " << b << " " << c << endl;

        if( x > a && y > a){
            z = 1;
            while(z > 0 &&( z == a || z == b || z == c || z == x || z == y)){
                z++;
                if(z > 52){
                    z = -1;
                }
            }
            printf("%d\n",z);
        }
        else if( x > a && a > y && y > b){
            z = b+1;
            while(z > 0 &&(z == a || z == b || z == c || z == x || z == y)){
                z++;
                if(z > 52){
                    z = -1;
                }
            }
            printf("%d\n",z);   
        }
        else if( a > x && y > b){
            z = b+1;
            while(z > 0 &&(z == a || z == b || z == c || z == x || z == y)){
                z++;
                if(z > 52){
                    z = -1;
                }
            }
            printf("%d\n",z);
        }
        else if( x > a && y < b){
            z = a+1;
            while(z > 0 &&(z == a || z == b || z == c || z == x || z == y)){
                z++;
                if(z > 52){
                    z = -1;
                }
            }
            printf("%d\n",z);
        }
        else
            printf("-1\n");
    }while(true);
    return 0;
}
