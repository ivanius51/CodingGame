#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


void compute_pos(int* P, int* p_old, int* p_min, int* p_max, int length, string bombDir) {
    if (bombDir.compare("COLDER")==0 && *P-*p_old>0 || bombDir.compare("WARMER")==0 && *P-*p_old<0) 
        *p_max = (*P + *p_old)%2 ? (*P + *p_old)/2 : (*P + *p_old)/2 - 1;

    else if (bombDir.compare("COLDER")==0 && *P-*p_old<0 || bombDir.compare("WARMER")==0 && *P-*p_old>0) 
        *p_min = (*P + *p_old)/2 + 1;
        
    else if (bombDir.compare("SAME")==0) {
        *p_min = *p_max = (*P + *p_old)/2;
        *p_old = *P;
        *P     = *p_min;
    }
    
    *p_old = *P;
    *P     = *p_min + *p_max - *P;
    
    if (*P < 0) 
        *P = *p_old/2;
        
    else if (*P > length - 1)
        *P = (length-1 + *p_old)/2;
            
    if (*P == *p_old && *p_min != *p_max) 
        *P = *P != *p_max ? *P+1 : *P-1;
            
    if (*p_min == *p_max)
        *P = *p_min;
}

int main() {
    string bombDir;
    int W,H,N,X,Y;
    int xmin,ymin,xmax,ymax,xold,yold,f=1;
    cin >> W >> H >> N >> X >> Y;

    xold=X;yold=Y;
    xmin=ymin=0;
    xmax=W-1;ymax=H-1;

    // game loop
    while (1) {
        cin >> bombDir;

        if (xmax != xmin) 
            compute_pos(&X, &xold, &xmin, &xmax, W, bombDir);
        
        else if (f) {
            f    = 0;
            yold = Y;
            Y    = ymin;
        }
        
        else 
            compute_pos(&Y, &yold, &ymin, &ymax, H, bombDir);
        
        cout << X << " " << Y << endl;
    }
    return 0;
}