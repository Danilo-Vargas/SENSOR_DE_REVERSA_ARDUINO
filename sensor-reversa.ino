// SENSOR DE REVERSA - Aldo Danilo Vargas Esquivel

// DECLARAR PINES

#define TRIG 8     // pin trig del sensor
#define ECHO A5    // pin echo del sensor
#define BUZZER 12  // buzzer activo
#define LED 13     // led

// INICIALIZAR VARIABLES

int t;   // tiempo
float d; // distancia
int f;   // frecuencia

// INICIAR FUNCIONES

void getDistance() {  // obtenemos la distancia entre el sensor y el objeto, se le asigna a la variable d

  digitalWrite(TRIG, 1);
  delayMicroseconds(10);
  digitalWrite(TRIG, 0);

  t = pulseIn(ECHO, 1);
  d = ( t * 0.01715 );

}

void beep( int frecuency ) { // hacemos que suene el beep a la frecuencia establecida

  digitalWrite(BUZZER, 1);
  digitalWrite(LED, 1);
  delay( frecuency );
  digitalWrite(BUZZER, 0);
  digitalWrite(LED, 0);
  delay( frecuency );

}

void setBeep() { // obtenemos la frecuencia para poder usarla en la función beep(), y se agregan las condiciones necesarias para el correcto funcionamiento del sensor de reversa
  
  f = d * 10;

  if ( d <= 100 ) {
    beep(f);
  }

}

void setup() {
  
  // DECLARAR LOD TIPOS DE PINES

  pinMode( TRIG, OUTPUT );
  pinMode( ECHO, INPUT );
  pinMode( BUZZER, OUTPUT );
  pinMode( LED, OUTPUT );

  digitalWrite(TRIG, 0);

}

void loop() {
  // put your main code here, to run repeatedly:

  getDistance();
  setBeep();

}
