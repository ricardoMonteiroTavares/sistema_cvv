class Engine 
{
  public:
    Engine(unsigned int enginePort, unsigned int maxRPMLimit);

    void setup();

    // Modifica o limite máximo de velocidade do motor
    void setSpeedLimiter(unsigned int speedLimiter);

    unsigned int getSpeedLimiter();

    // Busca a velocidade atual do motor
    int getSpeed();

  private:
    unsigned int enginePort;
    unsigned int maxRPMLimit;
    unsigned int speedLimiter;

    // Local onde guardará no módulo PWM o valor da velocidade do motor
    void write(unsigned int speed);

    // Local onde buscará a velocidade atual do motor
    int read();
}