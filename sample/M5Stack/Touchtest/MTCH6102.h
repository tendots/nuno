
#ifndef MTCH6102_H
#define MTCH6102_H

#if (ARDUINO >= 100)
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include <Wire.h>

// The default I2C address
#define MTCH6102_I2CADDR_DEFAULT   0x25

#define MTCH6102_CMD                    0x04
#define MTCH6102_MODE                   0x05
#define MTCH6102_MODE_TOUCH   0x02
#define MTCH6102_MODE_FULL    0x03
#define MTCH6102_MODE_GESTURE 0x01
#define MTCH6102_MODE_RAW     0x40
#define MTCH6102_MODE_STANDBY 0x00
#define MTCH6102_MODECON                0x06

#define MTCH6102_TOUCHSTATE             0x10
#define MTCH6102_TOUCHX                 0x11
#define MTCH6102_TOUCHY                 0x12
#define MTCH6102_TOUCHLSB               0x13
#define MTCH6102_GESTURESTATE           0x14
#define MTCH6102_GESTUREDIAG            0x15

#define MTCH6102_NUMBEROFXCHANNELS        0x20
#define MTCH6102_NUMBEROFYCHANNELS        0x21
#define MTCH6102_SCANCONUT                0x06  //0x06
#define MTCH6102_TOUCHTHRESHX             0x37  //0x37
#define MTCH6102_TOUCHTHRESHY             0x28  //0x28
#define MTCH6102_ACTIVEPERIODL            0x85  //0x85
#define MTCH6102_ACTIVEPERIODH            0x02  //0x02
#define MTCH6102_IDLEPERIODL              0x4C  //0x4C
#define MTCH6102_IDLEPERIODH              0x06  //0x06
#define MTCH6102_IDLETIMEOUT              0x10  //0x10
#define MTCH6102_HYSTERESIS               0x04  //0x04
#define MTCH6102_DEBOUNCEUP               0x01  //0x01
#define MTCH6102_DEBOUNCEDOWN             0x01  //0x01
#define MTCH6102_BASEINTERVALL     　     0  //10
#define MTCH6102_BASEINTERVALH            0  //0
#define MTCH6102_BASEPOSFILTER            20  //20
#define MTCH6102_BASENEGAFILTER           20  //20
#define MTCH6102_FILTERTYPE               2  //2
#define MTCH6102_FILTERSTRENGTH           1  //1
#define MTCH6102_BASEFILTERTYPE           2  //2
#define MTCH6102_BASEFILTERSTRENGTH       1  //1
#define MTCH6102_LARGEACTIVATIONTHRESHL   0  //0
#define MTCH6102_LARGEACTIVATIONTHRESHH   0  //0
#define MTCH6102_HORIZONTALSWIPEDISTANCE  0x49  //0x40
#define MTCH6102_VERTICALSWIPEDISTANCE    0x40  //0x40
#define MTCH6102_SWIPEHOLDBOUNDARY        0x19  //0x19
#define MTCH6102_TAPDISTANCE              0x19  //0x19
#define MTCH6102_DISTANCEBETWEENTAPS      0x40  //0x40
#define MTCH6102_TAPHOLDTIMEL             0x32  //0x32
#define MTCH6102_TAPHOLDTIMEH             0x00  //0x00
#define MTCH6102_GESTURECLICKTIME         0x0C  //0x0C
#define MTCH6102_SWIPEHOLDTHRESH          0x20  //0x20
#define MTCH6102_MINSWIPEVELOCITY         0x04  //0x04
#define MTCH6102_HORIZONTALGESTUREANGLE   0x2D  //0x2D
#define MTCH6102_VERTICALGESTUREANGLE     0x2D  //0x2D
#define MTCH6102_I2CADDR                  0x25  //0x25
#define MTCH6102_SENSORVALUE_RX0   0x80
#define MTCH6102_SENSORVALUE_RX1   0x81
#define MTCH6102_SENSORVALUE_RX2   0x82
#define MTCH6102_SENSORVALUE_RX3   0x83
#define MTCH6102_SENSORVALUE_RX4   0x84
#define MTCH6102_SENSORVALUE_RX5   0x85
#define MTCH6102_SENSORVALUE_RX6   0x86
#define MTCH6102_SENSORVALUE_RX7   0x87
#define MTCH6102_SENSORVALUE_RX8   0x88
#define MTCH6102_SENSORVALUE_RX9   0x89
#define MTCH6102_SENSORVALUE_RX10  0x8A
#define MTCH6102_SENSORVALUE_RX11  0x8B
#define MTCH6102_SENSORVALUE_RX12  0x8C
#define MTCH6102_SENSORVALUE_RX13  0x8D
#define MTCH6102_SENSORVALUE_RX14  0x8E

class MTCH6102 {
  public:

    MTCH6102(void);
    boolean begin(uint8_t i2caddr = MTCH6102_I2CADDR_DEFAULT);
    uint8_t readRegister(uint8_t reg);
    void writeRegister(uint8_t reg, uint8_t value);
    void setMode(uint8_t mode);

  private:
    int8_t _i2caddr;
};

#endif // MTCH6102_H
