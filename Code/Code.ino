#include <IRremote.h>
#include <IRremoteInt.h>

/* ON    1==  3792343877  */
/*       2 == 943552219   */
/*       3 == 1696584147  */
/* OFF   4 == 1023205609  */


#include <IRremote.h>


int zero_crossing_detect = 7;     //initialising zero crossing pin
int RECV_PIN2 = 2;                //initialising ir receiver pin
IRrecv irrecv2(RECV_PIN2);
int led = 9;                     //initialising gate trigger pin
decode_results results2;

void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(zero_crossing_detect,INPUT);
  irrecv2.enableIRIn();        // Start the receiver
}

void loop() {
  int buttonState=digitalRead(zero_crossing_detect);
  if (irrecv2.decode(&results2)) {

    delay(100);
    irrecv2.resume(); 
      
      if(results2.value == 3792343877){                  // Turn the bulb high

        digitalWrite(led,HIGH);
        
       
     Serial.println(results2.value);
      }
      else if((results2.value == 943552219)){           //dim the bulb
        if((buttonState==0)){
        while(results2.value == 943552219){
       delayMicroseconds(32);
       digitalWrite(led,HIGH);
       //delayMicroseconds(4);
       digitalWrite(led,LOW);
       //delay(200);

       
        Serial.println(results2.value);

         
        if(irrecv2.decode(&results2)){
         // delay(100);
          irrecv2.resume();
          }
          else{
            continue;
            
            }
        
        }
        
      }
        }

         else if((results2.value == 1696584147)||(buttonState==0)){      // dim the bulb
         while(results2.value == 1696584147){
        delay(30);
        digitalWrite(led,HIGH);
        //delay(10);
        digitalWrite(led,LOW);
        //delay(500);
        Serial.println(results2.value);
        
        if(irrecv2.decode(&results2)){
         // delay(100);
          irrecv2.resume();
          }
          else{
           continue;
            
            }
        
        }
         }
    else if((results2.value == 1023205609)){                // turn the bulb off
        
        
        digitalWrite(led,LOW);
        delay(10);
        Serial.println(results2.value);
        
        
        
        }
  }  
}
