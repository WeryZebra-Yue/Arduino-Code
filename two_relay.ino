#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

int pin = 4; // Pin D4 on ESP32 // First pin
int pin = 5; // Pin D4 on ESP32 // Second pin
// Blynk Auth Token
char auth[] = "YcPzE2hn7vCu1UA24ksnLBlIG3q584cO";
// Your Wi-Fi Credentials
char ssid[] = " ";
char pass[] = " ";

void setup()
{
    pinMode(pin, OUTPUT);
    Serial.begin(115200);
    delay(10);
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, pass);
    int wifi_ctr = 0;
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("WiFi connected");
    Blynk.begin(auth, ssid, pass);
}
void loop()
{
    Blynk.run();
