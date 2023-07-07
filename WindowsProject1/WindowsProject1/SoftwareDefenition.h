#pragma once


#define OnButtonClicked1 5
#define OnReadField1 6
#define OnReadField2 7

#define TermBufferSize  20  

#define DlgIndexNumber  200

char TBuffer[TermBufferSize];
unsigned num1;
unsigned num2;


HWND hEditControl;
HWND hStaticControl1;
HWND hStaticControl2;
HWND hStaticControl3;
HWND hNumberControl;
LRESULT CALLBACK SoftwareMainProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
WNDCLASS NewWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure);

void MainWndAddMenus(HWND hWnd);
void MainWndAddWidgets(HWND hWnd);
void MainWndAddWidgets2(HWND hWnd);
void MainWndAddWidgets3(HWND hWnd);
