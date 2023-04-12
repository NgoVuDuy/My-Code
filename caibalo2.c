#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
	int pa;
	char dv[20];
	float tl,gt,dg
}dovat;
int swap (dovat *x,dovat *y){
	dovat temp;
	temp=*x;
	*x=*y;
	*y=*x;
}

dovat* docfile(float *W,int *n){
	FILE *f;
	f=fopen("caibalo13.txt","r");
	fscanf(f,"%f",*W);
	int i=0;
	dovat *ds;
	ds=(dovat*)malloc(sizeof(dovat));
	 while (!feof(f)){
	 	printf (f,"%f%f%[^\n]",ds[i].tl,ds[i].gt,ds[i].dv);
	 	ds[i].gt=ds[i].gt/ds[i].tl;
	 	ds[i].pa=0;
	 	i++;
	  ds=(dovat*)realloc(ds, sizeof(dovat)*(i+1)); 
	 }*n=i;
	 fclose(f);
	 return ds;
}
void bubble (dovat *ds,int n){
	int i,j;
	for ( i=0;i<=n-2;i++)
		for ( j=n-1;j>i+1;j--){
			if (ds[j].dg>ds[j-1].dg)
			swap(&ds[j],&ds[j-1]);
	}
} 
void infile (dovat *ds,int n,float W){
	int i;
	float tongtl=0.0;
	float tonggt=0;
	printf(  "|---|----------|-----------|-------|-------|---------|");
	printf("\n|STT|ten do vat|trong luong|gia tri|don gia|phuong an|");
	printf("\n|---|----------|-----------|-------|-------|---------|");
	for (i=0;i<n;i++){
	printf("\n|%3d|%9s|%11.2f|%7.2f|%7.2f|%9d|",i+1,ds[i].dv,ds[i].tl,ds[i].gt,ds[i].dg,ds[i].pa);
	tongtl=tongtl+ds[i].tl*ds[i].pa;
	tonggt=tonggt+ds[i].gt*ds[i].pa;
}
	printf("\n|---|----------|-----------|-------|-------|---------|");
	for (i=0;i<=n-1;i++){
		printf("\nphuong an duoc xep theo don gia X(");
		printf ("%d",ds[i].pa);
	}
	printf(")");
	printf("\ntong trong luong:%f",tongtl);
	printf("\ntong gia tri",tonggt);
}void Greedy(dovat *ds,int n, float W){
  int i;
  for(i=0; i<n; i++) {
     ds[i].pa = (W/ds[i].tl);
     if(ds[i].pa>=1)
     W = W- ds[i].tl;
  }
int main (){
	int n;
	float W;
	dovat *ds;
	ds=docfile(&W, &n);
    bubble(ds,n);
	Greedy(ds,n,W);
	infile(ds,n,W);
	free(ds);
	return 0;
}
















