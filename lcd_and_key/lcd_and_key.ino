#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

const byte ROWS = 4; // four rows
const byte COLS = 3; // three columns
char array1[]=" Hello I'm EMBOT!         "; //the string to print on the LCD
char array2[]="Your multipurpose robot   "; //the string to print on the LCD
int tim = 150; //the value of delay time
// initialize the library with the numbers of the interface pins
LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address to 0x27 for a 16 chars and 2 line display

char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte rowPins[ROWS] = {5, 4, 3, 2}; // connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 7, 6};    // connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


//initializations
#define BUZZ 9

void setup() {
  Serial.begin(9600);
  pinMode(BUZZ,OUTPUT);

}
  
void loop() {
  intro();
  menu();
  
  char key = keypad.getKey();
  while (key == NO_KEY)
   {
    lcd.setCursor(0,0);
    lcd.print("Press key of");
    lcd.setCursor(0,1);
    lcd.print("your choice: ");
    key = keypad.getKey();
   
    if (key!=NO_KEY){
      digitalWrite(BUZZ,HIGH);
      lcd.print(key);
      delay(100);
      digitalWrite(BUZZ,LOW);
      lcd.clear();
      switch(key){
        case '1': confirm();
                  lineTr();
                  break;
        case '2': confirm();
                  obstacleAv();
                  break;
        case '3': confirm();
                  sumoBot();
                  break;
        default: lcd.setCursor(0,1);
                 
                 lcd.print("Invalid choice!");
                 digitalWrite(BUZZ,HIGH);
                 delay(100);
                 digitalWrite(BUZZ,LOW);
                 digitalWrite(BUZZ,HIGH);
                 delay(100);
                 digitalWrite(BUZZ,LOW);
                 key == NO_KEY;
      }
    }
   }
}
   
  
  void intro(){
  lcd.init(); //initialize the lcd
  lcd.backlight(); //open the backlight 
  lcd.setCursor(15,0); // set the cursor to column 15, line 0
  for (int positionCounter1 = 0; positionCounter1 < 26; positionCounter1++)
  {
     lcd.scrollDisplayLeft(); //Scrolls the contents of the display one space to the left.
     lcd.print(array1[positionCounter1]); // Print a message to the LCD.
     delay(tim); //wait for 250 microseconds
  }
  lcd.clear(); //Clears the LCD screen and positions the cursor in the upper-left  corner.
  lcd.setCursor(15,1); // set the cursor to column 15, line 1
  for (int positionCounter = 0; positionCounter < 26; positionCounter++)
  {
     lcd.scrollDisplayLeft(); //Scrolls the contents of the display one space to the left.
     lcd.print(array2[positionCounter]); // Print a message to the LCD.
     delay(tim); //wait for 250 microseconds
  }
  lcd.clear();

  }

  void menu(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("I can be a...");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("1. Line Tracing");
  lcd.setCursor(0,1);
  lcd.print("   Robot");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("2. Obstacle");
  lcd.setCursor(0,1);
  lcd.print("  Avoiding Robot");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("3. Sumobot");
  delay(1000);
  lcd.clear();
}

void confirm(){
  char key2=keypad.getKey();
      while(key2==NO_KEY){
      lcd.setCursor(0,0);
      lcd.print("Are you sure?");
      lcd.setCursor(0,1);
      lcd.print("*-Yes | #-No: ");
      key2 = keypad.getKey();
      if (key2!=NO_KEY){
        digitalWrite(BUZZ,HIGH);
        lcd.print(key2);
        delay(100);
        digitalWrite(BUZZ,LOW);
        if(key2=='*')
        return;
        else if(key2=='#')
        loop();
        else {
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Invalid choice!");
          digitalWrite(BUZZ,HIGH);
          delay(100);
          digitalWrite(BUZZ,LOW);
          digitalWrite(BUZZ,HIGH);
          delay(100);
          digitalWrite(BUZZ,LOW);
          loop();
        }
      }
}}

void lineTr(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("LINE TRACING");
}

void obstacleAv(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("OBSTACLE");
  lcd.setCursor(0,1);
  lcd.print("AVOIDING");
}

void sumoBot(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("SUMOBOT");
}
