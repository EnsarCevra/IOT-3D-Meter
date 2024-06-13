#include <Ultrasonic.h>
#include<ESP8266WiFi.h>
#include<FirebaseESP8266.h>

const char *ssid = "YOUR_SSID";
const char *password = "YOUR_WIFI_PASSWORD";

#define FIREBASE_HOST "YOUR_HOST"
#define FIREBASE_AUTH "YOUR_AUTH"
#define REFERENCE_URL "REFERENCE URL"

#define TRIGGER_PIN_DISTANCE D1
#define ECHO_PIN_DISTANCE D2

#define TRIGGER_PIN_HEIGHT D3
#define ECHO_PIN_HEIGHT D4

#define TRIGGER_PIN_WIDTH D5
#define ECHO_PIN_WIDTH D6

FirebaseData firebaseData;
Ultrasonic ultrasonic_distance(TRIGGER_PIN_DISTANCE, ECHO_PIN_DISTANCE);
Ultrasonic ultrasonic_height(TRIGGER_PIN_HEIGHT, ECHO_PIN_HEIGHT);
Ultrasonic ultrasonic_width(TRIGGER_PIN_WIDTH, ECHO_PIN_WIDTH);
void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED)
  {
    delay(250);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
  Firebase.setMaxRetry(firebaseData, 5);
}

void loop() {
  bool Status;
  bool StatusDistance;
  bool StatusHeight;
  bool StatusWidth;
  
  if(Firebase.getBool(firebaseData, "/Status/Device", &Status))
  {
    if(Status)
    {

      //duzina
      if(Firebase.getBool(firebaseData, "Status/Distance", &StatusDistance)){
        if(StatusDistance)
        {
          Firebase.setInt(firebaseData, "data/Distance", ultrasonic_distance.read());
        }
      }

      //visina
      if(Firebase.getBool(firebaseData, "Status/Height", &StatusHeight)){
        if(StatusHeight)
        {
          Firebase.setInt(firebaseData, "data/Height", ultrasonic_height.read());
        }
      }


      //Sirina
      if(Firebase.getBool(firebaseData, "Status/Width", &StatusWidth))
      {
        if(StatusWidth)
        {
          Firebase.setInt(firebaseData, "data/Width", ultrasonic_width.read());
        }
      }
    }
    else
    {
      Firebase.setInt(firebaseData, "data/Distance", 0);
      Firebase.setInt(firebaseData, "data/Width", 0);
      Firebase.setInt(firebaseData, "data/Height", 0);
    }
  }
  delay(100);
}
