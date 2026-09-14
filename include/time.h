#ifndef GUARD_TIME_H
#define GUARD_TIME_H

#define INGAME_SECS_PER_MIN 6
#define INGAME_MINS_PER_HR 60
#define INGAME_HRS_PER_DAY 24

void InitInGameTime(s8 dayOfWeek, s8 hour, s8 minute);
void UpdateInGameTime(void);
void FormatDecimalTimeWithoutSeconds(u8 *dest, s8 hour, s8 minute, u16 clockMode);
const u8 *GetDayOfWeekString(s16 day);

#endif // GUARD_TIME_H