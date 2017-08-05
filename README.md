# piezoRingbox
Playing RTTTL ringtones through a piezo buzzer / Trinket &amp; Arduino IDE

---------------------------------
Background of this Project: 
---------------------------------
I built a house "intercom" from two old landline telephones: one ancient rotary Stromberg-Carlson, and one newer push-button model. That's a pretty simple project, mostly involving putting a 9V battery and 330-ohm resistor in series with the RJ-11 cable that connects both phones. With this fun setup, we don't need to shout at each other from different floors in the house.

So, now I have one phone upstairs and one downstairs, but how do you let the person on the other end know that you want them to pick up the phone?
I didn't have parts handy for a traditional ring-down module (see note), so I faked it with a Trinket, piezo buzzers, and momentary switches (and LEDs because heck yeah blinkenlights). Anyway, everyone likes to push a button and cause magic ^_^

Note: Ring-down module: would cause one phone to ring, using its built-in ringer, when the other is taken off the reciever. 

---------------------------------
About the Piezo Ringbox:
---------------------------------
Along the way, I learned that the arduino tone() function isn't supported on Trinket, as noted below:

*"Note: The Arduino tone library does not work for the ATTiny85 on the
Trinket and Gemma.  The beep function below is similar.  The beep code
is adapted from Dr. Leah Buechley at http://web.media.mit.edu/~leah/LilyPad/07_sound_code.html"*
Note: that MIT page 404s.
Sources:
https://learn.adafruit.com/trinket-gemma-mini-theramin-music-maker/code
https://forums.adafruit.com/viewtopic.php?f=52&t=89990&p=453219&hilit=tone+arduino+function#p453219



To adapt beep() to play a series of frequencies at differing durations, I used two arrays passed to beep() via a For loop. One array holds the frequences of the notes to be played, the other holds the durations in milliseconds. 

For music sources, I looked at old RTTTL ringtone files, and translated them into sets of frequencies / durations. For funsies, I started writing a python translation program to automate this tedious process. Will post that when it's ready.
Reference & External link to RTTTL files: https://en.wikipedia.org/wiki/Ring_Tone_Transfer_Language

So now, when one of the buttons at either phone gets pressed, the buzzers on both ends play out a song to signal that there's someone who wants to talk to you on the phone!

The code is built around using just one or two songs for the moment, because that suited the project's needs. If I get the python RTTTL translator going, I'd like to modify this code to be able to use any song data passed in to it.

*Lo-Fi FTW*
