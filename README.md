# Biblioteca para utilização MPU9250 com esp32 e biblioteca Eigen.

<!--excerpt-->
Utiliza a bibliteca de [álgebra linear Eigen](https://eigen.tuxfamily.org/index.php?title=Main_Page).

Recomendo fortemente para usuários iniciantes a utilização de um IDE como o [Atom](https://atom.io/). Caso o usuário tenha interesse, neste [link](https://roneydua.github.io/computacao/2020/12/23/linux-configuracao.html) há uma explicação de como instalar o Atom com a biblioteca Eigen.

# Utilização
## Conexões
Esta bilioteca utiliza I2C. As portas padrões são SDA e SCL iguais a 21 e 22 respectivamente. Isto pode ser modificado facilmete fazendo `IMU imu(Wire, 0x68, sua_sda, sua_scl);`
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

Esta biblioteca foi inspirada no trabalho do grupo [bolderflight](https://github.com/bolderflight) disponível em  [https://github.com/bolderflight/MPU9250](https://github.com/bolderflight/MPU9250)
