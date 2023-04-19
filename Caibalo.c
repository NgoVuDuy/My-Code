// Bai toan cai ba lo 1
// Moi do vat co so luong khong han che
// Du lieu cho trong file QHD_CaiBalo.INP
// Giai bai toan bang thuat toan QUY HOACH DONG

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
	char TenDV[20];
	int TL, GT, PA;
} DoVat; //Khai bao mot ctdl quan li cac do vat

typedef int bang[50][100];// Ba lo co trong luong toi da 99 va co toi da 50 do vat

DoVat *ReadFromFile(int *W, int *n){ //Khoi tao ham doc file du lieu
     FILE *f; //Khoi tao bien kieu FILE
     f = fopen("QHD_CaiBalo.txt", "r"); //Mo file va trao quyen doc cho stdin
     fscanf(f, "%d",W); // Doc tu file trong luong cua Ba lo
	 DoVat *dsdv; //Khoi tao bien mang con tro dsdv kieu do vat
	 dsdv=(DoVat*)malloc(sizeof(DoVat)); //Cap phat bo nho cho bien dsdv
	 int i=0;//Khoi tao bien vi tri i;
 	 while (!feof(f)){//Duyet qua file f
	   fscanf(f, "%d%d%[^\n]",&dsdv[i].TL,&dsdv[i].GT,&dsdv[i].TenDV);//Doc lan luot cac gia tri TL, GT, ten do vat vao mang dsdv
	   dsdv[i].PA=0;//Khoi tao phuong an bang 0 o tat ca do vat
	   i++;//Tang bien chay i len 1 dv
	   dsdv=(DoVat*)realloc(dsdv,sizeof(DoVat)*(i+1));  
	 }
	 *n=i; //Luu lai so luong do vat vao bien con tro n
     fclose(f);//Dong file du lieu
     return dsdv;//Tra ve danh sach cac do vat
}

void InDSDV(DoVat *dsdv ,int n, int W){
	int i, TongTL=0, TongGT=0;
	printf("\nPhuong an Cai Ba lo 1 dung thuat toan QUY HOACH DONG nhu sau:\n");
		printf("|---|------------------|----------|---------|-----------|\n");
		printf("|STT|     Ten Do Vat   | T Luong  | Gia Tri | Phuong an |\n");
		printf("|---|------------------|----------|---------|-----------|\n");
	for(i=0;i<n;i++){
		printf("|%2d |%-18s|%5d     |%5d    |%6d     |\n",
		i+1,dsdv[i].TenDV,dsdv[i].TL,dsdv[i].GT,dsdv[i].PA);
		TongTL=TongTL+dsdv[i].PA * dsdv[i].TL;
		TongGT=TongGT+dsdv[i].PA * dsdv[i].GT;
	}	
	printf("|---|------------------|----------|---------|-----------|\n");	
	printf("Trong luong cua ba lo = %-9d\n",W);
	printf("Tong trong luong = %-9d\n",TongTL);
	printf("Tong gia tri = %-9d\n",TongGT);
}

void TaoBang(DoVat *dsdv,int n,int W, bang F,bang X){
 	int xk, yk, k;//Do vat k
 	int FMax, XMax, V;//Khoi tao gia tri lon nhat, so luong lon nhat va trong luong con lai
	
	// Dien dong dau tien cua hai bang
	//Bo do vat dau tien vao bang
 	for(V= 0; V<=W; V++) {
 		X[0][V] = V/dsdv[0].TL;//So do vat toi da co the bo
 		F[0][V] = X[0][V] * dsdv[0].GT;//Gia tri tuong ung voi so do vat
 	}
	
	// Dien cac dong con lai
	
	 for(k= 1; k<n; k++)//Duyet qua do vat thu 2 den n
		 for(V=0; V<=W; V++) {
			 FMax = F[k-1][V] ;//GTLN = gia tri do vat phia truoc do
			 XMax = 0;//So luong do vat lon nhat co the bo vao 
			 yk = V/dsdv[k].TL;//So luong do vat k co the bo duoc vao bang
			 for(xk = 1; xk<=yk; xk++)//Tat ca cac truong hop co the bo do vat vao bang
			 	if(F[k-1][V-xk*dsdv[k].TL]+xk*dsdv[k].GT>FMax){//Tim ra truong hop bo do vat k co gia tri lon nhat
			 		FMax=F[k-1][V-xk*dsdv[k].TL]+xk*dsdv[k].GT;//Cap nhat lai gia tri lon nhat
			 		XMax= xk;//Cap nhat lai so luong do vat k
			 		}
			 F[k][V] = FMax;//Dien gia tri vao bang
			 X[k][V] = XMax;//Dien so luong do vat vao bang
	 	}
}

void InBang(int n, int W, bang F, bang X){
	int V, k;//Khoi tao do vat k va trong luong do vat bang 0
	for(k=0; k<n; k++){//Duyet qua tat ca cac do vat
		for(V=0; V<=W; V++)//Duyet qua trong luong do vat
		 	printf("|%4d%2d",F[k][V], X[k][V]);//In gia tri va so luong tuong ung
		printf("\n");
	}
}

void TraBang(DoVat *dsdv, int n, int W, bang X) {
	int k, V;
	V = W;//Trong luong hien tai cua ba lo
	for(k= n-1; k>=0; k--) {//Duyet do vat thu n ve do vat 1
	 	dsdv[k].PA = X[k][V];//Cap nhat lai phuong an
	 	V = V - X[k][V] * dsdv[k].TL;//Cap nhat lai trong luong hien tai
	}
}

int main(){
	int n, W;//Khoi tao so luong do vat va trong luong ba lo
	bang X,F;//So luong va do vat tuong ung tren bang
	DoVat *dsdv;//Bien mang con tro luu danh sach cac do vat
	dsdv=ReadFromFile(&W, &n);//Doc file du lieu va luu vao bien dsdv, n, w
	TaoBang(dsdv,n,W,F,X);//Tao bang
	InBang(n,W,F,X);//In bang
	printf("\n");
	TraBang(dsdv,n,W,X);//Tra bang
	InDSDV(dsdv,n,W);//In bang
	free(dsdv);//Giai phong vung nho cho bien con tro 
	return 0;
}
