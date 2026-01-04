
#include "portaudio.h"
#include <math.h>
#include <stdio.h>

struct dataPoint {
  float frequency;
  float amplitude;
};
class audioHandler {
public:
  dataPoint buffer[1024];
  audioHandler() = default;
  audioHandler(audioHandler &&) = default;
  audioHandler(const audioHandler &) = default;
  audioHandler &operator=(audioHandler &&) = default;
  audioHandler &operator=(const audioHandler &) = default;
  ~audioHandler() = default;

  int audioInputHandlerCallback(const void *inputBuffer, void *outputBuffer,
                                unsigned long framesPerBuffer,
                                const PaStreamCallbackTimeInfo *timeInfo,
                                PaStreamCallbackFlags statusFlags,
                                void *userData) {
    return 0;
  }

private:
};
