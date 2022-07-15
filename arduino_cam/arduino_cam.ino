#include <SpheroRVR.h>
#include <Servo.h>
#include <math.h>

static DriveControl driveControl;
int item1, item2, item3, item4;
int heading = 0;

void setup() {
  // set up communication with the RVR
  rvr.configUART(&Serial);
  // get the RVR's DriveControl
  driveControl = rvr.getDriveControl();
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  int a0 = digitalRead(A0);
  int a1 = digitalRead(A1);
  int a2 = digitalRead(A2);
  int a3 = digitalRead(A3);
  int a4 = digitalRead(A4);

  if (a0 == 1) {
    driveControl.setRawMotors(rawMotorModes::forward, 90, rawMotorModes::forward, 90);
    delay(200);
  }
  if (a1 == 1) {
    driveControl.setRawMotors(rawMotorModes::reverse, 64, rawMotorModes::reverse, 64);
    delay(200);
  }
  if (a2 == 1) {
    driveControl.setRawMotors(rawMotorModes::forward, 20, rawMotorModes::forward, 120);
    delay(200);
  }
  if (a3 == 1) {
    driveControl.setRawMotors(rawMotorModes::forward, 120, rawMotorModes::forward, 20);
    delay(200);
  }
  if (a4 == 1) {
    driveControl.setRawMotors(rawMotorModes::off, 0, rawMotorModes::off, 0);
  }
}
