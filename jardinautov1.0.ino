/*
 * TOMATE
 */
int analogPinTomate = A0;
int analogTomateValue;
int limitTomate = 500;
bool etatValveTomate = false; //Boolean pour savoir l'état de ta valve Tomates
/*
 * FINE HERBE
 */
int analogPinFineHerbe = A1;
int analogFineHerbeValue;
int limitFineHerbe = 450;
bool etatValveFineHerbe = false; //Boolean pour savoir l'était de ta valve Fines herbes

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);//VALVE TOMATE
  pinMode(12, OUTPUT);//VALVE FINE HERBE

  pinMode(11, OUTPUT);
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
  digitalWrite(13, LOW);
  etatValveTomate = false; //Ton boolean devient false en meme temps que la sortie
  // digitalWrite(11, LOW); Enlever cette ligne (la pompe va démarrer plus bas)
  Serial.println("Le taux d'humidité des TOMATE est *HAUTE* donc pas besoin d'arroser !");
  }
  else {
  digitalWrite(13, HIGH);
  Serial.println("Le taux d'humidité des TOMATE est *BAS*, la vanne ouvre !");
  delay(1000);
  etatValveTomate = true; //Ton boolean devient true en meme temps que la sortie
  // digitalWrite(11, HIGH); Enlever cette ligne (la pompe va démarrer plus bas)
  // Serial.println("** La pompe Start T **");
  }

  /*
   * FINE HERBE
   */
  Serial.println("Analog Fine Herbe valeur : ");
  Serial.println(analogFineHerbeValue);
  if (analogFineHerbeValue<limitFineHerbe) {
  digitalWrite(12, LOW);
  etatValveFineHerbe = false; //Ton boolean devient false en meme temps que la sortie
  // digitalWrite(11, LOW); Enlever cette ligne (la pompe va démarrer plus bas)
  Serial.println("Le taux d'humidité des FINE HERBE est *HAUTE* donc pas besoin d'arroser !");
  }
  else {
  digitalWrite(12, HIGH);
  Serial.println("Le taux d'humidité des FINE HERBE est *BAS*, la vanne ouvre !");
  delay(1000);
  etatValveFineHerbe = true; //Ton boolean devient true en meme temps que la sortie
  // digitalWrite(11, LOW); Enlever cette ligne (la pompe va démarrer plus bas)
  // Serial.println("** La pompe Start FH **");
  }
  
  /*  Si la valve tomate ou si la valve fines herbes est à true, la pompe démarre
   *  sinon, la pompe arrête
   */
  if(etatValveTomate || etatValveFineHerbe) {
    digitalWrite(11, HIGH);
    Serial.println("** La pompe Start **");
  }
  else {
    digitalWrite(11, LOW);
    Serial.println("** La pompe arrete **");
  }
  
  delay(2000); 
}
