#ifndef Debounce_h
#define Debounce_h

class Debounce {
  public:
    Debounce(short int pin);
    short int read();
  private:
    short int _pinBtn;
    int _btnStadoAnterior;
};

Debounce::Debounce(short int pin) {
  pinMode(_pinBtn, INPUT);
  _pinBtn = pin;
  _btnStadoAnterior = 0;
}

short int Debounce::read() {
  short int rta = LOW;
  short int sActual = digitalRead(_pinBtn);
  if ( sActual == 1 && _btnStadoAnterior == 0 ) {
    rta = HIGH;
    _btnStadoAnterior = 1;
  } else if (sActual == 1 && _btnStadoAnterior == 1) {
    rta = LOW;
  }
  if (sActual == 0) {
    rta = LOW;
    _btnStadoAnterior = 0;
  }
  return rta;
}

#endif
