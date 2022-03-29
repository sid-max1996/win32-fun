# Win32 Fun

## Usage
disk memory information,
put the monitor into sleep mode,
wake up the monitor, set volume

```javascript
  const win32Fun = require('win32-fun');
  // retrieving disk memory information
  const { free, total, available } = await win32Fun.getDiskSpace('c:');
  const { free, total, available } = win32Fun.getDiskSpaceSync('c:');
  // put the monitor into sleep mode
  win32Fun.turnOffMonitor();
  // wake up the monitor
  win32Fun.turnOnMonitor();
  // prevent system lock screen
  win32Fun.preventLockScreen();
  // set volume
  win32Fun.setVolume(30); // 0 - 100
```

## Screen sleep example
```javascript
let running = true

async function screenWakeUpAfter(timeout) {
  setTimeout(() => {
    running = false
  }, timeout)
}

async function screenSleep() {
  while (running) {
    console.log('turn off monitor')
    win32Fun.turnOffMonitor()
    win32Fun.preventLockScreen()
    await (new Promise(resolve => setTimeout(() => resolve(), 5000)))
  }
  console.log('turn on monitor')
  win32Fun.turnOnMonitor()
}

screenSleep()
screenWakeUpAfter(30000)
```
