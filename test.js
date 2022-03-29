const win32Fun = require('./index')

/******* Test check space ********/

// async function checkSpace() {
//   const { free, total, available } = await win32Fun.getDiskSpace('c:')
//   console.log('free', free, 'total', total, 'available', available)
// }

// checkSpace()

/******* Test screen sleep ********/

// let running = true

// async function screenWakeUpAfter(timeout) {
//   setTimeout(() => {
//     running = false
//   }, timeout)
// }

// async function screenSleep() {
//   while (running) {
//     console.log('turn off monitor')
//     win32Fun.turnOffMonitor()
//     win32Fun.preventLockScreen()
//     await (new Promise(resolve => setTimeout(() => resolve(), 5000)))
//   }
//   console.log('turn on monitor')
//   win32Fun.turnOnMonitor()
// }

// screenSleep()
// screenWakeUpAfter(30000)

/******* Test set volume ********/

// win32Fun.setVolume(30)

