#include <windows.h>
#include <wchar.h>

#define NOMINMAX
#pragma comment(lib, "user32.lib")

int
main(void) {
    int x = GetSystemMetrics(SM_CXSCREEN);
    int y = GetSystemMetrics(SM_CYSCREEN);
    wprintf(L"Size: %dx%d", x, y);
    MessageBox(0, "Blah Blah...", "My Windows App!", MB_SETFOREGROUND);
}
