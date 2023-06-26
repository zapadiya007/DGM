#include "dht.h"
#define dht_apin A0 // Analog Pin sensor is connected to
dht DHT; 
int water; //random variable 

void setup(){

  Serial.begin(9600);
  delay(500);//Delay to let system boot

  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  Serial.println("Soil Moisture Sensor\n\n");

  pinMode(4,OUTPUT); //output pin for relay board, this will sent signal to the relay
  pinMode(6,INPUT); //input pin coming from soil sensor

  delay(1000);//Wait before accessing Sensor
 
}//end "setup()"
 
void loop(){
    //Start of Program 

    // Soil sensor =====================
    water = digitalRead(6);  // reading the coming signal from the soil sensor
    if(water == HIGH) // if water level is full then cut the relay 
    {
    digitalWrite(4,HIGH); // low is to cut the relay
    }
    else
    {
    digitalWrite(4,LOW); //high to continue proving signal and water supply
    } 

    // DHT Senosr ===================
    DHT.read11(dht_apin);
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
    delay(1000);//Wait 1 seconds before accessing sensor again.
 
    //Fastest should be once every two seconds.
 
}// end loop()
