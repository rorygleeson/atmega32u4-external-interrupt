"# atmega32u4-external-interrupt" 



Simple working code, running on Adafruit Lora Feather board, which has 32u4. INT0 is used, this is pin labled 3 on the feather board.
Tie it high, then apply power. First led flashes 3 times..then device goes to sleep. Remove wire from pin 3 (High to LOW) to give the low interrupt required. Then the device will wake up and flash the led 5 times. 

Handy to know for sure if sleep mode is working, since the feather device will loose USB comms after it goes to sleep, serial debugging will not resume. So using the on board LED is a way to know it working. 

