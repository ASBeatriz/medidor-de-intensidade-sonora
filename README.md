# Medidor de Intensidade Sonora
Projeto desenvolvido para a disciplina de Eletrônica para Computação (SSC0180) da USP - São Carlos.
## Alunos:
* Beatriz Alves dos Santos - 15588630
* Gustavo Ramos Santos Pires - 15458030
* Newton Eduardo Pena Villegas - 15481732
* Ryan Diniz Pereira - 15590907
## Descrição
O projeto "Medidor de Intensidade Sonora" realiza a medição do nível de ruído externo a partir de um sensor de som e indica a intesidade a partir de 3 LEDs nas cores verde, amarelo e vermelho. Para indicar uma baixa intensidade sonora, apenas o LED verde se mantém aceso. Para uma intensidade média, o LED amarelo também acende. Por fim, para indicar uma intensidade sonora alta, o LED vermelho também acende.
## Componentes
|Componente|Quantidade|Preço(R$)|
|---|---|---|
|Resistor 120Ω|3|0,30|
|LED|3|0,30|
|Arduino UNO|1|80,00|
## Circuito
Imagem do circuito físico:

![red-foto-circuito3](https://github.com/ASBeatriz/medidor-de-intensidade-sonora/assets/98134629/47117545-e644-4d39-ae7e-dd34f8c9a523)
![red-foto-circuito1](https://github.com/ASBeatriz/medidor-de-intensidade-sonora/assets/98134629/c4f08302-d541-4274-9abd-9e1f3cecdc4f)
## Vídeo
[Vídeo no YouTube](https://youtu.be/lC4U-7NyWsI) explicando o funcionamento do circuito.
## Código
<details>
<summary>Código para Arduino utilizado no projeto:</summary>
  
```

/*
 * Projeto Medidor de Intensidade Sonora
 * Desenvolvido para a disciplina de Eletrônica para Computação - USP São Carlos
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

```

</details>
