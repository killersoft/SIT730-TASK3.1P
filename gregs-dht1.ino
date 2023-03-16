// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_DHT.h>


#define DHTPIN 2     // what pin the sensor is plugged into

#define DHTTYPE DHT22		// DHT 22 (AM2302)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
	Serial.begin(9600); // Can see output using putty and connecting to console port on windows pc of particle device for println etc...
	dht.begin(); //Enable the DHT sensor
}

void loop() {

	delay(30000); // Wait 30 seconds

	float t = dht.getTempCelcius(); // Get Temp as a float value

	if ( isnan(t)) { // Check validity of readings
			return; // If bad then exit
	} else {  // If values were good....
	    
	char tempcelcius[5]; // small string to store float to string conversion in

    snprintf(tempcelcius, sizeof(tempcelcius), "%.2f", t); //Best way to put a float with 2 decimal points and convert to string and for it to fit the string space !

    Particle.publish("temp", tempcelcius, PRIVATE);  // Send data back to particle integrations, and then to thingspeak ( prob better to send back to thingspeak direct )
	}
}