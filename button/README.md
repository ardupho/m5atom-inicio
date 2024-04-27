# Boton y leds

Este programa nos enseña a usar los leds de la matriz y el boton.

ATOM Matrix tiene dos botones: un botón de usuario en la parte frontal del dispositivo y un botón de reinicio en el lateral. El botón de usuario está directamente detrás de los LED RGB de 5 x 5, por lo que para hacer clic en el botón de usuario, simplemente presione en la pantalla. La API M5 maneja la eliminación de rebotes y proporciona los siguientes métodos para trabajar con eventos de botones:

M5.Btn.isPressed()
M5.Btn.isReleased()
M5.Btn.wasPressed()
M5.Btn.wasReleased()
M5.Btn.pressedFor(uint32_t ms)
M5.Btn.releasedFor(uint32_t ms)

Todos estos devuelven valores booleanos. También existen métodos para leer inmediatamente el estado del botón, así como para determinar cuándo ocurrió el último cambio.
No parece haber una manera de tratar estos eventos como interrupciones: los métodos deben usarse dentro del bucle de la aplicación.