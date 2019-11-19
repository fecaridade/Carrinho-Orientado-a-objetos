/*
autor: Felipe Caridade
desc: Controlar um carro de controle remoto usando OO
*/

#include "Arduino.h"
#include "OO-car.h"


//Construtor - Metodos
OOCarMotor::OOCarMotor(int pino_In1, int pino_In2, int pino_pwm){
    _pino_In1 = pino_In1;
    _pino_In2 = pino_In2;
    _pino_pwm = pino_pwm;
     pinMode(_pino_In1, OUTPUT);
     pinMode(_pino_In2, OUTPUT);
     pinMode(_pino_pwm, OUTPUT);
}
//Velocidade - Metodos
void OOCarMotor::setSpeed(int velocidade){
    _velocidade = velocidade;
}

//Direção - Metodos
void OOCarMotor::run(int direcao){
    _direcao = direcao;

    switch (_direcao) {
	    case FORWARD:
	        digitalWrite(_pino_In1, HIGH);
	        digitalWrite(_pino_In2, LOW);
	        break;
	    case BACKWARD:
	        digitalWrite(_pino_In1, LOW);
	        digitalWrite(_pino_In2, HIGH);
	        break;
	    case BRAKE:
	        digitalWrite(_pino_In1, HIGH);
	        digitalWrite(_pino_In2, HIGH);
	        break;
	    case RELEASE:
	        digitalWrite(_pino_In1, LOW);
	        digitalWrite(_pino_In2, LOW);
	      break;
    

	}
}

OOCarControlLed::OOCarControlLed(int pino_led){
    _pino_led = pino_led;

    pinMode(_pino_led, OUTPUT);
}

void OOCarControlLed::acender(){
    pinMode(_pino_led,HIGH);
}

void OOCarControlLed::apagar(){
    pinMode(_pino_led,LOW);
}

