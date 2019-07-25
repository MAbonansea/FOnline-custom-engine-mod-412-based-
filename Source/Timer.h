#ifndef __TIMER__
#define __TIMER__

struct DateTime
{
    ushort Year;         // 1601 .. 30827
    ushort Month;        // 1 .. 12
    ushort DayOfWeek;    // 0 .. 6
    ushort Day;          // 1 .. 31
    ushort Hour;         // 0 .. 23
    ushort Minute;       // 0 .. 59
    ushort Second;       // 0 .. 59
    ushort Milliseconds; // 0 .. 999
};

namespace Timer
{
    void Init();
    void Finish();

    uint   FastTick();
    double AccurateTick();

    uint GameTick();
    void SetGamePause( bool pause );
    bool IsGamePaused();

    void StartAccelerator( int num );
    bool ProcessAccelerator( int num );
    int  GetAcceleratorNum();

    void GetCurrentDateTime( DateTime& dt );
    void DateTimeToFullTime( const DateTime& dt, uint64& ft );
    void FullTimeToDateTime( uint64 ft, DateTime& dt );
    int  GetTimeDifference( const DateTime& dt1, const DateTime& dt2 );
    void ContinueTime( DateTime& dt, int seconds );

    // Game time
    uint     GetFullSecond( ushort year, ushort month, ushort day, ushort hour, ushort minute, ushort second );
    DateTime GetGameTime( uint full_second );
    uint     GameTimeMonthDay( ushort year, ushort month );
    void     ProcessGameTime();
};

#endif // __TIMER__
