#include <stdio.h>
 
int main(int argc, char *argv[]) {
    int n, x[100], y[100], i, j, k, max = 2 , shart1 = 0,shart2 = 0;
    float shib1 = 0, shib2 = 0;
    int tedad = 2;
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d %d",&x[i],&y[i]);
    }
    if(n == 1)
        max = 1;
    else if(n == 2)
    	max = 2;
    else{
    	
    for(i = 0; i < n - 2; i++){
        for(j = i + 1; j < n - 1; j++){
 			tedad = 2;
            if(x[j] != x[i]){
                shib1 = (float)(y[j] - y[i]) / (x[j] - x[i]);
                shart1 = 0;
			}
            if(x[j] - x[i] == 0){
                shib1 =(float) x[i];
                shart1 = 1;
            }   
			for(k = j + 1;k < n; k ++){
				if(x[j] != x[k]){
               		shib2 = (float)(y[j] - y[k]) / (x[j] - x[k]);
               		shart2 = 0;
				}
            	if(x[j] - x[k] == 0){
                	shib2 =(float) x[k];
                	shart2 = 1;
            	}
            	
            	if((shart1 == shart2) && (shib1 == shib2)){
            		tedad ++;
				}
			}
			if(tedad > max)
				max = tedad;
        }
	}
    }        
    printf("%d",max);
    return 0;
}
