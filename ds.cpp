#include <iostream>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <time.h>
#define n 69999999
#define inc 2279
#define po 0.714
using namespace std;
long long int comp_m=0,comp_wm=0,comp=0,countt=0,sq=0;
long long int in[n+1];
long long int ne[n+1];
long long int a[n+1],ra[n+1];
void printArray(long long int A[], long long int size)
{
	long long int i;
	for (i=0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}
void merge(long long int arr[], long long int l, long long int m,long long  int r)
{
	long long int i, j, k;
	long long int n1 = m - l + 1;
	long long int n2 =  r - m;

	/* create temp arrays */
	long long int L[n1], R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1+ j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
			comp++;
		}
		else
		{
			arr[k] = R[j];
			j++;
			comp++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	   are any */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	   are any */
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(long long int arr[], long long int l, long long int r)
{
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		long long int m = l+(r-l)/2;

		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);

		merge(arr, l, m, r);
	}
}

int main()
{
	//long long int n;

	long long int diff;long long int counter =0;
	long long int rank_higher,rank_lower,j,higher,countp=0,diffp=0,compp=0,comp_wmp=0;

	for(long long int g=0;g<10;g++){
		comp_m=0;comp_wm=0;comp=0;countt=0;sq=0;
		for( long long int i = 0 ; i < n ; ++i ){
			in[i]=i;
		}
		srand(time(0));

		std::random_shuffle( in, in+n ) ;
		/*for(int i=0;i<9999;++i){
		  myfile << in[i] <<"\n";
		  }*/
		srand(time(0));

		//cin >> n;

		for(long long int i=0;i<n;i++){
			a[i]=i;
			//   cin >> in[i];
		}

		while(2){

			std :: random_shuffle(a,a+n);
			for(long long int i=0;i<(long long int)pow((double)n,po);++i){
				ra[i]=a[i];
				counter++;
			}
			for(long long int i=0;i<counter;i++){
				ne[i]=in[ra[i]];
			}
			//for(int i=0;i*i<n;i++){
			//  sq++;
			//}
			mergeSort(ne, 0,counter -1);
			//printf("\nSorted array is \n");
			//printArray(ne,counter);
			long long int lower=ne[(counter/2)-inc];higher=ne[(counter/2)+inc];
			rank_lower=1;rank_higher=1;
			counter=0;
			j=0;
			ne[j]=lower;
			j++;
			diff=higher-lower;
			for(long long int i=0;i<n;i++){
				if(in[i]>lower){
					comp++;
					comp_wm++;
					if(in[i]<higher){
						comp++;
						comp_wm++;
						ne[j]=in[i];
						j++;
						//   counter++;
					}
					else{
						comp++;
						comp_wm++;
						rank_higher++;
					}
				}
				else{
					rank_lower++;
					comp++;
					comp_wm++;
				}
			}
			if(rank_lower<n/2&&rank_higher<n/2){
				break;
			}
			countt++;
		}
		ne[j]=higher;
		mergeSort(ne,0,j);
		//  printf("\nSorted array is \n");
		// printArray(ne,j+1);
		//cout << rank_lower<<endl;
		long long int median=ne[(n/2)-rank_lower+2];
		if(countt>0)
			countp++;
		diffp+=diff;
		compp+=comp;
		comp_wmp+=comp_wm;

	}

	cout<<endl;
	//comp_m=comp-comp_wm;
	//cout << median << endl;
	cout <<"difference in guards: "<< diffp/10<<endl;
	cout << "comparison total: "<<compp/10 <<endl;
	//cout << "comparison for merging: "<<(compp-comp_wmp<<endl;
	cout << "comparision not for merging: "<<comp_wmp/10<<endl;
	cout << "no of time guards were calculated : "<<countp<<endl;

	return 0;
}
