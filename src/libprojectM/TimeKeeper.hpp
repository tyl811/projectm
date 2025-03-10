#ifndef TimeKeeper_HPP
#define TimeKeeper_HPP

#ifndef WIN32
#include <sys/time.h>
#endif

#include "timer.h"

#define HARD_CUT_DELAY 3

class TimeKeeper
{

public:

  TimeKeeper(double presetDuration, double smoothDuration, double hardcutDuration, double easterEgg);

  void UpdateTimers();

  void StartPreset();
  void StartSmoothing();
  void EndSmoothing();
 
  bool CanHardCut();

  double SmoothRatio();
  bool IsSmoothing();

  double GetRunningTime(); 

  double PresetProgressA();
  double PresetProgressB();

  int PresetFrameA();
  int PresetFrameB();

  int PresetTimeA();
  int PresetTimeB();

  double sampledPresetDuration();

  void ChangeHardcutDuration(int seconds) { _hardcutDuration = seconds; }
  void ChangePresetDuration(int seconds) { _presetDuration = seconds; }
  void ChangeHardcutDuration(double seconds) { _hardcutDuration = seconds; }
  void ChangePresetDuration(double seconds) { _presetDuration = seconds; }

#ifndef WIN32
  /* The first ticks value of the application */
  struct timeval startTime;
#else  
  long startTime;
#endif /** !WIN32 */

private:

  double _easterEgg;
  double _presetDuration;
  double _presetDurationA;
  double _presetDurationB;
  double _smoothDuration;
  double _hardcutDuration;

  double _currentTime;
  double _presetTimeA;
  double _presetTimeB;
  int _presetFrameA;
  int _presetFrameB;

  bool _isSmoothing;
  

};
#endif
