# 🖥️ Cliente-Servidor con Sockets Multihilo en Java  

Este proyecto implementa un sistema **Cliente-Servidor multihilo** en Java utilizando **sockets TCP**.  
Cada cliente puede enviar un número al servidor, y este le responde con el **cuadrado del número ingresado**.  

## 🚀 Características  
- Soporte para múltiples clientes en paralelo (multithreading).  
- Comunicación en tiempo real entre clientes y servidor.  
- Cálculo del cuadrado de un número enviado desde el cliente.  
- Mensajes personalizados indicando qué cliente envió la información.  

---

## 📂 Archivos principales  
- `MultithreadedSocketServer.java` → Código del servidor principal.  
- `ServerClientThread.java` → Manejo de cada cliente en un hilo separado.  
- `TCPClient.java` → Código del cliente que envía números al servidor.  

---

## ⚡ Ejecución  

1. Compilar los archivos Java:  
   ```bash
   javac MultithreadedSocketServer.java ServerClientThread.java TCPClient.java
   ```

2. Iniciar el servidor:  
   ```bash
   java MultithreadedSocketServer
   ```

3. Ejecutar uno o varios clientes en diferentes terminales:  
   ```bash
   java TCPClient
   ```

4. Ingresar números y observar la comunicación con el servidor.  

---

## 📸 Capturas de pantalla  

### 🔹 Inicio del servidor y conexión de clientes  
![Server Started](./Imagen%20de%20WhatsApp%202025-08-29%20a%20las%2015.46.27_ee6482c6.jpg)  

### 🔹 Cliente enviando un número (ejemplo: 20)  
![Cliente 2](./Imagen%20de%20WhatsApp%202025-08-29%20a%20las%2015.46.59_ef525aa3.jpg)  

### 🔹 Cliente enviando un número (ejemplo: 12)  
![Cliente 3](./Imagen%20de%20WhatsApp%202025-08-29%20a%20las%2015.47.28_791d5fe1.jpg)  

### 🔹 Cliente enviando un número (ejemplo: 15)  
![Cliente 1](./Imagen%20de%20WhatsApp%202025-08-29%20a%20las%2015.47.46_b4e548e4.jpg)  

### 🔹 Consola del servidor mostrando mensajes de los clientes  
![Servidor Consola](./Imagen%20de%20WhatsApp%202025-08-29%20a%20las%2015.47.59_5c0c107e.jpg)  

---

## 📑 Informe breve  

- El servidor inicia y queda a la espera de conexiones.  
- Los clientes se conectan correctamente y pueden enviar números.  
- El servidor procesa cada número en **hilos independientes** y devuelve el resultado.  
- Las pruebas muestran que con varios clientes simultáneos el sistema responde de manera estable y eficiente.  

---
 

