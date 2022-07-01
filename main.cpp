#include "Header.h"
int main()
{
#pragma region setup
	SetConsoleTitle(L"Quản Lý Thư Viện");
	// ẩn con trỏ
	ShowCur(0);
	// để in ra được kí tự trong txt
	SetConsoleOutputCP(65001);
	system("mode con: cols=209 lines=75");
	system("cls");
#pragma endregion
	ItemType* bucket = new ItemType[MAXSIZE];
	initBucket(bucket);
	Label(5);
	menu();
	char filename[30], MaHocPhan[20];
	int x_input, y_input;
	y_input = 57;
	x_input = 18;
	int chon;
	do {
		Chon(chon);
		switch (chon)
		{
		case 1:
			clear_input();
			printf("Doc file: ");
			gets_s(filename);
			insert_FILE(bucket,filename);
			getch();
			clear_input();
			break;
		case 2:
			clear_input();
			display_Bucket(bucket);
			break;
		case 3:
			clear_input();
			Nhap_1_HocPhan(bucket);
			break;
		case 4:
			// xóa
			Xoa_1_HocPhan(bucket);
			break;
		case 5:
			// tìm kiếm
			Tim_1_HocPhan(bucket);
			break;
		case 6:
			// Cập nhật
			CapNhat(bucket);
			break;
		case 7:
			resize(bucket);
			clear_input();
			printf("Da tang kich thuoc bang bam!");
			getch();
			clear_input();
			break;
		case 8:
			Xuat_DieuKien(bucket);
			break;
		case 9:
			clear_input();
			TongTinChi_KhoaCNTT(bucket);
			break;
		case 10:
			clrscr();
			ThongKe_LoaiHP(bucket);
			break;
		}
	} while (chon != 0);
	_getch();
	return 0;
}