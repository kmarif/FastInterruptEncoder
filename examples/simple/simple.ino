#include "FastInterruptEncoder.h"

Encoder enc(PA0, PA1, SINGLE /* or HALFQUAD or FULLQUAD */); // - Example for STM32, check datasheet for possible Timers for Encoder mode. TIM_CHANNEL_1 and TIM_CHANNEL_2 only
//Encoder enc(25, 26, SINGLE);  - Example for ESP32

unsigned long encodertimer = 0;

void setup() {
  Serial.begin(115200);
  
  if (enc.init()) {
    Serial.println("Encoder Initialization OK");
  } else {
    Serial.println("Encoder Initialization Failed");
    while(1);
  }

}

void loop() {
  enc.loop();                     //better to use with Timer Interrupt
                  
  if ((millis() > (encodertimer + 1000)) || (millis() < encodertimer)) {
    Serial.println(enc.getTicks());
    encodertimer = millis();
  }
}
