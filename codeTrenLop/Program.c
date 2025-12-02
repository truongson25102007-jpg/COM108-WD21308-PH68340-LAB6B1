#include <stdio.h>

void kiemTraSoNguyen()
{
	printf("Kiem Tra So Nguyen");
}

void uocChungBoiChung()
{
	printf("Uoc Chung Boi Chung");


}

void sapXepPhanTuMang1Chieu()
{
	int integerArray[100];
	int tmp;
	int length;
	printf("Nhap so luong phan tu mang: ");
	scanf("%d", &length);
	printf("Nhap du lieu mang %d phan tu:\n", length);
	for (int i = 0; i < length; i++)
	{
		printf("Phan tu thu %d: ", i + 1);
		scanf("%d", &integerArray[i]);
	}
	printf("Xuat mang du lieu %d phan tu Giam dan\n", length);
	for (int i = length - 1; i > -1; i--)
	{
		printf("mang[%d] = %d\n", i, integerArray[i]);
	}
	printf("Sap xep tang dan du lieu mang %d phan tu\n", length);
	for (int i = 0; i < length - 1; i++)
	{
		if (integerArray[i] > integerArray[i + 1])
		{
			tmp = integerArray[i];
			integerArray[i] = integerArray[i + 1];
			integerArray[i + 1] = tmp;
			i = -1; // reset i to -1 because it will be incremented to 0 at the start of the next loop iteration
		}
	}
	printf("In du lieu mang %d phan tu\n", length);
	for (int i = 0; i < length; i++)
	{
		printf("mang[%d] = %d\n", i, integerArray[i]);
	}
}

void demoMang2Chieu() 
{
	char kyTu = 'A';
	// string - "string.h"
	char mangkyTu[10] = "Anh";
	for (int i = 0; i < 3; i++)
	{
		scanf("%c", &mangkyTu[i]);
	}
	for (int i = 0; i < 3; i++)
	{
		printf("%c", &mangkyTu[i]);
	}
	

	int array[2][3];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			printf("Mang[%d][%d] = ", i, j);
			scanf("%d", &array[i][j]);
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d, ", array[i][j]);
		}
		printf("\n");
	}
}

void lapChucNang(int chonChucNang)
{
	int tiepTuc = 1;
	while (tiepTuc == 1)
	{
		switch (chonChucNang)
		{
		case 1:
			kiemTraSoNguyen();
			break;
		case 2:
			uocChungBoiChung();
			break;
		case 3:
			sapXepPhanTuMang1Chieu();
			break;
		case 4:
			demoMang2Chieu();
			break;
		case 0:
			return;
		default:
			printf("Hay chon lai [0-3]");
			break;
		}

		printf("\n");
		printf("Tiep tuc CN nay? [1=Co | 0=Khong]: ");
		scanf("%d", &tiepTuc);
		system("cls");
	}
}

int main()
{
	int chonChucNang;
	do
	{
		printf("Menu");
		printf("\n");
		printf("1. Kiem Tra So Nguyen");
		printf("\n");
		printf("2. Uoc Chung Boi Chung");
		printf("\n");
		printf("3. Sap xep mang");
		printf("\n");
		printf("4. Demo Mang 2 Chieu");
		printf("\n");
		printf("Hay chon CN [0-3]: ");
		scanf("%d", &chonChucNang);
		lapChucNang(chonChucNang);
	} while (chonChucNang != 0);
}

// GV: AnhTT184