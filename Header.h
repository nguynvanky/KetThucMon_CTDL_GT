#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string>
using namespace std;
extern int MAXSIZE;
#define THESHOLD 0.6;
extern int MAXCOUNT;
extern int nCount;
// Câu 1
struct HocPhan {
	char MaHocPhan[20], TenHocPhan[50], LoaiHocPhan[15], ChuNhiem[30], ChuyenNganh[20];
	int SoTinChi;
};
#define key_Up		72
#define key_Down	80
#define key_Enter	13
#define key_ESC		27

struct ThongKe {
	char loaiHocPhan[15];
	int tinChi = 0;
};
typedef HocPhan ItemType;
void Label(int time);
void TenThanhVien(int time);
void menu();
void Chon(int& chon);
void clear_input();

#pragma region hashtable
int hashfunction(char key[]);
// Câu 3 
void push(ItemType*& bucket, ItemType x);
// p = i^2 + i
int P(int i);

// Khởi tạo bảng băm rỗng
void initBucket(ItemType*& bucket);

// Tạo bảng băm từ file, Câu 1
void insert_FILE(ItemType*& bucket, char *filename);

// Điều chỉnh lại kích thước, Câu 7
void resize(ItemType *&bucket);

// Xuất danh sách các học phần trong bảng băm
void display_Bucket(ItemType* bucket);

// Nhập 1 học phần vào bảng băm, Câu 1
void Nhap_1_HocPhan(ItemType*& bucket);

// TÌm vị trí của Mã Học Phần, nếu có thì trả về vị trí đó, ngược lại trả về 1, Bổ trợ cho hàm xóa
int Tim(ItemType*& bucket, char *ma);

// Xóa 1 học phần trong bảng băm, Câu 4
void Xoa_1_HocPhan(ItemType*& bucket);

// Tìm 1 học phần trong bảng băm, và in ra thông tin của học phần đó, Câu 5
void Tim_1_HocPhan(ItemType* bucket);

// Cập nhật lại thông tin của 1 học phần, Câu 6
void CapNhat(ItemType* bucket);


// Xuất tất cả học phần có chỉ số lớn hơn X, X nhập từ bàn phím, Câu 8
void Xuat_DieuKien(ItemType* bucket);


// Câu 10

// Kiểm tra xem Loại Học Phần đã tồn tại trong bảng Thống kê chưa, nếu chưa trả về -1, ngược lại trả về vị trí của bảng thống kê
int check(ThongKe a[], int n, char* loaiHocPhan);

// Khởi tạo bảng thống kê với các giá trị  = 0;
void init(ThongKe a[]);

// Tạo thống kê các loại học phần, Ví dụ: bắt buộc, tự chọn,..., và buộc phải là của khoa CNTT
void taoBangThongKe(ThongKe LoaiHP[], int& nThongKe, ItemType *bucket);

// In ra bảng thống kê sau khi đã thống kê xong, VD:
// Tổng tự chọn : 20 tín chỉ
// Tổng bắt buộc : 30 tín chỉ
void ThongKe_LoaiHP(ItemType *bucket);

// Tính tổng số tín chỉ mà Khoa CNTT quản lý, Câu 9
void TongTinChi_KhoaCNTT(ItemType* bucket);
#pragma endregion

#pragma region SetUpRegion
void gotoXY(int column, int line);
int whereX();
int whereY();
void TextColor(int color);
void ShowCur(bool CursorVisibility);
void DisableResizeWindow();
void clrscr();

#pragma endregion