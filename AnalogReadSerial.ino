// INCLUDES =================================================

#include <LiquidCrystal.h>
#include <EEPROM.h>
//#include <dht.h>
#include <secTimer.h>

#define DHT11_PIN 13

// INIZIALIZATION ===========================================
LiquidCrystal lcd(8,9,4,5,6,7);

int relay[]={2,3,4,5}; // RELAY's PINS

//Adafruit_SHTC3 shtc3 = Adafruit_SHTC3(); //si usamos shtc3
//dht DHT; //si usamos dht

secTimer relayOneTimer; 
secTimer relayTwoTimer;
secTimer gralTimer;

int relayOneTime[][2]={};
int relayTwoTime[][2]={};

int relayOneTimerSet = 0;
int relayTwoTimerSet = 0;

bool relayOne = false;

unsigned long secondsBefore=0, secondsNow=0, secondsBeforeRelayOne=0, secondsBeforeRelayTwo=0, secondsNowRelayOne = 0, secondsNowRelayTwo = 0;
//Pantallas

const int nScreens = 6;
char* screens[][2] = { {"TEMP:**|PRENDIDO",
                               "HUM:** |  -  -  "},
                      
                    { "    <-TEMP->    ",
                      "   T:**-VAR:**  "},
                      
                    { "     <-R1->     ",
                      "  **:**==**:**  "},
                      
                    { "     <-R2->     ",
                      "  **:**==**:**  "},
                      
                    { "<-TIEMPO 24HS-> ", 
                      "** ** ** ** P:**"},
                      
                    { "<- HUM   24HS-> ", 
                      "** ** ** ** P:**"}};


                      
int screenDown[][4] = {{6,13,6,13},{3,6,10,13},{2,6,10,13}};
int screenDownTwo[][4][2] = {{{5,6},{12,13},{5,6},{12,13}},{{2,3},{5,6},{9,10},{12,13}},{{2,3},{5,6},{9,10},{12,13}}};

class Menu {
public:
  void up();
  void down();
  void left();
  void right();
  void select();
  void blinkTo(int coursors);
    void noBlinkTo(int coursors);
  void printScreen(int screen);
private:
 int actualScreen = 0;
  bool selected = false;
  int selection = 0;

};
  void Menu::blinkTo(int coursors){
    lcd.setCursor(coursors,1);
    lcd.blink();
  }

    void Menu::noBlinkTo(int coursors){
    lcd.setCursor(coursors,1);
    lcd.noBlink();
  }
  
  void Menu::up(){}

  
  void Menu::down(){}
  void Menu::left(){
    if(!selected){
       actualScreen = (actualScreen +(nScreens-1))%nScreens;
       printScreen(actualScreen);
    }else{
      selection = (selection +(4-1))%4;
      blinkTo(screenDown[actualScreen-1][selection]);
    }
    }

    
  void Menu::right(){
     if(!selected){
       actualScreen = (actualScreen +1)%nScreens;
       printScreen(actualScreen);
    }else{
      selection = (selection +1)%4;
      blinkTo(screenDown[actualScreen-1][selection]);
    }
    }
  void Menu::select(){
    if((actualScreen==1 || actualScreen == 2))
      selected = !selected; 
      if (selected){
      selection = 0;
      blinkTo(screenDown[actualScreen-1][selection]);
      }else{
        noBlinkTo(screenDown[actualScreen-1][selection]);
      }
    }
  void Menu::printScreen(int screen){
  lcd.setCursor(0,0);
  
  lcd.print (screens[screen][0]);
  lcd.setCursor(0,1);
  lcd.print (screens[screen][1]);
  }

//int actualScreen = 0;


Menu menu;


//SETUP =====================================================
void setup() {
  lcd.begin(16, 2);
  relayOneTimer.startTimer(); 
  relayTwoTimer.startTimer(); 
  gralTimer.startTimer(); 
  menu.printScreen(0);
  secondsBeforeRelayOne=relayOneTimer.readTimer();
  secondsBeforeRelayTwo=relayTwoTimer.readTimer();
  secondsBefore=gralTimer.readTimer();
  
}




// the loop routine runs over and over again forever:
void loop() {

  // ============TIMER==============
//  relayOneTime= {{EEPROM.read(0),EEPROM.read(1)},{EEPROM.read(2),EEPROM.read(3)}};
//  relayTwoTime= {{EEPROM.read(4),EEPROM.read(5)},{EEPROM.read(6),EEPROM.read(7)}};
//  
//  secondsNowRelayOne = relayOneTimer.readTimer()
//  secondsNowRelayTwo = relayTwoTimer.readTimer()
//  
//  // RELAY 1------------------------
//  
//  if(relayOne && (secondsNowRelayOne - secondsBeforeRelayOne > (relayOneTime[relayOneTimerSet][0] * 3600)+ (relayOneTime[relayOneTimerSet][1] * 60)){
//    relayOneTimerSet = (relayOneTimerSet + 1) % 2; // new timer set
//    digitalWrite(relay[0], relayOneTimerSet); // on/off relay
//    secondsBeforeRelayOne = relayOneTimer.readTimer();// reset timer
//  }
//
//  // RELAY 2------------------------
//
//  if((secondsNowRelayTwo - secondsBeforeRelayTwo > (relayTwoTime[relayTwoTimerSet][0] * 3600)+ (relayTwoTime[relayTwoTimerSet][1] * 60)){
//    relayTwoTimerSet = (relayTwoTimerSet + 1) % 2; // new timer set
//    digitalWrite(relay[0], relayTwoTimerSet); // on/off relay
//    secondsBeforeRelayTwo = relayTwoTimer.readTimer();// reset timer
//  }

  
  // CASO RELE 1
  

  // ===============================
  int x;
  x = analogRead (0);
  
  if (x < 60) { //right
    menu.right();
    
  }
  else if (x < 200) {//up
    lcd.setCursor(0,0);
    lcd.blink();
  }
  else if (x < 400){//down
    lcd.setCursor(0,0);
    lcd.noBlink();
  }
  else if (x < 600){//left
   menu.left();
  }
  else if (x < 800){
    menu.select();
    //select
  }
  delay(200);
}

// USE OF EEPROM ==============================
//  EEPROM.write(0, 7);
//  EEPROM.write(3, 50); 
//   int value1 = EEPROM.read(0);
//  Serial.println(value1);
//  int value2 = EEPROM.read(3);

//USE OF DHT ==================================
//  int chk = DHT.read11(DHT11_PIN);
//  Serial.print("Temperature = ");
//  Serial.println(DHT.temperature);
//  Serial.print("Humidity = ");
//  Serial.println(DHT.humidity);
//  Serial.println(value2);

//USE OF RELAY ================================
//pinMode(relay[0], OUTPUT);// connected to relay1
//digitalWrite(relay[0], HIGH); // Turn the relay OFF  
//
//
//pinMode(relay[1], OUTPUT);// connected to relay2
//digitalWrite(relay[1], HIGH); // Turn the relay OFF  
//
//pinMode(relay[2], OUTPUT);// connected to relay3
//digitalWrite(relay[2], HIGH); // Turn the relay OFF  
//
//pinMode(relay[3], OUTPUT);// connected to relay4
//digitalWrite(relay[3], HIGH); // Turn the relay OFF   

//USE OF SHTC3 ================================
// https://learn.adafruit.com/adafruit-sensirion-shtc3-temperature-humidity-sensor/arduino

// Serial.println("SHTC3 test");
// if (! shtc3.begin()) {
//    Serial.println("Couldn't find SHTC3");
//    while (1) delay(1);
// }
//Serial.println("Found SHTC3 sensor");

//sensors_event_t humidity, temp;
//  
//shtc3.getEvent(&humidity, &temp);// populate temp and humidity objects with fresh data
//
//Serial.print("Temperature: "); Serial.print(temp.temperature); Serial.println(" degrees C");
//Serial.print("Humidity: "); Serial.print(humidity.relative_humidity); Serial.println("% rH");
