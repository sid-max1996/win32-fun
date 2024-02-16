#include "screen.h"
#include <Windows.h>

void ScreenSleep() {
  SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)2);
}

void ScreenWakeUp () {
  mouse_event(1, 0, 1, 0, 0);
}

void PreventLockScreen() {
  SetThreadExecutionState(ES_CONTINUOUS | ES_SYSTEM_REQUIRED | ES_DISPLAY_REQUIRED);
}
