int input = 0;
int LED = 13;

int redPin = 11;
int greenPin = 9;
int bluePin = 10;


int colour_value = 1;

int red, green, blue;

//#define COMMON_ANODE


void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  if(Serial.available() > 0){
    input = Serial.read();
    if(input == '1'){
      make_colour(255,0,0);
    }
    else if(input == '2' ){
      make_colour(0,255,0);
    }
    else if(input == '3' ){
      make_colour(0,0,255);
    }
    else if(input == 4 ){
      make_colour(0,0,0);
    }
    else if(input == 5 ){
      make_colour(255,255,255);
    }
}
}

void make_colour(int r, int g, int b){
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  Serial.println("Making Colour");
  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);
}

void status_report(){
  Serial.print("Red: ");
  Serial.println(red);
  Serial.print("Green: ");
  Serial.println(green);
  Serial.print("Blue: ");
  Serial.println(blue);
  Serial.print("Value: ");
  Serial.println(colour_value);
  Serial.println("");
  Serial.println("");
}


