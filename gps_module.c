/*
    Project name : ESP32 GPS Module
    Modified Date: 24-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/esp32-gps-module
*/

#include <HardwareSerial.h>

// Define the serial interface connected to the GPS module
HardwareSerial gpsSerial(1);

void setup() {
  Serial.begin(9600);   // Initialize Serial Monitor for debugging
  gpsSerial.begin(9600); // Initialize Serial1 (UART) for GPS communication
}

void loop() {
  // Check if data is available to read from GPS module
  if (gpsSerial.available() > 0) {
    String gpsData = gpsSerial.readStringUntil('\n'); // Read the GPS data until newline character

    // Example: Assuming GPS module sends NMEA sentences, extract relevant information
    if (gpsData.startsWith("$GPGGA")) {
      // Parse the GPS data (example for GPGGA sentence)
      // For detailed parsing, refer to NMEA format specifications
      Serial.print("GPS Data: ");
      Serial.println(gpsData);
    }
  }
}
