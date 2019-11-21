/*
autor: Felipe Caridade 
desc: Controlar um carro de controle remoto usando OO
*/

#ifndef Carro_OO_h
#define Carro_OO_h
#include "Arduino.h"


// Variavies que guardam o valor para onde o carro deverá ir
#define FORWARD  1
#define BACKWARD 2
#define BRAKE    3
#define RELEASE  4



//Classe de controle do motor
class OOCarMotor
{
    public:
        OOCarMotor(int pino_In1, int pino_In2, int pino_pwm);
	    void setSpeed(int velocidade);
	    void run(int direcao);

    private:
        int _pino_In1, _pino_In2, _pino_pwm;
		int _velocidade;
		int _direcao;
};
// Classe para controle dos Led´s
class OOCarControlLed
{
    public:
        OOCarControlLed(int pino_led);
	    void acender();
        void apagar();


    private:
        int _pino_led;
};

#endif