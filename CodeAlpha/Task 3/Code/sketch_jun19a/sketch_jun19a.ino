#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 3;

char keys[ROWS][COLS] =
{
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte rowPins[ROWS] = {0,1,2,3};
byte colPins[COLS] = {4,5,6};

Keypad keypad = Keypad(makeKeymap(keys),
                       rowPins,
                       colPins,
                       ROWS,
                       COLS);

String password = "1234";
String enteredPassword = "";

int greenLED = 12;
int redLED = 11;

void setup()
{
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);

}

void loop()
{
  char key = keypad.getKey();

  if(key)
  {
    if(key == '#')
    {
      if(enteredPassword == password)
      {
        digitalWrite(greenLED, HIGH);
        digitalWrite(redLED, LOW);

        delay(3000);

        digitalWrite(greenLED, LOW);
      }
      else
      {
        digitalWrite(redLED, HIGH);
        delay(2000);
        digitalWrite(redLED, LOW);
      }

      enteredPassword = "";
    }

    else if(key == '*')
    {
      enteredPassword = "";
    }

    else
    {
      enteredPassword += key;
    }
  }
}
