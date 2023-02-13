#include "../include/date.h"

unsigned int diffdays(struct tm start, struct tm end)
{
    /**
     * Calculate the different days between two calendar day
     */
    time_t x, y;
    double difference;
    start.tm_hour = 0;
    start.tm_min = 0;
    start.tm_sec = 0;
    start.tm_year = start.tm_year - 1900;
    end.tm_hour = 0;
    end.tm_min = 0;
    end.tm_sec = 0;
    end.tm_year = end.tm_year - 1900;
    x = mktime(&start);
    y = mktime(&end);
    if (x != (time_t)(-1) && y != (time_t)(-1))
    {
        difference = difftime(y, x) / (60 * 60 * 24);
    }
    return ((int)difference + 1);
}

unsigned int diffmonths(struct tm start, struct tm end)
{
    /**
     * Calculate the different months between two calendar day
     */
    time_t x, y;
    double difference;
      start.tm_hour = 0;
    start.tm_min = 0;
    start.tm_sec = 0;
    start.tm_year = start.tm_year - 1900;
    end.tm_hour = 0;
    end.tm_min = 0;
    end.tm_sec = 0;
    end.tm_year = end.tm_year - 1900;
    x = mktime(&start);
    y = mktime(&end);
    if (x != (time_t)(-1) && y != (time_t)(-1))
    {
        difference = difftime(y, x) / (60 * 60 * 24 * 30);
    }
    return ((int)difference + 1);
}
