/*
  +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

   KISS Version 1.0

   Keep It Simple... Silly! Stay busy with these daily activity suggestions 
   and greetings. Follow the suggested Arduino Setup below to plug in the 
   wires and components for the system!

   

   Required Components:
   Liquid Crystal Display (LCD)

   Optional Components:
  2 LEDs (Any Color)
	 -1 used as an indicator to show that the system is online
   -1 used to show "processing"
  2 Buttons
	 -1 to reload (A)
	 -1 to "re-roll" suggestion (B)

  

   Suggested Arduino Setup (UNFINISHED):
   ooooo ggggg o
 0 ***** ***** o
 1 ***** ***** o
 2 ***** ***** o
 3 ***** ***** o
 4 ***** ***** o
 5 ***** ***** o
 6 ***** ***** o
 7 ***** ***** o
 8 ***** ***** o
 9 ***** ***** o
10 ***** ***** o
11 ***** ***** o
12 ***** *****
13 ***** *****
 g ***** *****
AR ***** *****
   ***** *****
   ***** *****

  *Based upon Arduino Prototype Shield

  +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#include <LiquidCrystal.h>
#define ARRAYSIZEA 82
#define ARRAYSIZEB 101

LiquidCrystal lcd(5, 4, 3, 2, 1, 0);
const int buttonPinA = 7;
const int buttonPinB = 8;
const int ledPinOnline = 9;
const int ledPinLoading = 10;
const int LCDInterval = 500;
const int threeSeconds = 3000;
const int oneHour = 3600000;
const int twentyFourHours = 86400000;

unsigned long previousDailyMillis = 0;
unsigned long previousLCDMillis = 0;
unsigned long currentMillis = 0;

String todaysMessage = "";

void setup() {
   lcd.begin(16, 2); //Initialize LCD
   lcd.print("  Welcome!  "); //Display Welcome

   randomSeed(analogRead(0));
   
   pinMode(ledPinOnline, OUTPUT); //Initialize green light
   pinMode(ledPinLoading, OUTPUT); //Initialize red light
   pinMode(buttonPinA, INPUT); //Initialize Reload Btn
   pinMode(buttonPinB, INPUT); //Initialize Reroll Btn
    
   digitalWrite(ledPinOnline, HIGH); //Turn on green light
   digitalWrite(ledPinLoading, HIGH); //Turn on red light
   
   delay(threeSeconds); //Delay for 3 seconds
   dailyMessage();
}

void reInitialize() {
   lcd.begin(16, 2); //Initialize LCD
   lcd.print("  Welcome!  "); //Display Welcome
   
   pinMode(ledPinOnline, OUTPUT); //Initialize green light
   pinMode(ledPinLoading, OUTPUT); //Initialize red light
   pinMode(buttonPinA, INPUT); //Initialize Reload Btn
   pinMode(buttonPinB, INPUT); //Initialize Reroll Btn
    
   digitalWrite(ledPinOnline, HIGH); //Turn on green light
   digitalWrite(ledPinLoading, HIGH); //Turn on red light
   
   delay(threeSeconds); //Delay for 3 seconds
   dailyMessage();
}

void loop() {
   currentMillis = millis();

   readButton();
   checkDailyUpdate();
}

void readButton(){
   if (currentMillis - previousLCDMillis >= LCDInterval) {
      if (digitalRead(buttonPinA) == LOW)
         reInitialize();
      if (digitalRead(buttonPinB) == LOW)
         dailyMessage();
      previousLCDMillis += LCDInterval;
   }
}

void checkDailyUpdate(){
  if(currentMillis - previousDailyMillis >= twentyFourHours) {
    dailyMessage();
    previousDailyMillis += twentyFourHours;
  }
}

void dailyMessage() {
   digitalWrite(ledPinOnline, LOW); //turn off green light
   digitalWrite(ledPinLoading, HIGH); //turn on red light
   setTodaysMessage();
   digitalWrite(ledPinOnline, HIGH); //turn on green light
   digitalWrite(ledPinLoading, LOW); //turn off red light
}

void setTodaysMessage() {
   int randomNum = 0;
   String messages[ARRAYSIZEA] = {"Do Smthn New", "Take A Walk", 
                 "Try Yoga",     "Take A Hike",  "Exercise 15m",
                 "Exercise 30m", "Go Swimming",  "Read A Book",
                 "Fancy Dinner", "Mini Golf",    "Bowling",
                 "Sing A Song",  "Play Playlst", "Card Game",
                 "Board Game",   "Go 2 Museum",  "Burger Night",
                 "Trivia Night", "Relax",        "Go Camping",
                 "Play Pinball", "Water Park!",  "Amusmnt Park",
 /*24,25,26*/    "Go To Arcade", "Laser Tag",    "Scvngr Hunt",
                 "Paint Canvas", "Doodle!",      "Tennis",
                 "Baseball",     "Basketball",   "Go To Gym",
                 "Go To Zoo",    "Drive RC Car", "Fly Drone",
                 "Kickball",     "Rollerblade",  "Mntn Bike",
                 "Ultmt Frsbee", "Bike Ride",    "Watch Movie",
                 "Make Music",   "Hum A Tune",   "State Fair",
                 "Corn Maze",    "Go Karting",   "Arts & Crfts",
 /*48,49,50*/    "Bake!",        "Video Games",  "Host Party",
                 "Resrch Topic", "Gardening",    "Plnt A Flowr",
                 "Reorg House",  "Fnd New Hbby", "Puzzle",
                 "Host BBQ",     "Eat Outside",  "Paint By #",
                 "Clean Home",   "Pillow Fort",  "Crdbrd House",
                 "Blow Bubbles", "Hide & Seek",  "Bird Feeder",
                 "Hopscotch",    "Wash Car",     "Shopping",
                 "Paint Rocks",  "Explore",      "Take Pics",
                 "Sidewlk Chlk", "Watch Sunset", "Magic Tricks",
 /*75,76,77*/    "Paper Planes", "PlayDough",    "Marbles!",
                 "Make Bouquet", "Stargaze",     "Bath Bomb",
                 "Take A Bath",  "Watch Clouds"}; //82

   String greetings[ARRAYSIZEB] = {"Hi There!", "Howdy!", 
                 "Good Day!",    "Nice 2 C U!",  "What's New?",
                 "How Goes It?", "Greetings!",   "Salutations!",
                 "What's Up?",   "Hey!",         "Hello!",
                 "How Are You?", "Feeling Gud?", "Good 2 C U!",
                 "Great 2 C U!", "Lk Who It Is", "Hey, Boo!",
                 "There They R", "Whts happnin", "Oi!",
                 "Hola!",        "Que Tal?",     "Ciao!",
 /*24,25,26*/    "Salut!",       "Hallo!",       "Namaste!",
                 ":)",           ":D"            "Xin Chao!",
                 "Ni Hao!",      "BD",           "B)",
                 ":v",           ":}",           ":>",
                 "Meow!",        "Woof!",        "Chirp!",
                 "Hej!",         "Bonjour!",     "Halo!",
                 "Guten Tag!",   "Buon Giorno!", "Salve!",
                 "Moien!",       "Ola!",         "Helo!",
 /*48,49,50*/    "Shalom!",      "Aloha!",       "Hi!",
                 "How're You?",  "How's Life?",  "Been A While",
                 "Crocodile!",   "Alligator",    "C U L8R!",
                 "Yo!",          "Suh!",         "Wassup?",
                 "Sup?",         "Asuh!",        "G\'day Mate!",
                 "Hiya!",        ":-)",          ":]",
                 ":-]",          ":-3",          ":3",
                 ":->",          "8)",           "8-)",
                 ":-}",          ":o)",          ":c)",
 /*75,76,77*/    ":^)",          "=)",           "=]",
                 ":-D",          "8-D",          "XD",
                 "X-D",          "=D",           "=3",
                 "B^)",          "B^D",          ":,-)",
                 ":,)",          ":,-D",         ":,D",
                 "O:)",          "O:-)",         "O:D",
                 "O:-D",         ";-)",          ";)",
                 ";D",           ";D",           "<3",
                 "<3 <3",        "<3 <3 <3",     "<3 <3 <3 <3"};//101

   randomNum = random(2);
   if(randomNum == 0){
      randomNum = random(ARRAYSIZEA + 1);
      todaysMessage = messages[randomNum];
      
      lcd.setCursor(1, 1);
      lcd.print("To Do Today:");
   } else {
      randomNum = random(ARRAYSIZEB + 1);
      todaysMessage = greetings[randomNum];
      
      lcd.setCursor(1, 1);
      lcd.print(todaysMessage);
      
      randomNum = random(ARRAYSIZEB + 1);
      todaysMessage = greetings[randomNum];
   }
   
   lcd.setCursor(2, 1);
   lcd.print(todaysMessage);
}
