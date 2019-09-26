int led = 5;
int boton = 3;
bool encendido = false;
int brillo = 0;


void setup() {
  Serial.begin(9600);
  pinMode(boton, INPUT);
  pinMode(led, OUTPUT);


}

void loop() {
  bool estado_pulsador = digitalRead(boton);
//  Serial.println(estado_pulsador);
  if(estado_pulsador == false){
    if(digitalRead(led) == false){
      for (int brillo = 0; brillo < 255; brillo++) {
        analogWrite(led,brillo);
        delay(10);
      }
      digitalWrite(led,HIGH);
      encendido = true;
  //    delay(250);
      Serial.println("encendido");
    }
    else{
      for (int brillo = 255; brillo > 0; brillo--) {
        analogWrite(led,brillo);
        delay(10);
      }
      digitalWrite(led,LOW);
      encendido = false;
  //    delay(250);
      Serial.println("apagado");
    }

  }
}
