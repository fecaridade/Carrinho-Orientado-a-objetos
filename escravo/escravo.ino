#include <AFMotor.h>
#include <SoftwareSerial.h>
AF_DCMotor motor_Frontal_Esquerdo(1);
AF_DCMotor motor_Frontal_Direito(4);
AF_DCMotor motor_Traseiro_Esquerdo(2);
AF_DCMotor motor_Traseiro_Direito(3);
SoftwareSerial bluetooth(53, 51);
int commando = 0;

#define ledBaixo 52
#define farolEsquerdo 45
#define farolDireito 47
#define ledBaixoUltra 50




void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(ledBaixoUltra,OUTPUT);
  pinMode(ledBaixo, OUTPUT);
  pinMode(farolEsquerdo, OUTPUT);
  pinMode(farolDireito, OUTPUT);
  motor_Frontal_Esquerdo.setSpeed(255);
  motor_Frontal_Direito.setSpeed(255);
  motor_Traseiro_Esquerdo.setSpeed(255);
  motor_Traseiro_Direito.setSpeed(255);
}

void loop() {


  if (Serial.available() > 0) {
    digitalWrite(ledBaixoUltra,HIGH);
    digitalWrite(ledBaixo, HIGH);
    digitalWrite(farolEsquerdo, HIGH);
    digitalWrite(farolDireito, HIGH);
    commando = Serial.read();
    Serial.println(commando);

    if (commando == 102)
    {
      Frente();
    }
    if (commando == 98)
    {
      Tras();
    }
    if (commando == 108)
    {
      Esquerda();
    }
    if (commando == 114)
    {
      Direita();
    }
    if (commando == 97)
    {
      digitalWrite(farolEsquerdo,HIGH);
      digitalWrite(farolEsquerdo,HIGH);
      }
      if (commando == 112)
    {
      digitalWrite(farolEsquerdo,LOW);
      digitalWrite(farolDireito,LOW);
      }
    
  }
  else if (bluetooth.available() > 0)
  {
    digitalWrite(ledBaixo, HIGH);
    digitalWrite(farolEsquerdo, HIGH);
    digitalWrite(farolDireito, HIGH);
    commando = bluetooth.read();
    Serial.println(commando);
    if (commando == 'f')
    {
      Frente();
    }
    if (commando == 'b')
    {
      Tras();
    }
    if (commando == 'l')
    {
      Esquerda();
    }
    if (commando == 'r')
    {
      Direita();
    }

  }
}



void Frente() {
  motor_Frontal_Esquerdo.run(FORWARD);
  motor_Frontal_Direito.run(FORWARD);
  motor_Traseiro_Esquerdo.run(FORWARD);
  motor_Traseiro_Direito.run(FORWARD);

}

void Tras() {
  motor_Frontal_Esquerdo.run(BACKWARD);
  motor_Frontal_Direito.run(BACKWARD);
  motor_Traseiro_Esquerdo.run(BACKWARD);
  motor_Traseiro_Direito.run(BACKWARD);

}


void Esquerda() {
  motor_Frontal_Esquerdo.run(RELEASE);
  motor_Frontal_Direito.run(FORWARD);
  motor_Traseiro_Esquerdo.run(RELEASE);
  motor_Traseiro_Direito.run(FORWARD);

}


void Direita() {
  motor_Frontal_Esquerdo.run(FORWARD);
  motor_Frontal_Direito.run(RELEASE);
  motor_Traseiro_Esquerdo.run(FORWARD);
  motor_Traseiro_Direito.run(RELEASE);

}
