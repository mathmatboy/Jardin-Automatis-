/*
 * TOMATE
 */
int analogPinTomate = A0;
int analogTomateValue;
int limitTomate = 500;
bool etatValveTomate = false;
/*
 * FINE HERBE
 */
int analogPinFineHerbe = A1;
int analogFineHerbeValue;
int limitFineHerbe = 450;
bool etatValveFineHerbe = false;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);//VALVE TOMATE
  pinMode(12, OUTPUT);//VALVE FINE HERBE

  pinMode(8, OUTPUT);//POMPE
}

void loop() {

  analogTomateValue = analogRead(analogPinTomate);
  analogFineHerbeValue = analogRead(analogPinFineHerbe);
  /*
   * TOMATE
   */
  Serial.println("Analog TOMATE valeur : ");
  Serial.println(analogTomateValue);
  if (analogTomateValue<limitTomate) {
  digitalWrite(13, HIGH);
  delay(1000);
  etatValveTomate = true;
  Serial.println("Le taux d'humidité des TOMATE est *HAUTE* donc pas besoin d'arroser !");
  }
  else {
  digitalWrite(13, LOW);
  Serial.println("Le taux d'humidité des TOMATE est *BAS*, la vanne ouvre !");
  etatValveTomate = false;
  }

  /*
   * FINE HERBE
   */
  Serial.println("Analog Fine Herbe valeur : ");
  Serial.println(analogFineHerbeValue);
  if (analogFineHerbeValue<limitFineHerbe) {
  digitalWrite(12, HIGH);
  delay(1000);
  etatValveFineHerbe = true;
  Serial.println("Le taux d'humidité des FINE HERBE est *HAUTE* donc pas besoin d'arroser !");
  }
  else {
  digitalWrite(12, LOW);
  Serial.println("Le taux d'humidité des FINE HERBE est *BAS*, la vanne ouvre !");
  etatValveFineHerbe = false;
  }

  if(etatValveTomate || etatValveFineHerbe){
    digitalWrite(8, HIGH);
    Serial.println("** La pompe Démarre **");
  }
  else{
    digitalWrite(8, LOW);
    Serial.println("** La pompe en Arrêt **");
  }
  delay(2000);
  
   
}
