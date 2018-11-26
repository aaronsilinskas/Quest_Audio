#ifndef quest_audio_h
#define quest_audio_h

#include <SD.h>
#include <ArduinoSound.h>

class Quest_Audio
{
  public:
    void begin(uint8_t sdPin);
    bool playSound(const char *filename, uint8_t volume);
    bool isPlaying();

  private:
    SDWaveFile waveFile;
};

#endif