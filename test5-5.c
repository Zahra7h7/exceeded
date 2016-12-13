#include <stdio.h>
#include<math.h>

void Swap(int Arr[], int a, int b)
{
    int aux = Arr[a];
    Arr[a] = Arr[b];
    Arr[b] = aux;
}


int Max(int arr[], int a)
{
    int max = 0, i = 0;
    for(i = 0; i <= a; i++)
        if(arr[i] > arr[max])
            max = i;
    return max;
}



int bmm(int a, int b){
	int i, m = b;
	if(a < b)
		m = a;
	for(i = m; i > 1; i --){
		if(a % i == 0 && b % i == 0)
			return i;
	}
	return 1;
}

int squer(a){
	int i;
	for(i  = sqrt(a) ; i > 0 ; i--){
		if(a % (i * i) == 0)
		return i;
	}  	
}

int main(int argc, char *argv[]) {
	int a[100] , c[100] ;
	int b[100]  ,d[100] ;
	int n, i, j, m, c1, b1;
	scanf("%d",&n);
	for(i = 0; i < n; i ++){
		scanf("%d %d",&b[i] ,&c[i]);
		m = bmm(c[i], b[i]);
		c[i] /= m;
		b[i] /= m;
		c1 = squer(c[i]);
		b1 = squer(b[i]);
		d[i] = c[i] / (c1 * c1) * b[i] / (b1 * b1);
		b[i] = b1;
		c[i] /= c1;
	}
	
	int counter = 0, k ,shart,kmm = 1;
	for(i = 0; i < n; i++){
		shart = 0;
		for(k  = 0 ; k < counter; k++){
			if(d[k] == d[i])
				shart = -1;
		}
		if(shart == -1)
			continue;
		d[counter] = d[i];
		c[counter] = c[i];
		b[counter] = b[i];
		for(j = n - 1; j > i; j--){
			if(d[j] == d[i]){
				m = bmm(c[counter],c[j]);	
				kmm = c[counter] * c[j] / m;
				b[counter] = kmm / c[counter] * b[counter] + kmm / c[j] * b[j] ;
				c[counter] = kmm;
			}
		}
		counter ++;
	}
	
	int argMax;
	for(i = counter - 1; i > 0; i--)
    {
        argMax = Max(d, i);
        Swap(d,argMax, i);
        Swap(b,argMax,i);
        Swap(c,argMax, i);
   }
   
   for(i = 0;i < counter;i++){
		m = bmm(c[i], b[i]);
		c[i] /= m;
		b[i] /= m;   		
		a[i] = b[i] / c[i];
		b[i] %= c[i];
		printf("%d %d %d %d\n",a[i] , b[i] ,c[i], d[i]);
   }
    
	return 0;
}
