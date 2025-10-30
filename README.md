# Ponderada 3 - Semáforo com Classes e Ponteiros em C++

## Marcos Vinicius Marcondes Silva

Este projeto implementa um semáforo utilizando a plataforma Arduino e um ESP32, demonstrando o uso de classes e ponteiros em C++. O semáforo controla três LEDs (vermelho, amarelo e verde) para simular o funcionamento de um semáforo real.

## Componentes Utilizados

- Placa ESP32
- LED Vermelho
- LED Amarelo
- LED Verde
- Resistores (220 ohms)
- Protoboard e fios de conexão

<img src="https://mm.digikey.com/Volume0/opasdata/d220001/medias/images/425/MFG_ESP32-DEVKITC-VIE.jpg?hidebanner=true" alt="ESP32" width="200" height="200" />

<img src="https://images.tcdn.com.br/img/img_prod/751846/led_difuso_3mm_vermelho_4049_1_650809d5daa4a4b8d0745bd94f5a95ec_20240418035744.jpg" alt="LED Vermelho" width="200" height="200" />

<img src="https://m.media-amazon.com/images/I/71DvlkHeCuL._AC_UF1000,1000_QL80_.jpg" alt="Jumpers" width="200" height="200" />

<img src="https://cdn.awsli.com.br/800x800/468/468162/produto/298521954cf2ed7ff4.jpg" alt="Resistores" width="200" height="200" />

## Demonstração do Projeto

![Demonstração do projeto](./assets/ponderada-semaforo.gif)

## Como Rodar

1. Clone o repositótrio: `git clone https://github.com/MZMS1510/pond-comp-3.git`
2. Abra o projeto no VS Code utilizando a extensão PlatformIO.
3. Conecte a placa ESP32 ao computador.
4. Compile e faça o upload do código para a placa.

## Estrutura do Código

### Classes

#### Led

A classe `Led` representa um LED e fornece métodos para controlá-lo (ligar e desligar).

```cpp
class Led {
private:
  int pin;
public:
  Led(int pin) : pin(pin) {
    pinMode(pin, OUTPUT);
  }
  void on() {
    digitalWrite(pin, HIGH);
  }
  void off() {
    digitalWrite(pin, LOW);
  }
};
```

#### Semaforo

A classe `Semaforo` representa o semáforo e controla os LEDs de acordo com a lógica de trânsito.
Esta classe funciona como uma máquina de estados finitos, alternando entre os estados RED, YELLOW e GREEN.

```cpp
class Semaforo {
private:
  Led redLed_m;
  Led yellowLed_m;
  Led greenLed_m;
  State state = RED;

public:
  Semaforo(Led* redLed, Led* yellowLed, Led* greenLed) :
    redLed_m(*redLed),
    yellowLed_m(*yellowLed),
    greenLed_m(*greenLed) {}

  void run() {
    switch (this->state)
    {
    case RED:
      redLed_m.on();
      yellowLed_m.off();
      greenLed_m.off();
      delay(6000); // Red for 6 seconds
      this->state = GREEN;
      break;

    case YELLOW:
      redLed_m.off();
      yellowLed_m.on();
      greenLed_m.off();
      delay(2000); // Yellow for 2 seconds
      this->state = RED;
      break;

    case GREEN:
      redLed_m.off();
      yellowLed_m.off();
      greenLed_m.on();
      delay(4000); // Green for 4 seconds
      this->state = YELLOW;
      break;
    default:
      break;
    }
  }
};
```

#### LED

A classe `Led` representa um LED individual, permitindo ligar e desligar o LED conectado a um pino específico do ESP32.

```cpp
Led::Led(int pin)
{
  pin_m = pin;
  pinMode(pin_m, OUTPUT);
}

void Led::on()
{
  digitalWrite(pin_m, HIGH);
}

void Led::off()
{
  digitalWrite(pin_m, LOW);
}
```

### Loop Principal

No loop principal chamamos o método `run` de uma instância do semáforo em um loop infinito.

```cpp
void loop() {
  semaforo.run();
}
```

### Avaliações

| Avaliador | Observações | Nota |
| --- | --- | --- |
| Davi Duarte | Trabalho muito bem executado, incluindo a lógica de detecção de obstáculos para maior segurança, realmente um trabalho excepcional. | 10 |
| Rayssa Guedes | Sistema de semáforo funcional e bem estruturado, com uso adequado de classes e objetos. Inclui ainda o uso de ponteiros, que demonstra domínio do assunto. | 10 |