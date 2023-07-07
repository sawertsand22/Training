#include <Windows.h>
#include "SoftwareDefenition.h"
#include <string.h>
#include <string>

int WINAPI WinMain(HINSTANCE hINst, HINSTANCE hPrevInst, LPSTR args, int ncmshow)
{
	WNDCLASS SoftwareMainClass = NewWindowClass((HBRUSH)COLOR_WINDOW, LoadCursor(NULL, IDC_ARROW), hINst, LoadIcon(NULL, IDI_QUESTION),
		L"MainWndClass", SoftwareMainProcedure);
	if (!RegisterClassW(&SoftwareMainClass)) { return -1; }
	MSG SofrwareMainMessage = { 0 };

	CreateWindow(L"MainWndClass", L"First C++ window ", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 500, 250, NULL, NULL, NULL, NULL);
	while (GetMessage(&SofrwareMainMessage, NULL, NULL, NULL)) {
		TranslateMessage(&SofrwareMainMessage);
		DispatchMessage(&SofrwareMainMessage);
	}
	return 0;

}

WNDCLASS NewWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure)
{
	WNDCLASS  NWC = { 0 };
	NWC.hIcon = Icon;
	NWC.hCursor = Cursor;
	NWC.hInstance = hInst;
	NWC.lpszClassName = Name;
	NWC.hbrBackground = BGColor;
	NWC.lpfnWndProc = Procedure;

	return NWC;
}

LRESULT CALLBACK SoftwareMainProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
	case WM_COMMAND:
		switch (wp)
		{

		case OnButtonClicked1:
			SetWindowTextA(hEditControl, "");
			//MessageBoxA(hWnd, "You are input 1st term", "1st term Saved", MB_OK);
			break;

		case OnReadField1:
			num1 = GetDlgItemInt(hWnd, DlgIndexNumber, NULL, false);
			SetWindowTextA(hStaticControl1, std::to_string(num1).c_str());
			EnableWindow(GetDlgItem(hWnd, OnReadField1), false);
			MainWndAddWidgets2(hWnd);
			
			

	 		break;

		case OnReadField2:
			num2 = GetDlgItemInt(hWnd, DlgIndexNumber, NULL, false);
			SetWindowTextA(hStaticControl2, std::to_string(num2).c_str());
			EnableWindow(GetDlgItem(hWnd, OnReadField2), false);
			EnableWindow(GetDlgItem(hWnd, DlgIndexNumber), false);
			MainWndAddWidgets3(hWnd);
			SetWindowTextA(hStaticControl3,std::to_string(num1 + num2).c_str());

			break;
		default:
			break;
		}
		break;

	case WM_CREATE:

		MainWndAddMenus(hWnd);
		MainWndAddWidgets(hWnd);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);   

	default: return DefWindowProc(hWnd, msg, wp, lp);
	}
}

void MainWndAddMenus(HWND  hWnd)
{
	HMENU RootMenu = CreateMenu();


	SetMenu(hWnd, RootMenu);
}

void MainWndAddWidgets(HWND hWnd)
{
	hStaticControl1 =CreateWindowA("static", "1st term", WS_VISIBLE | WS_CHILD | ES_CENTER, 5, 5, 480, 20, hWnd, NULL, NULL, NULL);
	CreateWindowA("static", "Input term,then click on button", WS_VISIBLE | WS_CHILD | ES_CENTER, 5, 85, 480, 20, hWnd, NULL, NULL, NULL);
	CreateWindowA("static", "sum: ", WS_VISIBLE | WS_CHILD | ES_CENTER, 5, 105, 480, 20, hWnd, NULL, NULL, NULL);
	CreateWindowA("button", "term1", WS_VISIBLE | WS_CHILD, 5, 5, 120, 30, hWnd, (HMENU)OnReadField1, NULL, NULL);
	

	hNumberControl = CreateWindowA("edit", "0", WS_VISIBLE | WS_CHILD | ES_NUMBER, 5, 120, 120, 30, hWnd, (HMENU)DlgIndexNumber, NULL, NULL);


} 


void MainWndAddWidgets2(HWND hWnd)
{
	CreateWindowA("button", "term2", WS_VISIBLE | WS_CHILD, 5, 45, 120, 30, hWnd, (HMENU)OnReadField2, NULL, NULL);
	hStaticControl2 = CreateWindowA("static", "2nd term", WS_VISIBLE | WS_CHILD | ES_CENTER, 205, 45, 80, 20, hWnd, NULL, NULL, NULL);
}

void MainWndAddWidgets3(HWND hWnd)
{
	hStaticControl3=CreateWindowA("static", "sum", WS_VISIBLE | WS_CHILD|ES_CENTER,150, 120, 220, 30, hWnd, (HMENU)OnReadField1 + OnReadField2, NULL, NULL);
}

