/* ======================================================================================================
   
   Baseado no código fornecido pela Usina Info & WR Kits
   
   Medindo RPM de um Motor DC com Arduino


   Compilador: Arduino IDE 1.8.4

   Autor: Eng. Wagner Rambo  Data: Março de 2018
   
   www.wrkits.com.br | facebook.com/wrkits | youtube.com/canalwrkits


   HARDWARE:
 

   ARDUINO    ENCODER

   GND          GND
   5V            5V
   D2           OUT

   
====================================================================================================== */

class Speedometer {
  public:
    Speedometer();
    Speedometer(unsigned int pulsesAround);

    void setup();

    // Busca a velocidade atual em RPMs
    int getSpeed();
  private:
    int           rpm;
    volatile byte pulses;
    unsigned long timeOld;

    //Altere o numero abaixo de acordo com o seu disco encoder
    unsigned int pulsesAround;

    void incrementCounterValue();

    // Calcula a diferença
    unsigned long delta();

    void detach();
    void attach();

}