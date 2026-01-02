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

private:
};
