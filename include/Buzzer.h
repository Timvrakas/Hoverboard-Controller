//
// This file is part of the GNU ARM Eclipse distribution.
// Copyright (c) 2014 Liviu Ionescu.
//

#ifndef BUZZER_H_
#define BUZZER_H_

int volume;
int i;

extern void enable(long freq);

extern void setTone(long freq, int newVolume);

extern void endTone(void);

#endif // TIMER_H_
