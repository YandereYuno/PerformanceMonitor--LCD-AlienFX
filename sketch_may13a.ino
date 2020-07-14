#include <LiquidCrystal.h>

//Set's lcd to the Arduino's ports
LiquidCrystal lcd(10, 2, 4, 5, 6, 7);

void setup()
{
  lcd.begin(16, 2);

  Serial.begin(9600);
  lcd.print("    YANDERE");
}

void loop() {

  String content = "";
  char character;


  while (Serial.available())
  {
    character = Serial.read();
    content.concat(character);
  }

  if (content != "")
  {

    if (content == "`")
    {
      content = "";
      lcd.setCursor(0, 1);
    }

    if (content == "*")
    {
      content = "";
      lcd.setCursor(0, 0);
    }

    Serial.println(content);
    lcd.print(content);
  }

  if (content == "~")
  {
    lcd.clear();
  }


}
