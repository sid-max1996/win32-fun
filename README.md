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
  // set volume
  win32Fun.setVolume(30); // 0 - 100
```
