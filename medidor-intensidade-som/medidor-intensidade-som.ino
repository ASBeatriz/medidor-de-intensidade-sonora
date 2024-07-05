/*
 * Projeto Medidor de Intensidade Sonora
 * Desenvolvido para a disciplina de Eletrônica - USP São Carlos
 * Baseado no site Arduino & Cia: https://www.arduinoecia.com.br/sensor-de-som-ky-038-microfone-arduino/
 */

//Difine os pinos
int pinoled_ver = 3;
int pinoled_ama = 4;
int pinoled_verm = 5;
int pino_analogico = A5;

int valor_A0 = 0;

void setup()
{
  Serial.begin(9600);
  //Inicializa os pinos
  pinMode(pinoled_ver, OUTPUT);
  pinMode(pinoled_ama, OUTPUT);
  pinMode(pinoled_verm, OUTPUT);
  pinMode(pino_analogico, INPUT);
}
void loop()
{
  valor_A0 = analogRead(pino_analogico);
  
  //Imprime o valor captado pelo sensor
  Serial.print("Saida A0: ");
  Serial.print(valor_A0);

  //Intesidade baixa
  if (valor_A0 > 20 && valor_A0 < 40)
  {
    //Apenas LED vermelho ligado
    digitalWrite(pinoled_ver, HIGH);
    digitalWrite(pinoled_ama, LOW);
    digitalWrite(pinoled_verm, LOW);
  }
  //Intensidade média
  if (valor_A0 > 40 && valor_A0 < 80)
  {
    //LEDs verde e amarelo ligados
    digitalWrite(pinoled_ver, HIGH);
    digitalWrite(pinoled_ama, HIGH);
    digitalWrite(pinoled_verm, LOW);
  }
  //Intensidade alta
  if (valor_A0 > 80)
  {
    //LEDs verde, amarelo e vermelho ligados
    digitalWrite(pinoled_ver, HIGH);
    digitalWrite(pinoled_ama, HIGH);
    digitalWrite(pinoled_verm, HIGH);
  }
  delay(50);

  //Apaga todos os LEDs
  digitalWrite(pinoled_ver, LOW);
  digitalWrite(pinoled_ama, LOW);
  digitalWrite(pinoled_verm, LOW);
}
