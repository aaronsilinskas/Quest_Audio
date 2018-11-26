#include "Quest_Audio.h"

void Quest_Audio::begin(uint8_t sdPin)
{
  if (!SD.begin(sdPin))
  {
    Serial.println("SD initialization failed!");
    return;
  }
}

bool Quest_Audio::playSound(const char *filename, uint8_t volume)
{
  if (volume > 100)
  {
    volume = 100;
  }

  waveFile = SDWaveFile(filename);
  if (!waveFile)
  {
    Serial.print("wave file is invalid: ");
    Serial.println(filename);
    return false;
  }

  AudioOutI2S.volume(volume);

  if (!AudioOutI2S.canPlay(waveFile))
  {
    Serial.println("unable to play wave file using I2S!");
    return false;
  }

  Serial.print("starting playback: ");
  Serial.println(filename);
  if (AudioOutI2S.play(waveFile) == 0)
  {
    Serial.print("could not play: ");
    Serial.println(filename);
    return false;
  }

  Serial.print("playback started: ");
  Serial.println(filename);
  return true;
}

bool Quest_Audio::isPlaying()
{
  return AudioOutI2S.isPlaying();
}