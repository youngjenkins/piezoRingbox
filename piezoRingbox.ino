/*
  Turns on LEDs & Buzzers when either of
  two switches, connected from pin #0 to GND,
  get pressed.

  July 2017
*/

#define SWITCH 0
#define SWITCH2 2
#define LED 3  //must unplug while uploading!
#define BUZZ 4 //must unplug while uploading!


void setup() {
  pinMode(BUZZ, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(SWITCH, INPUT);
  pinMode(SWITCH2, INPUT);
  digitalWrite(SWITCH, HIGH);
  digitalWrite(SWITCH2, HIGH);
}

void loop() {

  if (! digitalRead(SWITCH)|| ! digitalRead(SWITCH2)) {
    digitalWrite(LED, HIGH); 
    beepSong(BUZZ);	
  }
  else {
    digitalWrite(LED, LOW);
  }
}

/* the sound producing function, beep()
* by Dr. Leah Buechley, Sourced from: 
* https://learn.adafruit.com/trinket-gemma-mini-theramin-music-maker/code
*/ 

void beep (unsigned char speakerPin, int frequencyInHertz, long timeInMilliseconds)
{  
  int x;   
  long delayAmount = (long)(1000000/frequencyInHertz);
  long loopTime = (long)((timeInMilliseconds*1000)/(delayAmount*2));
  for (x=0;x<loopTime;x++)   
    {   
      digitalWrite(speakerPin,HIGH);
      delayMicroseconds(delayAmount);
      digitalWrite(speakerPin,LOW);
      delayMicroseconds(delayAmount);
    }      
}


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
    if(fq[i]==0){          // when pitch==0 pause prgm
      delay(duration[i]);  // unless you want to divide by 0
    }
    else{
      beep(buzzPin, fq[i], duration[i]);
    }
      
  }
}

    