#include "Header.h"
int MAXSIZE = 20;
int MAXCOUNT = MAXSIZE * THESHOLD;
int nCount = 0;

void TenThanhVien(int time)
{
	int x = 18;
	int y = 5;
	gotoXY(27, 2);
	TextColor(13);
	cout << "ThÃ nh viÃªn nhÃ³m 4";
	Sleep(time);
	TextColor(14);
	gotoXY(x, y);
	cout << "2001207059 - Nguyen Van Ky (Nhom truong)";
	Sleep(time);
	y = y + 2;
	gotoXY(x, y);
	y = y + 2;
	cout << "2001190955 - Nguyen Chi Xiu  ";
	Sleep(time);
	gotoXY(x, y);
	y = y + 2;
	cout << "2001202008 - Hoang The Anh      ";
	Sleep(time);
	gotoXY(x, y);
	y = y + 2;
	cout << "2001202264 - Vuong Cuong Thuan ";
	Sleep(time);
	gotoXY(x, y);
	cout << "2001207234 - Dao Duc Huy     ";
	Sleep(time);

	TextColor(7);
}
void Chon(int& chon)
{
	char key;
	int y = 20;
	int x = 16;
	while (true)
	{
		TextColor(13);
		gotoXY(x, y);
		printf(">>");
		TextColor(7);
		key = getch();
		if (key == key_Down)
		{
			gotoXY(x, y);
			printf("  ");
			y += 2;
			if (y > 40)
				y = 20;
		}
		else if (key == key_Up)
		{
			gotoXY(x, y);
			printf("  ");
			y -= 2;
			if (y < 20)
				y = 40;
		}
		else if (key == key_ESC)
		{
			gotoXY(0,0);
			Label(0);
			menu();
		}
		else if (key == key_Enter)
		{
			if (y == 20)
				chon = 1;
			else if (y == 22)
				chon = 2;
			else if (y == 24)
				chon = 3;
			else if (y == 26)
				chon = 4;
			else if (y == 28)
				chon = 5;
			else if (y == 30)
				chon = 6;
			else if (y == 32)
				chon = 7;
			else if (y == 34)
				chon = 8;
			else if (y == 36)
				chon = 9;
			else if (y == 38)
				chon = 10;
			else if (y == 40)
				chon = 0;
			gotoXY(x, y);
			printf("  ");
			break;
		}
	}
}
void clear_input()
{
	gotoXY(18, 57);
	printf("                                           ");
	gotoXY(18, 57);

}
void menu()
{
	int x = 19;
	int y = 20;
	gotoXY(x, y);
	printf("1. Doc file (dshocphan.txt)");
	y += 2;
	gotoXY(x, y);
	printf("2. Liet ke danh sach hoc phan");
	y += 2;
	gotoXY(x, y);
	printf("3. Them 1 hoc phan moi");
	y += 2;
	gotoXY(x, y);
	printf("4. Xoa 1 hoc phan");
	y += 2;
	gotoXY(x, y);
	printf("5. Tim kiem 1 hoc phan");
	y += 2;
	gotoXY(x, y);
	printf("6. Cap nhat lai 1 hoc phan");
	y += 2;
	gotoXY(x, y);
	printf("7. Dieu chinh lai bang bam Hoc Phan");
	y += 2;
	gotoXY(x, y);
	printf("8. Xuat tat ca hoc phan co so tin chi > x");
	y += 2;
	gotoXY(x, y);
	printf("9. So tin chi cac hoc phan cua Khoa CNTT");
	y += 2;
	gotoXY(x, y);
	printf("10. SL va So TC tung loai cua Khoa CNTT");
	y += 2;
	gotoXY(x, y);
	printf("0. Thoat");

}
void clrscr()
{
	int a, b;
	a = 62;
	b = 27;
	gotoXY(a, b);
	printf("                                                                                                                                    ");
	b = b + 3;
	for (int i = 0; i <= 32; i++)
	{
		gotoXY(a, b);
		printf("                                                                                                                                     ");
		b += 1;
	}
}
// không tìm thấy thì trả về -1;
int Tim(ItemType*& bucket, char* ma)
{
	int id = hashfunction(ma);
	int res = id;
	int i = 1;
	while (bucket[id].MaHocPhan[0] != '\0')
	{
		if (strcmpi(bucket[id].MaHocPhan, ma) == 0)
			return id;
		id = (res + P(i)) % MAXSIZE;
		i++;
	}
	/*if (strcmpi(bucket[id].MaHocPhan, ma) == 0)
		return id;*/
	return -1;
}
void Xoa_1_HocPhan(ItemType*& bucket)
{
	if (nCount == 0)
	{
		clear_input();
		printf("Danh sach rong!");
		getch();
		clear_input();
		return;
	}
	int a, b;
	gotoXY(100, 27);
	printf("                                                    ");

	gotoXY(115, 27);
	printf("Xoa 1 hoc phan");
	char ma[20];
	//cin.ignore();
	clear_input();
	printf("Nhap ma hoc phan: ");
	gets_s(ma);
	a = 64;
	b = 31;
	gotoXY(a, b);
	int id = Tim(bucket, ma);
	if (id == -1)
	{
		clear_input();
		printf("%s khong ton tai trong danh sach", ma);
		getch();
		clear_input();
	}
	else
	{
		bucket[id].MaHocPhan[0] = '\0';
		bucket[id].ChuNhiem[0] = '\0';
		bucket[id].ChuyenNganh[0] = '\0';
		bucket[id].TenHocPhan[0] = '\0';
		bucket[id].LoaiHocPhan[0] = '\0';
		bucket[id].SoTinChi = 0;
		clear_input();
		printf("Da xoa hoc phan nay thanh cong");
		getch();
		clear_input();

	}
}
void Tim_1_HocPhan(ItemType* bucket)
{
	if (nCount == 0)
	{
		clear_input();
		printf("Danh sach rong!");
		getch();
		clear_input();
		return;
	}
	int a, b;
	gotoXY(100, 27);
	char ma[20];
	//cin.ignore();
	printf("                                                    ");

	gotoXY(115, 27);
	printf("Tim kiem 1 hoc phan");
	clear_input();
	printf("Nhap ma hoc phan: ");
	gets_s(ma);
	a = 64;
	b = 31;
	gotoXY(a, b);
	int id = Tim(bucket, ma);
	if (id == -1)
	{
		clear_input();
		printf("%s khong ton tai trong danh sach", ma);
		getch();
		clear_input();

	}
	else
	{
		clrscr();
		gotoXY(a, b);
		printf("Bucket: %d", id);
		gotoXY(115, 27);
		printf("Tim kiem thanh cong");
		b++;
		gotoXY(a, b);
		printf("Ma hoc phan: %s", bucket[id].MaHocPhan);
		b++;
		gotoXY(a, b);
		printf("Ten hoc phan: %s", bucket[id].TenHocPhan);
		b++;
		gotoXY(a, b);
		printf("Loai hoc phan: %s", bucket[id].LoaiHocPhan);
		b++;
		gotoXY(a, b);
		printf("Chu nhiem mon hoc: %s", bucket[id].ChuNhiem);
		b++;
		gotoXY(a, b);
		printf("Chuyen nganh: %s", bucket[id].ChuyenNganh);
		b++;
		gotoXY(a, b);
		printf("Tin chi: %d", bucket[id].SoTinChi);
	}
}
void Nhap_1_HocPhan(ItemType*& bucket)
{
	int a, b;
	ItemType x;
	
	//cin.ignore();
	//Thực hiện nhập các thông tin cho 1 học phần như là: Mã học phần, tên học phần ...
	clrscr();
	gotoXY(115, 27);
	printf("Nhap 1 hoc phan moi");
	a = 64;
	b = 31;
	gotoXY(a, b);
	printf("Ma hoc phan: ");
	gets_s(x.MaHocPhan);

	b++;
	gotoXY(a, b);
	printf("Ten hoc phan: ");
	gets_s(x.TenHocPhan);

	b++;
	gotoXY(a, b);
	printf("Loai hoc phan: ");
	gets_s(x.LoaiHocPhan);

	b++;
	gotoXY(a, b);
	printf("Chu nhiem: ");
	gets_s(x.ChuNhiem);

	b++;
	gotoXY(a, b);
	printf("Chuyen nganh: ");
	gets_s(x.ChuyenNganh);
	b++;
	gotoXY(a, b);
	printf("So tin chi: ");
	scanf("%d", &x.SoTinChi);
	cin.ignore();
	b++;
	gotoXY(a, b);
	push(bucket, x);
}
void Xuat_DieuKien(ItemType* bucket)
{
	if (nCount == 0)
	{
		clear_input();
		printf("Danh sach rong!");
		getch();
		clear_input();
		return;
	}
	int a;
	gotoXY(100, 27);
	printf("                                                    ");
	gotoXY(115, 27);
	printf("Danh sach cac hoc phan co so tin chi lon hon X");
	clear_input();
	printf("Nhap so tin chi X: ");
	scanf("%d", &a);
	int x, y;
	x = 63;
	y = 32;
	clrscr();
	gotoXY(115, 27);
	printf("Danh sach cac hoc phan co so tin chi lon hon %d", a);
	gotoXY(x, y - 2);
	TextColor(9);
	printf("  Bucket   | %-12s|%-50s|%-5s|%-10s|%-25s|%8s", "MaHocPhan", "TenHocPhan", "Chi", "Loai", "ChuNhiem", "Khoa");
	gotoXY(x, y - 1);
	printf("====================================================================================================================================");
	for (int i = 0; i < MAXSIZE; i++)
	{
		if (bucket[i].MaHocPhan[0] != '\0' && bucket[i].SoTinChi > a)
		{
			gotoXY(x, y);
			printf("Bucket[%-3d]: %-12s|%-50s|%-5d|%-10s|%-25s|%8s", i, bucket[i].MaHocPhan, bucket[i].TenHocPhan, bucket[i].SoTinChi, bucket[i].LoaiHocPhan, bucket[i].ChuNhiem, bucket[i].ChuyenNganh);
			y++;
		}
		else
		{
			/*gotoXY(x, y);
			printf("Bucket[%-3d]: %-12s|%-50s|%-5s|%-10s|%-25s|%8s", i, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL");*/
			//y++;
		}
	}
	gotoXY(x, y);

	printf("====================================================================================================================================");
	TextColor(7);
	cin.ignore();
}
void TongTinChi_KhoaCNTT(ItemType* bucket)
{
	if (nCount == 0)
	{
		clear_input();
		printf("Danh sach rong!");
		getch();
		clear_input();
		return;
	}
	int tong = 0;
	// Duyệt qua tất các bucket, so sánh với chuỗi CNTT, nếu giống thì trả về 0	
	for (int i = 0; i < MAXSIZE; i++)
	{
		if (strcmpi(bucket[i].ChuyenNganh, "CNTT") == 0)
			tong += bucket[i].SoTinChi;
	}
	clear_input();
	printf("Tong so tin chi cac phan cua Khoa CNTT: %d", tong);

}
void CapNhat(ItemType* bucket)
{
	if (nCount == 0)
	{
		clear_input();
		printf("Danh sach rong!");
		getch();
		clear_input();
		return;
	}
	int a, b;
	gotoXY(100, 27);
	char ma[20];
	//cin.ignore();
	printf("                                              ");
	gotoXY(115, 27);
	printf("Cap nhat lai hoc phan");
	clear_input();
	printf("Nhap ma hoc phan can sua: ");
	gets_s(ma);
	a = 64;
	b = 31;
	gotoXY(a, b);
	int id = Tim(bucket, ma);
	if (id == -1)
	{
		clrscr();
		printf("                                ");
		gotoXY(115, 27);
		printf("Cap nhat lai hoc phan");
		clear_input();
		printf("%s khong ton tai trong danh sach", ma);
		getch();
		clear_input();

	}
	else
	{
		clrscr();
		printf("                                 ");
		gotoXY(115, 27);
		printf("Cap nhat lai hoc phan");
		gotoXY(a, b);
		printf("Ma hoc phan: ");
		gets_s(bucket[id].MaHocPhan);
		b++;
		gotoXY(a, b);
		printf("Ten hoc phan: ");
		gets_s(bucket[id].TenHocPhan);
		b++;
		gotoXY(a, b);
		printf("Loai hoc phan: ");
		gets_s(bucket[id].LoaiHocPhan);

		b++;
		gotoXY(a, b);
		printf("Chu nhiem: ");
		gets_s(bucket[id].ChuNhiem);

		b++;
		gotoXY(a, b);
		printf("Chuyen nganh: ");
		gets_s(bucket[id].ChuyenNganh);
		b++;
		gotoXY(a, b);
		printf("So tin chi: ");
		scanf("%d", &bucket[id].SoTinChi);
		cin.ignore();
	}
}
void Label(int time)
{
	fstream f;
	string s;
	f.open("Label.txt", ios::in);
	f.seekg(3, 0);
	TextColor(11);
	while (!f.eof())
	{
		getline(f, s);
		cout << s << endl;
		Sleep(time);
	}
	TenThanhVien(time);
	TextColor(7);
	f.close();
}
void init(ThongKe a[])
{
	for (int i = 0; i < 100; i++)
	{
		a[i].loaiHocPhan[0] = '\0';
		a[i].tinChi = 0;
	}
}
int check(ThongKe a[], int n, char* loaiHocPhan)
{
	for (int i = 0; i < n; i++)
	{
		if (strcmpi(a[i].loaiHocPhan, loaiHocPhan) == 0)
			return i;
	}
	return -1;
}
void taoBangThongKe(ThongKe LoaiHP[], int& nThongKe, ItemType *bucket)
{
	int vitri;
	for (int i = 0; i < MAXSIZE; i++)
	{
		if (bucket[i].MaHocPhan[0] != '\0' && strcmpi(bucket[i].ChuyenNganh, "CNTT") == 0) // Phải là của Khoa CNTT
		{
			vitri = check(LoaiHP, nThongKe, bucket[i].LoaiHocPhan); // Check xem loại học phần của bucket này đã tồn tại chưa
			if (vitri == -1) // nếu chưa
			{
				strcpy(LoaiHP[nThongKe].loaiHocPhan, bucket[i].LoaiHocPhan); // copy tên của bucket vào Loại học phần của Thống kê
				LoaiHP[nThongKe].tinChi += bucket[i].SoTinChi; // Cộng dồn tín chỉ vào Số tín chỉ của thống kê
				nThongKe++; // Tăng số lượng của loại học phần lên
			}
			else // Nếu tồn tại
			{
				LoaiHP[vitri].tinChi += bucket[i].SoTinChi;// chỉ cần cộng dồn số tín chỉ của vị trí đã tìm thấy	
			}
		}
	}
}
void ThongKe_LoaiHP(ItemType *bucket)
{
	if (nCount == 0)
	{
		clear_input();
		printf("Danh sach rong!");
		getch();
		clear_input();
		return;
	}
	ThongKe LoaiHP[100];
	int nThongKe = 0;
	init(LoaiHP);
	taoBangThongKe(LoaiHP, nThongKe, bucket);
	int a, b;
	gotoXY(105, 27);
	printf("                                                ");
	gotoXY(105, 27);
	printf("SL va TC cua tung loai khoa CNTT quan ly");
	clear_input();
	a = 64;
	b = 31;
	gotoXY(a, b);
	printf("So luong loai hoc phan khoa CNTT quan ly: %d", nThongKe);
	for (int i = 0; i < nThongKe; i++)
	{
		b++;
		gotoXY(a, b);
		printf("Loai hoc phan %s. Tong tin chi: %d", LoaiHP[i].loaiHocPhan, LoaiHP[i].tinChi);
	}
}
#pragma region SetUpConsole
void gotoXY(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}
void TextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConCurInf;

	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = CursorVisibility;

	SetConsoleCursorInfo(handle, &ConCurInf);
}
void DisableResizeWindow()
{
	HWND hWnd = GetConsoleWindow();
	SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
}
#pragma endregion

#pragma region HashTable

int hashfunction(char key[])
{
	int s = 0;
	for (int i = 0; i < strlen(key); i++)
	{
		// ví dụ '1' có khi biến đổi '1' thành int thì là 49, nên 49 - 48 = 1 
		s += ((int)key[i] - 48);
	}
	return s % MAXSIZE;
}
void initBucket(ItemType*& bucket)
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		bucket[i].MaHocPhan[0] = '\0';
	}
}
int P(int i)
{
	return i * i + i;
}
void resize(ItemType*& bucket)
{
	if (nCount == 0)
	{
		clear_input();
		printf("Danh sach rong!");
		getch();
		clear_input();
		return;
	}
	if (nCount <= MAXCOUNT)
	{
		clear_input();
		printf("Chua can resize!");
		getch();
		clear_input();
		return;
	}
	int old = MAXSIZE;
	MAXSIZE = MAXSIZE * 2;
	MAXCOUNT = MAXSIZE * THESHOLD;
	ItemType* newBucket = new ItemType[MAXSIZE];
	initBucket(newBucket);
	nCount = 0;
	for (int i = 0; i < old; i++)
	{
		if (bucket[i].MaHocPhan[0] != '\0')
			push(newBucket, bucket[i]);
	}
	delete bucket;
	bucket = newBucket;
}
void push(ItemType*& bucket, ItemType x)
{
	// hash ra 1 id
	int id = hashfunction(x.MaHocPhan);
	int res = id; // dùng để lưu giá trị ban đầu của id
	int i = 1;
	// Trường hợp tại bucket này đang tồn tại 1 học phần rồi, thì thực hash lại (đụng độ)
	while (bucket[id].MaHocPhan[0] != '\0')
	{
		if (strcmpi(bucket[id].MaHocPhan, x.MaHocPhan) == 0) // Vô tình trùng mã học phần thì không thêm vô
		{
			clear_input();
			printf("Da ton tai ma hoc phan nay roi!");
			getch();
			clear_input();
			return;
		}
		id = (res + P(i)) % MAXSIZE; // rehash
		i++;
	}
	// thêm vào bucket này
	bucket[id] = x;
	nCount++;
	// Nếu các phần tử thêm vào vượt ngưỡng cho phép thì rehash
	if (nCount > MAXCOUNT)
		resize(bucket);
}
void display_Bucket(ItemType* bucket)
{
	if (nCount == 0)
	{
		clear_input();
		printf("Danh sach rong!");
		getch();
		clear_input();
		return;
	}
	int x, y;
	x = 63;
	y = 32;
	clrscr();
	gotoXY(115, 27);
	printf("Danh sach cac hoc phan");
	gotoXY(x, y - 2);
	TextColor(9);
	printf("  Bucket   | %-12s|%-50s|%-5s|%-10s|%-25s|%8s", "MaHocPhan", "TenHocPhan", "Chi", "Loai", "ChuNhiem", "Khoa");
	gotoXY(x, y - 1);
	printf("====================================================================================================================================");
	for (int i = 0; i < MAXSIZE; i++)
	{
		if (bucket[i].MaHocPhan[0] != '\0')
		{
			gotoXY(x, y);
			printf("Bucket[%-3d]: %-12s|%-50s|%-5d|%-10s|%-25s|%8s", i, bucket[i].MaHocPhan, bucket[i].TenHocPhan, bucket[i].SoTinChi, bucket[i].LoaiHocPhan, bucket[i].ChuNhiem, bucket[i].ChuyenNganh);
			y++;
		}
		else
		{
			/*gotoXY(x, y);
			printf("Bucket[%-3d]: %-12s|%-50s|%-5s|%-10s|%-25s|%8s", i, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL");
			y++;*/
		}
	}
	gotoXY(x, y);

	printf("====================================================================================================================================");
	TextColor(7);

}
void insert_FILE(ItemType*& bucket, char* filename)
{
	FILE* f;
	fopen_s(&f, filename, "rt");
	if (!f)
	{
		clear_input();
		printf("File khong ton tai!");
		return;
	}
	ItemType x;
	while (feof(f) == false)
	{
		fscanf(f, "%[^-]-%[^-]-%d-%[^-]-%[^-]-%[^.].\n", &x.MaHocPhan, &x.TenHocPhan, &x.SoTinChi, &x.LoaiHocPhan, &x.ChuNhiem, &x.ChuyenNganh);
		push(bucket, x);
	}
	fclose(f);
	clear_input();

	printf("Doc file thanh cong");
}
#pragma endregion