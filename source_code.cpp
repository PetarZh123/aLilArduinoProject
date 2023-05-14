#include<LiquidCrystal.h>

//defining pin nums
LiquidCrystal lcd(8,9,7,6,5,4);
int trigger_pin = 2;
int echo_pin = 3;
int buzzer_pin = 10;
int time;
int distance;




void setup()
{
    lcd.begin(16,2);

    Serial.begin (9600);
    pinMode (trigger_pin, OUTPUT);
    pinMode (echo_pin, INPUT);
    pinMode (buzzer_pin, OUTPUT);
}




void loop()
{
    lcd.setCursor(0,0);


    digitalWrite (trigger_pin, HIGH);
    delayMicroseconds (10);
    digitalWrite (trigger_pin, LOW);
    time = pulseIn (echo_pin, HIGH);
    distance = (time * 0.034) / 2;

    if (distance <= 200)
    {
        lcd.print("Person detected");
        digitalWrite (buzzer_pin, HIGH);
        delay (500);
    }
    else {
        lcd.print("               ");
        Serial.println (distance);
        digitalWrite (buzzer_pin, LOW);
        delay (500);
    }
}
