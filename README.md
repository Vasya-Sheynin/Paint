# Paint
### Средства разработки
Фреймворк Qt и язык C++
### Структура проекта
* Меню
* Строка состояния
* Контекстное меню
* Поле для рисования
### Функционал каждого элемента
* Меню содержит элементы File, Figures, Color.
  *  File используется для:
     1. Сохранения текущего рисунка в формате .jpg, .png, .bmp
     2. Открытия файла с изображением в том же формате
     3. Закрытия файла
     4. Выхода из приложения (Имеется диалог для сохранения изображения, если оно не было сохранено)
  *  Figures позволяет выбрать для рисования следующие геометрические примитивы:
     1. Произвольную кривую
     2. Прямую линию
     3. Круг
     4. Квадрат
  *  Color используется для выбора цвета пера для дальнейшего использования
* Строка состояния отображает название выбранной для рисования фигуры, координаты мыши относительно окна приложения
* Контекстное меню вызывается нажатием ПКМ по фигуре и содержит пункты:
  * Move - перемещает фигуру в заданное место
  * Rotate - поворачивает фигуру на заданное количество градусов
  * Design - вызывает диалоговое окно, которое позволяет:
      1. Для круга - изменить радиус
      2. Для квадрата - изменить длину и/или ширину
      3. Для любой фигуры - изменить цвет, стиль, толщину пера
  * Delete - удаляет фигуру. В случае наслоения одной фигуры на другую, удаляет ту, которая была нарисована раньше 
  * Animate - запускает короткую анимацию для фигуры (для каждой фигуры анимация уникальная)
