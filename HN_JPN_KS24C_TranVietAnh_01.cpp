#include<stdio.h>
int main(){
	int arr[100];
	int size=0;
	int choice,position;
	do{
		printf("\n MENU\n");
		printf("1. Nhap so phan tu va gia tri cho mang\n");
		printf("2. in ra gia tri cac phan tu trong mang\n");
		printf("3. dem so luong cac so nguyen to trong mang\n");
		printf("4. tim gia tri nho thu 2 trong mang\n");
		printf("5. them phan tu vao mang\n");
		printf("6. xoa phan tu\n");
		printf("7. sap xep mang theo thu tu giam dan\n");
		printf("8. tim kiem phan tu\n");
		printf("9. xoa toan bo phan tu trung lap va hien thi toan bo phan tu doc nhat\n");
		printf("10. dao nguoc thu tu cua cac phan tu co trong mang\n");
		printf("11. thoat chuong trinh\n");
		printf("\nnhap lua chon cua ban: ");
		scanf("%d",&choice);
		switch (choice){
			case 1:{
				printf("\n nhap so phan tu:");
				scanf("%d",&size);
				for(int i=0;i<size;i++){
					printf("\nnhap gia tri cua arr[%d]:",i);
					scanf("%d",&arr[i]);
				}
				
				break;
			}
			case 2:{
				if(size==0){
					printf("\nnhap cac gia tri o lua chon 1");
				}
				else{
					for(int i=0;i<size;i++){
					    printf("arr[%d]=%d , ",i,arr[i]);
				    }
			    }   
				break;
			}
			case 3:{
				if(size==0){
					printf("\nnhap cac gia tri o lua chon 1");
				}
				else{
					int co=0;
					int all=0;
					for(int i=0;i<size;i++){
						int snt=1;
						if(arr[i]<2){
							snt=0;
						}
						for(int j=2;j*j <=arr[i];j++){
							if(arr[i]%j==0){
								snt=0;
							}
						}
						if(snt==1){
							co=1;
							all++;
						}
					}
					if(co==0){
						printf("\ntrong mang khong co so nguyen to");
					}
					else{
						printf("\nco %d so nguyen to trong mang",all);
					}
			    }
				break;
			}
			case 5:{
				if(size ==0 ){
					printf("\nnhap cac gia tri o chon 1");
				}
				else if(size>=100){
					printf("\nkhong the them");
				}
				else{
				    do{
				    	printf("\nnhap vitri can them phan tu:");
					    scanf("%d",&position);
					    if(position<=0||position>size+1){
					    	printf("\nkhong hop le vui long nhap lai");
						}
					}while(position<=0||position>size+1);
					for(int i=size;i>position-1;i--){
						arr[i]=arr[i-1];
					}
					printf("\nnhap gia tri phan tu can them:");
					scanf("%d",&arr[position-1]);
					size++;
				}
				break;
			}
			case 6:{
				if(size ==0 ){
					printf("\nnhap gia tri o tuy chon 1");
				}
				else{
					do{
						printf("\nnhap vi tri phan tu can xoa");
						scanf("%d",&position);
						if(position<=0||position>size){
						    printf("\nkhong hop le vui long nhap lai");
						}
					}while(position<=0 || position>size);
					for(int i=position-1;i<size;i++){
					    arr[i]=arr[i+1];
					}
					size--;
				}
				break;
			}
			case 7:{
				for (int i = 1; i < size; i++) {
			        int key = arr[i]; 
			        int j = i - 1;
			        while (j >= 0 && arr[j] < key) {
			            arr[j + 1] = arr[j];
			            j--;
			        }
			        arr[j + 1] = key;
                } 
				break;
			}
			case 8:{
				int found = 0; 
				    int target;
				    printf("\nnhap phan tu can tim kiem");
				    scanf("%d",&target);
				    printf("Cac vi tri cua phan tu %d trong mang: ", target);
				    for (int i = 0; i < size; i++) {
				        if (arr[i] == target) {
				            printf("%d ", i);
				        }
				    }
				
				    if (!found) {
				        printf("Khong tim thay phan tu trong mang\n", target);
				    } else {
				        printf("\n");
				    }
				break;
			}
			case 9:{
				if(size ==0 ){
					printf("\nnhap gia tri o tuy chon 1");
				}
				else{
					for(int i=0;i<size-1;i++){
						for(int j=i+1;j<size;j++){
							if(arr[i]==arr[j]){
								for(int k=j;k<size;k++){
					                arr[k]=arr[k+1];
					            }
							    size--;
						    }
					    }
				    }
				}
				break;
			}
			case 11:{
				printf("thoat chuong trinh");
				break;
			}
			default:
				printf("vui long chon hop le");
		}
	}while(choice!=11);
return 0;
}
