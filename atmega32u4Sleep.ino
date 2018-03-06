#include <avr/sleep.h>
#include <avr/power.h>


int pin2 = 2;

/***************************************************
 *  Name:        pin2Interrupt
 *
 *  Returns:     Nothing.
 *
 *  Parameters:  None.
 *
 *  Description: Service routine for pin2 interrupt  
 *
 ***************************************************/
void pin2Interrupt(void)
{
  /* This will bring us back from sleep. */
  
  /* We detach the interrupt to stop it from 
   * continuously firing while the interrupt pin
   * is low.
   */
  detachInterrupt(0);
}


/***************************************************
 *  Name:        enterSleep
 *
 *  Returns:     Nothing.
 *
 *  Parameters:  None.
 *
 *  Description: Enters the arduino into sleep mode.
 *
 ***************************************************/
void enterSleep(void)
{
  
  /* Setup pin2 as an interrupt and attach handler. */
  attachInterrupt(0, pin2Interrupt, LOW);
  delay(100);
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  sleep_mode();
  /* The program will continue from here. */
   
  /* First thing to do is disable sleep. */
  sleep_disable(); 
   /* flash led 5 times . */
  flashLed5();
}


/***************************************************
 *  Name:        setup
 *
 *  Returns:     Nothing.
 *
 *  Parameters:  None.
 *
 *  Description: Setup for the Arduino.           
 *
 ***************************************************/
void setup()
{
  Serial.begin(9600);
  
  /* Setup the pin direction. */
  pinMode(pin2, INPUT);
  pinMode(13,OUTPUT); 
  
  Serial.println("Need to wait for PIR to settle, wait 60s then flash 3 times led.");
  delay(60000);
  flashLed3();
  
  
}



/***************************************************
 *  Name:        loop
 *
 *  Returns:     Nothing.
 *
 *  Parameters:  None.
 *
 *  Description: Main application loop.
 *
 ***************************************************/
int seconds=0;
void loop()
{
  delay(1000);
  seconds++;
  
  Serial.print("Awake for ");
  Serial.print(seconds, DEC);
  Serial.println(" second");
  
  if(seconds == 3)
  {
    Serial.println("Entering sleep");
    delay(200);
    seconds = 0;
    enterSleep();
    
  }

    
    
}









/***************************************************
 *  Name:        flashLed
 *
 *  Returns:     Nothing.
 *
 *  Parameters:  None.
 *
 *  Description: flashed onboard led p13 3 times
 *
 ***************************************************/
void flashLed3(void)
{
  Serial.println("Flash led.");
  
  digitalWrite(13,HIGH); 
  delay(500);
  digitalWrite(13,LOW); 
  delay(500);
  digitalWrite(13,HIGH); 
  delay(500);
  digitalWrite(13,LOW); 
  delay(500);
  digitalWrite(13,HIGH); 
  delay(500);
  digitalWrite(13,LOW); 
  
}


void flashLed5(void)
{
  Serial.println("Flash led.");
  
  digitalWrite(13,HIGH); 
  delay(500);
  digitalWrite(13,LOW); 
  delay(500);
  digitalWrite(13,HIGH); 
  delay(500);
  digitalWrite(13,LOW); 
  delay(500);
  digitalWrite(13,HIGH); 
  delay(500);
  digitalWrite(13,LOW); 
  delay(500);
  digitalWrite(13,HIGH); 
  delay(500);
  digitalWrite(13,LOW); 
  delay(500);
  digitalWrite(13,HIGH); 
  delay(500);
  digitalWrite(13,LOW);
}
