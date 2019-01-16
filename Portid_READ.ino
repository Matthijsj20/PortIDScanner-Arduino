

//* RST/Reset   RST          9             5         D9         RESET/ICSP-5     RST
//* SPI SS      SDA(SS)      10            53        D10        10               10
//* SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16
//* SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14
//* SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15


const int ledr = 3;
const int ledg = 5;
const int ledb = 6;
const int buzzer = 7;
const int potmeter = A5;


const int button = 2;
bool boolreadcheck = false;
bool boolserieelcheck = false;
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9           // Configurable, see typical pin layout above
#define SS_PIN          10          // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance


void setup() {
  Serial.begin(9600);                                           // Initialize serial communications with the PC
  SPI.begin();                                                  // Init SPI bus
  mfrc522.PCD_Init();                                              // Init MFRC522 card

  pinMode(button, INPUT);
  pinMode(ledr, OUTPUT);
  pinMode(ledg, OUTPUT);
  pinMode(ledb,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(potmeter,INPUT);

}


void loop() {

  int buttoncheck = digitalRead(button);
  if (buttoncheck == HIGH )
  {
    boolreadcheck = true;
  }

  if (boolreadcheck == true)
  {
    RFIDREAD();

  }
  if (serieelcheck())
  { 
    setoff();
    boolserieelcheck = true;
 
  }

  if (boolserieelcheck == true)
  {
    serieel();
    agecheck();
  

  }

}
