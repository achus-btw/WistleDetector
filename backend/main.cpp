
#include "portaudio.h"
#include <math.h>
#include <stdio.h>

#ifdef WIN32
#include <windows.h>

#if PA_USE_ASIO
#include "pa_asio.h"
#endif
#endif

/*******************************************************************/
static void
PrintSupportedStandardSampleRates(const PaStreamParameters *inputParameters,
                                  const PaStreamParameters *outputParameters) {
  static double standardSampleRates[] =
      {
          8000.0,  9600.0,  11025.0,  12000.0, 16000.0,
          22050.0, 24000.0, 32000.0,  44100.0, 48000.0,
          88200.0, 96000.0, 192000.0, -1 /* negative terminated  list */
      };
  int i, printCount;
  PaError err;

  printCount = 0;
  for (i = 0; standardSampleRates[i] > 0; i++) {
    err = Pa_IsFormatSupported(inputParameters, outputParameters,
                               standardSampleRates[i]);
    if (err == paFormatIsSupported) {
      if (printCount == 0) {
        printf("\t%8.2f", standardSampleRates[i]);
        printCount = 1;
      } else if (printCount == 4) {
        printf(",\n\t%8.2f", standardSampleRates[i]);
        printCount = 1;
      } else {
        printf(", %8.2f", standardSampleRates[i]);
        ++printCount;
      }
    }
  }
  if (!printCount)
    printf("None\n");
  else
    printf("\n");
}

/*******************************************************************/
int main(void);
int main(void) {
  int i, numDevices, defaultDisplayed;
  const PaDeviceInfo *deviceInfo;
  PaStreamParameters inputParameters, outputParameters;
  PaError err;

  err = Pa_Initialize();
  if (err != paNoError) {
    printf("ERROR: Pa_Initialize returned 0x%x\n", err);
    goto error;
  }

  printf("PortAudio version: 0x%08X\n", Pa_GetVersion());
  printf("Version text: '%s'\n", Pa_GetVersionInfo()->versionText);

  numDevices = Pa_GetDeviceCount();
  if (numDevices < 0) {
    printf("ERROR: Pa_GetDeviceCount returned 0x%x\n", numDevices);
    err = numDevices;
    goto error;
  }

  printf("Number of devices = %d\n", numDevices);
  for (i = 0; i < numDevices; i++) {
    deviceInfo = Pa_GetDeviceInfo(i);
  }

  Pa_Terminate();

  printf("----------------------------------------------\n");
  return 0;

error:
  Pa_Terminate();
  fprintf(stderr, "Error number: %d\n", err);
  fprintf(stderr, "Error message: %s\n", Pa_GetErrorText(err));
  return err;
}
