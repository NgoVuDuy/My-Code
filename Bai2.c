#include<stdio.h>
typedef struct {
	float do_dai;
	int dau, cuoi;
} canh;
void read_file(char file_name[], int canh a[], int n) {
	int i, j , t;
	float temp;
	FILE *f;
	f = fopen(file_name, "r");
	if(f == NULL) {
		printf("Loi mo file!!\n");
		return;
	}
	fscanf(f, "%d", n);
	int k;
	for(i=0; i < *n; i++) {
		for(j = i; j < *n; j ++) {
			if(i == j) {
				for(t = 0; t <= j; t ++) {
					fscanf(f, "%f", &temp);
				}
			}
			else
			{
				fscanf(f, "%f", &a[k].do_dai);
				a[k].dau = i;
				a[k].cuoi = j;
				k ++;
			}
		}
	}
	fclose(f);
}
void in_ds_canh(canh a[], int m, int la_PA) {
	int i;
	float tong = 0.0;
	for(i=0; i < m; i ++) {
		printf("%3d %c %c=%8.2f\n", i + 1, a[i].dau + 97, a[i].cuoi + 97, a[i].do_dai);
		if(la_PA)
			tong += a[i].do_dai;
	}
	if(la_PA)
		printf("Tong do dai cac canh = %5.2f\n", tong);
}
void Swap(canh *x, canh *y) {
	canh temp = *x;
	*x = *y;
	*y = temp;
}
void bubble_sort(canh a[], int n) {
	int i, j;
	for(i = 0; i < n - 1; i ++){
		for(j = n - 1; j > i; j --) {
			if(a[j].do_dai < a[j - 1].do_dai) {
				Swap(&a[j], &a[j - 1]);
			}
		}
	}
}
int dinh_cap_3(canh PA[], int k, canh moi) {
	int i, dem;
	i = 0;
	dem = 1;
	while(i < k && dem <3) {
		if(moi.dau == PA[i].dau || moi.dau == PA[i].cuoi)
			dem ++;
	i ++
	}
	while(i<k && dem < 3) {
		if(moi.cuoi = PA[i].dau || moi.cuoi == PA[i].cuoi)
			dem ++;
	i ++;
	}
	return dem==3;
}
int main() {
	canh ds_canh[size];
	int n;
	printf("Phuong an TPS dung thu thuat tham an: \n");
	read_file("TSP.txt", ds_canh, &n);
	printf("Danh sach cac canh cua do thi: \n");
	in_ds_canh(ds)
}




























