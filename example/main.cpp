#include <IMU.h>
#include <Eigen/Core>
#include <Arduino.h>

using namespace Eigen;

Vector3f acel = Vector3f::Zero(), giro = Vector3f::Zero(),
         mag = Vector3f::Zero();
// Instancia a classe IMU
IMU imu(Wire, 0x68);

void setup() {
  Serial.begin(115200);
  // instancia os ponteiros com as medidas
  delay(2000);
  imu.begin(acel, giro, mag, 21, 22);
}
void loop() {
  imu.readSensor();
  Serial.printf("Acel: %2.4f;", acel(0));
  Serial.printf("%2.4f;", acel(1));
  Serial.printf("%2.4f\t", acel(2));

  Serial.printf("Giro: %2.4f;", giro(0));
  Serial.printf("%2.4f;", giro(1));
  Serial.printf("%2.4f\t", giro(2));

  Serial.printf("Mag: %2.4f;", mag(0));
  Serial.printf("%2.4f;", mag(1));
  Serial.printf("%2.4f \n", mag(2));
  vTaskDelay(200);
}
