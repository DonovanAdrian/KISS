/*
  +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

   KISS Version 1.0

   Keep It Simple... Silly! Stay busy with these daily activity suggestions 
   and greetings.

  +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#include <LiquidCrystal.h>

LiquidCrystal lcd(0, 1, 10, 11, 12, 13);
const int LCDInterval = 500;
const int threeSeconds = 3000;
const int twentyFourHours = 86400000;
String todaysMessage = "";

void setup() {
   lcd.begin(16, 2); //Initialize LCD
   lcd.print("  Welcome!  "); //Display Welcome
   
   delay(threeSeconds); //Delay for 3 seconds
}

void loop() {
   dailyMessage();
   delay(twentyFourHours);
}

void dailyMessage() {
   setTodaysMessage();
   
   lcd.setCursor(0,0);
   lcd.print("  TADA!!!!!  ");
}

void setTodaysMessage() {
   lcd.setCursor(0,0);
   lcd.print("  Hooray??  ");

   //Not getting any further than this
  
   int randomNum = 0;
   String messages[] = {"Do Smthn New", "Take A Walk", 
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

   String greetings[] = {"Hi There!", "Howdy!", 
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

   lcd.setCursor(0,0);
   lcd.print("  Hooray!!  ");


   randomNum = random(2);
   if(randomNum == 0){
      randomNum = random(83);
      todaysMessage = messages[randomNum];
      
      lcd.setCursor(0, 0);
      lcd.print("To Do Today:");
   } else {
      randomNum = random(102);
      todaysMessage = greetings[randomNum];
      
      lcd.setCursor(0, 0);
      lcd.print(todaysMessage);
      
      randomNum = random(102);
      todaysMessage = greetings[randomNum];
   }
   
   lcd.setCursor(0, 1);
   lcd.print(todaysMessage);
}
