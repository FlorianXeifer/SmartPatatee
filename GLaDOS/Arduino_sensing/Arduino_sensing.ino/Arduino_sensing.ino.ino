//****************************************************************************************
// Illutron take on Disney style capacitive touch sensor using only passives and Arduino
// Dzl 2012
//****************************************************************************************


//                              10n
// PIN 9 --[10k]-+-----10mH---+--||-- OBJECT
//               |            |
//              3.3k          |
//               |            V 1N4148 diode
//              GND           |
//                            |
//Analog 0 ---+------+--------+
//            |      |
//          100pf   1MOmhm
//            |      |
//           GND    GND



#define SET(x,y) (x |=(1<<y))				//-Bit set/clear macros
#define CLR(x,y) (x &= (~(1<<y)))       		// |
#define CHK(x,y) (x & (1<<y))           		// |
#define TOG(x,y) (x^=(1<<y))            		//-+



#define N 160  //How many frequencies

float results[N];            //-Filtered result buffer
float freq[N];            //-Filtered result buffer
int sizeOfArray = N;

                                                  //Debut partie eleve
#include <LiquidCrystal.h>                      
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;                              
int reply;                                     
int tempo = 0;
                                                //Fin parie eleve
 
   
   

void setup()
{
  
  
  TCCR1A=0b10000010;        //-Set up frequency generator
  TCCR1B=0b00011001;        //-+
  ICR1=110;
  OCR1A=55;

  pinMode(9,OUTPUT);        //-Signal generator pin
  pinMode(8,OUTPUT);        //-Sync (test) pin

  Serial.begin(115200);
 

  for(int i=0;i<N;i++)      //-Preset results
    results[i]=0;         //-+

                                  //Debut partie eleve
    lcd.begin(16, 2);                 
    pinMode(switchPin, INPUT);
    delay(1500);
    lcd.print("Oh hi!");
    lcd.setCursor(0, 1);
    delay(1000);
    lcd.print("Hello");   
    delay(2000);
    lcd.clear();
    lcd.print("How are you");
    lcd.setCursor(0, 1);
    lcd.print("Holding up?"); 
    delay(3000);
    lcd.clear();
     lcd.print("BECAUSE I AM");
    lcd.setCursor(0, 1);
    lcd.print("A POTATO!"); 
    delay(3000);
   lcd.clear();
                                  //Fin partie eleve
}

void loop()
{
  Serial.println(analogRead(0));
  switchState = digitalRead(switchPin);
  int touch = analogRead(0);
  unsigned int d;

  int counter = 0;

                                      //Debut partie eleve
/*if (touch < 165 && touch > 155) {  
    
  tempo++;
     if (tempo == 10){
     reply = random(5);
   
    switch(reply){
        case 0:
        lcd.print("When life gives");
        lcd.setCursor(0, 1);
        lcd.print("you lemons?!"); 
        delay(3000);
        lcd.clear();
        lcd.print("Don't make");
        lcd.setCursor(0, 1);
        lcd.print("lemonade."); 
        delay(3000);
        lcd.clear();
        lcd.print("Make life!");
        delay(1500);
        lcd.clear();
        lcd.print("take the lemons");
        lcd.setCursor(0, 1);
        lcd.print("back! "); 
        delay(1500);
        lcd.setCursor(6, 1);
        lcd.print("Get mad!"); 
        delay(1500);
        lcd.clear();
        tempo = 0;
        break;
        case 1:
        lcd.print("The cake is");
        lcd.setCursor(0, 1);
        lcd.print("a lie!"); 
        delay(3000);
        lcd.clear();
        lcd.print("All the cake");
        lcd.setCursor(0, 1);
        lcd.print("is gone."); 
        delay(3000);
        lcd.clear();
        tempo = 0;
        break;
        case 2:
        lcd.print("Hello?");
        delay(1500);
        lcd.clear();
        lcd.print("Where are you?");
        delay(3000);
        lcd.clear();
        lcd.print("I know you're");
        lcd.setCursor(0, 1);
        lcd.print("there,");
        delay(3000);
        lcd.clear();
        lcd.print("I can feel"); 
        lcd.setCursor(0, 1);
        lcd.print("you here.");
        delay(3000);
        lcd.clear();
        tempo = 0;
        break;
        case 3:
        lcd.print("Are you avoiding");
        lcd.setCursor(0, 1);
        lcd.print("me?!"); 
        delay(3000);
        lcd.clear();
        lcd.print("You will touch");
        lcd.setCursor(0, 1);
        lcd.print("me,"); 
        delay(1500);
        lcd.setCursor(4, 1);
        lcd.print("I know it."); 
        delay(3000);
        lcd.clear();
        tempo = 0;
        break;
        case 4:
        lcd.print("One does not");
        lcd.setCursor(0, 1);
        lcd.print("simply touch the"); 
        delay(2000);
        lcd.clear();
        lcd.print("potato!"); 
        delay(1500);
        lcd.clear();
        tempo = 0;
        break;
       
       
      }
    }
 }*/
if (touch < 178 && touch > 169) {
    if (switchState != prevSwitchState) {
      if (switchState == LOW) {     
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("One finger");
    lcd.setCursor(0, 1);
    lcd.print("Ok...");
    delay(3000);
    lcd.clear();
    
        }
      }
      
  }
  else if (touch < 189&& touch > 180) {
    if (switchState != prevSwitchState) {
      if (switchState == LOW) {   
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Two fingers");
    lcd.setCursor(0, 1);
    lcd.print("Why...");
    delay(3000);
    lcd.clear();
    reply = random(8);
      lcd.clear();
      
        }
      } 
      
  }
  else if (touch < 250&& touch > 190) {
    if (switchState != prevSwitchState) {
      if (switchState == LOW) {   
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("U're Grabing me");
    lcd.setCursor(0, 1);
    lcd.print("I can't...breath!");
    delay(3000);
    lcd.clear();
   
        }
      }
  }

 else if (touch < 194 && touch > 170) {

   tempo++;
  if (tempo == 15){

        lcd.print("You need to");
        lcd.setCursor(0, 1);
        lcd.print("press the button!"); 
        delay(3000);
        lcd.clear();
        
    tempo = 0;
  }
  
 }
 
   prevSwitchState = switchState;
                                  //Fin partie eleve
                                  
  for(unsigned int d=0;d<N;d++)
  {
    int v=analogRead(0);    //-Read response signal
    CLR(TCCR1B,0);          //-Stop generator
    TCNT1=0;                //-Reload new frequency
    ICR1=d;                 // |
    OCR1A=d/2;              //-+
    SET(TCCR1B,0);          //-Restart generator

    results[d]=results[d]*0.5+(float)(v)*0.5; //Filter results
   
    freq[d] = d;

 //   plot(v,0);              //-Display
 //   plot(results[d],1);
  // delayMicroseconds(1);
  }


//PlottArray(1,freq,results); 
 

  TOG(PORTB,0);            //-Toggle pin 8 after each sweep (good for scope)

    
  
  //Serial.println(touch);
}
   
