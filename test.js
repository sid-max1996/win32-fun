const win32Fun = require('./index')

async function start() {
  const { free, total, available } = await win32Fun.getDiskSpace('c:')
  console.log('free', free, 'total', total, 'available', available)
}

start()

win32Fun.turnOffMonitor()

setTimeout(() => {
  win32Fun.turnOnMonitor()
}, 10000)

