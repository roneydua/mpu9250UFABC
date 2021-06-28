#include <IMU.h>
#include <Eigen/Dense>
// #include <eigen3/Eigen/Dense>
#include <Arduino.h>

using namespace Eigen;

Vector3f acel, giro, mag = Vector3f::Zero();
// Instancia a classe IMU
IMU imu(Wire, 0x68);

void setup() {
  Serial.begin(115200);
  // instancia os ponteiros com as medidas
  imu.begin(acel, giro, mag);
}
void loop() {
  imu.readSensor();
  Serial.printf("%.f;", acel(0));
  Serial.printf("%.f;", acel(1));
  Serial.printf("%.f\t", acel(2));
  Serial.printf("%.f;", giro(0));
  Serial.printf("%.f;", giro(1));
  Serial.printf("%.f\t", giro(2));
  Serial.printf("%.f;", mag(0));
  Serial.printf("%.f;", mag(1));
  Serial.printf("%.f\t", mag(2));
}
