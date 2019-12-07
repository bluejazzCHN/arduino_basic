int potPin = 0;
int latchPin = 5;
int clockPin = 6;
int dataPin = 4;

int leds = 0;

void setup()
{
    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
    Serial.begin(115200);
    while (!Serial)
        ; // Wait untilSerial is ready - Leonardo
    Serial.println("Serial communication setup!");
}

void loop()
{
    int reading = analogRead(potPin);
    int numLEDSLit = reading / 114; //1023 / 9
    leds = 0;
    for (int i = 0; i < numLEDSLit; i++)
    {
        bitSet(leds, i);
    }
    updateShiftRegister();
    Serial.println(numLEDSLit);
    delay(500);
}

void updateShiftRegister()
{
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, leds);
    digitalWrite(latchPin, HIGH);
}