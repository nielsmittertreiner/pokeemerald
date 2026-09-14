#include "global.h"
#include "time.h"
#include "string_util.h"
#include "strings.h"
#include "text.h"

const u8 *const sText_DaysOfWeek[] =
{
    gText_Monday,
    gText_Tuesday,
    gText_Wednesday,
    gText_Thursday,
    gText_Friday,
    gText_Saturday,
    gText_Sunday,
};

EWRAM_DATA static u8 sInGameTimeFrameCounter = 0;

void InitInGameTime(s8 dayOfWeek, s8 hour, s8 minute)
{
    gSaveBlock2Ptr->time.days = dayOfWeek;
    gSaveBlock2Ptr->time.hours = hour;
    gSaveBlock2Ptr->time.minutes = minute;
}

void UpdateInGameTime(void)
{
    sInGameTimeFrameCounter++;

    if (sInGameTimeFrameCounter < 60)
        return;

    sInGameTimeFrameCounter = 0;
    gSaveBlock2Ptr->time.seconds++;

    if (gSaveBlock2Ptr->time.seconds < INGAME_SECS_PER_MIN)
        return;

    gSaveBlock2Ptr->time.seconds = 0;
    gSaveBlock2Ptr->time.minutes++;

    if (gSaveBlock2Ptr->time.minutes < INGAME_MINS_PER_HR)
        return;

    gSaveBlock2Ptr->time.minutes = 0;
    gSaveBlock2Ptr->time.hours++;

    if (gSaveBlock2Ptr->time.hours < INGAME_HRS_PER_DAY)
        return;

    gSaveBlock2Ptr->time.hours = 0;
    gSaveBlock2Ptr->time.days++;
}

void FormatDecimalTimeWithoutSeconds(u8 *dest, s8 hour, s8 minute, u16 clockMode)
{
    switch (clockMode)
    {
    case OPTIONS_CLOCK_12H:
        if (hour < 13)
            dest = ConvertIntToDecimalStringN(dest, hour, STR_CONV_MODE_LEADING_ZEROS, 2);
        else
            dest = ConvertIntToDecimalStringN(dest, hour - 12, STR_CONV_MODE_LEADING_ZEROS, 2);

        *dest++ = CHAR_COLON;
        dest = ConvertIntToDecimalStringN(dest, minute, STR_CONV_MODE_LEADING_ZEROS, 2);

        if (hour < 13)
            dest = StringAppend(dest, gText_AM);
        else
            dest = StringAppend(dest, gText_PM);
        break;
    case OPTIONS_CLOCK_24H:
        dest = ConvertIntToDecimalStringN(dest, hour, STR_CONV_MODE_LEADING_ZEROS, 2);
        *dest++ = CHAR_COLON;
        dest = ConvertIntToDecimalStringN(dest, minute, STR_CONV_MODE_LEADING_ZEROS, 2);
        break;
    }

    *dest = EOS;
}

const u8 *GetDayOfWeekString(s16 day)
{
    u8 dayOfWeek = day % 7;
    return sText_DaysOfWeek[dayOfWeek];
}
