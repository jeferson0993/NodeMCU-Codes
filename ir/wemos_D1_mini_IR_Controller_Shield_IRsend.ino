/* IRremoteESP8266: IRsendDemo - demonstrates sending IR codes with IRsend.
 *
 * Version 1.0 April, 2017
 * Based on Ken Shirriff's IrsendDemo Version 0.1 July, 2009,
 * Copyright 2009 Ken Shirriff, http://arcfn.com
 *
 * An IR LED circuit *MUST* be connected to the ESP8266 on a pin
 * as specified by IR_LED below.
 *
 * TL;DR: The IR LED needs to be driven by a transistor for a good result.
 *
 * Suggested circuit:
 *     https://github.com/markszabo/IRremoteESP8266/wiki#ir-sending
 *
 * Common mistakes & tips:
 *   * Don't just connect the IR LED directly to the pin, it won't
 *     have enough current to drive the IR LED effectively.
 *   * Make sure you have the IR LED polarity correct.
 *     See: https://learn.sparkfun.com/tutorials/polarity/diode-and-led-polarity
 *   * Typical digital camera/phones can be used to see if the IR LED is flashed.
 *     Replace the IR LED with a normal LED if you don't have a digital camera
 *     when debugging.
 *   * Avoid using the following pins unless you really know what you are doing:
 *     * Pin 0/D3: Can interfere with the boot/program mode & support circuits.
 *     * Pin 1/TX/TXD0: Any serial transmissions from the ESP8266 will interfere.
 *     * Pin 3/RX/RXD0: Any serial transmissions to the ESP8266 will interfere.
 *   * ESP-01 modules are tricky. We suggest you use a module with more GPIOs
 *     for your first time. e.g. ESP-12 etc.
 */

#ifndef UNIT_TEST
#include <Arduino.h>
#endif
#include <IRremoteESP8266.h>
#include <IRsend.h>

#define IR_LED D3  

IRsend irsend(IR_LED);  // Set the GPIO to be used to sending the message.

// Example of data captured by IRrecvDumpV2.ino
uint16_t rawData[71] = {9020, 4430,  596, 544,  590, 546,  590, 570,  566, 548,  590, 546,  592, 544,  590, 570,  566, 570,  566, 1664,  592, 1664,  594, 1664,  592, 1664,  592, 1662,  592, 1666,  594, 568,  566, 1666,  592, 1666,  592, 1664,  592, 546,  590, 546,  590, 546,  590, 546,  588, 550,  590, 544,  592, 570,  566, 570,  594, 1638,  592, 1664,  592, 1664,  592, 1664,  594, 1662,  592, 1664,  594, 41070,  9024, 2222,  592};  // NEC FDC03F
// uint16_t rawData[71] = {8996, 4456,  566, 574,  562, 574,  588, 546,  564, 574,  564, 574,  586, 550,  564, 572,  590, 548,  562, 1692,  564, 1692,  588, 1668,  590, 1666,  588, 1668,  564, 1692,  590, 548,  588, 1666,  564, 1694,  566, 1690,  566, 574,  562, 572,  564, 572,  564, 596,  538, 598,  540, 572,  562, 574,  564, 598,  538, 1692,  566, 1692,  564, 1692,  564, 1692,  566, 1690,  566, 1692,  566, 41094,  8996, 2250,  566};  // NEC FDC03F

void setup() {
  irsend.begin();
  Serial.begin(115200, SERIAL_8N1, SERIAL_TX_ONLY);
}

void loop() {
  Serial.println("a rawData capture from IRrecvDumpV2:");
  irsend.sendRaw(rawData, 71, 38);  // Send a raw data capture at 38kHz.

  delay(2000);
}
