#include<stdio.h>
typedef int keytype;
typedef float othertype;
typedef struct {
	keytype key;
	othertype otherfields;
}recordtype;
void Swap(recordtype *x, recordtype *y) {
	recordtype temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
void readData(recordtype arr[], int *n) {
	FILE *f;
	f = fopen("Data.txt","r");
	int i = 0;
	if(f != NULL) {
		while(!feof(f)) {
			fscanf(f, "%d%f", &arr[i].key, &arr[i].otherfields);
			i++;
		}
	}else printf("Loi mo file!");
	fclose(f);
	*n = i; 
}
void printData(recordtype arr[], int n) {
	int i;
	for(i = 0;  i < n; i++) {
		printf("%3d %5d %8.2f\n", i + 1, arr[i].key, arr[i].otherfields);
	}
}
void SelectionSort(recordtype arr[], int n) {
	keytype min;
	int i, j;
	for(i = 0; i < n - 1; i ++) {
		min = i;
		for(j = i + 1; j < n; j ++) {
			if(arr[j].key < arr[min].key) {
				min = j;
			}
		}
		Swap(&arr[i], &arr[min]);
	}
}
void InsertSort(recordtype arr[], int n) {
	int i, j;
	for(i = 1; i <= n - 1; i ++) {
		j = i;
		while((j > 0) &&(arr[j].key < arr[j - 1].key)) {
			Swap(&arr[j], &arr[j - 1]);
			j--;
		}
	}
}
void BubbleSort(recordtype a[], int n) {
	int i,j;
 	for(i= 0; i<= n-2; i++)
 		for(j=n-1;j>=i+1; j--)
 			if (a[j].key < a[j-1].key)
 				Swap(&a[j], &a[j-1]);
}
int FindPivot(recordtype a[], int i,int j) {
	keytype firstkey;
	int k ;
 	k = i+1;
	firstkey = a[i].key;
 	while ( (k <= j) && (a[k].key == firstkey) ) k++;
		if (k > j) 
			return -1;
		else
		if (a[k].key>firstkey) 
			return k; 
		else 
			return i;
}
int Partition(recordtype a[], int i, int j, keytype pivot) { 
	int L,R;
	L = i;
	R = j;
	while (L <= R){ 
		while (a[L].key < pivot) 
			L++;
 		while (a[R].key >= pivot) 
		 	R--;
 		if (L<R) 
			Swap(&a[L], &a[R]);
	}
	return L;
}
void QuickSort(recordtype a[], int i,int j) { 
	keytype pivot;
	int pivotindex, k;
	pivotindex = FindPivot(a,i,j);
	if (pivotindex != -1) {
		pivot = a[pivotindex].key;
		k = Partition(a,i,j,pivot);
		QuickSort(a,i,k-1);
		QuickSort(a,k,j);
	}
}
void PushDown(recordtype a[], int first,int last){ 
	int r= first;
	while (r <= (last-1)/2)
		if (last == 2*r+1) {
			if (a[r].key > a[last].key) Swap(&a[r], &a[last]);
			r = last;
		} 
		else
		if ((a[r].key>a[2*r+1].key) && (a[2*r+1].key<=a[2*r+2].key)){
			Swap(&a[r],&a[2*r+1]);
			r = 2*r+1 ;
		} 
		else
		if ((a[r].key>a[2*r+2].key) && (a[2*r+2].key<a[2*r+1].key)){
			Swap(&a[r],&a[2*r+2]);
			r = 2*r+2 ;
		}
		else
			r = last;
}
void HeapSort(recordtype a[], int n){ 
	int i;
	for (i = (n-2)/2; i>=0; i--)
		PushDown(a, i, n-1);
	for (i = n-1; i>=2; i--) {
		Swap(&a[0], &a[i]);
		PushDown(a, 0, i-1);
	}
 	Swap(&a[0], &a[1]);
}
int main() {
	recordtype arr[100];
	int n;
	readData(arr, &n);
	printf("\nDu lieu mang truoc khi sap xep: \n");
	printData(arr, n);
	int choice;
	printf("Nhap thuat toan sap xep:\n1.Selection Sort\n2.Insert Sort\n3.Bubble Sort\n4.Quick Sort\n5.Heap Sort\nLua chon cua ban la: ");
	scanf("%d", &choice);
	printf("----------------------------------------------------------\n");
	switch(choice) {
		case 1: printf("SelectionSort: \n");
				SelectionSort(arr, n);
				printf("\nDu lieu mang sau khi sap xep: \n");
				printData(arr, n);
				break;
		case 2: printf("InsertSort: \n");
				InsertSort(arr, n);
				printf("\nDu lieu mang sau khi sap xep: \n");
				printData(arr, n);
				break;
		case 3: printf("BubbleSort: \n");
				BubbleSort(arr, n);
				printf("\nDu lieu mang sau khi sap xep: \n");
				printData(arr, n);
				break;
		case 4: printf("QuickSort: \n");
				QuickSort(arr, 0, n - 1);
				printf("\nDu lieu mang sau khi sap xep: \n");
				printData(arr, n);
				break;
		case 5: printf("HeapSort: \n");
				HeapSort(arr, n);
				printf("\nDu lieu mang sau khi sap xep: \n");
				printData(arr, n);
				break;
	}
	return 0;
	
}
