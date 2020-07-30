#include <ESP8266WiFi.h>
 
const char* nombre = "hackeame";//Nombre de la red wifi
const char* password = "facilito";//Password

WiFiServer server(80);//Puerto (dejar en 80 por defecto)
 
void setup() {
  Serial.begin(115200);
  delay(50); //Hay que dejar un margen de tiempo
 
  // Conectar a la red WiFi
  WiFi.begin(nombre, password);
  while (WiFi.status() != WL_CONNECTED)
    delay(100); //aqui tambien hay que dejar un margen de tiempo
  Serial.println("Conectado a la red WiFi");
  
  // Iniciar el servidor
  server.begin();
  Serial.println("Se ha iniciado el servidor");
  
  // Escribir la direccion IP
  Serial.print("IP: ");
  Serial.print(WiFi.localIP());
  Serial.println("");
  
}
  
void loop() {
  // Comprobar si se ha conectado algun cliente
  WiFiClient client = server.available();
   
  if (client) {
    Serial.println("Nueva conexion");
    
    // Escribir las cabeceras HTML
    
   
    //Escribir el contenido que vamos a visualizar
    client.println("<html>");
    client.print("<H1> HOLA GUSTAVO </H1>");
    client.print("<H1> ISISTE LA TAREA </H1>");
    client.print("<H1> NOS VEMOS POR EL CENTROO </H1>");
    client.print("<H1> ADIOS </H1>");
    client.println("</html>");
     
  }
  
}
