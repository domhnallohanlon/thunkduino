//variable for Serial input
int input = 0;

//Pins for LEDs
const int LED = 13;
const int redPin = 11;
const int greenPin = 9;
const int bluePin = 10;

void setup() {
  //Start the serial monitor at 9600 baud
  Serial.begin(9600);
  
  //Declare the LEDs to be outputs
  pinMode(LED, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  //check if there's incoming data,
  if(Serial.available() > 0){
    //if so, then read the incoming data.
    input = Serial.read();
    
    //make different colours depending on the input value
    if(input == '1'){
      make_colour(255,0,0);
    }
    else if(input == '2' ){
      make_colour(0,255,0);
    }
    else if(input == '3' ){
      make_colour(0,0,255);
    }
    else if(input == '4' ){
      make_colour(0,0,0);
    }
    else if(input == '5' ){
      make_colour(255,255,255);
    }
  }
}

void make_colour(int r, int g, int b){
  //just for testing
  Serial.println("Making Colour");
  
  //sets the duty cycle for each pin
  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);
}



