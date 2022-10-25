

#ifndef     __SPEAKER_HAL
#define     __SPEAKER_HAL

//---------------------------------

#include <Arduino.h>

//------------------------------------

 class speaker_hal{

    

public:

//constructor
    speaker_hal(uint8_t softPinValue, uint8_t logicOnValue, int8_t loudPinValue);

        /**
         * @brief if only one volume - leave loud tone at -1 and just supply the
         *  value for the soft tone
         * 
         * @param softPinValue 
         * @param logicOnValue 
         * @param loudPinValue 
         */
        void begin(void);

        /**
         * @brief this is a blocking function
         * 
         * @param period  sound the buzzer at the period. Frequency = 1/period
         * @param time_ms total time to sound in milliSeconds
         * @param loudTone if set use the loud tone (if available)
         */
        void on(uint32_t period_us, uint32_t time_ms, bool loudTone );


private:


    uint8_t _pinSoft;
    int8_t _pinLoud = -1;
    uint8_t _logicOn;

        bool pinState=0;

    void _spkOff(bool loudPin);
    void _spkOn(bool loudPin);

 }; 
//---------------------------------
#endif