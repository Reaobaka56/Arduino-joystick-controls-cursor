#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the LCD. 0x27 is the common I2C address. 16 columns, 2 rows.
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int xAxisPin = A0; 
const int yAxisPin = A1; 
const int switchPin = 2; 

String lastDirection = "Center"; 
void setup() {
  Serial.begin(9600);
  pinMode(switchPin, INPUT_PULLUP);
  
  
  lcd.init();
  lcd.backlight();
  
  
  lcd.setCursor(0, 0);
  lcd.print("Mouse Status:");
  lcd.setCursor(0, 1);
  lcd.print("Center");
}

void loop() {
  int xVal = analogRead(xAxisPin);
  int yVal = analogRead(yAxisPin);
  int buttonVal = digitalRead(switchPin);

  int mouseX = map(xVal, 0, 1023, -10, 10);
  int mouseY = map(yVal, 0, 1023, 10, -10); 

  
  String currentDirection = "Center";

  
  if (mouseX > 3) {
    currentDirection = "Right";
  } else if (mouseX < -3) {
    currentDirection = "Left";
  } else if (mouseY > 3) {
    currentDirection = "Forward";
  } else if (mouseY < -3) {
    currentDirection = "Backward";
  }

 
  if (buttonVal == LOW) {
    currentDirection = "Clicked!";
  }

  
  if (currentDirection != lastDirection) {
    lcd.setCursor(0, 1);
    lcd.print("                "); 
    lcd.setCursor(0, 1);
    lcd.print(currentDirection); 
    lastDirection = currentDirection;
  }

  
  if (abs(mouseX) > 2 || abs(mouseY) > 2 || buttonVal == LOW) {
    Serial.print(mouseX);
    Serial.print(",");
    Serial.print(mouseY);
    Serial.print(",");
    Serial.println(buttonVal == LOW ? "1" : "0");
  }

  delay(30); 
}
