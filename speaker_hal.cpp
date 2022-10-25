
#include "speaker_hal.h"

//constructor
speaker_hal:: speaker_hal(uint8_t softPinValue, uint8_t logicOnValue, int8_t loudPinValue = -1){
 _pinLoud = loudPinValue;
    _pinSoft = softPinValue;
    _logicOn = logicOnValue; 

}
//------------------------------


/**
 * @brief if only one volume - leave loud tone at -1 and just supply the
 *  value for the soft tone
 * 
 * @param softPinValue  pin value for soft tone
 * @param logicOnValue  logic state when on
 * @param loudPinValue  pin value for lound tone do not supply parameter if only one
 *                  connection to the speaker
 */
void speaker_hal:: begin(void){


   

    pinMode(_pinSoft, OUTPUT);


    if(_pinLoud != -1)
    {

        pinMode(_pinLoud, OUTPUT);


    }

pinState = 0;


}       //end function
//----------------------------------

/**
 * @brief this is a blocking function if the loud tone is supplied as true, but the
 *  loudPin value was not supplied, the soft tone pin value will be used
 * 
 * @param period  sound the buzzer at the period. Frequency = 1/period
 * @param time_ms total time to sound in milliSeconds
 * @param loudTone if set use the loud tone (if available)
 */
void speaker_hal:: on(uint32_t period_us, uint32_t time_ms, bool loudTone = 0 ){


uint32_t timing, periodTiming;

timing = millis();
periodTiming = micros();


while((millis()-timing < time_ms)){



    if((micros()-periodTiming)>period_us)
    {
        if(pinState == 1)
        {
            _spkOff(loudTone);
        }
        else
        {
            _spkOn(loudTone);
        }

        periodTiming = micros();


    }

    delay(0);


}


_spkOff(loudTone);

}       //end function
//-----------------------------

void speaker_hal::_spkOff(bool loud_pin){



//if the loud pin exists
if((loud_pin==1) && (_pinLoud != -1))
{

    digitalWrite(_pinLoud, 0); //~_logicOn);
}
else
{
    digitalWrite(_pinSoft, 0);
}

pinState = 0;

}      //end function
//-----------------------------

void speaker_hal::_spkOn(bool loud_pin){

//if the loud pin exists
if((loud_pin==1) && (_pinLoud != -1))
{

    digitalWrite(_pinLoud, _logicOn);
}
else
{
    digitalWrite(_pinSoft, _logicOn);

}

pinState = 1;

}     //end function
//-----------------------------
