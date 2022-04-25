#define RED_LED D2
#define YELLOW_LED D3
#define GREEN_LED D4

// Forward declare functions
void    ResetLEDs();
int     ChangeLights(String colour);

// Allow code to be run before connecting to the cloud. Not very usefull in this case.
SYSTEM_THREAD(ENABLED);

void setup() {
    pinMode(RED_LED, OUTPUT);
    pinMode(YELLOW_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);
    
    Particle.function("ChangeLights", ChangeLights);
}

void loop() {
    // controlled by web function, therefore can be left empty
}

// Ensures all LEDs are off before turning the correct one on
void ResetLEDs() {
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
}

int ChangeLights(String colour) {
    ResetLEDs();
    Particle.publish("Light_Change", colour);
    
    if (colour.equals("red")) {
        digitalWrite(RED_LED, HIGH);
        return 1;
    } else if (colour.equals("yellow")) {
        digitalWrite(YELLOW_LED, HIGH);
        return 1;
    } else if (colour.equals("green")) {
        digitalWrite(GREEN_LED, HIGH);
        return 1;
    } else if (colour.equals("off")) {
        return 1;
    }
    return -1;
}