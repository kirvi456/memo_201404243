# Modulo MEMORIA

Modulo que muestra la informacion del estado de la memria del sistema.

### Prerequisites

What things you need to install the software and how to install them

```
GitHub
Gcc
TextEditor
```

### Installing

Clonar este repositorio https://github.com/kirvi456/mem_201404243.git

```
git clone 
```

Compilar archivo

```
make all
```
Insertar modulo

```
sudo insmod mem_201404243.ko
```
Verificar mensaje de insersion

```
dmesg
```
Verificar informacion de los procesos en el directorio proc/

```
cd /proc/
cat mem_201404243
```
Se deberia abrir el archivo con la informacion del PID, Nombre y Estado de los procesos que estan corriendo en el sistema.


## Descripcion del Codigo

Para la obtencion de los datos referente a los datos del estado de la memoria se consulto el struct sysinfo, el cual contiene la informacion de nuestro sistemas desde el SO corriendo hasta el estado de la memoria.

Ya con nuestra estructura llena, se procedio a consultar los datos que necesitamos con las funciones .totalram .freeram.

## Authors

* **Bryan Ordoñez** - *Sistemas Operativos 1*


## License

Bajo licencia GLP.
