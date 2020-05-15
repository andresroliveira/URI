#include<bits/stdc++.h>
#define N 2000010
  
using namespace std;
  
bool v[N];
bool k[N];
int V[N];
  
void crivo(){
    int aux;
  
    for (int i=0;i<N;i++)
       v[i] = true;
  
    for(int i=2;i<N;i++){ 
        if(v[i]){
            aux = (int) N/(double)i;
             
            if(aux == 0) break;
  
            for(int j=2;j<=aux;j++){
                if(i*j > N) break;
                 
                v[i*j] = false;
            }
        }
    }
}
  
int div(int x){
 
    int aux = (int)pow(x,1/2.0), out = 0;
  
        for(int j=2;j<aux;j++){
            if(x % j == 0) out++;
        }
         
        out++;out *= 2;out++;
         
        return out;
     
}

void vet(){
	k[0] = k[1] = false;
	
	for(int i=2;i<N;i++){
		if(v[i]) k[i] = true;
		else{
			int a = (int)sqrt(i);
			
			if(a == sqrt(i)){
				if(v[div(i)]) k[i] = true;
				else k[i] = false;
			}
			else k[i] = false;
		}
	}
}

void vet2(){
	int n;int r = 1;
    
    V[2] = r;
     
    for(n=3;n<N;n++){    	
    	if(k[n]) r++;
		V[n] = r;
  	}
}
  
int main (){
    crivo(); vet(); vet2();
  	int n;
	while(~scanf("%d",&n)) printf("%d\n",V[n]);
    
    return 0;
}