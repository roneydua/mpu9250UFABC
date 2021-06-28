# Biblioteca para utilização MPU9250 com esp32 e biblioteca Eigen.
Utiliza a bibliteca Eigen para instalação da biblioteca Eigen portanto é necessário baixar e instalar a bibliote Einge

Eu recomendo fortemente para usuários iniciantes a utilização de um IDE como o [Atom](https://atom.io/). Caso o usuário tenha interesse, neste [link](https://roneydua.github.io/computacao/2020/12/23/linux-configuracao.html) há uma explicação de como instalar o Atom com a biblioteca Eigen.


# Utilização
## Conexões
Esta bbilioteca utiliza I2C. Atribua a porta adequada na `linha 27 ` do arquivo `IMU.cpp` da seguinte maneira `_i2c->begin(21, 22);` quando `sda=21` e `scl=22`.
## Utilização mínima

A bibliteca está escrita para utiliza-la como uma subclasse de um eventual estimador de atitude. Para um utilização mínima devese instanciar as referencias dos vetores que armazenarão as medidas em unidades de engenharia sendo acelerômetros em m/s, giroscópio e m rad/s e o magnetômetro em Tesla.

Instanciando da seguinte maneira:

```
Vector3f acel, giro, mag = Vector3f::Zero();
```
no `Setup();` inicializa-se a biblioteca com:
```
imu.begin(acel, giro, mag);
```
então, em uma função do tipo `loop()` pode-se chamar a função `imu.readSensor()`  para atualizar os valores nos ponteiros `acel`, `giro` e `mag`


# Nota

Esta biblioteca foi inspirada no trabalho do grupo [bolderflight](https://github.com/bolderflight) disponível em  https://github.com/bolderflight/MPU9250
