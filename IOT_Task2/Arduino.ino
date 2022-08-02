#include <Servo.h>


Servo gripper;
Servo wrist;
Servo elbow;
Servo shoulder;
Servo base;

double base_angle=90;
double shoulder_angle=90;
double elbow_angle=90;
double wrist_angle=90;


void setup() {
  
  Serial.begin(115200);
  base.attach(9);
  shoulder.attach(10);
  elbow.attach(11);
  wrist.attach(12);
  gripper.attach(13);

  base.write(base_angle);
  shoulder.write(shoulder_angle);
  elbow.write(elbow_angle);
  wrist.write(wrist_angle);

}


String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;

  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}

void loop() {
  
  String computerText = Serial.readStringUntil('@');
  computerText.trim();
  if (computerText.length() == 0) {
    return;
  }

  String command = getValue(computerText, ' ',0);

    if (command == "right" || command == "Right" || command == "رايت") {
      base.write(base_angle -= 20);
    }
    if (command == "left" || command == "Left" || command == "لفت" ) {
     base.write(base_angle += 20);
    }

    if (command == "top" || command == "Top" || command == "توب") {
      shoulder.write(shoulder_angle -= 20);
    }

   if (command == "bottom"|| command == "Bottom" || command == "بوتوم" ) {
     shoulder.write(shoulder_angle += 20);
    }
    Serial.println(command);
  Serial.println("WORKING");
  delay(1000);
}
