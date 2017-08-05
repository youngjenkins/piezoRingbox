/*
  Turns on LEDs & Buzzers when either of
  two switches, connected from pin #0 to GND,
  get pressed.

  To upload to Trinket:
  1) Have the sketch open in Arduino IDE,
  2) Disconnect anything on GPIO 3 & 4 (interferes with USB, 
      reconnect after upload completes)
  3) Select the proper board from the Tools->Board Menu
  4) Select USBtinyISP from the Tools->Programmer
  5) Plug in the Trinket thru a hub, make sure you see the green LED lit
  6) Press the button on the Trinket - verify you see
     the red LED pulse. This means it is ready to receive data
  7) Click the upload button in IDE within 10 seconds
*/

//you gotta define the GPIOs
#define SWITCH 0
#define SWITCH2 2
#define LED 3  //must unplug while uploading!
#define BUZZ 4 //must unplug while uploading!


// the setup routine runs once when you press reset:

void setup() {
  pinMode(BUZZ, OUTPUT);
  pinMode(LED, OUTPUT);
  // initialize the switch pins as inputs
  pinMode(SWITCH, INPUT);
  pinMode(SWITCH2, INPUT);
  // ...with a pullup (sets an initial state)
  digitalWrite(SWITCH, HIGH);
  digitalWrite(SWITCH2, HIGH);
}
 
// the loop routine runs over and over again forever:
void loop() {
  // if either button is pressed:
  if (! digitalRead(SWITCH)|| ! digitalRead(SWITCH2)) {
    digitalWrite(LED, HIGH); // light the LEDs
    beepSong(BUZZ);			 // and play songs
  }
  else {
    digitalWrite(LED, LOW); // otherwise, turn LED off
  }

}

/* the sound producing function, beep()
* by Dr. Leah Buechley, Sourced from: 
* https://learn.adafruit.com/trinket-gemma-mini-theramin-music-maker/code
* 
* About delayMicroseconds() : 
*   Pauses the program for the amount of time (in microseconds) 
*   specified as parameter. There are a thousand microseconds 
*   in a millisecond, and a million microseconds in a second.
*/ 

void beep (unsigned char speakerPin, int frequencyInHertz, long timeInMilliseconds)
{  
  int x;   
  long delayAmount = (long)(1000000/frequencyInHertz);
  long loopTime = (long)((timeInMilliseconds*1000)/(delayAmount*2));
  for (x=0;x<loopTime;x++)   
    {   
      digitalWrite(speakerPin,HIGH);
      delayMicroseconds(delayAmount); //pause program while tone plays
      digitalWrite(speakerPin,LOW);
      delayMicroseconds(delayAmount);
    }      
}
//freq in Hz; durations in milliseconds
//delay() takes args in milliseconds

void beepSong(char buzzPin){
  int arrayLengths = 32;

//frequencies
int fq[] = {1319, 1480, 1661, 1760, 1661, 1480, 1319, 1661,
 1480, 1319, 1175, 1480, 1319, 1175, 1109, 1319, 0, 1109, 988,
 880, 988, 1109, 1175, 988, 1109, 1175, 0, 1319, 1319, 1480,
 1661, 1480};

//durations
int duration[] = {226, 226, 226, 226, 226, 339, 113, 226,
 226, 339, 113, 226, 226, 113, 226, 452, 226, 113, 113, 226,
 226, 226, 226, 113, 226, 339, 113, 113, 226, 226, 113, 452};
  
  for(int i=0; i<arrayLengths; i++){
    if(fq[i]==0){          //when pitch==0 pause prgm
      delay(duration[i]);  //can't call beep with a 0 value bc division by 0
    }
    else{
      beep(buzzPin, fq[i], duration[i]);
    }
      
  }
}   //close beepSong

    