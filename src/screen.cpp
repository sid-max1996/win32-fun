#include "screen.h"
#include <Windows.h>

void ScreenSleep() {
  // HWND_BROADCAST intead GetConsoleWindow() works too
  SendMessage(GetConsoleWindow(), WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)2);
}

void ScreenWakeUp () {
  mouse_event(1, 0, 1, 0, 0);
}

void PreventLockScreen() {
  SetThreadExecutionState(ES_CONTINUOUS | ES_DISPLAY_REQUIRED | ES_SYSTEM_REQUIRED | ES_AWAYMODE_REQUIRED);
}
