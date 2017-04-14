// Puzzle.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "Puzzle.h"
#include "stdlib.h"
#include "time.h"


#define MAX_LOADSTRING 100

// 全局变量: 
int g[3][3]; //存储图片块对应的标号
int wind; //是否进入游戏窗口 
int k;	  //当前空白格位置标号
int move; //已走步数
int cnt;  //初始化计数
int minm = 99999;
HINSTANCE hInst;                                // 当前实例
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名

//存储图片的变量
BITMAPINFOHEADER  bi;
HBITMAP             hbmp;
BITMAP               bmp;
HANDLE              hDib;
BYTE                 *lpbitmap = NULL;

BITMAPINFOHEADER    bi1;
HBITMAP             hbmp1;
BITMAP              bmp1;
HANDLE              hDib1;
BYTE                *lpbitmap1 = NULL;

BITMAPINFOHEADER    bi2;
HBITMAP             hbmp2;
BITMAP              bmp2;
HANDLE              hDib2;
BYTE                *lpbitmap2 = NULL;

BITMAPINFOHEADER    bi3;
HBITMAP             hbmp3;
BITMAP              bmp3;
HANDLE              hDib3;
BYTE                *lpbitmap3 = NULL;

BITMAPINFOHEADER    bi4;
HBITMAP             hbmp4;
BITMAP              bmp4;
HANDLE              hDib4;
BYTE                *lpbitmap4 = NULL;

BITMAPINFOHEADER    bi5;
HBITMAP             hbmp5;
BITMAP              bmp5;
HANDLE              hDib5;
BYTE                *lpbitmap5 = NULL;

BITMAPINFOHEADER    bi6;
HBITMAP             hbmp6;
BITMAP              bmp6;
HANDLE              hDib6;
BYTE                *lpbitmap6 = NULL;

BITMAPINFOHEADER    bi7;
HBITMAP             hbmp7;
BITMAP              bmp7;
HANDLE              hDib7;
BYTE                *lpbitmap7 = NULL;

BITMAPINFOHEADER    bi8;
HBITMAP             hbmp8;
BITMAP              bmp8;
HANDLE              hDib8;
BYTE                *lpbitmap8 = NULL;

BITMAPINFOHEADER    bi9;
HBITMAP             hbmp9;
BITMAP              bmp9;
HANDLE              hDib9;
BYTE                *lpbitmap9 = NULL;

BITMAPINFOHEADER    bi10;
HBITMAP             hbmp10;
BITMAP              bmp10;
HANDLE              hDib10;
BYTE                *lpbitmap10 = NULL;

BITMAPINFOHEADER    bi11;
HBITMAP             hbmp11;
BITMAP              bmp11;
HANDLE              hDib11;
BYTE                *lpbitmap11 = NULL;


// 此代码模块中包含的函数的前向声明: 
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
void paintimg(HWND hWnd, int k, int x, int y); //绘制单个小图片
int swapup(int k);       //交换空白格与邻近格
int swapdown(int k);
int swapleft(int k);
int swapright(int k);
int check();        //检查是否完成拼图
void print(HWND hWnd); //重绘拼图
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: 在此放置代码。
	//载入图片
	{
	if (LoadImage(hInstance, L"background.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE) == NULL)
	{
		MessageBox(NULL, L"加载图像错误", L"message", NULL);
	}
	else
	{
		hbmp = (HBITMAP)LoadImage(hInstance, L"background.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	}
	GetObject(hbmp, sizeof(BITMAP), &bmp);
	bi.biSize = sizeof(BITMAPINFOHEADER);
	bi.biWidth = bmp.bmWidth;
	bi.biHeight = bmp.bmHeight;
	bi.biPlanes = bmp.bmPlanes;
	bi.biBitCount = bmp.bmBitsPixel;
	bi.biCompression = bmp.bmType;
	bi.biSizeImage = bmp.bmWidth * bmp.bmHeight * bmp.bmBitsPixel / 8;
	bi.biXPelsPerMeter = 0;
	bi.biYPelsPerMeter = 0;
	bi.biClrImportant = 0;
	hDib = GlobalAlloc(GHND, bi.biSizeImage);
	lpbitmap = (BYTE*)GlobalLock(hDib);

	if (LoadImage(hInstance, L"csu1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE) == NULL)
	{
		MessageBox(NULL, L"加载图像错误", L"message", NULL);
	}
	else
	{
		hbmp1 = (HBITMAP)LoadImage(hInstance, L"csu1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	}
	GetObject(hbmp1, sizeof(BITMAP), &bmp1);
	bi1.biSize = sizeof(BITMAPINFOHEADER);
	bi1.biWidth = bmp1.bmWidth;
	bi1.biHeight = bmp1.bmHeight;
	bi1.biPlanes = bmp1.bmPlanes;
	bi1.biBitCount = bmp1.bmBitsPixel;
	bi1.biCompression = bmp1.bmType;
	bi1.biSizeImage = bmp1.bmWidth * bmp1.bmHeight * bmp1.bmBitsPixel / 8;
	bi1.biXPelsPerMeter = 0;
	bi1.biYPelsPerMeter = 0;
	bi1.biClrImportant = 0;
	hDib1 = GlobalAlloc(GHND, bi1.biSizeImage);
	lpbitmap1 = (BYTE*)GlobalLock(hDib1);


	if (LoadImage(hInstance, L"csu2.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE) == NULL)
	{
		MessageBox(NULL, L"加载图像错误", L"message", NULL);
	}
	else
	{
		hbmp2 = (HBITMAP)LoadImage(hInstance, L"csu2.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	}
	GetObject(hbmp2, sizeof(BITMAP), &bmp2);
	bi2.biSize = sizeof(BITMAPINFOHEADER);
	bi2.biWidth = bmp2.bmWidth;
	bi2.biHeight = bmp2.bmHeight;
	bi2.biPlanes = bmp2.bmPlanes;
	bi2.biBitCount = bmp2.bmBitsPixel;
	bi2.biCompression = bmp2.bmType;
	bi2.biSizeImage = bmp2.bmWidth * bmp2.bmHeight * bmp2.bmBitsPixel / 8;
	bi2.biXPelsPerMeter = 0;
	bi2.biYPelsPerMeter = 0;
	bi2.biClrImportant = 0;
	hDib2 = GlobalAlloc(GHND, bi2.biSizeImage);
	lpbitmap2 = (BYTE*)GlobalLock(hDib2);

	if (LoadImage(hInstance, L"csu3.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE) == NULL)
	{
		MessageBox(NULL, L"加载图像错误", L"message", NULL);
	}
	else
	{
		hbmp3 = (HBITMAP)LoadImage(hInstance, L"csu3.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	}
	GetObject(hbmp3, sizeof(BITMAP), &bmp3);
	bi3.biSize = sizeof(BITMAPINFOHEADER);
	bi3.biWidth = bmp3.bmWidth;
	bi3.biHeight = bmp3.bmHeight;
	bi3.biPlanes = bmp3.bmPlanes;
	bi3.biBitCount = bmp3.bmBitsPixel;
	bi3.biCompression = bmp3.bmType;
	bi3.biSizeImage = bmp3.bmWidth * bmp3.bmHeight * bmp3.bmBitsPixel / 8;
	bi3.biXPelsPerMeter = 0;
	bi3.biYPelsPerMeter = 0;
	bi3.biClrImportant = 0;
	hDib3 = GlobalAlloc(GHND, bi3.biSizeImage);
	lpbitmap3 = (BYTE*)GlobalLock(hDib3);


	if (LoadImage(hInstance, L"csu4.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE) == NULL)
	{
		MessageBox(NULL, L"加载图像错误", L"message", NULL);
	}
	else
	{
		hbmp4 = (HBITMAP)LoadImage(hInstance, L"csu4.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	}
	GetObject(hbmp4, sizeof(BITMAP), &bmp4);
	bi4.biSize = sizeof(BITMAPINFOHEADER);
	bi4.biWidth = bmp4.bmWidth;
	bi4.biHeight = bmp4.bmHeight;
	bi4.biPlanes = bmp4.bmPlanes;
	bi4.biBitCount = bmp4.bmBitsPixel;
	bi4.biCompression = bmp4.bmType;
	bi4.biSizeImage = bmp4.bmWidth * bmp4.bmHeight * bmp4.bmBitsPixel / 8;
	bi4.biXPelsPerMeter = 0;
	bi4.biYPelsPerMeter = 0;
	bi4.biClrImportant = 0;
	hDib4 = GlobalAlloc(GHND, bi4.biSizeImage);
	lpbitmap4 = (BYTE*)GlobalLock(hDib4);


	if (LoadImage(hInstance, L"csu5.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE) == NULL)
	{
		MessageBox(NULL, L"加载图像错误", L"message", NULL);
	}
	else
	{
		hbmp5 = (HBITMAP)LoadImage(hInstance, L"csu5.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	}
	GetObject(hbmp5, sizeof(BITMAP), &bmp5);
	bi5.biSize = sizeof(BITMAPINFOHEADER);
	bi5.biWidth = bmp5.bmWidth;
	bi5.biHeight = bmp5.bmHeight;
	bi5.biPlanes = bmp5.bmPlanes;
	bi5.biBitCount = bmp5.bmBitsPixel;
	bi5.biCompression = bmp5.bmType;
	bi5.biSizeImage = bmp5.bmWidth * bmp5.bmHeight * bmp5.bmBitsPixel / 8;
	bi5.biXPelsPerMeter = 0;
	bi5.biYPelsPerMeter = 0;
	bi5.biClrImportant = 0;
	hDib5 = GlobalAlloc(GHND, bi5.biSizeImage);
	lpbitmap5 = (BYTE*)GlobalLock(hDib5);


	if (LoadImage(hInstance, L"csu6.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE) == NULL)
	{
		MessageBox(NULL, L"加载图像错误", L"message", NULL);
	}
	else
	{
		hbmp6 = (HBITMAP)LoadImage(hInstance, L"csu6.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	}
	GetObject(hbmp6, sizeof(BITMAP), &bmp6);
	bi6.biSize = sizeof(BITMAPINFOHEADER);
	bi6.biWidth = bmp6.bmWidth;
	bi6.biHeight = bmp6.bmHeight;
	bi6.biPlanes = bmp6.bmPlanes;
	bi6.biBitCount = bmp6.bmBitsPixel;
	bi6.biCompression = bmp6.bmType;
	bi6.biSizeImage = bmp6.bmWidth * bmp6.bmHeight * bmp6.bmBitsPixel / 8;
	bi6.biXPelsPerMeter = 0;
	bi6.biYPelsPerMeter = 0;
	bi6.biClrImportant = 0;
	hDib6 = GlobalAlloc(GHND, bi6.biSizeImage);
	lpbitmap6 = (BYTE*)GlobalLock(hDib6);


	if (LoadImage(hInstance, L"csu7.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE) == NULL)
	{
		MessageBox(NULL, L"加载图像错误", L"message", NULL);
	}
	else
	{
		hbmp7 = (HBITMAP)LoadImage(hInstance, L"csu7.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	}
	GetObject(hbmp7, sizeof(BITMAP), &bmp7);
	bi7.biSize = sizeof(BITMAPINFOHEADER);
	bi7.biWidth = bmp7.bmWidth;
	bi7.biHeight = bmp7.bmHeight;
	bi7.biPlanes = bmp7.bmPlanes;
	bi7.biBitCount = bmp7.bmBitsPixel;
	bi7.biCompression = bmp7.bmType;
	bi7.biSizeImage = bmp7.bmWidth * bmp7.bmHeight * bmp7.bmBitsPixel / 8;
	bi7.biXPelsPerMeter = 0;
	bi7.biYPelsPerMeter = 0;
	bi7.biClrImportant = 0;
	hDib7 = GlobalAlloc(GHND, bi7.biSizeImage);
	lpbitmap7 = (BYTE*)GlobalLock(hDib7);


	if (LoadImage(hInstance, L"csu8.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE) == NULL)
	{
		MessageBox(NULL, L"加载图像错误", L"message", NULL);
	}
	else
	{
		hbmp8 = (HBITMAP)LoadImage(hInstance, L"csu8.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	}
	GetObject(hbmp8, sizeof(BITMAP), &bmp8);
	bi8.biSize = sizeof(BITMAPINFOHEADER);
	bi8.biWidth = bmp8.bmWidth;
	bi8.biHeight = bmp8.bmHeight;
	bi8.biPlanes = bmp8.bmPlanes;
	bi8.biBitCount = bmp8.bmBitsPixel;
	bi8.biCompression = bmp8.bmType;
	bi8.biSizeImage = bmp8.bmWidth * bmp8.bmHeight * bmp8.bmBitsPixel / 8;
	bi8.biXPelsPerMeter = 0;
	bi8.biYPelsPerMeter = 0;
	bi8.biClrImportant = 0;
	hDib8 = GlobalAlloc(GHND, bi8.biSizeImage);
	lpbitmap8 = (BYTE*)GlobalLock(hDib8);


	if (LoadImage(hInstance, L"csu9.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE) == NULL)
	{
		MessageBox(NULL, L"加载图像错误", L"message", NULL);
	}
	else
	{
		hbmp9 = (HBITMAP)LoadImage(hInstance, L"csu9.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	}
	GetObject(hbmp9, sizeof(BITMAP), &bmp9);
	bi9.biSize = sizeof(BITMAPINFOHEADER);
	bi9.biWidth = bmp9.bmWidth;
	bi9.biHeight = bmp9.bmHeight;
	bi9.biPlanes = bmp9.bmPlanes;
	bi9.biBitCount = bmp9.bmBitsPixel;
	bi9.biCompression = bmp9.bmType;
	bi9.biSizeImage = bmp9.bmWidth * bmp9.bmHeight * bmp9.bmBitsPixel / 8;
	bi9.biXPelsPerMeter = 0;
	bi9.biYPelsPerMeter = 0;
	bi9.biClrImportant = 0;
	hDib9 = GlobalAlloc(GHND, bi9.biSizeImage);
	lpbitmap9 = (BYTE*)GlobalLock(hDib9);


	if (LoadImage(hInstance, L"csu.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE) == NULL)
	{
		MessageBox(NULL, L"加载图像错误", L"message", NULL);
	}
	else
	{
		hbmp10 = (HBITMAP)LoadImage(hInstance, L"csu.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	}
	GetObject(hbmp10, sizeof(BITMAP), &bmp10);
	bi10.biSize = sizeof(BITMAPINFOHEADER);
	bi10.biWidth = bmp10.bmWidth;
	bi10.biHeight = bmp10.bmHeight;
	bi10.biPlanes = bmp10.bmPlanes;
	bi10.biBitCount = bmp10.bmBitsPixel;
	bi10.biCompression = bmp10.bmType;
	bi10.biSizeImage = bmp10.bmWidth * bmp10.bmHeight * bmp10.bmBitsPixel / 8;
	bi10.biXPelsPerMeter = 0;
	bi10.biYPelsPerMeter = 0;
	bi10.biClrImportant = 0;
	hDib10 = GlobalAlloc(GHND, bi10.biSizeImage);
	lpbitmap10 = (BYTE*)GlobalLock(hDib10);

	//背景图片
	if (LoadImage(hInstance, L"back.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE) == NULL)
	{
		MessageBox(NULL, L"加载图像错误", L"message", NULL);
	}
	else
	{
		hbmp11 = (HBITMAP)LoadImage(hInstance, L"back.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	}
	GetObject(hbmp11, sizeof(BITMAP), &bmp11);
	bi11.biSize = sizeof(BITMAPINFOHEADER);
	bi11.biWidth = bmp11.bmWidth;
	bi11.biHeight = bmp11.bmHeight;
	bi11.biPlanes = bmp11.bmPlanes;
	bi11.biBitCount = bmp11.bmBitsPixel;
	bi11.biCompression = bmp11.bmType;
	bi11.biSizeImage = bmp11.bmWidth * bmp11.bmHeight * bmp11.bmBitsPixel / 8;
	bi11.biXPelsPerMeter = 0;
	bi11.biYPelsPerMeter = 0;
	bi11.biClrImportant = 0;
	hDib11 = GlobalAlloc(GHND, bi11.biSizeImage);
	lpbitmap11 = (BYTE*)GlobalLock(hDib11);
}
    // 初始化全局字符串
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_PUZZLE, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 执行应用程序初始化: 
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_PUZZLE));

    MSG msg;

	//初始化游戏
	
	
    // 主消息循环: 
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  函数: MyRegisterClass()
//
//  目的: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PUZZLE));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_PUZZLE);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目的: 保存实例句柄并创建主窗口
//
//   注释: 
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 将实例句柄存储在全局变量中

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW^WS_THICKFRAME,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }
   MoveWindow(hWnd, 200, 300, 1000, 740, false);
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的:    处理主窗口的消息。
//
//  WM_COMMAND  - 处理应用程序菜单
//  WM_PAINT    - 绘制主窗口
//  WM_DESTROY  - 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	
    switch (message)
    {

		//按键消息响应
	case WM_KEYDOWN:
		if (wParam == VK_RIGHT) {
			if (check()) break;
			if (swapleft(k)) { k -= 1; move++; }
			print(hWnd);
		}
		else if (wParam == VK_LEFT)
		{
			if (check()) break;
			if (swapright(k)){k += 1; move++;	}
			print(hWnd);
		}
		else if (wParam == VK_DOWN)
		{
			if (check()) break;
			if (swapup(k)){ k -= 3; move++;		}
			print(hWnd);
		}
		else if (wParam == VK_UP)
		{
			if (check()) break;
			if (swapdown(k)){k += 3; move++;	}
			print(hWnd);
			
		}
		else if (wParam == VK_RETURN)  
		{
			
			move = 0;
			k = 8;
			for (int i = 0; i<3; i++)
				for (int j = 0; j<3; j++)
				{
					g[i][j] = i * 3 + j + 1;
				}
			
			int matchcnt = 0;
			while (1)
			{
				cnt = 0;
				int r = (rand() % 4);
				switch (r)
				{
				case 0: {if (swapup(k)) k -= 3;//print();
					break; }
				case 1: {if (swapdown(k))k += 3;//print();
					break; }
				case 2: {if (swapleft(k))k -= 1;//print();
					break; }
				case 3: {if (swapright(k))k += 1;//print();
					break; }
				}
				for(int i=0;i<3;i++)
					for (int j = 0; j < 3; j++)
					{
						if (g[i][j] == i * 3 + j + 1) cnt++;
					}
				if (cnt<4 && k == 8) break;
			}

			//重新绘图
			HDC hdc = GetDC(hWnd);

			GetDIBits(hdc,
				hbmp11,
				0,
				(UINT)bmp11.bmHeight,
				lpbitmap11,
				(BITMAPINFO*)&bi11,
				DIB_RGB_COLORS);
			SetDIBitsToDevice(hdc,
				0,
				0,
				bi11.biWidth,
				bi11.biHeight,
				0,
				0,
				0,
				bi11.biHeight,
				lpbitmap11,
				(BITMAPINFO *)&bi11,
				DIB_RGB_COLORS);

			GetDIBits(hdc,
				hbmp10,
				0,
				(UINT)bmp10.bmHeight,
				lpbitmap10,
				(BITMAPINFO*)&bi10,
				DIB_RGB_COLORS);
			SetDIBitsToDevice(hdc,
				15,
				60,
				bi10.biWidth,
				bi10.biHeight,
				0,
				0,
				0,
				bi10.biHeight,
				lpbitmap10,
				(BITMAPINFO *)&bi10,
				DIB_RGB_COLORS);

			CString str;
			str.Format(_T("%d"), move);
			LOGFONT   logfont;       //改变输出字体
			ZeroMemory(&logfont, sizeof(LOGFONT));
			logfont.lfCharSet = GB2312_CHARSET;
			logfont.lfHeight = -40;      //设置字体的大小
			HFONT   hFont = CreateFontIndirect(&logfont);
			::SetTextColor(hdc, RGB(0, 0, 0));
			::SetBkColor(hdc, RGB(200, 200, 0));
			::SetBkMode(hdc, TRANSPARENT);
			SelectObject(hdc, hFont);
					
			TextOut(hdc, 100, 415, L"Move:" + str, str.GetLength() + 5);
			str.Format(_T("%d"), minm);
			TextOut(hdc, 30, 515, L"Min-Move:" + str, str.GetLength() + 9);
			ReleaseDC(hWnd, hdc);
			DeleteObject(hFont);

			for (int i = 0; i<3; i++)
			{
				for (int j = 0; j < 3; j++)
					if (g[i][j] != 9) paintimg(hWnd, g[i][j], 345 + j * 201, 60 + i * 201);
			
			}

			
		}

    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 分析菜单选择: 
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 在此处添加使用 hdc 的任何绘图代码...
			//绘制初始背景图
			GetDIBits(hdc,
				hbmp,
				0,
				(UINT)bmp.bmHeight,
				lpbitmap,
				(BITMAPINFO*)&bi,
				DIB_RGB_COLORS);
			SetDIBitsToDevice(hdc,
				0,
				0,
				bi.biWidth,
				bi.biHeight,
				0,
				0,
				0,
				bi.biHeight,
				lpbitmap,
				(BITMAPINFO *)&bi,
				DIB_RGB_COLORS);
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}


void paintimg(HWND hWnd,int k,int x,int y)
{
	HDC hdc = GetDC(hWnd);
	
	switch (k)
	{
		case 1:{GetDIBits(hdc,
			hbmp1,
			0,
			(UINT)bmp1.bmHeight,
			lpbitmap1,
			(BITMAPINFO*)&bi1,
			DIB_RGB_COLORS);
			SetDIBitsToDevice(hdc,
				x,
				y,
				bi1.biWidth,
				bi1.biHeight,
				0,
				0,
				0,
				bi1.biHeight,
				lpbitmap1,
				(BITMAPINFO *)&bi1,
				DIB_RGB_COLORS); break; }
		case 2: {GetDIBits(hdc,
			hbmp2,
			0,
			(UINT)bmp2.bmHeight,
			lpbitmap2,
			(BITMAPINFO*)&bi2,
			DIB_RGB_COLORS);
			SetDIBitsToDevice(hdc,
				x,
				y,
				bi2.biWidth,
				bi2.biHeight,
				0,
				0,
				0,
				bi2.biHeight,
				lpbitmap2,
				(BITMAPINFO *)&bi2,
				DIB_RGB_COLORS); break; }
		case 3: {GetDIBits(hdc,
			hbmp3,
			0,
			(UINT)bmp3.bmHeight,
			lpbitmap3,
			(BITMAPINFO*)&bi3,
			DIB_RGB_COLORS);
			SetDIBitsToDevice(hdc,
				x,
				y,
				bi3.biWidth,
				bi3.biHeight,
				0,
				0,
				0,
				bi3.biHeight,
				lpbitmap3,
				(BITMAPINFO *)&bi3,
				DIB_RGB_COLORS); break; }
		case 4: {GetDIBits(hdc,
			hbmp4,
			0,
			(UINT)bmp4.bmHeight,
			lpbitmap4,
			(BITMAPINFO*)&bi4,
			DIB_RGB_COLORS);
			SetDIBitsToDevice(hdc,
				x,
				y,
				bi4.biWidth,
				bi4.biHeight,
				0,
				0,
				0,
				bi4.biHeight,
				lpbitmap4,
				(BITMAPINFO *)&bi4,
				DIB_RGB_COLORS); break; }
		case 5: {GetDIBits(hdc,
			hbmp5,
			0,
			(UINT)bmp5.bmHeight,
			lpbitmap5,
			(BITMAPINFO*)&bi5,
			DIB_RGB_COLORS);
			SetDIBitsToDevice(hdc,
				x,
				y,
				bi5.biWidth,
				bi5.biHeight,
				0,
				0,
				0,
				bi5.biHeight,
				lpbitmap5,
				(BITMAPINFO *)&bi5,
				DIB_RGB_COLORS); break; }
		case 6: {GetDIBits(hdc,
			hbmp6,
			0,
			(UINT)bmp6.bmHeight,
			lpbitmap6,
			(BITMAPINFO*)&bi6,
			DIB_RGB_COLORS);
			SetDIBitsToDevice(hdc,
				x,
				y,
				bi6.biWidth,
				bi6.biHeight,
				0,
				0,
				0,
				bi6.biHeight,
				lpbitmap6,
				(BITMAPINFO *)&bi6,
				DIB_RGB_COLORS); break; }
		case 7: {GetDIBits(hdc,
			hbmp7,
			0,
			(UINT)bmp7.bmHeight,
			lpbitmap7,
			(BITMAPINFO*)&bi7,
			DIB_RGB_COLORS);
			SetDIBitsToDevice(hdc,
				x,
				y,
				bi7.biWidth,
				bi7.biHeight,
				0,
				0,
				0,
				bi7.biHeight,
				lpbitmap7,
				(BITMAPINFO *)&bi7,
				DIB_RGB_COLORS); break; }
		case 8: {GetDIBits(hdc,
			hbmp8,
			0,
			(UINT)bmp8.bmHeight,
			lpbitmap8,
			(BITMAPINFO*)&bi8,
			DIB_RGB_COLORS);
			SetDIBitsToDevice(hdc,
				x,
				y,
				bi8.biWidth,
				bi8.biHeight,
				0,
				0,
				0,
				bi8.biHeight,
				lpbitmap8,
				(BITMAPINFO *)&bi8,
				DIB_RGB_COLORS); break; }
		case 9: {GetDIBits(hdc,
			hbmp9,
			0,
			(UINT)bmp9.bmHeight,
			lpbitmap9,
			(BITMAPINFO*)&bi9,
			DIB_RGB_COLORS);
			SetDIBitsToDevice(hdc,
				x,
				y,
				bi9.biWidth,
				bi9.biHeight,
				0,
				0,
				0,
				bi9.biHeight,
				lpbitmap9,
				(BITMAPINFO *)&bi9,
				DIB_RGB_COLORS); break; }
	}
	
	ReleaseDC(hWnd, hdc);

}

int swapup(int k)
{
    if(k/3<1) return 0;
    int temp;
    temp=g[k/3-1][k%3];
    g[k/3-1][k%3]=g[k/3][k%3];
    g[k/3][k%3]=temp;
    return 1;
}
int swapdown(int k)
{
    if(k/3>1) return 0;
    int temp;
    temp=g[k/3+1][k%3];
    g[k/3+1][k%3]=g[k/3][k%3];
    g[k/3][k%3]=temp;
    return 1;
}
int swapleft(int k)
{
    if(k%3<1) return 0;
    int temp;
    temp=g[k/3][k%3-1];
    g[k/3][k%3-1]=g[k/3][k%3];
    g[k/3][k%3]=temp;
    return 1;
}
int swapright(int k)
{
    if(k%3>1) return 0;
    int temp;
    temp=g[k/3][k%3+1];
    g[k/3][k%3+1]=g[k/3][k%3];
    g[k/3][k%3]=temp;
    return 1;
}

int check()
{
    for(int i=0;i<3;i++)
     for(int j=0;j<3;j++)
            if(g[i][j]!=i*3+j+1) return 0;

    return 1;
}

void print(HWND hWnd)
{
	HDC hdc = GetDC(hWnd);

	GetDIBits(hdc,
		hbmp11,
		0,
		(UINT)bmp11.bmHeight,
		lpbitmap11,
		(BITMAPINFO*)&bi11,
		DIB_RGB_COLORS);
	SetDIBitsToDevice(hdc,
		0,
		0,
		bi11.biWidth,
		bi11.biHeight,
		0,
		0,
		0,
		bi11.biHeight,
		lpbitmap11,
		(BITMAPINFO *)&bi11,
		DIB_RGB_COLORS);

	GetDIBits(hdc,
		hbmp10,
		0,
		(UINT)bmp10.bmHeight,
		lpbitmap10,
		(BITMAPINFO*)&bi10,
		DIB_RGB_COLORS);
	SetDIBitsToDevice(hdc,
		15,
		60,
		bi10.biWidth,
		bi10.biHeight,
		0,
		0,
		0,
		bi10.biHeight,
		lpbitmap10,
		(BITMAPINFO *)&bi10,
		DIB_RGB_COLORS);

	CString str;
	str.Format(_T("%d"), move);
	LOGFONT   logfont;       //改变输出字体
	ZeroMemory(&logfont, sizeof(LOGFONT));
	logfont.lfCharSet = GB2312_CHARSET;
	logfont.lfHeight = -40;      //设置字体的大小
	HFONT   hFont = CreateFontIndirect(&logfont);
	::SetTextColor(hdc, RGB(0, 0, 0));
	::SetBkColor(hdc, RGB(200, 200, 0));
	::SetBkMode(hdc, TRANSPARENT);
	SelectObject(hdc, hFont);




	TextOut(hdc, 100, 415, L"Move:" + str, str.GetLength() + 5);
	str.Format(_T("%d"), minm);
	TextOut(hdc, 30, 515, L"Min-Move:" + str, str.GetLength() + 9);
	ReleaseDC(hWnd, hdc);
	DeleteObject(hFont);

	
	if (check())
	{
		for (int i = 0; i<3; i++)
		{
			for (int j = 0; j < 3; j++)
				paintimg(hWnd, g[i][j], 345 + j * 201, 60 + i * 201);

		}
		minm = minm<move?minm:move;
		HDC hdc = GetDC(hWnd);
		LOGFONT   logfont;       //改变输出字体
		ZeroMemory(&logfont, sizeof(LOGFONT));
		logfont.lfCharSet = GB2312_CHARSET;
		logfont.lfHeight = -40;      //设置字体的大小
		logfont.lfWeight = 1000;
		HFONT   hFont = CreateFontIndirect(&logfont);
		::SetTextColor(hdc, RGB(255, 215, 0));
		::SetBkColor(hdc, RGB(200, 200, 0));
		::SetBkMode(hdc, TRANSPARENT);
		SelectObject(hdc, hFont);
		
		TextOut(hdc, 500, 300, L"Congratulation!", 15);
		ReleaseDC(hWnd, hdc);
		DeleteObject(hFont);
	}
		

	else
		for (int i = 0; i<3; i++)
		{
			for (int j = 0; j < 3; j++)
				if (g[i][j] != 9) paintimg(hWnd, g[i][j], 345 + j * 201, 60 + i * 201);

		}
}