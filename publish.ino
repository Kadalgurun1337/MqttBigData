#include <WiFi.h>
#include <PubSubClient.h>

// WiFi credentials
const char* ssid = "Z-tech";
const char* password = "ngokngok";

// MQTT Broker credentials
const char* mqtt_server = "";
const int mqtt_port = 1883;
const char* mqtt_user = "";
const char* mqtt_password = "";

// JSON Payload (ringkas agar muat di contoh; ganti dengan full JSON Anda)
const char* jsonPayload = R"rawliteral(
{
  "gateway": {
    "sn": "dgo0007",
    "slave_status": "active"
  },
  "temperatures": {
    "TEMP1": "-50.00",
    "TEMP2": "32.40",
    "TEMP3": "-50.00",
    "TEMP4": "32.50",
    "TEMP5": "33.40",
    "TEMP6": "-50.00",
    "TEMP7": "-50.00",
    "TEMP8": "-50.00",
    "TEMP9": "-50.00",
    "TEMP10": "-50.00",
    "TEMP11": "-50.00",
    "TEMP12": "-50.00",
    "TEMP13": "-50.00",
    "TEMP14": "-50.00",
    "TEMP15": "-50.00",
    "TEMP16": "-50.00",
    "TEMP17": "-50.00",
    "TEMP18": "-50.00",
    "TEMP19": "32.30",
    "TEMP20": "30.90",
    "TEMP21": "-50.00",
    "TEMP22": "-50.00",
    "TEMP23": "32.30",
    "TEMP24": "31.20",
    "TEMP25": "32.60",
    "TEMP26": "31.10",
    "TEMP27": "32.60",
    "TEMP28": "31.10",
    "TEMP29": "32.50",
    "TEMP30": "31.20",
    "TEMP31": "-50.00",
    "TEMP32": "-50.00",
    "TEMP33": "-50.00",
    "TEMP34": "-50.00",
    "TEMP35": "-50.00",
    "TEMP36": "-50.00",
    "TEMP37": "-50.00",
    "TEMP38": "-50.00",
    "TEMP39": "-50.00",
    "TEMP40": "-50.00",
    "TEMP41": "-50.00",
    "TEMP42": "-50.00",
    "TEMP43": "-50.00",
    "TEMP44": "-50.00",
    "TEMP45": "-50.00",
    "TEMP46": "-50.00",
    "TEMP47": "-50.00",
    "TEMP48": "-50.00",
    "TEMP49": "-50.00",
    "TEMP50": "-50.00",
    "TEMP51": "-50.00",
    "TEMP52": "-50.00",
    "TEMP53": "-50.00",
    "TEMP54": "-50.00",
    "TEMP55": "-50.00",
    "TEMP56": "-50.00",
    "TEMP57": "-50.00",
    "TEMP58": "-50.00",
    "TEMP59": "-50.00",
    "TEMP60": "-50.00",
    "TEMP61": "-50.00",
    "TEMP62": "-50.00",
    "TEMP63": "-50.00",
    "TEMP64": "-50.00",
    "TEMP65": "-0.10",
    "TEMP66": "-0.10",
    "TEMP67": "-0.10",
    "TEMP68": "-0.10",
    "TEMP69": "-0.10",
    "TEMP70": "-0.10",
    "TEMP71": "-0.10",
    "TEMP72": "-0.10",
    "TEMP73": "-0.10",
    "TEMP74": "-0.10",
    "TEMP75": "-0.10",
    "TEMP76": "-0.10",
    "TEMP77": "-0.10",
    "TEMP78": "-0.10",
    "TEMP79": "-0.10",
    "TEMP80": "-0.10",
    "TEMP81": "-0.10",
    "TEMP82": "-0.10",
    "TEMP83": "-0.10",
    "TEMP84": "-0.10",
    "TEMP85": "-0.10",
    "TEMP86": "-0.10",
    "TEMP87": "-0.10",
    "TEMP88": "-0.10",
    "TEMP89": "-0.10",
    "TEMP90": "-0.10",
    "TEMP91": "-0.10",
    "TEMP92": "-0.10",
    "TEMP93": "-0.10",
    "TEMP94": "-0.10",
    "TEMP95": "-0.10",
    "TEMP96": "-0.10",
    "TEMP97": "-0.10",
    "TEMP98": "-0.10",
    "TEMP99": "-0.10",
    "TEMP100": "-0.10",
    "TEMP101": "-0.10",
    "TEMP102": "-0.10",
    "TEMP103": "-0.10",
    "TEMP104": "-0.10",
    "TEMP105": "-0.10",
    "TEMP106": "-0.10",
    "TEMP107": "-0.10",
    "TEMP108": "-0.10",
    "TEMP109": "-0.10",
    "TEMP110": "-0.10",
    "TEMP111": "-0.10",
    "TEMP112": "-0.10",
    "TEMP113": "-0.10",
    "TEMP114": "-0.10",
    "TEMP115": "-0.10",
    "TEMP116": "-0.10",
    "TEMP117": "-0.10",
    "TEMP118": "-0.10",
    "TEMP119": "-0.10",
    "TEMP120": "-0.10"
  },
  "ids": {
    "id1": "f8d1",
    "id2": "fa2f",
    "id3": "4fac",
    "id4": "4f6f",
    "id5": "3a8c",
    "id6": "3c24",
    "id7": "f8d0",
    "id8": "f8a3",
    "id9": "4fde",
    "id10": "4f94",
    "id11": "38e1",
    "id12": "38bd",
    "id13": "fb4a",
    "id14": "f960",
    "id15": "4f1d",
    "id16": "4c9d",
    "id17": "3adb",
    "id18": "3b1f",
    "id19": "fa44",
    "id20": "fa23",
    "id21": "4eaf",
    "id22": "4efe",
    "id23": "3a81",
    "id24": "3aba",
    "id25": "fb27",
    "id26": "f956",
    "id27": "4e39",
    "id28": "4ed2",
    "id29": "3938",
    "id30": "3aac",
    "id31": "91c7",
    "id32": "fae9",
    "id33": "4fb8",
    "id34": "4f98",
    "id35": "398d",
    "id36": "3944",
    "id37": "ffff",
    "id38": "ffff",
    "id39": "ffff",
    "id40": "ffff",
    "id41": "ffff",
    "id42": "ffff",
    "id43": "ffff",
    "id44": "ffff",
    "id45": "ffff",
    "id46": "ffff",
    "id47": "ffff",
    "id48": "ffff",
    "id49": "ffff",
    "id50": "ffff",
    "id51": "ffff",
    "id52": "ffff",
    "id53": "ffff",
    "id54": "ffff",
    "id55": "ffff",
    "id56": "ffff",
    "id57": "ffff",
    "id58": "ffff",
    "id59": "ffff",
    "id60": "ffff",
    "id61": "ffff",
    "id62": "ffff",
    "id63": "ffff",
    "id64": "ffff",
    "id65": "ffff",
    "id66": "ffff",
    "id67": "ffff",
    "id68": "ffff",
    "id69": "ffff",
    "id70": "ffff",
    "id71": "ffff",
    "id72": "ffff",
    "id73": "ffff",
    "id74": "ffff",
    "id75": "ffff",
    "id76": "ffff",
    "id77": "ffff",
    "id78": "ffff",
    "id79": "ffff",
    "id80": "ffff",
    "id81": "ffff",
    "id82": "ffff",
    "id83": "ffff",
    "id84": "ffff",
    "id85": "ffff",
    "id86": "ffff",
    "id87": "ffff",
    "id88": "ffff",
    "id89": "ffff",
    "id90": "ffff",
    "id91": "ffff",
    "id92": "ffff",
    "id93": "ffff",
    "id94": "ffff",
    "id95": "ffff",
    "id96": "ffff",
    "id97": "ffff",
    "id98": "ffff",
    "id99": "ffff",
    "id100": "ffff",
    "id101": "ffff",
    "id102": "ffff",
    "id103": "ffff",
    "id104": "ffff",
    "id105": "ffff",
    "id106": "ffff",
    "id107": "ffff",
    "id108": "ffff",
    "id109": "ffff",
    "id110": "ffff",
    "id111": "ffff",
    "id112": "ffff",
    "id113": "ffff",
    "id114": "ffff",
    "id115": "ffff",
    "id116": "ffff",
    "id117": "ffff",
    "id118": "ffff",
    "id119": "ffff",
    "id120": "ffff"
  }
}
)rawliteral";

// Interval pengiriman (5 menit)
unsigned long lastMsg = 0;
const long interval = 3000;  // 5 menit dalam milidetik

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  delay(100);
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);
  int retry = 0;
  while (WiFi.status() != WL_CONNECTED && retry < 20) {
    delay(500);
    Serial.print(".");
    retry++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWiFi connected. IP address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("\nWiFi connection failed.");
  }
}

bool mqtt_connect() {
  if (client.connected()) return true;

  Serial.print("Attempting MQTT connection...");
  if (client.connect("ESP32Client", mqtt_user, mqtt_password)) {
    Serial.println("connected");
    return true;
  } else {
    Serial.print("failed, rc=");
    Serial.print(client.state());
    Serial.println(", will retry later");
    return false;
  }
}

void sendData() {
  if (mqtt_connect()) {
    bool success = client.publish("glosmon/gateway/data", jsonPayload);
    if (success) {
      Serial.println("Payload sent successfully.");
    } else {
      Serial.println("Failed to send payload.");
    }
  } else {
    Serial.println("MQTT not connected, skip sending.");
  }
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setBufferSize(8192);
  client.setServer(mqtt_server, mqtt_port);

  // Kirim data langsung saat start
  sendData();
  lastMsg = millis();
}

void loop() {
  client.loop();

  unsigned long now = millis();
  if (now - lastMsg > interval) {
    lastMsg = now;
    sendData();
  }
}
