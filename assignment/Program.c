// CConsoleApplication.c : file nay chua 'main' function. 
// Chuong trinh phan mem Bat dau thuc thi & Ket thuc o day.
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>



//ham ho tro
int isPrime(int x) {
	if (x <= 1) return 0;
	if (x == 2) return 1;
	if (x % 2 == 0) return 0;
	int i;
	for (i = 3; i <= sqrt(x); i += 2)
		if (x % i == 0) return 0;
	return 1;
}

int isSquare(int x) {
	if (x < 0) return 0;
	int k = sqrt(x);
	return (k * k == x);
}

int gcd(int a, int b) {
	if (a < 0) a = -a;
	if (b < 0) b = -b;
	while (b != 0) {
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int lcm(int a, int b) {
	return (a / gcd(a, b)) * b;
}

//cac chuc nang
void tEst_chucnang1()
{
	int tt;

	do {
		system("cls");
		printf("=== KIEM TRA SO NGUYEN ===\n");

		int x;
		printf("Nhap so nguyen x: ");
		scanf("%d", &x);

		printf("So %d la so nguyen!\n", x);

		if (isPrime(x)) printf("-> %d la so nguyen to.\n", x);
		else printf("-> %d khong la so nguyen to.\n", x);

		if (isSquare(x)) printf("-> %d la so chinh phuong.\n", x);
		else printf("-> %d khong la so chinh phuong.\n", x);

		printf("\nBan co muon tiep tuc? [1-Co | Khac-Khong]: ");
		scanf("%d", &tt);

	} while (tt == 1);
}
void tEst_chucnang2()
{
	int tt;

	do {
		system("cls");
		printf("=== CHUC NANG 2: UCLN - BCNN ===\n");

		int x, y;
		printf("Nhap 2 so nguyen x y: ");
		scanf("%d %d", &x, &y);

		printf("UCLN: %d\n", gcd(x, y));
		printf("BCNN: %d\n", lcm(x, y));

		printf("\nTiep tuc? [1-Co]: ");
		scanf("%d", &tt);

	} while (tt == 1);
}
void tEst_chucnang3()
{
	int tt;

	do {
		system("cls");
		printf("===  TINH TIEN KARAOKE ===\n");

		int s, e;
		printf("Nhap gio bat dau (12..23): ");
		scanf("%d", &s);
		printf("Nhap gio ket thuc (13..23): ");
		scanf("%d", &e);

		if (s < 12 || e > 23 || e <= s) {
			printf("Thoi gian khong hop le!\n");
		}
		else {
			int gio = e - s;
			double total = 0;

			if (gio <= 3) total = gio * 150000;
			else total = 3 * 150000 + (gio - 3) * (150000 * 0.7);

			if (s >= 14 && s <= 17)
				total *= 0.9;

			printf("Tien phai tra = %.0f VND\n", total);
		}

		printf("\nTiep tuc? [1-Co]: ");
		scanf("%d", &tt);

	} while (tt == 1);
}
void tEst_chucnang4()
{
	int tt;

	do {
		system("cls");
		printf("=== TINH TIEN DIEN ===\n");

		int kwh;
		printf("Nhap so kWh: ");
		scanf("%d", &kwh);

		int remain = kwh;
		double total = 0;

		if (remain > 0) { int d = remain > 50 ? 50 : remain; total += d * 1678; remain -= d; }
		if (remain > 0) { int d = remain > 50 ? 50 : remain; total += d * 1734; remain -= d; }
		if (remain > 0) { int d = remain > 100 ? 100 : remain; total += d * 2014; remain -= d; }
		if (remain > 0) { int d = remain > 100 ? 100 : remain; total += d * 2536; remain -= d; }
		if (remain > 0) { int d = remain > 100 ? 100 : remain; total += d * 2834; remain -= d; }
		if (remain > 0) total += remain * 2927;

		printf("Tien dien = %.0f VND\n", total);

		printf("\nTiep tuc? [1-Co]: ");
		scanf("%d", &tt);

	} while (tt == 1);
}
void tEst_chucnang5()
{
	int tt;

	do {
		system("cls");
		printf("=== DOI TIEN ===\n");

		int money;
		printf("Nhap so tien: ");
		scanf("%d", &money);

		int menhgia[] = { 500,200,100,50,20,10,5,2,1 };
		int i;

		for (i = 0; i < 9; i++) {
			int count = money / menhgia[i];
			if (count > 0) {
				printf("%d to %d VND\n", count, menhgia[i]);
				money -= count * menhgia[i];
			}
		}

		printf("\nTiep tuc? [1-Co]: ");
		scanf("%d", &tt);
	} while (tt == 1);
}
void tEst_chucnang6()
{
	int tt;

	do {
		system("cls");
		printf("===  LAI SUAT TRA GOP 12 THANG ===\n");

		double money;
		printf("Nhap tien vay: ");
		scanf("%lf", &money);

		double total = money * (1 + 0.05 * 12);
		double monthly = total / 12;

		printf("Tong phai tra: %.0lf VND\n", total);
		printf("Tra moi thang: %.0lf VND\n", monthly);

		printf("\nTiep tuc? [1-Co]: ");
		scanf("%d", &tt);

	} while (tt == 1);
}
void tEst_chucnang7()
{
	int tt;

	do {
		system("cls");
		printf("=== VAY MUA XE ===\n");

		double percent;
		printf("Nhap %% vay (VD 80): ");
		scanf("%lf", &percent);

		double car = 500000000;
		double vay = car * percent / 100;
		double trtruoc = car - vay;

		double rate = 0.072 / 12;
		int months = 24;

		double monthPay = (vay * rate) / (1 - pow(1 + rate, -months));

		printf("Tra truoc: %.0lf VND\n", trtruoc);
		printf("Tra moi thang (%d thang): %.0lf VND\n", months, monthPay);

		printf("\nTiep tuc? [1-Co]: ");
		scanf("%d", &tt);

	} while (tt == 1);
}
void tEst_chucnang8()
{
	int tt;

	do {
		system("cls");
		printf("=== NHAP & SAP XEP SINH VIEN ===\n");

		int n;
		printf("Nhap so sinh vien: ");
		scanf("%d", &n);

		char name[50];
		double score[100];
		char ten[100][50];

		int i, j;

		for (i = 0; i < n; i++) {
			printf("Nhap ten sinh vien %d: ", i + 1);
			fflush(stdin);
			gets(ten[i]);

			printf("Nhap diem: ");
			scanf("%lf", &score[i]);
		}

		for (i = 0; i < n - 1; i++) {
			for (j = i + 1; j < n; j++) {
				if (score[i] < score[j]) {
					double tmp = score[i];
					score[i] = score[j];
					score[j] = tmp;

					char tmpname[50];
					strcpy(tmpname, ten[i]);
					strcpy(ten[i], ten[j]);
					strcpy(ten[j], tmpname);
				}
			}
		}

		printf("\n--- Danh sach sau khi sap xep ---\n");
		for (i = 0; i < n; i++) {
			printf("%s - %.1lf\n", ten[i], score[i]);
		}

		printf("\nTiep tuc? [1-Co]: ");
		scanf("%d", &tt);

	} while (tt == 1);
}
void tEst_chucnang9()
{
	int tt;

	do {
		system("cls");
		printf("===  GAME FPOLY-LOTT ===\n");

		int a, b;
		printf("Nhap 2 so (1..15): ");
		scanf("%d %d", &a, &b);

		srand(time(NULL));
		int r1 = rand() % 15 + 1;
		int r2 = rand() % 15 + 1;

		printf("Ket qua: %d - %d\n", r1, r2);

		int hit = 0;
		if (a == r1 || a == r2) hit++;
		if (b == r1 || b == r2) hit++;

		if (hit == 0) printf("Chuc ban may man lan sau!\n");
		else if (hit == 1) printf("Chuc mung! Ban trung giai NHI!\n");
		else printf("Chuc mung! Ban trung giai NHAT!\n");

		printf("\nTiep tuc? [1-Co]: ");
		scanf("%d", &tt);

	} while (tt == 1);
}
void tEst_chucnang10()
{
	int tt;

	do {
		system("cls");
		printf("=== TINH PHAN SO ===\n");

		int a, b, c, d;
		printf("Nhap phan so 1 (a b): ");
		scanf("%d %d", &a, &b);
		printf("Nhap phan so 2 (c d): ");
		scanf("%d %d", &c, &d);

		if (b == 0 || d == 0) {
			printf("Mau so khong hop le!\n");
		}
		else {
			printf("Tong = %d/%d\n", a * d + c * b, b * d);
			printf("Hieu = %d/%d\n", a * d - c * b, b * d);
			printf("Tich = %d/%d\n", a * c, b * d);

			if (c == 0) printf("Khong chia cho 0!\n");
			else printf("Thuong = %d/%d\n", a * d, b * c);
		}

		printf("\nTiep tuc? [1-Co]: ");
		scanf("%d", &tt);

	} while (tt == 1);
}

// menu chinh
int main()
{
	int chon;

	do {
		system("cls");
		printf("========== MENU CHUONG TRINH ==========\n");
		printf("1. Kiem tra so nguyen"); printf("\n");
		printf("2. UCLN - BCNN");printf("\n");
		printf("3. Tinh tien karaoke"); printf("\n");
		printf("4. Tinh tien dien"); printf("\n");
		printf("5. Doi tien"); printf("\n");
		printf("6. Lai suat tra gop 12 thang"); printf("\n");
		printf("7. Vay mua xe"); printf("\n");
		printf("8. Sap xep sinh vien"); printf("\n");
		printf("9. FPOLY-LOTT"); printf("\n");
		printf("10. Tinh phan so"); printf("\n");
		printf("0. Thoat"); printf("\n");
		printf("Chon chuc nang: ");
		scanf("%d", &chon);

		switch (chon)
		{
		case 1:  tEst_chucnang1();
		    break;
		case 2:  tEst_chucnang2(); 
			break;
		case 3:  tEst_chucnang3(); 
			break;
		case 4:  tEst_chucnang4(); 
			break;
		case 5:  tEst_chucnang5(); 
			break;
		case 6:  tEst_chucnang6(); 
			break;
		case 7:  tEst_chucnang7(); 
			break;
		case 8:  tEst_chucnang8(); 
			break;
		case 9:  tEst_chucnang9(); 
			break;
		case 10: tEst_chucnang10(); 
			break;

		case 0:
			printf("Thoat chuong trinh...\n");
			break;

		default:
			printf("Vui long chon dung chuc nang!\n");
		}

	} while (chon != 0);

	return 0;
}


// Debug/Run chuong trinh: bam "F5" hoac "Debug > Start Debugging" tren menu

// Danh cho nguoi moi bat dau:
//   1. Dung "Solution Explorer window" de them/quan ly cac files
//   2. Dung "Output window" de kiem tra "build output" va "cac thong bao khac"
//   3. Dung "Error List window" de xem loi
//   4. Chon "Project > Add New Item" de tao moi file code,
//      hoac "Project > Add Existing Item" de them file da ton tai vao project nay.
//   5. Sau nay, de mo lai project nay,
//      chon "File > Open > Project" va chon file *.sln
//      Co the xem thu muc project, noi luu file *.sln bang cach
//      bam phim chuot phai vao "Solution" > chon "Open Folder in File Explorer"

// GV: AnhTT184