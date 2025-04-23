// WHAT IT DOSE:-
// -> Connects to WiFi (STA Mod)
// -> Hosts a Web server on local IP
// -> Whene you visit that IPin a browser, it show: "Hello from ESP8266!"

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "Vijaypatil"; // ssid:- Service set identifire
const char* password = "12345678";

//create a web server object names "srver that listens for incoming HTTP requests on Port 80"
//Clint (Request) -> server (responce) -> Client

ESP8266WebServer server(80); //Port 80 is default for HTTP

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); //star serial communication
  WiFi.begin(ssid, password);
  Serial.println("\n Connecting to WiFi...");

  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\n Connected to WiFi!");
  Serial.print("IP Address:");
  Serial.println(WiFi.localIP());

  //Define the responce for whene  the user visits the root URL ("/") in there browser

  server.on("/",[](){
    //send an HTTP status 200(ok),with content type "text/html,and a simple HTML messgae
    server.send(200,"text/html", "<h1> VIJAY PATIL <h1>");
  });
  server.begin();
  Serial.println("Web Server Started!"); 
}

//the loop function runs continously after setup() it listens and response to HTTP client
//request
void loop() {
  // put your main code here, to run repeatedly:
server.handleClient();
// this function cheacks if any client has made request and handles it
}

