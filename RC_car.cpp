#include <IRremote.hpp>
#define IR_RECP 11


int forward_motorL_in1 = 2;
int forward_motorL_in2 = 3;
int forward_motorL_enA = 4;

int forward_motorR_in3 = 7;
int forward_motorR_in4 = 5;
int forward_motorR_enB = 6;



//IR CODES

//B946FF00 70 VOL+
//EA15FF00 21 VOL-
//BB44FF00 68 REWIND
//BC43FF00 67 FORWARD CONTENT

void decode_input (uint16_t code){
  Serial.println(code);
  switch (code) {
      case 70:
        Serial.println("FORWARD");

        digitalWrite(forward_motorR_in3, HIGH);
        digitalWrite(forward_motorR_in4, LOW);
        digitalWrite(forward_motorR_enB, 100);

        digitalWrite(forward_motorL_in1, HIGH);
        digitalWrite(forward_motorL_in2, LOW);
        digitalWrite(forward_motorL_enA, 100);

  
        

        break;

      case 64:
        Serial.println("STOP");
        digitalWrite(forward_motorL_in1, LOW);
        digitalWrite(forward_motorL_in2, LOW);
        digitalWrite(forward_motorL_enA, 100);

        digitalWrite(forward_motorR_in3, LOW);
        digitalWrite(forward_motorR_in4, LOW);
        digitalWrite(forward_motorR_enB, 100);

        break;
        
      case 68:
        Serial.println("LEFT");

        digitalWrite(forward_motorR_in3, LOW);
        digitalWrite(forward_motorR_in4, LOW);
        digitalWrite(forward_motorR_enB, 100);

        digitalWrite(forward_motorL_in1, HIGH);
        digitalWrite(forward_motorL_in2, LOW);
        digitalWrite(forward_motorL_enA, 100);

        break;
      case 67:
        Serial.println("RIGHT");
        digitalWrite(forward_motorL_in1, LOW);
        digitalWrite(forward_motorL_in2, LOW);
        digitalWrite(forward_motorL_enA, 100);

        digitalWrite(forward_motorR_in3, HIGH);
        digitalWrite(forward_motorR_in4, LOW);
        digitalWrite(forward_motorR_enB, 100);

        break;

    }


}




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(forward_motorL_in1, OUTPUT);
  pinMode(forward_motorL_in2, OUTPUT);
  pinMode(forward_motorL_enA, OUTPUT);

  pinMode(forward_motorR_in3, OUTPUT);
  pinMode(forward_motorR_in4, OUTPUT);
  pinMode(forward_motorR_enB, OUTPUT);

  IrReceiver.begin(IR_RECP, ENABLE_LED_FEEDBACK);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (IrReceiver.decode()){
    uint16_t button_click_code = IrReceiver.decodedIRData.command;
    decode_input(button_click_code);
    IrReceiver.resume();


  }
}
