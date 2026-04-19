#include <TM1637Display.h>
#include <DHT11.h>
TM1637Display display(3,4);// CLK - PIN3 ... DIO - PIN4
DHT11 dht11(2); //DHT11 - PIN2
uint8_t celcius[] = {
 SEG_A|SEG_B|SEG_F|SEG_G,
 SEG_A|SEG_D|SEG_E|SEG_F};
void setup() {
    display.setBrightness(3);
    delay(2000);
}
void loop() {
    int temp = dht11.readTemperature();
    display.clear();
    display.showNumberDec(temp,false,2,0);
    display.setSegments(celcius,2,2);
    delay(2000);
}
