#include <stdio.h>
#include <windows.h>
#include <mmdeviceapi.h>
#include <endpointvolume.h>
#include <math.h>

IAudioEndpointVolume* getVolume(int mic){
  HRESULT hr;
  IMMDeviceEnumerator *enumerator = NULL;
  IAudioEndpointVolume *volume = NULL;
  IMMDevice *defaultDevice = NULL;
  CoInitialize(NULL);
  hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER, __uuidof(IMMDeviceEnumerator), (LPVOID *) &enumerator);
  hr = enumerator->GetDefaultAudioEndpoint(mic ? eCapture : eRender, eConsole, &defaultDevice);
  if (hr != 0) {
    return volume;
  }
  hr = defaultDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_INPROC_SERVER, NULL, (LPVOID *) &volume);
  enumerator->Release();
  defaultDevice->Release();
  CoUninitialize();
  return volume;
}

void SetVolume(float newVolume) {
  newVolume = newVolume / 100.0f;
  printf("SetVolume %.6f", newVolume);
  IAudioEndpointVolume *temp_volume = NULL;
  temp_volume = getVolume(0);

  if (temp_volume == NULL) {
    return;
  }

  temp_volume->SetMasterVolumeLevelScalar(newVolume, NULL);
}
