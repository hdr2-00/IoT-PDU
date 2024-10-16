#include <ESP8266WiFi.h>
#include <PubSubClient.h>
void callback(char* topic, byte* payload, unsigned int length);
const char* ssid = "Honor 6X";
const char* password = "12348765";
//const char* mqtt_server = "192.168.0.160";
const char* mqtt_server = "192.168.43.28";
const int mqtt_port = 1883;
const char* topic1 = "Data";
const char* topic2 = "Control";
char const* switchTopic1 = "loadSwitch1";
char const* switchTopic2 = "loadSwitch2";
char const* switchTopic3 = "loadSwitch3";
char const* switchTopic4 = "loadSwitch4";
const int switchPin1 = D7;
const int switchPin2 = D5;
const int switchPin3 = D6;
const int switchPin4 = D3;

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {

   digitalWrite(switchPin1, HIGH);
    digitalWrite(switchPin2, HIGH);
    digitalWrite(switchPin3, HIGH);
     digitalWrite(switchPin4, HIGH);
   pinMode(switchPin1, OUTPUT); // Relay Switch 1
  pinMode(switchPin2, OUTPUT); // Relay Switch 2
  pinMode(switchPin3, OUTPUT); // Relay Switch 3
  pinMode(switchPin4, OUTPUT); // Relay Switch 4
 
  Serial.begin(115200); // Match baud rate with Arduino Uno
  delay(1000);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}
void callback(char* topic, byte* payload, unsigned int length) {
  String topicStr = topic; 
  Serial.println("Callback update.");
  Serial.print("Topic: ");
  Serial.println(topicStr);
   if (topicStr == "loadSwitch1") 
    {
     if(payload[0] == '1'){
       digitalWrite(switchPin1, LOW);
       }
     else if (payload[0] == '0'){
       digitalWrite(switchPin1, HIGH);
       
       }
     }

     else if (topicStr == "loadSwitch2") 
     {
     if(payload[0] == '1'){
       digitalWrite(switchPin2, LOW);
       }
     else if (payload[0] == '0'){
       digitalWrite(switchPin2, HIGH);
       }
     }
      else if (topicStr == "loadSwitch3") 
     {
     if(payload[0] == '1'){
       digitalWrite(switchPin3, LOW);
       }
     else if (payload[0] == '0'){
       digitalWrite(switchPin3, HIGH);
       }
     }
      else if (topicStr == "loadSwitch4") 
     {
     if(payload[0] == '1'){
       digitalWrite(switchPin4, LOW);
       }
     else if (payload[0] == '0'){
       digitalWrite(switchPin4, HIGH);
       }
     }
}
void reconnect() {
  while (!client.connected()) {
    Serial.print("Connecting to MQTT... ");
    if (client.connect("ESP8266Client")) {
      Serial.println("connected");
       client.subscribe(switchTopic1);
       client.subscribe(switchTopic2);
       client.subscribe(switchTopic3);
       client.subscribe(switchTopic4);
       
    } else {
      
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
       digitalWrite(switchPin1, HIGH);
      digitalWrite(switchPin2, HIGH);
      digitalWrite(switchPin3, HIGH);
      digitalWrite(switchPin4, HIGH);
      delay(3000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
   if (Serial.available() > 0) {
          String data = Serial.readStringUntil(';');
          client.publish(topic1, data.c_str());
          Serial.println(data);
        }
   
      
  delay(100);
}
