# tp3

Falta probar si lo que hice hasta ahora esta bien. Despues cuando este segura, reemplazar las veces que se use la lista de escritores en todo el codigo por la tabla de hashing, y volver a probar.


Agregue un metodo a lista_escritores, le agregue el codigo al metodo de mostrar datos de escritor

Falta agregar lectura, ver si tendria que eliminar el listar_por_nombre de la lista de escritores

Ver si se sigen usando todos los metodos de lista_escritores

Va todo bien excepto que con algunos numeros que parecen re random me anda mal el metodo obtener_escritor, como con el 3 y con el 5555. Un posible motivo seria que algo sale mal con el stoi, y posibles soluciones serian hacer que se guarde el codigo como int y no como string, o que cuando se use el metodo obtener_escritor chequee primero si el codigo que voy a pasar por parametro se encuentra en la tabla.