#include"conio.h"
#include"stdio.h"

int make_offer(int);

const int n = 5 + 1; // dlya matritsy 5x5

int mass_index[n];  //massiv tekuschego indeksa muzhchin
int mass_offer[n];  // massiv tekuschih predlozheniy zhenschin
int massA[n][n],massB[n][n];
int global_i;

void main(){
	int i,j,offer,count,count_0=0;

	for (i=1;i<n;i++){mass_index[i] = 1; mass_offer[i] = -1;};

	FILE *f;

	f = fopen("input.txt","r");
	for (i=1; i<n; i++)
		for (j=1; j<n; j++)
			fscanf(f,"%d", &massA[i][j]);
	
	for (i=1; i<n; i++)
		for (j=1; j<n; j++)
			fscanf(f,"%d", &massB[i][j]);
	fclose(f);

	global_i = 1;
	
	int x;
	while (count_0 != n-1){
		x = make_offer(global_i);
		if (x == 0){
			count_0++;
			global_i = count_0 + 1;
		}
		else global_i = x;  
	}

	for (i=1; i<n; i++)
		printf("%d - %d \n", i, mass_offer[i] );

	getch();
}

int make_offer(int count){
		int offer, i;
		
		offer = massA[count][mass_index[count]];
		if (mass_offer[offer] == -1){
			mass_offer[offer] = count;
			return 0;
		}
		else{
			for (i=1; i<n; i++){
				if ((massB[offer][i] == mass_offer[offer]) | (massB[offer][i] == count))
					if (massB[offer][i] == mass_offer[offer]){ 
						mass_index[count]++;
						return count; 
					}
					else{ 
						int x = mass_offer[offer];
						mass_index[mass_offer[offer]]++;
						mass_offer[offer] = count;
						return x; 

					}
			}
		}
}
