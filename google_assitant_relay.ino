#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
int pin = 2;
char auth[] = "YcPzE2hn7vCu1UA24ksnLBlIG3q584cO";       // You should get Auth Token in the Blynk App.
char ssid[] = "🥱";                    // Your Wi-Fi Credentials
char pass[] = "gaurav1709";
bool toggleState_1 = LOW;
BLYNK_CONNECTED() {
  Blynk.syncVirtual(V1);

}
BLYNK_WRITE(V1) {
  Serial.println("Toggle");  

  toggleState_1 = param.asInt();
  if(toggleState_1 == 1){
    digitalWrite(pin, LOW);
  }
  else { 
    digitalWrite(pin, HIGH);
  }
}

void setup() {  
  pinMode(pin, OUTPUT); 
  pinMode(pin, HIGH);
  Serial.begin(115200);
  delay(10);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  int wifi_ctr = 0;
  while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");
  }
  Serial.println("WiFi connected");  
  Blynk.begin(auth, ssid, pass);
}
void loop(){
    Blynk.run();
}
