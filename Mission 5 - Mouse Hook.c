#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

HHOOK _hook;

MSLLHOOKSTRUCT msllStruct;
FILE *fArchivo;

LRESULT __stdcall HookCallback(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode >= 0)
	{
		if (wParam == WM_LBUTTONDOWN)
		{
			msllStruct = *((MSLLHOOKSTRUCT*)lParam);

			fprintf(fArchivo, "X: %d, Y: %d\n", msllStruct.pt.x, msllStruct.pt.y);
		}
	}

	fclose(fArchivo);
    fArchivo = fopen("posiciones.txt","a");

	return CallNextHookEx(_hook, nCode, wParam, lParam);
}

void SetHook()
{
	if (!(_hook = SetWindowsHookEx(WH_MOUSE_LL, HookCallback, NULL, 0)))
	{
		MessageBox(NULL, "Failed to install hook!", "Error", MB_ICONERROR);
	}
}

void ReleaseHook()
{
	UnhookWindowsHookEx(_hook);
}

void main()
{
	SetHook();
    fArchivo = fopen("posiciones.txt", "w");
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{

	}
}