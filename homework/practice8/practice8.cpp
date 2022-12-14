#include <stdlib.h>
#include <math.h>
#define endmark -1
float stream xy;
float stream xz;
float stream yx;
float stream yz;
float stream zx;
float stream zy;

boolean isConverage(float a,float b){
    return  fabs(a-b)<0.00001;
}

void  sloveX(){
    float newx,x,y,z;
    recv(yx,y);
    recv(zx,z);
    while(true){
        newx =(8+z-y)/2;
        if(isConverage(newx,x)){
            x=newx;
            send(xy,x);
            send(xz,x);
            recv(yx,y);
            recv(zx,z);
        }
        else{
            break;
        }
    }
    cout << "x:="<< x << endl;
}

void  sloveY(){
    float x,newy,y,z;
    recv(zy,z);
    recv(xy,x);
     while(true){
        newy =(17-3*x+2*z)/3;
        if(isConverage(newy,y)){
            y=newy;
            send(yz,y);
            send(yx,y);
            recv(zy,z);
            recv(xy,x);
        }
        else{
            break;
        }
    }
    cout << "y:="<< y << endl;
}

void  sloveZ(){
    float x,y,newz,z;
    recv(yz,y);
    recv(xz,x);
    while(true){
        newz = (-3+2*x-y)/2;
        if(isConverage(newz,z)){
            z=newz;
            send(xz,z);
            send(xy,z);
            recv(yz,y);
            recv(xz,x);
        }
        else{
            break;
        }
    }
   
    cout << "z:="<< z << endl;
}

int main() {
    int i, xvalue;
    
    send(xy,0);
    send(xz,0);
    send(yz,0);
    send(yx,0);
    send(zy,0);
    send(zx,0);

    fork sloveX();
    fork sloveY();
    fork sloveZ();

    return 0;
}