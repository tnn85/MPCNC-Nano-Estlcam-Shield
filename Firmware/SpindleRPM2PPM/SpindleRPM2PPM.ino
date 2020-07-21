/*
 * Spindle RPM-Signal to PPM-Signal conversion (e.g. for controlling RC model motor with ESCs, RC model servos)  
 * 
 * Author: Till Nenz
 * Date: 20.07.2020
 * Version: 0.1
 * 
 * Description:
 * Reads an analog input pin (Signal "Spindle_Speed_Analog_0-5V"), 
 * maps the result to a range from MIN_PPM_PULSE (default 1000µs) to MAX_PPM_PULSE (default 2000µs) and uses
 * the result to set the pulse pause modulated signal (PPM) of an output pin (Signal "Servo_PPM").
 * Debug: If activated, prints the results to the Serial Monitor (however, this causes the servo signal to jitter and should only be used to debug).
 * 
 * Required IC:
 * -ATtiny25/45/85-20PU (Package: PDIP) (tested with ATtiny85) (ATtiny 25 Program space might be too small for future releases)
 * 
 * Required Software:
 * -Arduino IDE 1.8.13 or newer
 * -ATTiny Core by SpenceKonde (https://github.com/SpenceKonde/ATTinyCore/blob/master/Installation.md)
 * 
 * Required chip fuse settings:
 * -ATtiny fuse bytes have to be programmed before flashing this firmware
 * -Low Fuse: 0xE2; High Fuse: 0xDF; Extended Fuse: 0xFF;  (AVRDUDE: -U lfuse:w:0xe2:m -U hfuse:w:0xdf:m -U efuse:w:0xff:m)
 * 
 * The circuit:
 *   - see "MPCNC Nano Estlcam Shield V1.x.pdf" schematic
 *   - connect Servo/ESC to J28 pin header (white cable [servo signal] left pin [facing to the µC/ATtiny], red cable [VCC/5V] middle pin, black cable [GND] right pin)
 *   - UART debug output (Baud: 115200 bit/s) on MOSI pin (Pin 5/PB0/Arduino Pin 0) (see https://github.com/SpenceKonde/ATTinyCore/blob/master/avr/extras/ATtiny_x5.md) connected to the ICSP header
 * 
 * based on:   
 * https://github.com/SpenceKonde/ATTinyCore/blob/master/avr/libraries/Servo_ATTinyCore/examples/Knob/Knob.ino
 * 
 */

#include <Servo_ATTinyCore.h>

//#define DEBUG_SERIAL

// Pin definitions
#define ANALOG_SPINDLE_RPM_IN_PIN  A2  // Analog input pin that the Arduino Nano spindle RPM signal is attached to
#define PPM_SPINDLE_RPM_OUT_PIN  3 //  // Digital output pin that the motor ESC / servo is attached to

// ESC/Servo PPM pulse length [µs]
#define MIN_PPM_PULSE 1000
#define MAX_PPM_PULSE 2000

int analogSpindleRPMValue = 0;        // value read from the input spindle RPM signal
int ppmSpindleRPMValue = 0;           // value pulse length [µ output to the PPM 

Servo servo_esc;  // create servo object to control an esc or servo

void setup() {
#ifdef DEBUG_SERIAL
  // initialize serial communications at 115200 bps:
  Serial.begin(115200);
  //ACSR &=~(1<<ACIE);  //Turn off UART Tx
  //ACSR |=~(1<<ACD);   //Turn off UART Tx
#endif
  servo_esc.attach(PPM_SPINDLE_RPM_OUT_PIN, MIN_PPM_PULSE, MAX_PPM_PULSE);  // attaches the servo on pin PPM_SPINDLE_RPM_OUT_PIN to the servo object and sets min and max values for writes (in µs). 

}

void loop() {
  // read the analog in value:
  analogSpindleRPMValue = analogRead(ANALOG_SPINDLE_RPM_IN_PIN);
  // map it to the range of the analog out:
  ppmSpindleRPMValue = map(analogSpindleRPMValue, 0, 1023, MIN_PPM_PULSE, MAX_PPM_PULSE);
    
  //servo_esc.writeMicroseconds( (int) ppmSpindleRPMValueAvg.getAverage());  // sets the servo position according to the scaled value
  servo_esc.writeMicroseconds(ppmSpindleRPMValue);  // sets the servo position according to the scaled value


  // wait 15 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading and the esc/servo to geht there:
  delay(15); // waits for the servo to get there

#ifdef DEBUG_SERIAL
  // print the results to the Serial Monitor:
  //Serial.print("Spindle RPM [0..1023]= "); // Spindle RPM measured on ADC [0..1023]
  //Serial.print(analogSpindleRPMValue);
  //Serial.print("\t Servo/ESC pulse length= "); // Servo/ESC output PPM signal pulse length [MIN_PPM_PULSE µs..MAX_PPM_PULSE µs] 
  //Serial.println(ppmSpindleRPMValue);
#endif

}
