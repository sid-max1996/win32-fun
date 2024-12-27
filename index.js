// const native = require('./build/Release/win32-fun.node')

// Will load a compiled build if present or a prebuild.
// If no build if found it will throw an exception
const native = require("node-gyp-build")(__dirname);

// getMemory and getMemorySync
function check(path, callback) {
  var result = undefined;
  var error = undefined;

  try {
    result = native.getDiskUsage(path);
  } catch (error_) {
    error = error_;
  }

  if (callback) {
    callback(error, result);
  }
}

exports.getDiskSpace = function (path, callback) {
  if (callback) {
    return check(path, callback);
  }

  return new Promise((resolve, reject) => {
    check(path, (err, result) => {
      err ? reject(err) : resolve(result);
    });
  });
};

exports.getDiskSpaceSync = native.getDiskUsage;
exports.turnOffMonitor = native.screenSleep;
exports.turnOnMonitor = native.screenWakeUp;
exports.preventLockScreen = native.preventLockScreen;
exports.setVolume = native.setVolume;
