int speakerPin = 12;
int numTone = 10;

int tones[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440};

void setup()
{
    for (int i = 0; i < numTone; i++)
    {
        tone(speakerPin, tones[i]);
        delay(500);
    }
    noTone(speakerPin);
}

void loop()
{
}